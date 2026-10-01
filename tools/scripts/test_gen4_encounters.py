"""Validate Gen 4 tables/assets and run the real C encounter and evolution logic."""

import json
import os
from pathlib import Path
import re
import shutil
import struct
import subprocess
import tempfile
import zlib

import test_legendary_encounters as legendary
import generate_encounter_guide as guide

ROOT = legendary.ROOT
picker = legendary.picker


def section(text, start, end):
    return text[text.index(start):text.index(end)]


def check_png(path, size=(144, 48)):
    data = path.read_bytes()
    assert data[:8] == b"\x89PNG\r\n\x1a\n", path
    width, height, depth, mode, compression, filtering, interlace = struct.unpack(
        ">IIBBBBB", data[16:29])
    assert (width, height) == size and mode == 3 and depth in (4, 8), path
    assert compression == filtering == interlace == 0, path
    offset, compressed, palette = 8, b"", b""
    while offset < len(data):
        size = struct.unpack(">I", data[offset:offset + 4])[0]
        kind = data[offset + 4:offset + 8]
        chunk = data[offset + 8:offset + 8 + size]
        if kind == b"IDAT":
            compressed += chunk
        if kind == b"PLTE":
            palette = chunk
        offset += size + 12
    assert 0 < len(palette) <= 48, path
    decoded = zlib.decompress(compressed)
    stride = width * depth // 8
    previous = [0] * stride
    assert len(decoded) == (stride + 1) * height, path
    for y in range(height):
        base = y * (stride + 1)
        filter_type = decoded[base]
        row = list(decoded[base + 1:base + 1 + stride])
        for x in range(stride):
            left, above = row[x - 1] if x else 0, previous[x]
            corner = previous[x - 1] if x else 0
            if filter_type == 0:
                predictor = 0
            elif filter_type == 1:
                predictor = left
            elif filter_type == 2:
                predictor = above
            elif filter_type == 3:
                predictor = (left + above) // 2
            elif filter_type == 4:
                p = left + above - corner
                distances = [abs(p - left), abs(p - above), abs(p - corner)]
                predictor = [left, above, corner][distances.index(min(distances))]
            else:
                raise AssertionError((path, filter_type))
            row[x] = (row[x] + predictor) & 255
        pixels = row if depth == 8 else [v for byte in row for v in (byte >> 4, byte & 15)]
        assert max(pixels) < 16 and max(pixels) < len(palette) // 3, path
        previous = row


