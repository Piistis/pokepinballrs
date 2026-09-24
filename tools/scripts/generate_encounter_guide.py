"""Generate the player encounter guide from game tables plus curated exceptions.

No ROM/toolchain or third-party modules are needed. --check never writes files.
The parsers intentionally accept the repository's table formats, not arbitrary C.
"""

import argparse
from collections import Counter, defaultdict
import csv
from dataclasses import dataclass
from fractions import Fraction
import hashlib
import io
import json
from pathlib import Path
import re

ROOT = Path(__file__).resolve().parents[2]
MANUAL = Path("docs/encounters_special.json")
OUTPUT_MD = Path("docs/ENCUENTROS.md")
OUTPUT_CSV = Path("docs/encounters_generated.csv")
PICKER = "src/main_board_catch_hatch_picker.c"


def read(root, path):
    return (root / path).read_text(encoding="utf-8")


def function(source, name):
    match = re.search(r"\b" + re.escape(name) + r"\([^;{}]*\)\s*\{", source)
    if not match:
        raise ValueError(f"No se encuentra la funcion {name}")
    start, depth = match.end() - 1, 0
    # Braces in strings/comments are removed before counting, retaining offsets.
    masked = re.sub(r'//[^\n]*|/\*.*?\*/|"(?:\\.|[^"\\])*"',
                    lambda m: " " * len(m[0]), source, flags=re.S)
    for pos in range(start, len(source)):
        depth += (masked[pos] == "{") - (masked[pos] == "}")
        if depth == 0:
            return source[match.start():pos + 1]
    raise ValueError(f"Funcion incompleta: {name}")


def digest(source):
    return hashlib.sha256(source.replace("\r\n", "\n").encode()).hexdigest()


def percent(value):
    return f"{float(value * 100):.2f}".rstrip("0").rstrip(".").replace(".", ",") + "%"


def clean_c(source):
    return re.sub(r"//[^\n]*|/\*.*?\*/", "", source, flags=re.S)


def md_cell(text):
    return text.replace("|", "\\|").replace("\n", "<br>")


@dataclass(frozen=True)
class Route:
    species: str
    mode: str
    board: str
    area: str
    method: str
    arrows: int = 0
    chance: Fraction | None = None
    detail: str = ""


def species_data(root):
    ids = {name: int(number) for name, number in re.findall(
        r"#define (SPECIES_\w+)\s+(\d+)", read(root, "include/constants/species.h"))}
    portraits = re.findall(r'\.incbin "graphics/mon_portraits/(\d+)_[^"]+\.4bpp"',
                           read(root, "data/graphics/mon_portraits.inc"))
    info = {}
    for name, body in re.findall(r"\[(SPECIES_\w+)\] = \{(.*?)\n    \}",
                                read(root, "src/data/species.h"), re.S):
        fields = dict(re.findall(r"\.(catchIndex|eggIndex|evolutionMethod|evolutionTarget) = (\w+)", body))
        fields["name"] = re.search(r'\.name = "([^"]+)"', body)[1].strip().title()
        fields["number"] = int(portraits[ids[name]])
        info[name] = fields
    assert len(info) == len(portraits) == ids["SPECIES_NONE"], "Tablas de especies/retratos desalineadas"
    assert len({data["number"] for data in info.values()}) == len(info), "Numeros nacionales duplicados"
    return info


def catch_tables(root):
    source = read(root, "data/mon_locations.inc")
    tables = {}
    labels = list(re.finditer(r"^(gWildMonLocations\w*)::[^\n]*", source, re.M))
    for index, label in enumerate(labels):
        body = source[label.end():labels[index + 1].start() if index + 1 < len(labels) else len(source)]
        rows = []
        for area, board, arrows, entries in re.findall(
                r"@ ([^|\n]+) \| (Ruby|Sapphire) \| (Two|Three) arrows\s*\n"
                r"((?:[ \t]*\.2byte SPECIES_\w+\s*\n)+)", body):
            mons = re.findall(r"SPECIES_\w+", entries)
            if len(mons) != 8:
                raise ValueError(f"Fila de caza mal formada: {label[1]} / {area} / {board}")
            rows.append((area.strip(), board, 2 if arrows == "Two" else 3, mons))
        expected = len(re.findall(r"@ .* arrows", body))
        if not rows or len(rows) != expected or len(rows) % 2:
            raise ValueError(f"Formato de encuentros no reconocido: {label[1]}")
        tables[label[1]] = rows
    return tables


