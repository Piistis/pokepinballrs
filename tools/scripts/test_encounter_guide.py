"""Regression tests for the generated encounter guide; Python standard library only."""

from collections import defaultdict
from fractions import Fraction
import json
import subprocess
import sys
import unittest
from unittest.mock import patch

import generate_encounter_guide as guide


class GuideTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.info, cls.routes, cls.manual, cls.reachable = guide.build()
        cls.md, cls.csv = guide.render(cls.info, cls.routes, cls.manual, cls.reachable)

    def test_every_species_once_in_markdown(self):
        lines = [line for line in self.md.splitlines() if line.startswith("| ") and line[2:5].isdigit()]
        self.assertEqual(len(lines), len(self.info))
        numbers = [int(line.split("|")[1]) for line in lines]
        self.assertEqual(len(set(numbers)), len(self.info))
        self.assertIn("| 004 | Charmander |", self.md)
        self.assertIn("| 909 | Fuecoco |", self.md)
        self.assertEqual(self.info["SPECIES_BLITZLE"]["number"], 522)

    def test_reference_weights_sum_to_one(self):
        groups = defaultdict(Fraction)
        for route in self.routes:
            if route.chance is not None:
                groups[route.mode, route.board, route.area, route.method, route.arrows] += route.chance
        self.assertTrue(groups)
        self.assertTrue(all(value == 1 for value in groups.values()))

    def test_real_rare_weight_not_slot_share(self):
        forest = [r for r in self.routes if r.mode == "Gen 3" and r.board == "Ruby"
                  and r.area == "Forest" and r.arrows == 2]
        duskull = next(r for r in forest if r.species == "SPECIES_DUSKULL")
        kecleon = next(r for r in forest if r.species == "SPECIES_KECLEON")
        self.assertEqual(duskull.chance, kecleon.chance * 10)

    def test_random_catch_not_fixed_percentage(self):
        candidates = [r for r in self.routes if r.method == "Candidato a caza"]
        self.assertTrue(candidates)
        self.assertTrue(all(r.chance is None for r in candidates))
        excluded = {"SPECIES_MEW", "SPECIES_MANAPHY", "SPECIES_REGIROCK", "SPECIES_ARCEUS"}
        self.assertFalse({r.species for r in candidates} & excluded)

    def test_special_eggs_and_evolution_branches(self):
        eggs = {r.species for r in self.routes if r.method == "Huevo" and r.mode == "Gen 4"}
        self.assertIn("SPECIES_BUDEW", eggs)
        self.assertNotIn("SPECIES_MANAPHY", eggs)
        self.assertNotIn("SPECIES_PICHU", eggs)
        for mon in ("SPECIES_MOTHIM", "SPECIES_GALLADE", "SPECIES_FROSLASS", "SPECIES_SHEDINJA"):
            self.assertTrue(any(r.method == "Evolucion" and r.species == mon for r in self.routes))
        self.assertIn("001-150", next(e["description"] for e in self.manual["specials"] if e["species"] == "SPECIES_MEW"))

    def test_unavailable_species_not_invented(self):
        self.assertNotIn("SPECIES_FUECOCO", self.reachable)
        self.assertIn("Sin ruta natural detectada", self.md)
        # Jirachi has a known route, even though its roulette details need review.
        self.assertIn("SPECIES_JIRACHI", self.reachable)

    def test_gen2_eevee_and_johto_evolutions(self):
        for board in ("Ruby", "Sapphire"):
            routes = [r for r in self.routes if r.species == "SPECIES_EEVEE"
                      and r.mode == "Gen 2" and r.board == board and r.area == "Ruin"]
            self.assertEqual({r.arrows for r in routes}, {2, 3})
            self.assertTrue(all(r.chance > 0 for r in routes))
        for mon, area in (("SPECIES_ESPEON", "Plains"), ("SPECIES_UMBREON", "Ruin")):
            self.assertIn(mon, self.reachable)
            entry = next(e for e in self.manual["evolution_overrides"]["SPECIES_EEVEE"] if e["target"] == mon)
            self.assertEqual(entry["condition"], f"Gen 2 o RANDOM, {area} de ambos tableros")

    def with_modified_read(self, path, transform):
        original = guide.read

        def modified(root, relative):
            value = original(root, relative)
            return transform(value) if str(relative) == str(path) else value

        return patch.object(guide, "read", modified)

    def test_table_change_is_automatically_reflected(self):
        def change(source):
            prefix, gen1 = source.split("gWildMonLocationsGen1::", 1)
            return prefix + "gWildMonLocationsGen1::" + gen1.replace("SPECIES_BULBASAUR", "SPECIES_CHARMANDER", 1)

        with self.with_modified_read("data/mon_locations.inc", change):
            _, routes, _, _ = guide.build()
        self.assertTrue(any(r.species == "SPECIES_CHARMANDER" and r.mode == "Gen 1"
                            and r.board == "Ruby" and r.area == "Forest" for r in routes))

    def test_manual_text_survives_generation(self):
        def change(source):
            value = json.loads(source)
            value["specials"][0]["description"] = "REQUISITO MANUAL DE PRUEBA"
            return json.dumps(value)

        before = (guide.ROOT / guide.MANUAL).read_bytes()
        with self.with_modified_read(guide.MANUAL, change):
            md, _ = guide.render(*guide.build())
        self.assertIn("REQUISITO MANUAL DE PRUEBA", md)
        self.assertEqual(before, (guide.ROOT / guide.MANUAL).read_bytes())

    def test_missing_manual_special_fails(self):
        def change(source):
            value = json.loads(source)
            value["specials"] = [entry for entry in value["specials"] if entry["species"] != "SPECIES_MEW"]
            return json.dumps(value)

        with self.with_modified_read(guide.MANUAL, change):
            with self.assertRaisesRegex(ValueError, "Faltan especiales"):
                guide.build()

    def test_changed_rules_require_review(self):
        with self.with_modified_read(guide.PICKER, lambda s: s.replace("return gSelectedGeneration == GENERATION_RANDOM ? 75 : 25;",
                                                                       "return gSelectedGeneration == GENERATION_RANDOM ? 50 : 25;")):
            with self.assertRaisesRegex(ValueError, "Revisar porcentajes"):
                guide.build()

    def test_changed_legendary_weight_requires_review(self):
        with self.with_modified_read(guide.PICKER, lambda s: s.replace("LEGENDARY_FIELD_BOTH, 15, 300}",
                                                                       "LEGENDARY_FIELD_BOTH, 15, 240}", 1)):
            with self.assertRaisesRegex(ValueError, "Revisar reglas manuales"):
                guide.build()

    def test_check_is_read_only(self):
        paths = [guide.ROOT / path for path in (guide.OUTPUT_MD, guide.OUTPUT_CSV, guide.MANUAL)]
        before = [(p.read_bytes(), p.stat().st_mtime_ns) for p in paths]
        subprocess.run([sys.executable, str(guide.ROOT / "tools/scripts/generate_encounter_guide.py"), "--check"], check=True)
        self.assertEqual(before, [(p.read_bytes(), p.stat().st_mtime_ns) for p in paths])

    def test_output_is_deterministic(self):
        self.assertEqual((self.md, self.csv), guide.render(*guide.build()))


if __name__ == "__main__":
    unittest.main()