def prepare_data():
    ids = {name: int(number) for name, number in re.findall(
        r"#define (SPECIES_\w+)\s+(\d+)", (ROOT / "include/constants/species.h").read_text(encoding="utf-8"))}
    info = {}
    for name, body in re.findall(r"\[(SPECIES_\w+)\] = \{(.*?)\n    \}",
                                (ROOT / "src/data/species.h").read_text(encoding="utf-8"), re.S):
        info[name] = dict(re.findall(r"\.(catchIndex|eggIndex|evolutionMethod|evolutionTarget) = (\w+)", body))
    locations = (ROOT / "data/mon_locations.inc").read_text(encoding="utf-8").split("gWildMonLocationsGen4::")[1]
    rows = re.findall(r"@ ([^\n]+)\n((?:\s*\.2byte SPECIES_\w+\n)+)", locations)
    assert len(rows) == 32
    names = [re.findall(r"SPECIES_\w+", row) for _, row in rows]
    assert all(len(row) == 8 for row in names)
    ordinary = set(sum(names, []))
    eggs_source = (ROOT / "src/data/egg_locations.h").read_text(encoding="utf-8")
    eggs4 = section(eggs_source, "const u16 gEggLocationsGen4", "const u16 gEggLocationsGen2")
    eggs = set(re.findall(r"SPECIES_\w+", eggs4)) - {"SPECIES_NONE"}
    assert len(eggs) == 14 and not ordinary & eggs
    assert len([mon for mon in ordinary if ids[mon] >= ids["SPECIES_TURTWIG"]]) == 30
    special = set(re.findall(r"case (SPECIES_\w+): return \d+;", legendary.rules))
    assert not (ordinary | eggs) & special
    for mon in ordinary:
        assert int(info[mon]["catchIndex"]) > 0, mon
    for mon in eggs:
        assert int(info[mon]["eggIndex"]) > 0, mon
    # Every nonlegendary Gen 4 species must have a route on EACH main board.
    branches = {"SPECIES_BURMY": {"SPECIES_MOTHIM"}, "SPECIES_KIRLIA": {"SPECIES_GALLADE"},
                "SPECIES_SNORUNT": {"SPECIES_FROSLASS"},
                "SPECIES_EEVEE": {"SPECIES_LEAFEON", "SPECIES_GLACEON"}}
    for board in ("Ruby", "Sapphire"):
        reachable = eggs | set(sum([row for (label, _), row in zip(rows, names) if board in label], []))
        while True:
            expanded = reachable | {info[mon]["evolutionTarget"] for mon in reachable if mon in info}
            for mon in reachable:
                expanded |= branches.get(mon, set())
            if expanded == reachable:
                break
            reachable = expanded
        missing = {mon for mon, number in ids.items()
                   if ids["SPECIES_TURTWIG"] <= number <= ids["SPECIES_ARCEUS"]
                   and mon not in special and mon not in reachable}
        assert not missing, (board, missing)
    rom = (ROOT / "data/rom_2.s").read_text(encoding="utf-8")
    animation = section(rom, "gDexAnimationIx::", "gPokedexCatchAnimIndices::")
    expressions = [value.strip() for line in re.findall(r"\.2byte ([^\n]+)", animation)
                   for value in line.split(",")]
    assert len(expressions) == ids["SPECIES_NONE"]
    offset = int(re.search(r"#define HATCH_DEX_ANIM_OFFSET (\d+)",
                          (ROOT / "include/constants/global.h").read_text(encoding="utf-8"))[1])
    values = [sum(int(term.strip()) for term in expr.replace("HATCH_DEX_ANIM_OFFSET", str(offset)).split("+"))
              for expr in expressions]
    gfx = (ROOT / "data/graphics/mon_catch_sprites.inc").read_text(encoding="utf-8")
    pals = (ROOT / "data/graphics/mon_catch_sprites_pals.inc").read_text(encoding="utf-8")
    gfx_paths = re.findall(r'\.incbin "([^\"]+)\.4bpp"', gfx)
    pal_paths = re.findall(r'\.incbin "([^\"]+)\.gbapal"', pals)
    assert gfx_paths == pal_paths and len(gfx_paths) < offset
    manifest = json.loads((ROOT / "graphics/mon_catch_sprites/catch_sprites_gfx.json").read_text(encoding="utf-8"))
    registered = {entry["gfx_filename"] for entry in manifest["files"]}
    gen4 = {mon for mon, number in ids.items() if ids["SPECIES_TURTWIG"] <= number <= ids["SPECIES_ARCEUS"]}
    special_catches = (gen4 & special) - {"SPECIES_MANAPHY"}
    assert len(special_catches) == 13
    catch_animation = section(rom, "gPokedexCatchAnimIndices::", "gPokedexListNameVramOffsets::")
    catch_values = [int(value.strip()) for line in re.findall(r"\.2byte ([^\n]+)", catch_animation)
                    for value in line.split(",")]
    assert len(catch_values) == ids["SPECIES_NONE"]
    for mon in ordinary | special_catches | {"SPECIES_ZIGZAGOON"}:
        index = int(info[mon]["catchIndex"])
        assert 0 < index < 256, mon
        assert values[ids[mon]] == index, mon
        if mon in gen4:
            assert catch_values[ids[mon]] == 0, mon
        assert index < len(gfx_paths) and Path(gfx_paths[index]).stem in registered, mon
        if mon in gen4 or mon == "SPECIES_ZIGZAGOON":
            assert gfx_paths[index].endswith("_" + mon.removeprefix("SPECIES_").lower()), mon
            check_png(ROOT / (gfx_paths[index] + ".png"))
    # Sprite group addresses must agree with the /5 and %5 runtime lookup.
    for source, kind in ((gfx, "Gfx"), (pals, "Pals")):
        consumed = 0
        groups = re.findall(r"gMonCatchSpriteGroup(\d+)_" + kind + r"::([^:]*?)(?=gMonCatchSpriteGroup|\Z)", source, re.S)
        for number, body in groups:
            assert int(number) * 5 == consumed, (kind, number)
            consumed += len(re.findall(r"\.incbin", body))
        assert consumed == len(gfx_paths), kind
    portraits = re.findall(r'\.incbin "([^\"]+)\.4bpp"',
                           (ROOT / "data/graphics/mon_portraits.inc").read_text())
    portrait_pals = (ROOT / "data/graphics/mon_portraits_pals.inc").read_text()
    portrait_manifest = json.loads((ROOT / "graphics/mon_portraits/mon_portraits_gfx.json").read_text())
    portrait_files = {entry["gfx_filename"]: entry for entry in portrait_manifest["files"]}
    assert len(portraits) == ids["SPECIES_NONE"]
    for mon in gen4 | {"SPECIES_ZIGZAGOON"}:
        path = portraits[ids[mon]]
        name = {"SPECIES_MIME_JR": "mimejr", "SPECIES_PORYGON_Z": "porygon-z"}.get(
            mon, mon.removeprefix("SPECIES_").lower())
        assert path.endswith("_" + name + "_portrait"), mon
        assert f'"{path}.gbapal"' in portrait_pals, mon
        assert portrait_files[Path(path).stem]["palette"] == Path(path).name + ".gbapal", mon
        check_png(ROOT / (path + ".png"), (48, 32))
    hatch_paths = re.findall(r'\.incbin "([^\"]+)\.4bpp"',
                            (ROOT / "data/graphics/mon_hatch_sprites.inc").read_text())
    for mon in (eggs & gen4) | {"SPECIES_MANAPHY"}:
        index = int(info[mon]["eggIndex"])
        assert values[ids[mon]] == offset + index, mon
        name = mon.removeprefix("SPECIES_").lower().replace("_", "")
        assert hatch_paths[index].endswith("/" + name + "_hatch"), mon
        check_png(ROOT / (hatch_paths[index] + ".png"), (120, 72))
    # Check ALL hatch references after moving the namespace, including older generations.
    for mon, data in info.items():
        index = values[ids[mon]]
        if index >= offset:
            assert index - offset == int(data["eggIndex"]), mon
    for group in range((len(gfx_paths) + 4) // 5):
        for kind in ("Gfx", "Pals"):
            assert f".4byte gMonCatchSpriteGroup{group}_{kind}" in rom
    assert "/*0x130*/ s16 speciesWeights[25];" in (ROOT / "include/global.h").read_text(encoding="utf-8")
    species_c = "struct Species { u16 catchIndex, eggIndex; signed char evolutionMethod; u16 evolutionTarget; };\n"
    species_c += "const struct Species gSpeciesInfo[NUM_SPECIES] = {\n"
    for mon, data in info.items():
        species_c += "    [%s] = {%s, %s, %s, %s},\n" % (
            mon, data["catchIndex"], data["eggIndex"], data["evolutionMethod"], data["evolutionTarget"])
    species_c += "};\nconst u16 gWildMonLocationsGen4[AREA_COUNT][2][8] = {\n"
    for i in range(0, len(names), 2):
        species_c += "    {{%s}, {%s}},\n" % (", ".join(names[i]), ", ".join(names[i + 1]))
    species_c += "};\nconst u16 gWildMonLocationsGen2[AREA_COUNT][2][8] = {\n"
    gen2 = section((ROOT / "data/mon_locations.inc").read_text(encoding="utf-8"),
                   "gWildMonLocationsGen2::", "gWildMonLocationsGen4::")
    gen2_rows = re.findall(r"@ ([^\n]+)\n((?:\s*\.2byte SPECIES_\w+\n)+)", gen2)
    assert len(gen2_rows) == 32
    gen2_names = [re.findall(r"SPECIES_\w+", row) for _, row in gen2_rows]
    assert all(len(row) == 8 for row in gen2_names)
    for i in range(0, len(gen2_names), 2):
        species_c += "    {{%s}, {%s}},\n" % (", ".join(gen2_names[i]), ", ".join(gen2_names[i + 1]))
    species_c += "};\n"
    for table in ("gWildMonLocations", "gWildMonLocationsGen1"):
        rows = guide.catch_tables(ROOT)[table]
        species_c += f"const u16 {table}[AREA_COUNT][2][8] = {{\n"
        for i in range(0, len(rows), 2):
            species_c += "    {{%s}, {%s}},\n" % (", ".join(rows[i][3]), ", ".join(rows[i + 1][3]))
        species_c += "};\n"
    for table, rows in guide.catch_tables(ROOT).items():
        for area, board, arrows, mons in rows:
            for mon in mons:
                assert mon in ("SPECIES_NONE", "SPECIES_TREECKO") or int(info[mon]["catchIndex"]) > 0, (table, area, board, arrows, mon)
    return species_c + eggs_source


TESTS = r'''
#define CHECK(x) do { if (!(x)) return __LINE__; } while (0)
void SetDex(u16 species, u8 flag)
{
    if (species < NUM_SAVE_SPECIES) gMain_saveData.pokedexFlags[species] = flag;
    else gExtraPokedexFlags[species - NUM_SAVE_SPECIES] = flag;
}
int TestAllCatchTables(void)
{
    int gen, area, arrows, i, roll, pass;
    u16 total;
    CHECK(!CanSpeciesAppearInCatchEmMode(SPECIES_NATU));
    CHECK(!CanSpeciesAppearInCatchEmMode(SPECIES_PICHU));
    CHECK(!CanSpeciesAppearInCatchEmMode(SPECIES_XATU));
    CHECK(!CanSpeciesAppearInCatchEmMode(SPECIES_NONE));
    CHECK(CanSpeciesAppearInCatchEmMode(SPECIES_TREECKO));
    CHECK(CanSpeciesAppearInCatchEmMode(SPECIES_ZUBAT));
    CHECK(CanSpeciesAppearInCatchEmMode(SPECIES_ODDISH));
    CHECK(CanSpeciesAppearInCatchEmMode(SPECIES_HORSEA));
    CHECK(CanSpeciesAppearInCatchEmMode(SPECIES_SANDSHREW));
    /* Simulate an old/bad RANDOM row: reject Natu without rejecting Treecko's valid index 0. */
    gSelectedGeneration = GENERATION_RANDOM;
    sRandomWildMonLocationsGenerated = TRUE;
    game.area = 0; game.catchModeArrows = 2; game.caughtMonCount = 10;
    game.lastCatchSpecies = SPECIES_NONE;
    for (i = 0; i < 8; i++) sRandomWildMonLocations[0][0][i] = SPECIES_NATU;
    sRandomWildMonLocations[0][0][1] = SPECIES_TREECKO;
    BuildSpeciesWeightsForCatchEmMode();
    CHECK(game.speciesWeights[0] == 0 && game.totalWeight > 0);
    for (roll = 0; roll < game.totalWeight; roll++)
    {
        nextRoll = (u32)roll; PickSpeciesForCatchEmMode();
        CHECK(game.currentSpecies == SPECIES_TREECKO);
    }
    sRandomWildMonLocations[0][0][1] = SPECIES_NATU;
    BuildSpeciesWeightsForCatchEmMode(); CHECK(game.totalWeight == 0);
    PickSpeciesForCatchEmMode(); CHECK(game.currentSpecies == SPECIES_TREECKO);
    for (gen = GENERATION_1; gen <= GENERATION_RANDOM; gen++)
    {
        if (gen > GENERATION_4 && gen != GENERATION_RANDOM) continue;
        gSelectedGeneration = gen;
        InitRandomWildMonLocationsForNewGame();
        for (area = 0; area < AREA_COUNT; area++)
        for (arrows = 0; arrows < 2; arrows++)
        for (pass = 0; pass < 2; pass++)
        {
            game.area = (s16)area; game.catchModeArrows = (s16)(arrows + 2);
            game.caughtMonCount = pass ? 10 : 0;
            game.lastCatchSpecies = GetWildMonForSelectedGeneration((s16)area, (s16)arrows, 0);
            BuildSpeciesWeightsForCatchEmMode(); total = game.totalWeight;
            for (i = 0; i < 8; i++)
            {
                u16 mon = GetWildMonForSelectedGeneration((s16)area, (s16)arrows, (s16)i);
                if (mon != SPECIES_NONE) CHECK(CanSpeciesAppearInCatchEmMode(mon));
            }
            for (roll = 0; roll < (total ? total : 1); roll++)
            {
                nextRoll = (u32)roll;
                PickSpeciesForCatchEmMode();
                CHECK(CanSpeciesAppearInCatchEmMode(game.currentSpecies));
                CHECK(game.currentSpecies != SPECIES_NATU);
            }
            game.totalWeight = 0;
            game.debugForcedCatchSpecies = SPECIES_NATU;
            PickSpeciesForCatchEmMode();
            CHECK(CanSpeciesAppearInCatchEmMode(game.currentSpecies));
            CHECK(game.debugForcedCatchSpecies == SPECIES_NONE);
        }
    }
    return 0;
}
int main(void)
{
    int area, field, arrows, flag, last, i, count, generation, result;
    u16 total, candidate;
    int seen[NUM_SPECIES];
    gSelectedGeneration = GENERATION_4;
    gMain.mainState = STATE_GAME_IDLE;
    game.debugForcedCatchSpecies = SPECIES_NONE;
    game.debugForcedEggSpecies = SPECIES_NONE;
    result = TestAllCatchTables(); if (result) return result;
    gSelectedGeneration = GENERATION_4;
    /* Every row can start a game and survive excluding the last encounter. */
    for (flag = 0; flag <= SPECIES_CAUGHT; flag++)
    {
        for (i = 0; i < NUM_SPECIES; i++) SetDex((u16)i, (u8)flag);
        for (field = 0; field < MAIN_FIELD_COUNT; field++)
        for (area = 0; area < AREA_COUNT; area++)
        for (arrows = 0; arrows < 2; arrows++)
        for (last = 0; last < 8; last++)
        {
            gMain.selectedField = field; game.area = (s16)area;
            game.catchModeArrows = (s16)(arrows + 2);
            game.caughtMonCount = 0;
            game.lastCatchSpecies = gWildMonLocationsGen4[area][arrows][last];
            BuildSpeciesWeightsForCatchEmMode();
            total = game.totalWeight;
            CHECK(total > 0);
            for (nextRoll = 0; nextRoll < total; nextRoll++)
            {
                PickSpeciesForCatchEmMode();
                for (i = 0; i < 8; i++)
                    if (game.currentSpecies == gWildMonLocationsGen4[area][arrows][i]) break;
                CHECK(i < 8 && gSpeciesInfo[game.currentSpecies].catchIndex > 0);
            }
        }
    }
    /* Old guest/Pichu events must not replace a fourth-generation roll. */
    game.forceSpecialMons = 1;
    gMain.eReaderBonuses[EREADER_SPECIAL_GUESTS_CARD] = 1;
    PickSpeciesForCatchEmMode();
    CHECK(gMain.eReaderBonuses[EREADER_SPECIAL_GUESTS_CARD] == 1);
    game.forceSpecialMons = 0;
    gMain.eReaderBonuses[EREADER_SPECIAL_GUESTS_CARD] = 0;
    for (generation = GENERATION_2; generation <= GENERATION_RANDOM; generation++)
    {
        if (generation != GENERATION_2 && generation != GENERATION_3
         && generation != GENERATION_4 && generation != GENERATION_RANDOM) continue;
        gSelectedGeneration = generation;
        for (field = 0; field < MAIN_FIELD_COUNT; field++)
        for (flag = 0; flag <= SPECIES_CAUGHT; flag++)
        {
            gMain.selectedField = field;
            game.caughtMonCount = 10;
            game.forcePichuEgg = generation == GENERATION_4;
            game.lastEggSpecies = SPECIES_NONE;
            for (i = 0; i < NUM_SPECIES; i++) { SetDex((u16)i, (u8)flag); seen[i] = 0; }
            BuildSpeciesWeightsForEggMode();
            total = game.totalWeight; count = GetEggEncounterCount();
            CHECK(total > 0 && count == (generation == GENERATION_RANDOM ? 75 : 25));
            for (nextRoll = 0; nextRoll < total; nextRoll++)
            {
                game.lastEggSpecies = SPECIES_NONE;
                PickSpeciesForEggMode();
                CHECK(game.currentSpecies < SPECIES_NONE && game.currentSpecies != SPECIES_MANAPHY);
                CHECK(game.currentSpecies != SPECIES_PICHU || generation != GENERATION_4);
                CHECK(gSpeciesInfo[game.currentSpecies].eggIndex > 0 || game.currentSpecies == SPECIES_WURMPLE);
                seen[game.currentSpecies]++;
            }
            for (i = 0; i < count; i++)
            {
                candidate = GetEggMonForSelectedGeneration((s16)field, (s16)i);
                CHECK(seen[candidate] > 0);
                game.lastEggSpecies = candidate;
                CHECK(GetEggEncounterWeight(candidate) == 0);
            }
            game.lastEggSpecies = SPECIES_NONE;
            game.caughtMonCount = 0;
            BuildSpeciesWeightsForEggMode(); CHECK(game.totalWeight > 0);
        }
    }
    /* Missing evolution branches remain obtainable on either board. */
    gSelectedGeneration = GENERATION_4;
    for (field = 0; field < MAIN_FIELD_COUNT; field++)
    {
        gMain.selectedField = field;
        for (i = 0; i < NUM_SPECIES; i++) SetDex((u16)i, 0);
        CHECK(GetEvolutionTargetForCurrentContext(SPECIES_BURMY) == SPECIES_WORMADAM);
        SetDex(SPECIES_WORMADAM, SPECIES_CAUGHT);
        CHECK(GetEvolutionTargetForCurrentContext(SPECIES_BURMY) == SPECIES_MOTHIM);
        SetDex(SPECIES_GARDEVOIR, SPECIES_CAUGHT);
        CHECK(GetEvolutionTargetForCurrentContext(SPECIES_KIRLIA) == SPECIES_GALLADE);
        SetDex(SPECIES_GLALIE, SPECIES_CAUGHT);
        CHECK(GetEvolutionTargetForCurrentContext(SPECIES_SNORUNT) == SPECIES_FROSLASS);
        game.area = field == FIELD_RUBY ? AREA_FOREST_RUBY : AREA_FOREST_SAPPHIRE;
        CHECK(GetEvolutionTargetForCurrentContext(SPECIES_EEVEE) == SPECIES_LEAFEON);
        game.area = field == FIELD_RUBY ? AREA_CAVE_RUBY : AREA_ICE_CAVE;
        CHECK(GetEvolutionTargetForCurrentContext(SPECIES_EEVEE) == SPECIES_GLACEON);
    }
    /* Eevee is catchable in Gen 2 on either board, even as the first catch. */
    gSelectedGeneration = GENERATION_2;
    for (field = 0; field < MAIN_FIELD_COUNT; field++)
    for (arrows = 0; arrows < 2; arrows++)
    for (flag = 0; flag <= SPECIES_CAUGHT; flag++)
    {
        gMain.selectedField = field;
        game.area = field == FIELD_RUBY ? AREA_RUIN_RUBY : AREA_RUIN_SAPPHIRE;
        game.catchModeArrows = (s16)(arrows + 2);
        game.caughtMonCount = 0;
        game.lastCatchSpecies = SPECIES_NONE;
        for (i = 0; i < NUM_SPECIES; i++) SetDex((u16)i, (u8)flag);
        BuildSpeciesWeightsForCatchEmMode();
        total = game.totalWeight; count = 0;
        for (nextRoll = 0; nextRoll < total; nextRoll++)
        {
            PickSpeciesForCatchEmMode();
            if (game.currentSpecies == SPECIES_EEVEE) count++;
        }
        CHECK(count > 0 && gSpeciesInfo[SPECIES_EEVEE].catchIndex > 0);
    }
    /* Target, evolution items and successful registration agree in every mode. */
    gMain.mainState = 1;
    for (generation = GENERATION_1; generation <= GENERATION_RANDOM; generation++)
    for (field = 0; field < MAIN_FIELD_COUNT; field++)
    {
        gSelectedGeneration = generation;
        gMain.selectedField = field;
        game.area = field == FIELD_RUBY ? AREA_PLAINS_RUBY : AREA_PLAINS_SAPPHIRE;
        candidate = generation == GENERATION_2 || generation == GENERATION_RANDOM ? SPECIES_ESPEON : SPECIES_JOLTEON;
        CHECK(GetEvolutionTargetForCurrentContext(SPECIES_EEVEE) == candidate);
        CHECK(GetEvolutionMethodForCurrentContext(SPECIES_EEVEE) == (candidate == SPECIES_ESPEON ? 1 : 7));
        SetDex(candidate, 0);
        game.currentSpecies = SPECIES_EEVEE;
        RegisterCaptureOrEvolution(1);
        CHECK(game.currentSpecies == candidate && GetSavedPokedexFlag(candidate) == SPECIES_CAUGHT);

        game.area = field == FIELD_RUBY ? AREA_RUIN_RUBY : AREA_RUIN_SAPPHIRE;
        candidate = generation == GENERATION_2 || generation == GENERATION_RANDOM ? SPECIES_UMBREON : SPECIES_JOLTEON;
        CHECK(GetEvolutionTargetForCurrentContext(SPECIES_EEVEE) == candidate);
        CHECK(GetEvolutionMethodForCurrentContext(SPECIES_EEVEE) == (candidate == SPECIES_UMBREON ? 1 : 7));
        SetDex(candidate, 0);
        game.currentSpecies = SPECIES_EEVEE;
        RegisterCaptureOrEvolution(1);
        CHECK(game.currentSpecies == candidate && GetSavedPokedexFlag(candidate) == SPECIES_CAUGHT);

        game.area = field == FIELD_RUBY ? AREA_FOREST_RUBY : AREA_FOREST_SAPPHIRE;
        candidate = generation == GENERATION_4 || generation == GENERATION_RANDOM ? SPECIES_LEAFEON : SPECIES_JOLTEON;
        CHECK(GetEvolutionTargetForCurrentContext(SPECIES_EEVEE) == candidate);
        CHECK(GetEvolutionMethodForCurrentContext(SPECIES_EEVEE) == (candidate == SPECIES_LEAFEON ? 1 : 7));
        game.area = field == FIELD_RUBY ? AREA_CAVE_RUBY : AREA_ICE_CAVE;
        candidate = generation == GENERATION_4 || generation == GENERATION_RANDOM ? SPECIES_GLACEON : SPECIES_JOLTEON;
        CHECK(GetEvolutionTargetForCurrentContext(SPECIES_EEVEE) == candidate);
        CHECK(GetEvolutionMethodForCurrentContext(SPECIES_EEVEE) == (candidate == SPECIES_GLACEON ? 1 : 7));
        game.area = field == FIELD_RUBY ? AREA_OCEAN_RUBY : AREA_OCEAN_SAPPHIRE;
        CHECK(GetEvolutionTargetForCurrentContext(SPECIES_EEVEE) == SPECIES_VAPOREON);
        CHECK(GetEvolutionMethodForCurrentContext(SPECIES_EEVEE) == 6);
        game.area = field == FIELD_RUBY ? AREA_VOLCANO : AREA_LAKE;
        CHECK(GetEvolutionTargetForCurrentContext(SPECIES_EEVEE) == (field == FIELD_RUBY ? SPECIES_FLAREON : SPECIES_VAPOREON));
        CHECK(GetEvolutionMethodForCurrentContext(SPECIES_EEVEE) == (field == FIELD_RUBY ? 3 : 6));
        game.area = field == FIELD_RUBY ? AREA_CITY : AREA_WILDERNESS;
        CHECK(GetEvolutionTargetForCurrentContext(SPECIES_EEVEE) == SPECIES_JOLTEON);
        CHECK(GetEvolutionMethodForCurrentContext(SPECIES_EEVEE) == 7);
    }
    return 0;
}
'''


def main():
    data = prepare_data()
    fixture = legendary.FIXTURE.replace("#define WILD_MON_LOCATION_COUNT 10", "#define WILD_MON_LOCATION_COUNT 8\n#define SPECIES_SHARED 3")
    fixture = fixture.replace("speciesWeights[10]", "speciesWeights[25]")
    fixture = fixture.replace("    s16 area,", "    u16 debugForcedEggSpecies, lastEggSpecies;\n    u8 forcePichuEgg, manaphyEggActive;\n    s16 area,")
    fixture = fixture.replace("struct { u16 evolutionMethod, evolutionTarget, catchIndex; } gSpeciesInfo[NUM_SPECIES];", data)
    fixture = re.sub(r"u16 GetEvolutionTargetForCurrentContext[^\n]+\n", "", fixture)
    fixture = fixture[:fixture.index("static u16 GetWildMonForSelectedGeneration")]
    fixture += "static u16 GetWildMonForSelectedGeneration(s16 area, s16 arrows, s16 index);\n"
    fixture += "const u16 gCommonAndEggWeights[] = {10, 10, 15, 15, 2, 0};\n"
    fixture += "typedef signed char s8;\n"
    fixture += "#define EWRAM_DATA\n"
    random_code = section(picker, "#define RANDOM_WILD_MON_SOURCE_TABLE_COUNT", "void NormalizeEvolvablePartySpeciesStorage")
    random_code += section(picker, "static u16 GetWildMonForSelectedGeneration", "static u16 GetEggMonForSelectedGeneration")
    getter = section(picker, "static u16 GetEggMonForSelectedGeneration", "static u8 GetSavedPokedexFlag")
    evolution = section(picker, "static u16 PickMissingBranchEvolution", "/**\n *   0 if captured via ball")
    evolution += section((ROOT / "src/main_board_evolution_mode.c").read_text(),
                         "static s8 GetEvolutionMethodForCurrentContext", "void CleanupEvolutionModeState")
    evolution += legendary.registration
    weights = section(picker, "void BuildSpeciesWeightsForCatchEmMode", "void PickSpeciesForCatchEmMode")
    egg_code = picker[picker.index("static s16 GetEggEncounterCount"):]
    source_code = fixture + random_code + legendary.dex_code + legendary.rules + evolution + getter + weights + legendary.catch + egg_code + TESTS
    compiler = os.environ.get("CC") or shutil.which("cc") or shutil.which("cl")
    if not compiler and os.name == "nt":
        candidates = sorted(Path("C:/Program Files/Microsoft Visual Studio").glob(
            "*/Community/VC/Tools/MSVC/*/bin/Hostx64/x64/cl.exe"))
        if candidates:
            compiler = str(candidates[-1])
    if not compiler:
        raise SystemExit("A host C compiler (cc or MSVC cl) is required.")
    with tempfile.TemporaryDirectory(prefix="gen4-encounters-") as temporary:
        work = Path(temporary)
        source = work / "test.c"
        source.write_text(source_code)
        executable = work / ("test.exe" if os.name == "nt" else "test")
        env = os.environ.copy()
        if Path(compiler).name.lower() in ("cl", "cl.exe"):
            env["PATH"] = str(Path(compiler).parent) + os.pathsep + env["PATH"]
            command = [compiler, "/nologo", "/W3", "/WX", "/GS-", "/Od", f"/I{ROOT / 'include'}",
                       str(source), "/link", "/nodefaultlib", "/entry:main", "/subsystem:console", f"/out:{executable}"]
        else:
            command = [compiler, "-std=c99", "-Wall", "-Wextra", "-Werror", "-I", str(ROOT / "include"),
                       str(source), "-o", str(executable)]
        subprocess.run(command, cwd=work, env=env, check=True)
        result = subprocess.run([str(executable)], cwd=work)
        if result.returncode:
            lines = source_code.splitlines()
            line = result.returncode
            detail = lines[line - 1] if 0 < line <= len(lines) else "unknown line"
            raise SystemExit(f"C regression failed (line/status {line}): {detail}")
    print("PASS: all Gen 4 nonlegendary species reachable on both boards; 32 eight-slot rows;")
    print("      catch/hatch separation, PNG palettes, graphics groups and all Dex hatch indices;")
    print("      real C catch/egg lotteries, no empty starting pools, RANDOM eggs and evolution branches.")
    print("      Gen 2 Eevee catches on both boards; Eevee targets/items and Dex registration by mode.")
    print("      Gen 4 legendary catch assets, all Gen 4 portraits/hatch assets and Zigzagoon replacements.")
    print("      All Gen 1-4/RANDOM catch pools reject egg-only sprites; zero-weight fallback and Gen 1 exceptions.")


if __name__ == "__main__":
    main()