def egg_tables(root):
    source = clean_c(read(root, "src/data/egg_locations.h"))
    result = {}
    for name, body in re.findall(r"const u16 (gEggLocations\w*)\[[^;=]+ = \{(.*?)\n\};", source, re.S):
        rows = re.findall(r"\{([^{}]+)\}", body)
        values = [re.findall(r"SPECIES_\w+", row) for row in rows]
        if len(values) != 2 or any(len(row) != 26 for row in values):
            raise ValueError(f"Tabla de huevos mal formada: {name}")
        result[name] = dict(zip(("Ruby", "Sapphire"), (row[:25] for row in values)))
    if not result:
        raise ValueError("No se encuentran tablas de huevos")
    return result


def mode_mappings(picker):
    catch = function(picker, "GetWildMonForSelectedGeneration")
    mapping = {"Gen " + gen: table for gen, table in re.findall(
        r"case GENERATION_(\d+):\s*return (gWildMonLocations\w*)", catch)}
    mapping["Gen 3"] = re.search(r"default:\s*return (gWildMonLocations\w*)", catch)[1]
    egg = function(picker, "GetEggMonForSelectedGeneration")
    egg_mapping = {"Gen " + gen: table for gen, table in re.findall(
        r"if \(gSelectedGeneration == GENERATION_(\d+)\)\s*return (gEggLocations\w*)", egg)}
    default = re.findall(r"return (gEggLocations\w*)", egg)[-1]
    for mode in mapping:
        egg_mapping.setdefault(mode, default)
    random_body = egg.split("if (gSelectedGeneration == GENERATION_RANDOM)", 1)[1].split(
        "if (gSelectedGeneration == GENERATION_", 1)[0]
    random_eggs = list(dict.fromkeys(re.findall(r"return (gEggLocations\w*)", random_body)))
    return mapping, egg_mapping, random_eggs


def validate_manual(root, manual, picker, info):
    if manual.get("version") != 1:
        raise ValueError("Version del archivo manual no soportada")
    for review in manual.get("reviewed_blocks", []):
        source = read(root, review["file"])
        block = source[source.index(review["start"]):source.index(review["end"])]
        actual = digest(block)
        if actual != review["sha256"]:
            raise ValueError(f"Revisar reglas manuales: cambio el bloque {review['start']}. SHA256 actual: {actual}")
    for review in manual["reviewed_functions"]:
        actual = digest(function(read(root, review["file"]), review["function"]))
        if actual != review["sha256"]:
            raise ValueError(f"Revisar porcentajes/excepciones: cambio {review['function']} en {review['file']}. "
                             f"SHA256 actual: {actual}. Actualiza la descripcion y la huella SOLO tras revisarlo.")
    overrides = manual["evolution_overrides"]
    custom = set(re.findall(r"case (SPECIES_\w+):", function(picker, "GetEvolutionTargetForCurrentContext")))
    if not custom <= set(overrides):
        raise ValueError(f"Faltan ramas de evolucion: {sorted(custom - set(overrides))}")
    seen = set()
    for entry in manual["specials"]:
        if entry["species"] not in info or entry["species"] in seen:
            raise ValueError(f"Especie especial desconocida/duplicada: {entry['species']}")
        seen.add(entry["species"])
        if not entry["description"].strip():
            raise ValueError("Descripcion especial vacia")
    tracked = set(re.findall(r"case (SPECIES_\w+): return \d+;", function(picker, "GetLegendaryEncounterIndex")))
    if not tracked <= seen:
        raise ValueError(f"Faltan especiales: {sorted(tracked - seen)}")
    for parent, entries in overrides.items():
        if parent not in info or not entries:
            raise ValueError(f"Preevolucion desconocida/vacia: {parent}")
        for entry in entries:
            if entry["target"] not in info or not entry["condition"]:
                raise ValueError(f"Rama invalida: {parent}")


