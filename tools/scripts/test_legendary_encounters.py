"""Exhaust the encounter lottery using the game's C functions and species order."""

import os
from pathlib import Path
import re
import shutil
import subprocess
import tempfile

ROOT = Path(__file__).resolve().parents[2]
picker = (ROOT / "src/main_board_catch_hatch_picker.c").read_text()
dex = (ROOT / "src/pokedex.c").read_text()
rules = picker[picker.index("static u8 GetSavedPokedexFlag"):
               picker.index("static u16 PickMissingBranchEvolution")]
catch = picker[picker.index("void PickSpeciesForCatchEmMode(void)"):
               picker.index("void BuildSpeciesWeightsForEggMode(void)")]
registration = picker[picker.index("void RegisterCaptureOrEvolution(s16 evolved)"):
                      picker.index("static inline u32 GetTimeAdjustedRandom(void)\n{")]
dex_code = dex[dex.index("static const s16 gPokedexOrder"):
               dex.index("static s16 GetPokedexFlag")]
dex_code = dex_code.replace('#include "../data/pokedex_entries/pokedex_order.inc"',
                            (ROOT / "data/pokedex_entries/pokedex_order.inc").read_text())

FIXTURE = r'''
#include "constants/species.h"
#include "constants/generations.h"
#include "constants/fields.h"
#include "constants/areas.h"
#include "constants/ereader.h"
typedef unsigned char u8;
typedef unsigned char bool8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
#define TRUE 1
#define FALSE 0
#define SPECIES_UNSEEN 0
#define SPECIES_CAUGHT 4
#define STATE_GAME_IDLE 99
#define WILD_MON_LOCATION_COUNT 10
struct Game {
    u32 legendaryEncounterMagic;
    u16 legendaryCaughtMask, caughtMonCount, currentSpecies, lastCatchSpecies;
    u16 debugForcedCatchSpecies, totalWeight, speciesWeights[10];
    s16 area, catchModeArrows, forceSpecialMons, evolvingPartyIndex;
} game;
struct Game *gCurrentPinballGame = &game;
struct { int mainState, selectedField; u8 eReaderBonuses[NUM_EREADER_CARDS]; } gMain;
struct { int caughtSpeciesCount; } gBoardConfig;
struct { u8 pokedexFlags[NUM_SAVE_SPECIES]; } gMain_saveData;
u8 gExtraPokedexFlags[NUM_SPECIES - NUM_SAVE_SPECIES];
int gSelectedGeneration;
struct { u16 evolutionMethod, evolutionTarget; } gSpeciesInfo[NUM_SPECIES];
void SetDex(u16 species, u8 flag);
void SaveFile_SetPokedexFlags(u16 species, u8 flag) { SetDex(species, flag); }
void AddEvolvablePartySpecies(u16 species) { (void)species; }
void RemoveEvolvablePartySpecies(s16 index) { (void)index; }
u16 GetEvolutionTargetForCurrentContext(u16 species) { return gSpeciesInfo[species].evolutionTarget; }
u32 nextRoll;
static u32 GetTimeAdjustedRandom(void) { return nextRoll; }
static u16 GetWildMonForSelectedGeneration(s16 area, s16 arrows, s16 index)
{
    (void)area; (void)arrows; (void)index;
    return SPECIES_PIDGEY;
}
'''

