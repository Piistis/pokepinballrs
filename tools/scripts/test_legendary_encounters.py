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
#include "constants/legendary_encounters.h"
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
#define ARRAY_COUNT(a) (sizeof(a) / sizeof((a)[0]))
struct Game {
    u32 legendaryEncounterMagic;
    u32 legendaryCaughtMask, randomLegendarySpecialMask;
    u8 randomLegendaryRoamerMask, legendaryGeneration, legendarySelectionField, legendarySelectionReady;
    u16 caughtMonCount, currentSpecies, lastCatchSpecies;
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
u32 selectionSeed;
int randomizing;
static u32 GetTimeAdjustedRandom(void)
{
    if (!randomizing) return nextRoll;
    selectionSeed = selectionSeed * 1664525u + 1013904223u;
    return selectionSeed >> 8;
}
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
int TestNewRules(void)
{
    int field, i;
    for (field = FIELD_RUBY; field <= FIELD_SAPPHIRE; field++)
    {
        Reset(); gSelectedGeneration = GENERATION_3; gMain.selectedField = field;
        game.area = field == FIELD_RUBY ? AREA_RUIN_RUBY : AREA_RUIN_SAPPHIRE;
        SetDex(SPECIES_RAYQUAZA, SPECIES_CAUGHT);
        Sample(); CHECK(counts[SPECIES_DEOXYS] == 0);
        game.currentSpecies = SPECIES_RAYQUAZA;
        RegisterCaptureOrEvolution(0);
        Sample(); CHECK(counts[SPECIES_DEOXYS] == 240);
        game.area = AREA_CITY;
        Sample(); CHECK(counts[SPECIES_DEOXYS] == 0);

        Reset(); gSelectedGeneration = GENERATION_4; gMain.selectedField = field;
        Sample(); CHECK(counts[SPECIES_MESPRIT] == 60 && counts[SPECIES_CRESSELIA] == 60);
        game.area = AREA_LAKE; game.caughtMonCount = 9;
        Sample(); CHECK(counts[SPECIES_MESPRIT] == 240 && counts[SPECIES_UXIE] == 0);
        game.caughtMonCount = 10;
        Sample();
        CHECK(counts[SPECIES_UXIE] == (field == FIELD_SAPPHIRE ? 120 : 0));
        CHECK(counts[SPECIES_AZELF] == counts[SPECIES_UXIE]);
        RegisterLegendaryCapture(SPECIES_UXIE);
        Sample(); CHECK(counts[SPECIES_UXIE] == 0);
        CHECK(counts[SPECIES_AZELF] == (field == FIELD_SAPPHIRE ? 240 : 0));

        Reset(); gSelectedGeneration = GENERATION_4; gMain.selectedField = field;
        game.caughtMonCount = 20;
        SetDex(SPECIES_UXIE, SPECIES_CAUGHT); SetDex(SPECIES_AZELF, SPECIES_CAUGHT);
        SetDex(SPECIES_MESPRIT, SPECIES_CAUGHT - 1);
        Sample(); CHECK(counts[SPECIES_DIALGA] == 0 && counts[SPECIES_PALKIA] == 0);
        SetDex(SPECIES_MESPRIT, SPECIES_CAUGHT);
        game.caughtMonCount = 19;
        Sample(); CHECK(counts[SPECIES_DIALGA] == 0 && counts[SPECIES_PALKIA] == 0);
        game.caughtMonCount = 20;
        Sample(); CHECK(counts[SPECIES_DIALGA] == (field == FIELD_SAPPHIRE ? 300 : 0));
        CHECK(counts[SPECIES_PALKIA] == (field == FIELD_RUBY ? 300 : 0));

        Reset(); gSelectedGeneration = GENERATION_4; gMain.selectedField = field;
        game.area = AREA_VOLCANO; game.caughtMonCount = 14;
        Sample(); CHECK(counts[SPECIES_HEATRAN] == 0);
        game.caughtMonCount = 15;
        Sample(); CHECK(counts[SPECIES_HEATRAN] == (field == FIELD_RUBY ? 300 : 0));
        game.area = AREA_CITY;
        Sample(); CHECK(counts[SPECIES_HEATRAN] == 0);

        Reset(); gSelectedGeneration = GENERATION_4; gMain.selectedField = field;
        game.area = field == FIELD_RUBY ? AREA_RUIN_RUBY : AREA_RUIN_SAPPHIRE;
        SetDex(SPECIES_REGIROCK, SPECIES_CAUGHT); SetDex(SPECIES_REGICE, SPECIES_CAUGHT);
        SetDex(SPECIES_REGISTEEL, SPECIES_CAUGHT - 1);
        Sample(); CHECK(counts[SPECIES_REGIGIGAS] == 0);
        SetDex(SPECIES_REGISTEEL, SPECIES_CAUGHT);
        Sample(); CHECK(counts[SPECIES_REGIGIGAS] == 300);
        game.area = AREA_CITY;
        Sample(); CHECK(counts[SPECIES_REGIGIGAS] == 0);

        SetDex(SPECIES_DIALGA, SPECIES_CAUGHT); SetDex(SPECIES_PALKIA, SPECIES_CAUGHT);
        game.caughtMonCount = 19;
        Sample(); CHECK(counts[SPECIES_GIRATINA] == 0);
        game.caughtMonCount = 20;
        Sample(); CHECK(counts[SPECIES_GIRATINA] == 300);
        SetDex(SPECIES_PALKIA, SPECIES_CAUGHT - 1);
        Sample(); CHECK(counts[SPECIES_GIRATINA] == 0);
        SetDex(SPECIES_PALKIA, SPECIES_CAUGHT); SetDex(SPECIES_GIRATINA, SPECIES_CAUGHT);
        game.caughtMonCount = 29;
        Sample(); CHECK(counts[SPECIES_ARCEUS] == 0);
        game.caughtMonCount = 30;
        Sample(); CHECK(counts[SPECIES_ARCEUS] == 300);
        SetDex(SPECIES_GIRATINA, SPECIES_CAUGHT - 1);
        Sample(); CHECK(counts[SPECIES_ARCEUS] == 0);

        Reset(); gSelectedGeneration = GENERATION_4; gMain.selectedField = field;
        game.area = field == FIELD_RUBY ? AREA_OCEAN_RUBY : AREA_OCEAN_SAPPHIRE;
        SetDex(SPECIES_MANAPHY, SPECIES_CAUGHT);
        Sample(); CHECK(counts[SPECIES_PHIONE] == 0);
        game.currentSpecies = SPECIES_MANAPHY;
        RegisterCaptureOrEvolution(0);
        Sample(); CHECK(counts[SPECIES_PHIONE] == 300);
        game.area = AREA_CITY;
        Sample(); CHECK(counts[SPECIES_PHIONE] == 0);

        Reset(); gSelectedGeneration = GENERATION_4; gMain.selectedField = field;
        game.caughtMonCount = 15; SetDex(SPECIES_CRESSELIA, SPECIES_CAUGHT);
        Sample(); CHECK(counts[SPECIES_DARKRAI] == 0);
        game.currentSpecies = SPECIES_CRESSELIA; RegisterCaptureOrEvolution(0);
        game.caughtMonCount = 14;
        Sample(); CHECK(counts[SPECIES_DARKRAI] == 0 && counts[SPECIES_CRESSELIA] == 0);
        game.caughtMonCount = 15;
        Sample(); CHECK(counts[SPECIES_DARKRAI] == 300);
        game.area = field == FIELD_RUBY ? AREA_FOREST_RUBY : AREA_FOREST_SAPPHIRE;
        game.caughtMonCount = 14;
        Sample(); CHECK(counts[SPECIES_SHAYMIN] == 0);
        game.caughtMonCount = 15;
        Sample(); CHECK(counts[SPECIES_SHAYMIN] == 300);
        game.area = AREA_CITY;
        Sample(); CHECK(counts[SPECIES_SHAYMIN] == 0);
    }
    Reset(); CompleteDex(); gSelectedGeneration = GENERATION_4;
    game.area = AREA_FOREST_SAPPHIRE; game.caughtMonCount = 30;
    RegisterLegendaryCapture(SPECIES_MESPRIT); RegisterLegendaryCapture(SPECIES_CRESSELIA);
    Sample();
    CHECK(counts[SPECIES_DIALGA] == 240 && counts[SPECIES_GIRATINA] == 240);
    CHECK(counts[SPECIES_DARKRAI] == 240 && counts[SPECIES_SHAYMIN] == 240);
    CHECK(counts[SPECIES_ARCEUS] == 240 && counts[SPECIES_NONE] == 0);
    game.legendaryCaughtMask &= ~(1u << GetLegendaryEncounterIndex(SPECIES_MESPRIT));
    Sample();
    CHECK(counts[SPECIES_MESPRIT] == 200 && counts[SPECIES_DIALGA] == 200);
    CHECK(counts[SPECIES_GIRATINA] == 200 && counts[SPECIES_DARKRAI] == 200);
    CHECK(counts[SPECIES_SHAYMIN] == 200 && counts[SPECIES_ARCEUS] == 200);
    /* Seen-only prerequisite flags never qualify, including extended IDs. */
    for (i = 0; i < NUM_SPECIES; i++) SetDex(i, SPECIES_CAUGHT - 1);
    Sample(); CHECK(counts[SPECIES_DIALGA] == 0 && counts[SPECIES_GIRATINA] == 0 && counts[SPECIES_ARCEUS] == 0);
    return 0;
}

int TestRandomSelection(void)
{
    int seed, field, area, i, count, total, result;
    u16 species[LEGENDARY_CANDIDATE_COUNT], weights[LEGENDARY_CANDIDATE_COUNT];
    u32 specialMask, seenSpecials, expectedSpecials;
    u8 roamerMask, seenRoamers;
    struct Game saved;
    for (field = FIELD_RUBY; field <= FIELD_SAPPHIRE; field++)
    {
        seenSpecials = 0; seenRoamers = 0; expectedSpecials = 0;
        for (i = 0; i < (int)ARRAY_COUNT(sLegendarySpecialRules); i++)
            if (sLegendarySpecialRules[i].fields & (1 << field))
                expectedSpecials |= 1u << sLegendarySpecialRules[i].group;
        for (seed = 0; seed < 1024; seed++)
        {
            Reset(); CompleteDex(); gSelectedGeneration = GENERATION_RANDOM;
            gMain.selectedField = field; selectionSeed = seed; randomizing = TRUE;
            InitLegendaryEncountersForNewGame(); randomizing = FALSE;
            CHECK(IsLegendarySelectionValid());
            CHECK(CountLegendaryGroupBits(game.randomLegendaryRoamerMask) == 2);
            CHECK(CountLegendaryGroupBits(game.randomLegendarySpecialMask) == 2);
            specialMask = game.randomLegendarySpecialMask; roamerMask = game.randomLegendaryRoamerMask;
            seenSpecials |= specialMask; seenRoamers |= roamerMask;
            if (specialMask & (1u << LEGENDARY_SPECIAL_DARKRAI))
                CHECK(roamerMask & (1 << LEGENDARY_ROAM_CRESSELIA));
            saved = game;
            gSelectedGeneration = GENERATION_3;
            RestoreLegendaryEncounterState();
            CHECK(gSelectedGeneration == GENERATION_RANDOM);
            CHECK(game.randomLegendarySpecialMask == specialMask && game.randomLegendaryRoamerMask == roamerMask);
            game.caughtMonCount = 40;
            RegisterLegendaryCapture(SPECIES_RAYQUAZA); RegisterLegendaryCapture(SPECIES_MANAPHY);
            RegisterLegendaryCapture(SPECIES_CRESSELIA);
            for (area = 0; area < AREA_COUNT; area++)
            {
                game.area = area;
                count = BuildLegendaryEncounterWeights(species, weights);
                total = 0;
                CHECK(count <= LEGENDARY_CANDIDATE_COUNT);
                for (i = 0; i < count; i++) total += weights[i];
                CHECK(total <= LEGENDARY_ROLL_RANGE);
                /* Two special groups plus two compatible roamers cannot overflow. */
                for (i = 0; i < count; i++) CHECK(weights[i] <= 300);
                EnsureLegendaryEncounterSelection();
                CHECK(game.randomLegendarySpecialMask == specialMask && game.randomLegendaryRoamerMask == roamerMask);
            }
            game = saved;
            CHECK(game.legendaryCaughtMask == 0);
            gMain.selectedField = FIELD_RAYQUAZA;
            RestoreLegendaryEncounterState();
            CHECK(game.randomLegendarySpecialMask == specialMask);
            gMain.selectedField = field;
        }
        CHECK(seenSpecials == expectedSpecials);
        CHECK(seenRoamers == ((1 << LEGENDARY_ROAM_MESPRIT) | (1 << LEGENDARY_ROAM_CRESSELIA)
            | (1 << (field == FIELD_RUBY ? LEGENDARY_ROAM_BEASTS : LEGENDARY_ROAM_BIRDS))));
    }
    /* Migrate the old halfword without mistaking adjacent padding for captures. */
    Reset(); game.legendaryEncounterMagic = 0x4C454731; game.legendaryCaughtMask = 0xABCD07FF;
    NormalizeLegendaryEncounterState(); CHECK(game.legendaryCaughtMask == 0x7FF);
    CHECK(!game.legendarySelectionReady);
    InitLegendaryEncountersForNewGame(); CHECK(game.legendaryCaughtMask == 0);
    gSelectedGeneration = GENERATION_RANDOM;
    InitLegendaryEncountersForNewGame();
    game.randomLegendarySpecialMask = 0xFFFFFFFF;
    RestoreLegendaryEncounterState(); CHECK(IsLegendarySelectionValid());
    result = TestNewRules();
    return result;
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

    /* RANDOM enables only its two persisted special groups. */
    gSelectedGeneration = GENERATION_RANDOM;
    game.caughtMonCount = 20;
    game.area = AREA_FOREST_RUBY;
    game.legendarySelectionReady = TRUE;
    game.legendaryGeneration = GENERATION_RANDOM;
    game.legendarySelectionField = FIELD_RUBY;
    game.randomLegendaryRoamerMask = (1 << LEGENDARY_ROAM_BEASTS) | (1 << LEGENDARY_ROAM_MESPRIT);
    game.randomLegendarySpecialMask = (1u << LEGENDARY_SPECIAL_MEW) | (1u << LEGENDARY_SPECIAL_MEWTWO);
    Sample();
    CHECK(counts[SPECIES_MEW] == 300 && counts[SPECIES_MEWTWO] == 300);
    CHECK(counts[SPECIES_HO_OH] == 0 && counts[SPECIES_CELEBI] == 0);
    CHECK(counts[SPECIES_SUICUNE] == 20 && counts[SPECIES_NONE] == 480);
    /* Rolling an encounter does not consume it; only a successful capture does. */
    Sample(); CHECK(counts[SPECIES_MEW] == 300);
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
    CHECK(game.legendaryCaughtMask == LEGENDARY_CAPTURE_MASK);
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
         && generation != GENERATION_2 && generation != GENERATION_4 && generation != GENERATION_RANDOM))
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
    return TestRandomSelection();
}
'''


def main():
    names = re.findall(r"case (SPECIES_\w+): return \d+;", rules)
    locations = (ROOT / "data/mon_locations.inc").read_text()
    assert len(names) == 27
    assert not any(re.search(rf"\b{name}\b", locations) for name in names)
    assert "RegisterLegendaryCapture(gCurrentPinballGame->currentSpecies);" in picker
    layout = (ROOT / "include/global.h").read_text()
    assert "/*0x094*/ u32 legendaryEncounterMagic;" in layout
    assert "/*0x098*/ u32 legendaryCaughtMask;" in layout
    assert "/*0x09C*/ u32 randomLegendarySpecialMask;" in layout
    assert "/*0x0A4*/ u8 fillerA4[0x18];" in layout
    assert "/*0x0BC*/ s16 jirachiTargetX;" in layout
    assert "src/main_board_catch_hatch_picker.o(.rodata)" in (ROOT / "ld_script.txt").read_text()
    assert "InitLegendaryEncountersForNewGame();" in (ROOT / "src/all_board_pinball_game_main.c").read_text()
    assert "RestoreLegendaryEncounterState();" in (ROOT / "src/save_and_restore_game.c").read_text()
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
    print("      Gen 3/4 gates, Rayquaza/Manaphy/Cresselia this-game captures, equal overflow,")
    print("      2048 RANDOM selections, board compatibility, Darkrai dependency and save migration.")


if __name__ == "__main__":
    main()