def build(root=ROOT):
    info = species_data(root)
    picker = read(root, PICKER)
    manual = json.loads(read(root, MANUAL))
    validate_manual(root, manual, picker, info)
    catches, eggs = catch_tables(root), egg_tables(root)
    modes, egg_modes, random_eggs = mode_mappings(picker)
    # Reference state: all candidate/evolution Dex flags unseen, 1+ captures,
    # no last species, no e-Reader boosts. Rare/common formula is review-guarded.
    weights_text = read(root, "data/rom_2.s").split("gCommonAndEggWeights::", 1)[1]
    common = int(re.search(r"\.2byte\s+(\d+)", weights_text)[1])
    weight_func = function(picker, "BuildSpeciesWeightsForCatchEmMode")
    rare_block = weight_func.split("// Rare pokemon", 1)[1].split("case SPECIES_CLAMPERL:", 1)[0]
    rare = set(re.findall(r"case (SPECIES_\w+):", rare_block))
    blacklist = set(re.findall(r"case (SPECIES_\w+):", function(picker, "IsSpeciesBlacklistedFromRandomWildMons")))
    routes = []
    random_candidates = defaultdict(set)
    for mode, table in sorted(modes.items()):
        for area, board, arrows, mons in catches[table]:
            counts = Counter(mon for mon in mons if mon != "SPECIES_NONE")
            if not counts:
                raise ValueError(f"Fila vacia: {mode} {area} {board}")
            total = sum(count * (1 if mon in rare else common) for mon, count in counts.items())
            for mon, count in counts.items():
                routes.append(Route(mon, mode, board, area, "Caza", arrows,
                                    Fraction(count * (1 if mon in rare else common), total)))
                if mon not in blacklist:
                    random_candidates[mon, board, area].add(arrows)
    for (mon, board, area), arrows in sorted(random_candidates.items()):
        routes.append(Route(mon, "RANDOM", board, area, "Candidato a caza", detail="2/3 flechas" if len(arrows) == 2 else f"{next(iter(arrows))} flechas"))
    for mode, table in sorted(egg_modes.items()):
        for board, mons in eggs[table].items():
            counts = Counter(mon for mon in mons if mon != "SPECIES_NONE")
            if not counts:
                raise ValueError(f"Tabla de huevos vacia: {mode} {board}")
            for mon, count in counts.items():
                routes.append(Route(mon, mode, board, "Cualquier zona", "Huevo", chance=Fraction(count, sum(counts.values()))))
    for board in ("Ruby", "Sapphire"):
        mons = [mon for table in random_eggs for mon in eggs[table][board] if mon != "SPECIES_NONE"]
        for mon, count in Counter(mons).items():
            routes.append(Route(mon, "RANDOM", board, "Cualquier zona", "Huevo", chance=Fraction(count, len(mons))))
    overrides = manual["evolution_overrides"]
    edges = []
    for parent, data in info.items():
        if parent in overrides:
            edges.extend((parent, entry["target"], entry["condition"]) for entry in overrides[parent])
        elif data["evolutionTarget"] != "SPECIES_NONE" and int(data["evolutionMethod"]) != 0:
            edges.append((parent, data["evolutionTarget"], ""))
    for parent, target, condition in edges:
        routes.append(Route(target, "", "", "", "Evolucion", detail=f"Evolucion de {info[parent]['name']}" + (f" ({condition})" if condition else "")))
    for route in routes:
        if route.species not in info:
            raise ValueError(f"Encuentro con especie desconocida: {route.species}")
    reachable = {r.species for r in routes if r.method in ("Caza", "Huevo")}
    reachable |= {entry["species"] for entry in manual["specials"]}
    while True:
        expanded = reachable | {target for parent, target, _ in edges if parent in reachable}
        if expanded == reachable:
            break
        reachable = expanded
    return info, routes, manual, reachable


def route_lines(routes):
    grouped = defaultdict(set)
    for route in routes:
        grouped[(route.mode, route.area, route.method, route.arrows, route.chance, route.detail)].add(route.board)
    lines = []
    for (mode, area, method, arrows, chance, detail), boards in grouped.items():
        if method == "Evolucion":
            lines.append(detail)
            continue
        board = "Ambos" if boards == {"Ruby", "Sapphire"} else "/".join("Zafiro" if b == "Sapphire" else b for b in sorted(boards))
        text = f"{method}: {mode}, {board}, {area}"
        if arrows:
            text += f", {arrows} flechas"
        if chance is not None:
            text += f", {percent(chance)} ref."
        if detail:
            text += f", {detail}; seleccion y porcentaje variables por partida"
        lines.append(text)
    return lines