TESTS = r'''
#define CHECK(x) do { if (!(x)) return __LINE__; } while (0)
int counts[NUM_SPECIES + 1];
void SetDex(u16 species, u8 flag)
{
    if (species < NUM_SAVE_SPECIES) gMain_saveData.pokedexFlags[species] = flag;
    else gExtraPokedexFlags[species - NUM_SAVE_SPECIES] = flag;
}
void Reset(void)
{
    int i;
    for (i = 0; i < NUM_SPECIES; i++) SetDex(i, 0);
    for (i = 0; i < NUM_EREADER_CARDS; i++) gMain.eReaderBonuses[i] = 0;
    game.legendaryEncounterMagic = 0;
    game.legendaryCaughtMask = 0xFFFF;
    game.caughtMonCount = 0;
    game.area = AREA_CITY;
    game.debugForcedCatchSpecies = SPECIES_NONE;
    game.totalWeight = 1;
    game.speciesWeights[0] = 1;
    game.forceSpecialMons = 0;
    gBoardConfig.caughtSpeciesCount = 0;
    gMain.mainState = 1;
    gMain.selectedField = FIELD_SAPPHIRE;
    gSelectedGeneration = GENERATION_1;
}
void Sample(void)
{
    int i;
    for (i = 0; i <= NUM_SPECIES; i++) counts[i] = 0;
    for (nextRoll = 0; nextRoll < LEGENDARY_ROLL_RANGE; nextRoll++)
        counts[PickLegendaryEncounter()]++;
}
void CompleteDex(void)
{
    int i;
    for (i = 0; i < NUM_SPECIES; i++) SetDex(i, SPECIES_CAUGHT);
}
int main(void)
{
    int i, generation, field, area;
    struct Game saved;
    Reset();
    Sample();
    CHECK(counts[SPECIES_ARTICUNO] == 20 && counts[SPECIES_ZAPDOS] == 20);
    CHECK(counts[SPECIES_MOLTRES] == 20 && counts[SPECIES_NONE] == 1140);
    game.area = AREA_ICE_CAVE;
    game.caughtMonCount = 9;
    Sample();
    CHECK(counts[SPECIES_ARTICUNO] == 20);
    game.caughtMonCount = 10;
    Sample();
    CHECK(counts[SPECIES_ARTICUNO] == 240 && counts[SPECIES_ZAPDOS] == 30);
    CHECK(counts[SPECIES_MOLTRES] == 30 && counts[SPECIES_NONE] == 900);
    game.area = AREA_PLAINS_SAPPHIRE;
    Sample(); CHECK(counts[SPECIES_ZAPDOS] == 240);
    game.area = AREA_WILDERNESS;
    Sample(); CHECK(counts[SPECIES_MOLTRES] == 240);
    gMain.selectedField = FIELD_RUBY;
    Sample(); CHECK(counts[SPECIES_NONE] == 1200);

    gSelectedGeneration = GENERATION_2;
    game.area = AREA_OCEAN_RUBY;
    Sample(); CHECK(counts[SPECIES_SUICUNE] == 240 && counts[SPECIES_RAIKOU] == 30);
    game.area = AREA_SAFARI_ZONE;
    Sample(); CHECK(counts[SPECIES_RAIKOU] == 240);
    game.area = AREA_VOLCANO;
    Sample(); CHECK(counts[SPECIES_ENTEI] == 240);
    gMain.selectedField = FIELD_SAPPHIRE;
    Sample(); CHECK(counts[SPECIES_NONE] == 1200);

    /* Mew checks the first 150 national entries, not internal species IDs. */
    Reset();
    CompleteDex();
    SetDex(SPECIES_MEW, 0);
    CHECK(IsKantoPokedexCaught());
    for (i = 0; i < 150; i++)
    {
        SetDex(PokedexListPositionToSpecies(i), SPECIES_CAUGHT - 1);
        CHECK(!IsKantoPokedexCaught());
        SetDex(PokedexListPositionToSpecies(i), SPECIES_CAUGHT);
    }
    game.caughtMonCount = 14;
    Sample(); CHECK(counts[SPECIES_MEW] == 0);
    game.caughtMonCount = 15;
    Sample(); CHECK(counts[SPECIES_MEW] == 300);
    game.caughtMonCount = 19;
    Sample(); CHECK(counts[SPECIES_MEWTWO] == 0);
    game.caughtMonCount = 20;
    Sample(); CHECK(counts[SPECIES_MEWTWO] == 300);
    SetDex(SPECIES_ZAPDOS, SPECIES_CAUGHT - 1);
    Sample(); CHECK(counts[SPECIES_MEWTWO] == 0 && counts[SPECIES_MEW] == 0);
    SetDex(SPECIES_ZAPDOS, SPECIES_CAUGHT);
    gMain.selectedField = FIELD_RUBY;
    Sample(); CHECK(counts[SPECIES_MEWTWO] == 300);

    gSelectedGeneration = GENERATION_2;
    game.caughtMonCount = 19;
    Sample(); CHECK(counts[SPECIES_HO_OH] == 0);
    game.caughtMonCount = 20;
    Sample(); CHECK(counts[SPECIES_HO_OH] == 300 && counts[SPECIES_LUGIA] == 0);
    SetDex(SPECIES_ENTEI, SPECIES_CAUGHT - 1);
    Sample(); CHECK(counts[SPECIES_HO_OH] == 0);
    gMain.selectedField = FIELD_SAPPHIRE;
    Sample(); CHECK(counts[SPECIES_LUGIA] == 0);
    SetDex(SPECIES_ENTEI, SPECIES_CAUGHT);
    Sample(); CHECK(counts[SPECIES_LUGIA] == 300 && counts[SPECIES_HO_OH] == 0);
    game.area = AREA_FOREST_SAPPHIRE;
    game.caughtMonCount = 14;
    Sample(); CHECK(counts[SPECIES_CELEBI] == 0);
    game.caughtMonCount = 15;
    Sample(); CHECK(counts[SPECIES_CELEBI] == 300);
    gMain.selectedField = FIELD_RUBY;
    game.area = AREA_FOREST_RUBY;
    Sample(); CHECK(counts[SPECIES_CELEBI] == 300);
    game.area = AREA_CITY;
    Sample(); CHECK(counts[SPECIES_CELEBI] == 0);

    /* Four specials leave a shared 5% for the trio in RANDOM Forest. */
    gSelectedGeneration = GENERATION_RANDOM;
    game.caughtMonCount = 20;
    game.area = AREA_FOREST_RUBY;
    Sample();
    CHECK(counts[SPECIES_MEW] == 285 && counts[SPECIES_MEWTWO] == 285);
    CHECK(counts[SPECIES_HO_OH] == 285 && counts[SPECIES_CELEBI] == 285);
    CHECK(counts[SPECIES_SUICUNE] == 20 && counts[SPECIES_NONE] == 0);
    /* Rolling an encounter does not consume it; only a successful capture does. */
    Sample(); CHECK(counts[SPECIES_MEW] == 285);
    RegisterLegendaryCapture(SPECIES_MEW);
    Sample(); CHECK(counts[SPECIES_MEW] == 0 && counts[SPECIES_MEWTWO] == 300);
    saved = game;
    game.legendaryEncounterMagic = 0;
    NormalizeLegendaryEncounterState();
    CHECK(game.legendaryCaughtMask == 0);
    game = saved;
    Sample(); CHECK(counts[SPECIES_MEW] == 0);
    game.currentSpecies = SPECIES_MEWTWO;
    RegisterCaptureOrEvolution(0);
    CHECK(IsLegendaryCaughtThisGame(SPECIES_MEWTWO));
    CHECK(game.caughtMonCount == 20);
    Sample(); CHECK(counts[SPECIES_MEWTWO] == 0);
    RegisterLegendaryCapture(SPECIES_SUICUNE);
    Sample(); CHECK(counts[SPECIES_SUICUNE] == 0 && counts[SPECIES_RAIKOU] == 30);
    RegisterLegendaryCapture(SPECIES_RAIKOU);
    RegisterLegendaryCapture(SPECIES_ENTEI);
    Sample(); CHECK(counts[SPECIES_ENTEI] == 0);
    for (i = 0; i < NUM_SPECIES; i++)
    {
        if (GetLegendaryEncounterIndex(i) < 0) continue;
        game.currentSpecies = i;
        RegisterCaptureOrEvolution(0);
        CHECK(IsLegendaryCaughtThisGame(i));
    }
    CHECK(game.legendaryCaughtMask == 0x7FF);
    Sample(); CHECK(counts[SPECIES_NONE] == 1200);

    /* All boards, generations and areas: no forbidden species can leak. */
    for (generation = GENERATION_1; generation <= GENERATION_RANDOM; generation++)
    for (field = 0; field < 3; field++)
    for (area = 0; area < AREA_COUNT; area++)
    {
        Reset(); CompleteDex();
        gSelectedGeneration = generation;
        gMain.selectedField = field;
        game.area = area;
        game.caughtMonCount = 20;
        Sample();
        if (field >= MAIN_FIELD_COUNT || (generation != GENERATION_1
         && generation != GENERATION_2 && generation != GENERATION_RANDOM))
            CHECK(counts[SPECIES_NONE] == 1200);
        if (field != FIELD_SAPPHIRE || generation == GENERATION_2)
            CHECK(counts[SPECIES_ARTICUNO] + counts[SPECIES_ZAPDOS] + counts[SPECIES_MOLTRES] == 0);
        if (field != FIELD_RUBY || generation == GENERATION_1)
            CHECK(counts[SPECIES_SUICUNE] + counts[SPECIES_RAIKOU] + counts[SPECIES_ENTEI] == 0);
        if (area != AREA_FOREST_RUBY && area != AREA_FOREST_SAPPHIRE)
            CHECK(counts[SPECIES_CELEBI] == 0);
    }

    /* Exercise the actual catch entry point, fallback and debug precedence. */
    Reset(); game.area = AREA_ICE_CAVE; game.caughtMonCount = 10;
    nextRoll = 0;
    PickSpeciesForCatchEmMode();
    CHECK(game.currentSpecies == SPECIES_ARTICUNO && game.lastCatchSpecies == SPECIES_ARTICUNO);
    nextRoll = 1199;
    PickSpeciesForCatchEmMode(); CHECK(game.currentSpecies == SPECIES_PIDGEY);
    RegisterLegendaryCapture(SPECIES_ARTICUNO);
    game.debugForcedCatchSpecies = SPECIES_ARTICUNO;
    PickSpeciesForCatchEmMode();
    CHECK(game.currentSpecies == SPECIES_ARTICUNO && game.debugForcedCatchSpecies == SPECIES_NONE);
    gMain.mainState = STATE_GAME_IDLE;
    Sample(); CHECK(counts[SPECIES_NONE] == 1200);
    return 0;
}
'''