def render(info, routes, manual, reachable):
    by_species = defaultdict(list)
    for route in routes:
        by_species[route.species].append(route)
    specials = {entry["species"]: entry for entry in manual["specials"]}
    ordered = sorted(info, key=lambda mon: info[mon]["number"])
    missing = [mon for mon in ordered if mon not in reachable]
    md = ["# Lista de encuentros", "", "Generada desde el codigo. No editar este archivo: los especiales y las ramas",
          "condicionales se mantienen en [encounters_special.json](encounters_special.json).", "",
          f"Especies insertadas: **{len(info)}**. Sin ruta natural detectada: **{len(missing)}**.", "",
          "## Como leer los porcentajes", "",
          "- `ref.` es la probabilidad DENTRO del sorteo normal: candidatos y evoluciones sin registrar,",
          "  al menos una captura/evolucion en partida, sin excluir al ultimo Pokemon y sin mejoras e-Reader.",
          "- Se respetan los pesos de especies raras, no solo el numero de casillas. Los porcentajes estan redondeados.",
          "- La Pokedex, el ultimo encuentro, la primera captura y los eventos especiales cambian el resultado real.",
          "  Si un especial ocupa el 25%, el sorteo normal solo se ejecuta en el 75% restante (salvo otros eventos).",
          "- RANDOM muestra candidatos, NO encuentros garantizados: sus tablas normales se sortean por partida.",
          "  Los huevos RANDOM combinan las tablas original, Gen 2 y Gen 4; sus porcentajes tambien son de referencia.",
          "- La tabla original de huevos se usa actualmente en Gen 1 y Gen 3 y mezcla generaciones: se documenta",
          "  lo que hace el codigo, no una distribucion ideal. La evolucion requiere obtener antes la preevolucion.",
          "- No se cuentan trucos DEBUG como vias naturales. Una ruta detectada no certifica que su sprite este terminado.", "",
          "## Encuentros normales", "", "| No. | Pokemon | Como se consigue |", "| --- | --- | --- |"]
    output = io.StringIO(newline="")
    writer = csv.writer(output, delimiter=";", lineterminator="\n")
    writer.writerow(["Numero nacional", "Pokemon", "Seccion", "Modo", "Tablero", "Zona", "Metodo", "Flechas", "Porcentaje referencia", "Detalle"])
    for mon in ordered:
        if mon in specials:
            continue
        data = info[mon]
        descriptions = route_lines(by_species[mon])
        if mon not in reachable:
            descriptions.append("**Sin ruta natural detectada**" if not descriptions else "**Cadena sin origen natural detectado**")
        md.append(f"| {data['number']:03d} | {md_cell(data['name'])} | " + "<br>".join(md_cell(d) for d in descriptions) + " |")
    md += ["", "## Encuentros especiales", "", *manual["general_notes"], "",
           "| No. | Pokemon | Como se consigue |", "| --- | --- | --- |"]
    for mon in ordered:
        data = info[mon]
        for route in by_species[mon]:
            writer.writerow([f"{data['number']:03d}", data["name"], "Especial" if mon in specials else "Normal",
                             route.mode, "Zafiro" if route.board == "Sapphire" else route.board, route.area,
                             route.method, route.arrows or "", percent(route.chance) if route.chance is not None else "",
                             route.detail])
        if mon in specials:
            entry = specials[mon]
            description = entry["description"]
            if entry.get("pending"):
                description = "**Pendiente de completar:** " + description
            extra = route_lines(by_species[mon])
            if extra:
                description += "<br>Otras rutas detectadas: " + "<br>".join(extra)
            md.append(f"| {data['number']:03d} | {md_cell(data['name'])} | {md_cell(description)} |")
            writer.writerow([f"{data['number']:03d}", data["name"], "Especial", "", "", "", "Especial", "", "", entry["description"]])
        elif mon not in reachable:
            writer.writerow([f"{data['number']:03d}", data["name"], "Normal", "", "", "", "Sin ruta natural detectada", "", "", ""])
    md += ["", "## Pendientes detectados", ""]
    md += [f"- {info[mon]['number']:03d} - {info[mon]['name']}: sin origen natural en las fuentes revisadas." for mon in missing] or ["Ninguno."]
    md += ["", "## Regenerar", "", "```bash", "python3 tools/scripts/generate_encounter_guide.py", "```", "",
           "Comprobar que la lista esta al dia, sin modificar archivos:", "", "```bash",
           "python3 tools/scripts/generate_encounter_guide.py --check", "```", "",
           "Fuentes: `data/mon_locations.inc`, `src/data/egg_locations.h`, `src/data/species.h`,",
           "`data/graphics/mon_portraits.inc`, `src/main_board_catch_hatch_picker.c` y el JSON manual.", ""]
    return "\n".join(md), output.getvalue()


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--check", action="store_true", help="Fallar si falta regenerar; no escribir nada")
    args = parser.parse_args()
    try:
        artifacts = render(*build())
    except (ValueError, AssertionError, KeyError, IndexError) as error:
        parser.exit(1, f"No se ha generado la guia: {error}\n")
    stale = []
    for relative, content in zip((OUTPUT_MD, OUTPUT_CSV), artifacts):
        path = ROOT / relative
        if not path.exists() or path.read_text(encoding="utf-8-sig") != content:
            stale.append(str(relative))
            if not args.check:
                path.parent.mkdir(parents=True, exist_ok=True)
                path.write_text(content, encoding="utf-8", newline="\n")
    if args.check and stale:
        parser.exit(1, "Regenerar la lista de encuentros: " + ", ".join(stale) + "\n")
    print("Guia y CSV al dia." if args.check else "Generados docs/ENCUENTROS.md y docs/encounters_generated.csv")


if __name__ == "__main__":
    main()