def main():
    names = re.findall(r"case (SPECIES_\w+): return \d+;", rules)
    locations = (ROOT / "data/mon_locations.inc").read_text()
    assert len(names) == 11
    assert not any(re.search(rf"\b{name}\b", locations) for name in names)
    assert "RegisterLegendaryCapture(gCurrentPinballGame->currentSpecies);" in picker
    layout = (ROOT / "include/global.h").read_text()
    assert "/*0x094*/ u32 legendaryEncounterMagic;" in layout
    assert "/*0x098*/ u16 legendaryCaughtMask;" in layout
    assert "/*0x09A*/ u8 filler9A[0x22];" in layout
    assert "/*0x0BC*/ s16 jirachiTargetX;" in layout
    assert "src/main_board_catch_hatch_picker.o(.rodata)" in (ROOT / "ld_script.txt").read_text()
    compiler = os.environ.get("CC") or shutil.which("cc") or shutil.which("cl")
    if not compiler and os.name == "nt":
        candidates = sorted(Path("C:/Program Files/Microsoft Visual Studio").glob(
            "*/Community/VC/Tools/MSVC/*/bin/Hostx64/x64/cl.exe"))
        if candidates:
            compiler = str(candidates[-1])
    if not compiler:
        raise SystemExit("A host C compiler (cc or MSVC cl) is required.")
    with tempfile.TemporaryDirectory(prefix="legendary-test-") as temporary:
        work = Path(temporary)
        source = work / "test.c"
        source.write_text(FIXTURE + dex_code + rules + registration + catch + TESTS)
        executable = work / ("test.exe" if os.name == "nt" else "test")
        env = os.environ.copy()
        if Path(compiler).name.lower() in ("cl", "cl.exe"):
            env["PATH"] = str(Path(compiler).parent) + os.pathsep + env["PATH"]
            command = [compiler, "/nologo", "/W3", "/WX", "/GS-", "/Od",
                       f"/I{ROOT / 'include'}", str(source), "/link", "/nodefaultlib",
                       "/entry:main", "/subsystem:console", f"/out:{executable}"]
        else:
            command = [compiler, "-std=c99", "-Wall", "-Wextra", "-Werror",
                       "-I", str(ROOT / "include"), str(source), "-o", str(executable)]
        subprocess.run(command, cwd=work, env=env, check=True)
        result = subprocess.run([str(executable)], cwd=work)
        if result.returncode:
            raise SystemExit(f"C regression failed (source line/status {result.returncode})")
    print("PASS: exact lottery weights, 10/15/20 thresholds, caught-vs-seen Dex gates,")
    print("      all generations/fields/areas, RANDOM overlap, retries, capture exclusion,")
    print("      save state, debug precedence, normal fallback and ordinary-table exclusions.")


if __name__ == "__main__":
    main()
