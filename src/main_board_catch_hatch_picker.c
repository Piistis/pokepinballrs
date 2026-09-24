#include "global.h"
#include "functions.h"
#include "main.h"
#include "variables.h"
#include "constants/ereader.h"
#include "constants/fields.h"
#include "constants/generations.h"
#include "constants/species.h"
#include "constants/pinball_game.h"
#include "constants/areas.h"
#include "constants/legendary_encounters.h"

#define MANAPHY_EGG_STATE_MAGIC 0x4D414E42
#define MANAPHY_EGG_REQUIRED_CAPTURES 5

void NormalizeManaphyEggState(void)
{
    if (gCurrentPinballGame->manaphyEggStateMagic == 0x4D414E41)
    {
        // The previous version chose the egg at opening. Preserve that attempt.
        gCurrentPinballGame->manaphyEggStateMagic = MANAPHY_EGG_STATE_MAGIC;
        gCurrentPinballGame->manaphyEggPrepared = TRUE;
        gCurrentPinballGame->manaphyEggStarted = gCurrentPinballGame->manaphyEggActive;
    }
    if (gCurrentPinballGame->manaphyEggStateMagic != MANAPHY_EGG_STATE_MAGIC
     || gCurrentPinballGame->manaphyEggCatchCount > MANAPHY_EGG_REQUIRED_CAPTURES
     || gCurrentPinballGame->manaphyEggActive > TRUE
     || gCurrentPinballGame->manaphyEggPrepared > TRUE
     || gCurrentPinballGame->manaphyEggStarted > TRUE)
    {
        gCurrentPinballGame->manaphyEggStateMagic = MANAPHY_EGG_STATE_MAGIC;
        gCurrentPinballGame->manaphyEggCatchCount = 0;
        gCurrentPinballGame->manaphyEggActive = FALSE;
        gCurrentPinballGame->manaphyEggPrepared = FALSE;
        gCurrentPinballGame->manaphyEggStarted = FALSE;
    }
}

void AddManaphyEggCapture(void)
{
    NormalizeManaphyEggState();
    if (!gCurrentPinballGame->manaphyEggActive
     && gCurrentPinballGame->manaphyEggCatchCount < MANAPHY_EGG_REQUIRED_CAPTURES)
        gCurrentPinballGame->manaphyEggCatchCount++;
}

void PrepareManaphyEgg(void)
{
    NormalizeManaphyEggState();
    gCurrentPinballGame->manaphyEggPrepared = TRUE;
    gCurrentPinballGame->manaphyEggStarted = FALSE;
    gCurrentPinballGame->manaphyEggActive = FALSE;
    if (gMain.mainState == STATE_GAME_IDLE || gMain.selectedField >= MAIN_FIELD_COUNT)
        return;

    // Explicit debug species override the event, including a Manaphy preview.
    if (gCurrentPinballGame->debugForcedEggSpecies < SPECIES_NONE)
    {
        gCurrentPinballGame->manaphyEggActive =
            gCurrentPinballGame->debugForcedEggSpecies == SPECIES_MANAPHY;
        return;
    }

    if ((gSelectedGeneration == GENERATION_4 || gSelectedGeneration == GENERATION_RANDOM)
     && ((gMain.selectedField == FIELD_RUBY && gCurrentPinballGame->area == AREA_OCEAN_RUBY)
      || (gMain.selectedField == FIELD_SAPPHIRE && gCurrentPinballGame->area == AREA_OCEAN_SAPPHIRE))
     && gCurrentPinballGame->manaphyEggCatchCount == MANAPHY_EGG_REQUIRED_CAPTURES)
    {
        gCurrentPinballGame->manaphyEggActive = TRUE;
    }
}

void BeginManaphyEggAttempt(void)
{
    NormalizeManaphyEggState();
    if (!gCurrentPinballGame->manaphyEggPrepared)
        PrepareManaphyEgg();

    if (!gCurrentPinballGame->manaphyEggStarted)
    {
        if (gCurrentPinballGame->manaphyEggActive
         && gCurrentPinballGame->debugForcedEggSpecies >= SPECIES_NONE)
            gCurrentPinballGame->manaphyEggCatchCount = 0;
        gCurrentPinballGame->manaphyEggStarted = TRUE;
    }
}

extern const u16 gWildMonLocations[AREA_COUNT][2][WILD_MON_LOCATION_COUNT];
extern const u16 gWildMonLocationsGen1[AREA_COUNT][2][WILD_MON_LOCATION_COUNT];
extern const u16 gWildMonLocationsGen2[AREA_COUNT][2][WILD_MON_LOCATION_COUNT];
extern const u16 gWildMonLocationsGen4[AREA_COUNT][2][WILD_MON_LOCATION_COUNT];
extern const u16 gEggLocations[MAIN_FIELD_COUNT][26];
extern const u16 gEggLocationsGen2[MAIN_FIELD_COUNT][26];
extern const u16 gEggLocationsGen4[MAIN_FIELD_COUNT][26];

#define EVOLVABLE_PARTY_SPECIES_STORAGE_MAGIC 0x504B4556
#define RANDOM_WILD_MON_SOURCE_TABLE_COUNT 4
#define RANDOM_WILD_MON_POOL_CAPACITY (RANDOM_WILD_MON_SOURCE_TABLE_COUNT * 2 * WILD_MON_LOCATION_COUNT)

static EWRAM_DATA u16 sRandomWildMonLocations[AREA_COUNT][2][WILD_MON_LOCATION_COUNT];
static EWRAM_DATA bool8 sRandomWildMonLocationsGenerated = FALSE;

static bool8 IsSpeciesBlacklistedFromRandomWildMons(u16 species);
static u16 GetWildMonFromGenerationTable(s16 generationTable, s16 area, s16 threeArrows, s16 index);
static void AddSpeciesToRandomWildMonPool(u16 *pool, s16 *poolCount, u16 species);
static s16 BuildRandomWildMonPool(s16 area, s16 threeArrows, u16 *pool);
static bool8 IsSpeciesAlreadyInRandomWildMonRow(s16 area, s16 threeArrows, s16 slotLimit, u16 species);
static u16 PickRandomWildMonForSlot(s16 area, s16 threeArrows, s16 slot, u16 *pool, s16 poolCount);
static void BuildRandomWildMonLocations(void);
static inline u32 GetTimeAdjustedRandom(void);

void InitRandomWildMonLocationsForNewGame(void)
{
    sRandomWildMonLocationsGenerated = FALSE;

    if (gSelectedGeneration == GENERATION_RANDOM)
        BuildRandomWildMonLocations();
}

static bool8 IsSpeciesBlacklistedFromRandomWildMons(u16 species)
{
    switch (species)
    {
    case SPECIES_NONE:
    case SPECIES_DEOXYS:
    case SPECIES_ARTICUNO:
    case SPECIES_ZAPDOS:
    case SPECIES_MOLTRES:
    case SPECIES_MEWTWO:
    case SPECIES_MEW:
    case SPECIES_RAIKOU:
    case SPECIES_ENTEI:
    case SPECIES_SUICUNE:
    case SPECIES_LUGIA:
    case SPECIES_HO_OH:
    case SPECIES_CELEBI:
    case SPECIES_REGIROCK:
    case SPECIES_REGICE:
    case SPECIES_REGISTEEL:
    case SPECIES_LATIAS:
    case SPECIES_LATIOS:
    case SPECIES_KYOGRE:
    case SPECIES_GROUDON:
    case SPECIES_RAYQUAZA:
    case SPECIES_JIRACHI:
    case SPECIES_UXIE:
    case SPECIES_AZELF:
    case SPECIES_MESPRIT:
    case SPECIES_DIALGA:
    case SPECIES_PALKIA:
    case SPECIES_HEATRAN:
    case SPECIES_REGIGIGAS:
    case SPECIES_GIRATINA:
    case SPECIES_CRESSELIA:
    case SPECIES_PHIONE:
    case SPECIES_MANAPHY:
    case SPECIES_DARKRAI:
    case SPECIES_SHAYMIN:
    case SPECIES_ARCEUS:
        return TRUE;
    default:
        return FALSE;
    }
}

static u16 GetWildMonFromGenerationTable(s16 generationTable, s16 area, s16 threeArrows, s16 index)
{
    switch (generationTable)
    {
    case GENERATION_1:
        return gWildMonLocationsGen1[area][threeArrows][index];
    case GENERATION_2:
        return gWildMonLocationsGen2[area][threeArrows][index];
    case GENERATION_4:
        return gWildMonLocationsGen4[area][threeArrows][index];
    default:
        return gWildMonLocations[area][threeArrows][index];
    }
}

static void AddSpeciesToRandomWildMonPool(u16 *pool, s16 *poolCount, u16 species)
{
    if (IsSpeciesBlacklistedFromRandomWildMons(species))
        return;

    if (*poolCount >= RANDOM_WILD_MON_POOL_CAPACITY)
        return;

    pool[*poolCount] = species;
    (*poolCount)++;
}

static s16 BuildRandomWildMonPool(s16 area, s16 threeArrows, u16 *pool)
{
    s16 generationTable;
    s16 arrows;
    s16 index;
    s16 poolCount = 0;

    for (generationTable = 0; generationTable < RANDOM_WILD_MON_SOURCE_TABLE_COUNT; generationTable++)
    {
        for (index = 0; index < WILD_MON_LOCATION_COUNT; index++)
            AddSpeciesToRandomWildMonPool(pool, &poolCount, GetWildMonFromGenerationTable(generationTable, area, threeArrows, index));
    }

    if (poolCount != 0)
        return poolCount;

    for (generationTable = 0; generationTable < RANDOM_WILD_MON_SOURCE_TABLE_COUNT; generationTable++)
    {
        for (arrows = 0; arrows < 2; arrows++)
        {
            for (index = 0; index < WILD_MON_LOCATION_COUNT; index++)
                AddSpeciesToRandomWildMonPool(pool, &poolCount, GetWildMonFromGenerationTable(generationTable, area, arrows, index));
        }
    }

    return poolCount;
}

static bool8 IsSpeciesAlreadyInRandomWildMonRow(s16 area, s16 threeArrows, s16 slotLimit, u16 species)
{
    s16 slot;

    for (slot = 0; slot < slotLimit; slot++)
    {
        if (sRandomWildMonLocations[area][threeArrows][slot] == species)
            return TRUE;
    }

    return FALSE;
}

static u16 PickRandomWildMonForSlot(s16 area, s16 threeArrows, s16 slot, u16 *pool, s16 poolCount)
{
    s16 attempts;
    u16 species;

    if (poolCount == 0)
        return SPECIES_NONE;

    for (attempts = 0; attempts < WILD_MON_LOCATION_COUNT; attempts++)
    {
        species = pool[GetTimeAdjustedRandom() % poolCount];
        if (!IsSpeciesAlreadyInRandomWildMonRow(area, threeArrows, slot, species))
            return species;
    }

    return pool[GetTimeAdjustedRandom() % poolCount];
}

static void BuildRandomWildMonLocations(void)
{
    s16 area;
    s16 threeArrows;
    s16 slot;
    u16 pool[RANDOM_WILD_MON_POOL_CAPACITY];
    s16 poolCount;

    for (area = 0; area < AREA_COUNT; area++)
    {
        for (threeArrows = 0; threeArrows < 2; threeArrows++)
        {
            poolCount = BuildRandomWildMonPool(area, threeArrows, pool);
            for (slot = 0; slot < WILD_MON_LOCATION_COUNT; slot++)
                sRandomWildMonLocations[area][threeArrows][slot] = PickRandomWildMonForSlot(area, threeArrows, slot, pool, poolCount);
        }
    }

    sRandomWildMonLocationsGenerated = TRUE;
}

void NormalizeEvolvablePartySpeciesStorage(void)
{
    s16 i;
    s16 partySize = gCurrentPinballGame->evolvablePartySize;
    bool8 clearHighBytes = FALSE;

    if (partySize < 0 || partySize > MAX_EVOLVABLE_PARTY_SIZE)
        partySize = MAX_EVOLVABLE_PARTY_SIZE;

    if (gCurrentPinballGame->evolvablePartySpeciesStorageMagic != EVOLVABLE_PARTY_SPECIES_STORAGE_MAGIC)
    {
        clearHighBytes = TRUE;
    }
    else
    {
        for (i = 0; i < partySize; i++)
        {
            u16 species = gCurrentPinballGame->evolvablePartySpecies[i]
                        | (gCurrentPinballGame->evolvablePartySpeciesHighBytes[i] << 8);

            if (species >= SPECIES_NONE)
                clearHighBytes = TRUE;
        }
    }

    if (!clearHighBytes)
        return;

    for (i = 0; i < MAX_EVOLVABLE_PARTY_SIZE; i++)
        gCurrentPinballGame->evolvablePartySpeciesHighBytes[i] = 0;

    gCurrentPinballGame->evolvablePartySpeciesStorageMagic = EVOLVABLE_PARTY_SPECIES_STORAGE_MAGIC;
}

u16 GetEvolvablePartySpecies(s16 index)
{
    u16 species = gCurrentPinballGame->evolvablePartySpecies[index];

    if (gCurrentPinballGame->evolvablePartySpeciesStorageMagic == EVOLVABLE_PARTY_SPECIES_STORAGE_MAGIC)
        species |= gCurrentPinballGame->evolvablePartySpeciesHighBytes[index] << 8;

    return species;
}

void SetEvolvablePartySpecies(s16 index, u16 species)
{
    NormalizeEvolvablePartySpeciesStorage();

    gCurrentPinballGame->evolvablePartySpecies[index] = species & 0xFF;
    gCurrentPinballGame->evolvablePartySpeciesHighBytes[index] = species >> 8;
}

static void AddEvolvablePartySpecies(u16 species)
{
    s16 i;

    if (gCurrentPinballGame->evolvablePartySize < MAX_EVOLVABLE_PARTY_SIZE)
    {
        SetEvolvablePartySpecies(gCurrentPinballGame->evolvablePartySize, species);
        gCurrentPinballGame->evolvablePartySize++;
    }
    else
    {
        for (i = 0; i < MAX_EVOLVABLE_PARTY_SIZE - 1; i++)
            SetEvolvablePartySpecies(i, GetEvolvablePartySpecies(i + 1));

        SetEvolvablePartySpecies(MAX_EVOLVABLE_PARTY_SIZE - 1, species);
    }
}

static void RemoveEvolvablePartySpecies(s16 index)
{
    s16 i;

    if (gCurrentPinballGame->evolvablePartySize <= 0)
        return;

    gCurrentPinballGame->evolvablePartySize--;

    for (i = index; i < gCurrentPinballGame->evolvablePartySize; i++)
        SetEvolvablePartySpecies(i, GetEvolvablePartySpecies(i + 1));

    SetEvolvablePartySpecies(gCurrentPinballGame->evolvablePartySize, 0);
}

static u16 GetWildMonForSelectedGeneration(s16 area, s16 threeArrows, s16 index)
{
    switch (gSelectedGeneration)
    {
    case GENERATION_1:
        return gWildMonLocationsGen1[area][threeArrows][index];
    case GENERATION_2:
        return gWildMonLocationsGen2[area][threeArrows][index];
    case GENERATION_4:
        return gWildMonLocationsGen4[area][threeArrows][index];
    case GENERATION_RANDOM:
        if (!sRandomWildMonLocationsGenerated)
            BuildRandomWildMonLocations();
        return sRandomWildMonLocations[area][threeArrows][index];
    default:
        return gWildMonLocations[area][threeArrows][index];
    }
}

static u16 GetEggMonForSelectedGeneration(s16 field, s16 index)
{
    if (gSelectedGeneration == GENERATION_RANDOM)
    {
        if (index < 25)
            return gEggLocations[field][index];
        if (index < 50)
            return gEggLocationsGen2[field][index - 25];
        return gEggLocationsGen4[field][index - 50];
    }
    if (gSelectedGeneration == GENERATION_4)
        return gEggLocationsGen4[field][index];
    if (gSelectedGeneration == GENERATION_2)
        return gEggLocationsGen2[field][index];

    return gEggLocations[field][index];
}

static u8 GetSavedPokedexFlag(s16 species)
{
    if (species >= 0 && species < NUM_SAVE_SPECIES)
        return gMain_saveData.pokedexFlags[species];
    if (species >= NUM_SAVE_SPECIES && species < NUM_SPECIES)
        return gExtraPokedexFlags[species - NUM_SAVE_SPECIES];
    return SPECIES_UNSEEN;
}

#define LEGENDARY_ENCOUNTER_MAGIC 0x4C454732
#define LEGENDARY_ROLL_RANGE 1200
#define LEGENDARY_CAPTURE_MASK 0x07FFFFFF
#define LEGENDARY_CANDIDATE_COUNT 28
#define LEGENDARY_FIELD_RUBY (1 << FIELD_RUBY)
#define LEGENDARY_FIELD_SAPPHIRE (1 << FIELD_SAPPHIRE)
#define LEGENDARY_FIELD_BOTH (LEGENDARY_FIELD_RUBY | LEGENDARY_FIELD_SAPPHIRE)

struct LegendarySpecialRule
{
    u16 species;
    u8 group;
    u8 generation;
    u8 fields;
    u8 captures;
    u16 weight;
};

static const struct LegendarySpecialRule sLegendarySpecialRules[] =
{
    {SPECIES_MEW, LEGENDARY_SPECIAL_MEW, GENERATION_1, LEGENDARY_FIELD_BOTH, 15, 300},
    {SPECIES_MEWTWO, LEGENDARY_SPECIAL_MEWTWO, GENERATION_1, LEGENDARY_FIELD_BOTH, 20, 300},
    {SPECIES_HO_OH, LEGENDARY_SPECIAL_HO_OH, GENERATION_2, LEGENDARY_FIELD_RUBY, 20, 300},
    {SPECIES_LUGIA, LEGENDARY_SPECIAL_LUGIA, GENERATION_2, LEGENDARY_FIELD_SAPPHIRE, 20, 300},
    {SPECIES_CELEBI, LEGENDARY_SPECIAL_CELEBI, GENERATION_2, LEGENDARY_FIELD_BOTH, 15, 300},
    {SPECIES_DEOXYS, LEGENDARY_SPECIAL_DEOXYS, GENERATION_3, LEGENDARY_FIELD_BOTH, 0, 240},
    {SPECIES_UXIE, LEGENDARY_SPECIAL_LAKE_PAIR, GENERATION_4, LEGENDARY_FIELD_SAPPHIRE, 10, 120},
    {SPECIES_AZELF, LEGENDARY_SPECIAL_LAKE_PAIR, GENERATION_4, LEGENDARY_FIELD_SAPPHIRE, 10, 120},
    {SPECIES_DIALGA, LEGENDARY_SPECIAL_DIALGA, GENERATION_4, LEGENDARY_FIELD_SAPPHIRE, 20, 300},
    {SPECIES_PALKIA, LEGENDARY_SPECIAL_PALKIA, GENERATION_4, LEGENDARY_FIELD_RUBY, 20, 300},
    {SPECIES_HEATRAN, LEGENDARY_SPECIAL_HEATRAN, GENERATION_4, LEGENDARY_FIELD_RUBY, 15, 300},
    {SPECIES_REGIGIGAS, LEGENDARY_SPECIAL_REGIGIGAS, GENERATION_4, LEGENDARY_FIELD_BOTH, 0, 300},
    {SPECIES_GIRATINA, LEGENDARY_SPECIAL_GIRATINA, GENERATION_4, LEGENDARY_FIELD_BOTH, 20, 300},
    {SPECIES_PHIONE, LEGENDARY_SPECIAL_PHIONE, GENERATION_4, LEGENDARY_FIELD_BOTH, 0, 300},
    {SPECIES_DARKRAI, LEGENDARY_SPECIAL_DARKRAI, GENERATION_4, LEGENDARY_FIELD_BOTH, 15, 300},
    {SPECIES_SHAYMIN, LEGENDARY_SPECIAL_SHAYMIN, GENERATION_4, LEGENDARY_FIELD_BOTH, 15, 300},
    {SPECIES_ARCEUS, LEGENDARY_SPECIAL_ARCEUS, GENERATION_4, LEGENDARY_FIELD_BOTH, 30, 300},
};

static const u8 sLegendaryRoamerFields[LEGENDARY_ROAM_GROUP_COUNT] =
{
    LEGENDARY_FIELD_SAPPHIRE,
    LEGENDARY_FIELD_RUBY,
    LEGENDARY_FIELD_BOTH,
    LEGENDARY_FIELD_BOTH,
};

static s16 GetLegendaryEncounterIndex(u16 species)
{
    switch (species)
    {
    case SPECIES_ARTICUNO: return 0;
    case SPECIES_ZAPDOS: return 1;
    case SPECIES_MOLTRES: return 2;
    case SPECIES_MEWTWO: return 3;
    case SPECIES_MEW: return 4;
    case SPECIES_SUICUNE: return 5;
    case SPECIES_RAIKOU: return 6;
    case SPECIES_ENTEI: return 7;
    case SPECIES_LUGIA: return 8;
    case SPECIES_HO_OH: return 9;
    case SPECIES_CELEBI: return 10;
    case SPECIES_DEOXYS: return 11;
    case SPECIES_UXIE: return 12;
    case SPECIES_AZELF: return 13;
    case SPECIES_MESPRIT: return 14;
    case SPECIES_DIALGA: return 15;
    case SPECIES_PALKIA: return 16;
    case SPECIES_HEATRAN: return 17;
    case SPECIES_REGIGIGAS: return 18;
    case SPECIES_GIRATINA: return 19;
    case SPECIES_CRESSELIA: return 20;
    case SPECIES_PHIONE: return 21;
    case SPECIES_DARKRAI: return 22;
    case SPECIES_SHAYMIN: return 23;
    case SPECIES_ARCEUS: return 24;
    case SPECIES_RAYQUAZA: return 25;
    case SPECIES_MANAPHY: return 26;
    default: return -1;
    }
}

static s16 CountLegendaryGroupBits(u32 mask)
{
    s16 count = 0;
    while (mask)
    {
        count += mask & 1;
        mask >>= 1;
    }
    return count;
}

static bool8 IsLegendarySelectionValid(void)
{
    s16 i;
    u32 allowedSpecials = 0;
    u8 allowedRoamers = 0, fieldMask;
    if (gCurrentPinballGame->legendarySelectionReady != TRUE
     || gCurrentPinballGame->legendaryGeneration >= GENERATION_SELECT_OPTION_COUNT
     || gCurrentPinballGame->legendarySelectionField >= MAIN_FIELD_COUNT)
        return FALSE;
    if (gCurrentPinballGame->legendaryGeneration != GENERATION_RANDOM)
        return TRUE;
    fieldMask = 1 << gCurrentPinballGame->legendarySelectionField;
    for (i = 0; i < LEGENDARY_ROAM_GROUP_COUNT; i++)
        if (sLegendaryRoamerFields[i] & fieldMask)
            allowedRoamers |= 1 << i;
    for (i = 0; i < (s16)ARRAY_COUNT(sLegendarySpecialRules); i++)
        if (sLegendarySpecialRules[i].fields & fieldMask)
            allowedSpecials |= 1u << sLegendarySpecialRules[i].group;
    if (!(gCurrentPinballGame->randomLegendaryRoamerMask & (1 << LEGENDARY_ROAM_CRESSELIA)))
        allowedSpecials &= ~(1u << LEGENDARY_SPECIAL_DARKRAI);
    return !(gCurrentPinballGame->randomLegendaryRoamerMask & ~allowedRoamers)
        && !(gCurrentPinballGame->randomLegendarySpecialMask & ~allowedSpecials)
        && CountLegendaryGroupBits(gCurrentPinballGame->randomLegendaryRoamerMask) == RANDOM_LEGENDARY_ROAMER_COUNT
        && CountLegendaryGroupBits(gCurrentPinballGame->randomLegendarySpecialMask) == RANDOM_LEGENDARY_SPECIAL_COUNT;
}

static void NormalizeLegendaryEncounterState(void)
{
    u32 oldCaptures = 0;
    if (gCurrentPinballGame->legendaryEncounterMagic == LEGENDARY_ENCOUNTER_MAGIC
     && !(gCurrentPinballGame->legendaryCaughtMask & ~LEGENDARY_CAPTURE_MASK))
    {
        if (gCurrentPinballGame->legendarySelectionReady && !IsLegendarySelectionValid())
            gCurrentPinballGame->legendarySelectionReady = FALSE;
        return;
    }

    // Version 1 stored eleven capture bits in the low halfword at 0x098.
    if (gCurrentPinballGame->legendaryEncounterMagic == 0x4C454731)
        oldCaptures = gCurrentPinballGame->legendaryCaughtMask & 0x7FF;
    gCurrentPinballGame->legendaryEncounterMagic = LEGENDARY_ENCOUNTER_MAGIC;
    gCurrentPinballGame->legendaryCaughtMask = oldCaptures;
    gCurrentPinballGame->randomLegendarySpecialMask = 0;
    gCurrentPinballGame->randomLegendaryRoamerMask = 0;
    gCurrentPinballGame->legendarySelectionReady = FALSE;
}

static bool8 IsLegendaryCaughtThisGame(u16 species)
{
    s16 index = GetLegendaryEncounterIndex(species);
    return index >= 0 && (gCurrentPinballGame->legendaryCaughtMask & (1u << index));
}

static void RegisterLegendaryCapture(u16 species)
{
    s16 index = GetLegendaryEncounterIndex(species);
    NormalizeLegendaryEncounterState();
    if (index >= 0)
        gCurrentPinballGame->legendaryCaughtMask |= 1u << index;
}

static void ChooseRandomLegendaryGroups(void)
{
    u8 candidates[LEGENDARY_SPECIAL_GROUP_COUNT];
    s16 i, count = 0, pick;
    u32 eligible = 0;
    const struct LegendarySpecialRule *rule;
    u8 fieldMask = 1 << gMain.selectedField;

    gCurrentPinballGame->randomLegendaryRoamerMask = 0;
    gCurrentPinballGame->randomLegendarySpecialMask = 0;
    for (i = 0; i < LEGENDARY_ROAM_GROUP_COUNT; i++)
        if (sLegendaryRoamerFields[i] & fieldMask)
            candidates[count++] = (u8)i;
    for (i = 0; i < RANDOM_LEGENDARY_ROAMER_COUNT && count > 0; i++)
    {
        pick = GetTimeAdjustedRandom() % count;
        gCurrentPinballGame->randomLegendaryRoamerMask |= 1 << candidates[pick];
        candidates[pick] = candidates[--count];
    }

    for (i = 0; i < (s16)ARRAY_COUNT(sLegendarySpecialRules); i++)
    {
        rule = &sLegendarySpecialRules[i];
        if (!(rule->fields & fieldMask))
            continue;
        if (rule->group == LEGENDARY_SPECIAL_DARKRAI
         && !(gCurrentPinballGame->randomLegendaryRoamerMask & (1 << LEGENDARY_ROAM_CRESSELIA)))
            continue;
        eligible |= 1u << rule->group;
    }
    count = 0;
    for (i = 0; i < LEGENDARY_SPECIAL_GROUP_COUNT; i++)
        if (eligible & (1u << i))
            candidates[count++] = (u8)i;
    for (i = 0; i < RANDOM_LEGENDARY_SPECIAL_COUNT && count > 0; i++)
    {
        pick = GetTimeAdjustedRandom() % count;
        gCurrentPinballGame->randomLegendarySpecialMask |= 1u << candidates[pick];
        candidates[pick] = candidates[--count];
    }
}

static void EnsureLegendaryEncounterSelection(void)
{
    NormalizeLegendaryEncounterState();
    if (gCurrentPinballGame->legendarySelectionReady)
        return;
    if (gMain.mainState == STATE_GAME_IDLE || gMain.selectedField >= MAIN_FIELD_COUNT)
        return;

    gCurrentPinballGame->legendaryGeneration = gSelectedGeneration;
    gCurrentPinballGame->legendarySelectionField = gMain.selectedField;
    if (gSelectedGeneration == GENERATION_RANDOM)
        ChooseRandomLegendaryGroups();
    gCurrentPinballGame->legendarySelectionReady = TRUE;
}

void InitLegendaryEncountersForNewGame(void)
{
    gCurrentPinballGame->legendaryEncounterMagic = 0;
    EnsureLegendaryEncounterSelection();
}

void RestoreLegendaryEncounterState(void)
{
    NormalizeLegendaryEncounterState();
    if (gCurrentPinballGame->legendarySelectionReady
     && gCurrentPinballGame->legendaryGeneration < GENERATION_SELECT_OPTION_COUNT)
        gSelectedGeneration = gCurrentPinballGame->legendaryGeneration;
    EnsureLegendaryEncounterSelection();
}

static bool8 IsKantoPokedexCaught(void)
{
    s16 i;
    for (i = 0; i < 150; i++)
        if (GetSavedPokedexFlag(PokedexListPositionToSpecies(i)) < SPECIES_CAUGHT)
            return FALSE;
    return TRUE;
}

static bool8 IsTrioPokedexCaught(u16 first, u16 second, u16 third)
{
    return GetSavedPokedexFlag(first) >= SPECIES_CAUGHT
        && GetSavedPokedexFlag(second) >= SPECIES_CAUGHT
        && GetSavedPokedexFlag(third) >= SPECIES_CAUGHT;
}

static bool8 IsLegendaryOcean(void)
{
    return (gMain.selectedField == FIELD_RUBY && gCurrentPinballGame->area == AREA_OCEAN_RUBY)
        || (gMain.selectedField == FIELD_SAPPHIRE && gCurrentPinballGame->area == AREA_OCEAN_SAPPHIRE);
}

static bool8 IsLegendaryRuin(void)
{
    return (gMain.selectedField == FIELD_RUBY && gCurrentPinballGame->area == AREA_RUIN_RUBY)
        || (gMain.selectedField == FIELD_SAPPHIRE && gCurrentPinballGame->area == AREA_RUIN_SAPPHIRE);
}

static bool8 IsLegendaryForest(void)
{
    return (gMain.selectedField == FIELD_RUBY && gCurrentPinballGame->area == AREA_FOREST_RUBY)
        || (gMain.selectedField == FIELD_SAPPHIRE && gCurrentPinballGame->area == AREA_FOREST_SAPPHIRE);
}

static bool8 MeetsLegendarySpecialConditions(u16 species)
{
    switch (species)
    {
    case SPECIES_MEW:
        return IsKantoPokedexCaught();
    case SPECIES_MEWTWO:
        return IsTrioPokedexCaught(SPECIES_ARTICUNO, SPECIES_ZAPDOS, SPECIES_MOLTRES);
    case SPECIES_LUGIA:
    case SPECIES_HO_OH:
        return IsTrioPokedexCaught(SPECIES_SUICUNE, SPECIES_RAIKOU, SPECIES_ENTEI);
    case SPECIES_CELEBI:
    case SPECIES_SHAYMIN:
        return IsLegendaryForest();
    case SPECIES_DEOXYS:
        return IsLegendaryRuin() && IsLegendaryCaughtThisGame(SPECIES_RAYQUAZA);
    case SPECIES_UXIE:
    case SPECIES_AZELF:
        return gCurrentPinballGame->area == AREA_LAKE;
    case SPECIES_DIALGA:
    case SPECIES_PALKIA:
        return IsTrioPokedexCaught(SPECIES_UXIE, SPECIES_AZELF, SPECIES_MESPRIT);
    case SPECIES_HEATRAN:
        return gCurrentPinballGame->area == AREA_VOLCANO;
    case SPECIES_REGIGIGAS:
        return IsLegendaryRuin() && IsTrioPokedexCaught(SPECIES_REGIROCK, SPECIES_REGICE, SPECIES_REGISTEEL);
    case SPECIES_GIRATINA:
        return GetSavedPokedexFlag(SPECIES_DIALGA) >= SPECIES_CAUGHT
            && GetSavedPokedexFlag(SPECIES_PALKIA) >= SPECIES_CAUGHT;
    case SPECIES_PHIONE:
        return IsLegendaryOcean() && IsLegendaryCaughtThisGame(SPECIES_MANAPHY);
    case SPECIES_DARKRAI:
        return IsLegendaryCaughtThisGame(SPECIES_CRESSELIA);
    case SPECIES_ARCEUS:
        return IsTrioPokedexCaught(SPECIES_DIALGA, SPECIES_PALKIA, SPECIES_GIRATINA);
    }
    return FALSE;
}

static void AddLegendaryEncounter(u16 *species, u16 *weights, s16 *count, u16 mon, u16 weight)
{
    if (!IsLegendaryCaughtThisGame(mon))
    {
        species[*count] = mon;
        weights[*count] = weight;
        (*count)++;
    }
}

static bool8 IsLegendaryRoamerEnabled(s16 group, s16 generation)
{
    if (!(sLegendaryRoamerFields[group] & (1 << gMain.selectedField)))
        return FALSE;
    if (gSelectedGeneration == GENERATION_RANDOM)
        return (gCurrentPinballGame->randomLegendaryRoamerMask & (1 << group)) != 0;
    return gSelectedGeneration == generation;
}

static s16 BuildLegendaryEncounterWeights(u16 *species, u16 *weights)
{
    u16 trio[3];
    s16 count = 0, trioCount = 0, favored = -1;
    s16 i, others = 0;
    u32 totalWeight = 0, previous = 0;
    u16 weight;
    const struct LegendarySpecialRule *rule;

    if (IsLegendaryRoamerEnabled(LEGENDARY_ROAM_BIRDS, GENERATION_1))
    {
        trio[0] = SPECIES_ARTICUNO; trio[1] = SPECIES_ZAPDOS; trio[2] = SPECIES_MOLTRES;
        trioCount = 3;
        switch (gCurrentPinballGame->area)
        {
        case AREA_ICE_CAVE: favored = 0; break;
        case AREA_PLAINS_SAPPHIRE: favored = 1; break;
        case AREA_WILDERNESS: favored = 2; break;
        }
    }
    else if (IsLegendaryRoamerEnabled(LEGENDARY_ROAM_BEASTS, GENERATION_2))
    {
        trio[0] = SPECIES_SUICUNE; trio[1] = SPECIES_RAIKOU; trio[2] = SPECIES_ENTEI;
        trioCount = 3;
        switch (gCurrentPinballGame->area)
        {
        case AREA_OCEAN_RUBY: favored = 0; break;
        case AREA_SAFARI_ZONE: favored = 1; break;
        case AREA_VOLCANO: favored = 2; break;
        }
    }
    if (gCurrentPinballGame->caughtMonCount < 10)
        favored = -1;
    for (i = 0; i < trioCount; i++)
        if (i != favored && !IsLegendaryCaughtThisGame(trio[i]))
            others++;
    for (i = 0; i < trioCount; i++)
        if (!IsLegendaryCaughtThisGame(trio[i]))
            AddLegendaryEncounter(species, weights, &count, trio[i], i == favored ? 240 : 60 / others);
    if (IsLegendaryRoamerEnabled(LEGENDARY_ROAM_MESPRIT, GENERATION_4))
        AddLegendaryEncounter(species, weights, &count, SPECIES_MESPRIT,
            gCurrentPinballGame->area == AREA_LAKE ? 240 : 60);
    if (IsLegendaryRoamerEnabled(LEGENDARY_ROAM_CRESSELIA, GENERATION_4))
        AddLegendaryEncounter(species, weights, &count, SPECIES_CRESSELIA, 60);
    for (i = 0; i < (s16)ARRAY_COUNT(sLegendarySpecialRules); i++)
    {
        rule = &sLegendarySpecialRules[i];
        if (!(rule->fields & (1 << gMain.selectedField)))
            continue;
        if (gSelectedGeneration == GENERATION_RANDOM)
        {
            if (!(gCurrentPinballGame->randomLegendarySpecialMask & (1u << rule->group)))
                continue;
        }
        else if (gSelectedGeneration != rule->generation)
            continue;
        if (gCurrentPinballGame->caughtMonCount < rule->captures
         || IsLegendaryCaughtThisGame(rule->species) || !MeetsLegendarySpecialConditions(rule->species))
            continue;
        weight = rule->weight;
        if (rule->group == LEGENDARY_SPECIAL_LAKE_PAIR
         && (IsLegendaryCaughtThisGame(SPECIES_UXIE) || IsLegendaryCaughtThisGame(SPECIES_AZELF)))
            weight = 240;
        AddLegendaryEncounter(species, weights, &count, rule->species, weight);
    }

    for (i = 0; i < count; i++)
        totalWeight += weights[i];
    // If the agreed percentages exceed 100%, every eligible species gets an
    // equal share. Cumulative rounding assigns all 1200 rolls without overflow.
    if (totalWeight > LEGENDARY_ROLL_RANGE)
    {
        for (i = 0; i < count; i++)
        {
            weight = (i + 1) * LEGENDARY_ROLL_RANGE / count;
            weights[i] = weight - previous;
            previous = weight;
        }
    }
    return count;
}

static u16 PickLegendaryEncounter(void)
{
    u16 species[LEGENDARY_CANDIDATE_COUNT], weights[LEGENDARY_CANDIDATE_COUNT];
    s16 i, count;
    u32 roll;

    if (gMain.mainState == STATE_GAME_IDLE || gMain.selectedField >= MAIN_FIELD_COUNT)
        return SPECIES_NONE;
    EnsureLegendaryEncounterSelection();
    count = BuildLegendaryEncounterWeights(species, weights);
    if (!count)
        return SPECIES_NONE;
    roll = GetTimeAdjustedRandom() % LEGENDARY_ROLL_RANGE;
    for (i = 0; i < count; i++)
    {
        if (roll < weights[i])
            return species[i];
        roll -= weights[i];
    }
    return SPECIES_NONE;
}

static u16 PickMissingBranchEvolution(u16 target1, u16 target2)
{
    if (GetSavedPokedexFlag(target1) < SPECIES_CAUGHT)
        return target1;
    if (GetSavedPokedexFlag(target2) < SPECIES_CAUGHT)
        return target2;

    return gMain.selectedField == FIELD_RUBY ? target1 : target2;
}

static u16 PickMissingTripleBranchEvolution(u16 target1, u16 target2, u16 target3)
{
    switch (gCurrentPinballGame->area)
    {
    case AREA_FOREST_RUBY:
    case AREA_FOREST_SAPPHIRE:
    case AREA_SAFARI_ZONE:
        if (GetSavedPokedexFlag(target1) < SPECIES_CAUGHT)
            return target1;
        if (GetSavedPokedexFlag(target2) < SPECIES_CAUGHT)
            return target2;
        return target3;
    case AREA_VOLCANO:
    case AREA_CAVE_RUBY:
    case AREA_CAVE_SAPPHIRE:
        if (GetSavedPokedexFlag(target2) < SPECIES_CAUGHT)
            return target2;
        if (GetSavedPokedexFlag(target3) < SPECIES_CAUGHT)
            return target3;
        return target1;
    default:
        if (GetSavedPokedexFlag(target3) < SPECIES_CAUGHT)
            return target3;
        if (GetSavedPokedexFlag(target1) < SPECIES_CAUGHT)
            return target1;
        return target2;
    }
}

static u16 GetEvolutionTargetForCurrentContext(u16 species)
{
    if (species == SPECIES_EEVEE
     && (gSelectedGeneration == GENERATION_2 || gSelectedGeneration == GENERATION_RANDOM))
    {
        if (gCurrentPinballGame->area == AREA_PLAINS_RUBY
         || gCurrentPinballGame->area == AREA_PLAINS_SAPPHIRE)
            return SPECIES_ESPEON;
        if (IsLegendaryRuin())
            return SPECIES_UMBREON;
    }
    if (gSelectedGeneration == GENERATION_4 || gSelectedGeneration == GENERATION_RANDOM)
    {
        switch (species)
        {
        case SPECIES_BURMY:
            return PickMissingBranchEvolution(SPECIES_WORMADAM, SPECIES_MOTHIM);
        case SPECIES_KIRLIA:
            return PickMissingBranchEvolution(SPECIES_GARDEVOIR, SPECIES_GALLADE);
        case SPECIES_SNORUNT:
            return PickMissingBranchEvolution(SPECIES_GLALIE, SPECIES_FROSLASS);
        case SPECIES_EEVEE:
            if (IsLegendaryForest())
                return SPECIES_LEAFEON;
            if (gCurrentPinballGame->area == AREA_ICE_CAVE
             || (gMain.selectedField == FIELD_RUBY && gCurrentPinballGame->area == AREA_CAVE_RUBY))
                return SPECIES_GLACEON;
            break;
        }
    }
    switch (species)
    {
    case SPECIES_WURMPLE:
        return PickMissingBranchEvolution(SPECIES_SILCOON, SPECIES_CASCOON);
    case SPECIES_GLOOM:
        return gMain.selectedField == FIELD_RUBY ? SPECIES_VILEPLUME : SPECIES_BELLOSSOM;
    case SPECIES_CLAMPERL:
        return gMain.selectedField == FIELD_RUBY ? SPECIES_HUNTAIL : SPECIES_GOREBYSS;
    case SPECIES_POLIWHIRL:
        return gMain.selectedField == FIELD_RUBY ? SPECIES_POLIWRATH : SPECIES_POLITOED;
    case SPECIES_SLOWPOKE:
        return gMain.selectedField == FIELD_RUBY ? SPECIES_SLOWBRO : SPECIES_SLOWKING;
    case SPECIES_EEVEE:
        switch (gCurrentPinballGame->area)
        {
        case AREA_OCEAN_RUBY:
        case AREA_OCEAN_SAPPHIRE:
        case AREA_LAKE:
            return SPECIES_VAPOREON;
        case AREA_VOLCANO:
            return SPECIES_FLAREON;
        default:
            return SPECIES_JOLTEON;
        }
    case SPECIES_TYROGUE:
        return PickMissingTripleBranchEvolution(SPECIES_HITMONLEE, SPECIES_HITMONCHAN, SPECIES_HITMONTOP);
    default:
        return gSpeciesInfo[species].evolutionTarget;
    }
}

/**
 *   0 if captured via ball
 *   1 if evolved
*/
void RegisterCaptureOrEvolution(s16 evolved)
{
    if (!evolved)
    {
        if (gMain.mainState != STATE_GAME_IDLE)
        {
            RegisterLegendaryCapture(gCurrentPinballGame->currentSpecies);
            SaveFile_SetPokedexFlags(gCurrentPinballGame->currentSpecies, SPECIES_CAUGHT);
        }

        if (gSpeciesInfo[gCurrentPinballGame->currentSpecies].evolutionMethod != 0)
        {
            if (gSpeciesInfo[gCurrentPinballGame->currentSpecies].evolutionTarget < SPECIES_NONE)
                AddEvolvablePartySpecies(gCurrentPinballGame->currentSpecies);
        }
    }
    else
    {
        RemoveEvolvablePartySpecies(gCurrentPinballGame->evolvingPartyIndex);

        if (gCurrentPinballGame->currentSpecies == SPECIES_NINCADA)
        {
            gCurrentPinballGame->currentSpecies = SPECIES_SHEDINJA;
            if (gMain.mainState != STATE_GAME_IDLE)
                SaveFile_SetPokedexFlags(SPECIES_SHEDINJA, SPECIES_CAUGHT);

            gCurrentPinballGame->currentSpecies = SPECIES_NINJASK;
        }
        else
        {
            gCurrentPinballGame->currentSpecies = GetEvolutionTargetForCurrentContext(gCurrentPinballGame->currentSpecies);
        }

        if (gMain.mainState != STATE_GAME_IDLE)
            SaveFile_SetPokedexFlags(gCurrentPinballGame->currentSpecies, SPECIES_CAUGHT);

        if (gSpeciesInfo[gCurrentPinballGame->currentSpecies].evolutionMethod != 0)
        {
            if (gSpeciesInfo[gCurrentPinballGame->currentSpecies].evolutionTarget < SPECIES_NONE)
                AddEvolvablePartySpecies(gCurrentPinballGame->currentSpecies);
        }
    }
}

static inline u32 GetTimeAdjustedRandom(void)
{
    return Random() + (gMain.systemFrameCount + gMain.fieldFrameCount);
}

/*
BuildSpeciesWeightsForX constructs two key objects:

speciesWeights[] - A cumulative weight array where each entry represents the total weight of all species up to that index.
                   Species weights are influenced by factors such as whether the Pokémon has already been caught and if it has
                   an evolution needed for the Pokédex. This ensures rarer or more desirable species have appropriate weighting.

totalWeight - The final cumulative weight value, equal to the last value in speciesWeights[]. This is used as the upper bound
              for random selection.

PickSpeciesForX determines a species as follows:

1. Applies special conditions (e.g., forced rare selection if applicable).
2. Rolls a random number % totalWeight.
3. Iterates through speciesWeights[] and selects the first species whose cumulative weight meets or exceeds the rolled number.

*/

void BuildSpeciesWeightsForCatchEmMode(void)
{
    s16 threeArrows;
    s16 i;
    s16 j;
    s16 weight;
    s16 currentSpecies;
    s16 evolutionWeight;

    gCurrentPinballGame->totalWeight = 0;
    if (gCurrentPinballGame->catchModeArrows == 3)
        threeArrows = 1;
    else
        threeArrows = 0;

    for (i = 0; i < WILD_MON_LOCATION_COUNT; i++)
    {
        currentSpecies = GetWildMonForSelectedGeneration(gCurrentPinballGame->area, threeArrows, i);
        switch (currentSpecies)
        {
            // Rare pokemon
            case SPECIES_NOSEPASS:
            case SPECIES_SKARMORY:
            case SPECIES_LILEEP:
            case SPECIES_ANORITH:
            case SPECIES_FEEBAS:
            case SPECIES_CASTFORM:
            case SPECIES_KECLEON:
            case SPECIES_ABSOL:
            case SPECIES_WOBBUFFET:
                if (gMain.eReaderBonuses[EREADER_ENCOUNTER_RATE_UP_CARD])
                {
                    if (GetSavedPokedexFlag(currentSpecies) < SPECIES_SHARED)
                        weight = 2;
                    else
                        weight = 4;
                }
                else
                {
                    if (GetSavedPokedexFlag(currentSpecies) < SPECIES_SHARED)
                        weight = 1;
                    else
                        weight = 2;
                }

                if (gCurrentPinballGame->caughtMonCount == 0)
                    weight = 0;
                break;

            case SPECIES_CLAMPERL:
                weight = gCommonAndEggWeights[GetSavedPokedexFlag(SPECIES_CLAMPERL)];
                evolutionWeight = gCommonAndEggWeights[GetSavedPokedexFlag(GetEvolutionTargetForCurrentContext(SPECIES_CLAMPERL))];
                if (weight < evolutionWeight)
                    weight = evolutionWeight;
                break;
            case SPECIES_NONE:
                weight = 0;
                break;
            default:
                weight = gCommonAndEggWeights[GetSavedPokedexFlag(currentSpecies)];
                for (j = 0; j < 2; j++)
                {
                    currentSpecies = GetEvolutionTargetForCurrentContext(currentSpecies);
                    if (currentSpecies < SPECIES_NONE)
                    {
                        evolutionWeight = gCommonAndEggWeights[GetSavedPokedexFlag(currentSpecies)];
                        if (weight < evolutionWeight)
                        {
                            weight = evolutionWeight;
                        }
                    }
                    else
                    {
                        break;
                    }
                }
                currentSpecies = GetWildMonForSelectedGeneration(gCurrentPinballGame->area, threeArrows, i);
                if (gCurrentPinballGame->caughtMonCount == 0
                 && currentSpecies != SPECIES_DEOXYS
                 && gSpeciesInfo[currentSpecies].evolutionTarget >= SPECIES_NONE)
                {
                    weight = 0;
                }
                break;
        }

        if (gCurrentPinballGame->lastCatchSpecies == currentSpecies)
        {
            weight = 0;
        }
        gCurrentPinballGame->totalWeight += weight;
        gCurrentPinballGame->speciesWeights[i] = gCurrentPinballGame->totalWeight;
    }
}

void PickSpeciesForCatchEmMode(void)
{
    s16 i;
    u32 rand;
    u16 specialMons[6];
    u16 legendary;

    if (gCurrentPinballGame->debugForcedCatchSpecies < SPECIES_NONE)
    {
        gCurrentPinballGame->currentSpecies = gCurrentPinballGame->debugForcedCatchSpecies;
        gCurrentPinballGame->debugForcedCatchSpecies = SPECIES_NONE;
        gCurrentPinballGame->lastCatchSpecies = gCurrentPinballGame->currentSpecies;
        return;
    }

    legendary = PickLegendaryEncounter();
    if (legendary != SPECIES_NONE)
    {
        gCurrentPinballGame->currentSpecies = legendary;
        gCurrentPinballGame->lastCatchSpecies = legendary;
        return;
    }

    if (gSelectedGeneration != GENERATION_4 && gMain.eReaderBonuses[EREADER_SPECIAL_GUESTS_CARD])
    {
        gMain.eReaderBonuses[EREADER_SPECIAL_GUESTS_CARD] = FALSE;
        rand = GetTimeAdjustedRandom();
        rand %= NUM_BONUS_SPECIES;
        for (i = 0; i < NUM_BONUS_SPECIES; i++)
        {
            if (gMain_saveData.pokedexFlags[BONUS_SPECIES_START + ((i + rand) % NUM_BONUS_SPECIES)] < SPECIES_CAUGHT)
                break;
        }

        gCurrentPinballGame->currentSpecies = BONUS_SPECIES_START + ((i + rand) % NUM_BONUS_SPECIES);
    }
    else
    {
        rand = GetTimeAdjustedRandom();
        if (gMain.eReaderBonuses[EREADER_ENCOUNTER_RATE_UP_CARD])
            rand %= 50;
        else
            rand %= 100;

        if (gBoardConfig.caughtSpeciesCount < 100)
            rand = 1;

        if (gSelectedGeneration != GENERATION_4
         && ((rand == 0 && gCurrentPinballGame->caughtMonCount >= 5) || gCurrentPinballGame->forceSpecialMons))
        {
            s16 numSpecialMons = 0;
            gCurrentPinballGame->currentSpecies = 0;
            if (gMain_saveData.pokedexFlags[SPECIES_AERODACTYL])
            {
                specialMons[numSpecialMons++] = SPECIES_AERODACTYL;
                if (gMain_saveData.pokedexFlags[SPECIES_AERODACTYL] < SPECIES_CAUGHT)
                    gCurrentPinballGame->currentSpecies = SPECIES_AERODACTYL;
            }

            if (gMain_saveData.pokedexFlags[SPECIES_CHIKORITA])
            {
                specialMons[numSpecialMons++] = SPECIES_CHIKORITA;
                if (gMain_saveData.pokedexFlags[SPECIES_CHIKORITA] < SPECIES_CAUGHT)
                    gCurrentPinballGame->currentSpecies = SPECIES_CHIKORITA;
            }

            if (gMain_saveData.pokedexFlags[SPECIES_TOTODILE])
            {
                specialMons[numSpecialMons++] = SPECIES_TOTODILE;
                if (gMain_saveData.pokedexFlags[SPECIES_TOTODILE] < SPECIES_CAUGHT)
                    gCurrentPinballGame->currentSpecies = SPECIES_TOTODILE;
            }

            if (gMain_saveData.pokedexFlags[SPECIES_CYNDAQUIL])
            {
                specialMons[numSpecialMons++] = SPECIES_CYNDAQUIL;
                if (gMain_saveData.pokedexFlags[SPECIES_CYNDAQUIL] < SPECIES_CAUGHT)
                    gCurrentPinballGame->currentSpecies = SPECIES_CYNDAQUIL;
            }

            if (gMain.selectedField == FIELD_RUBY)
            {
                specialMons[numSpecialMons++] = SPECIES_LATIOS;
                if (gMain_saveData.pokedexFlags[SPECIES_LATIOS] < SPECIES_CAUGHT)
                    gCurrentPinballGame->currentSpecies = SPECIES_LATIOS;
            }
            else
            {
                specialMons[numSpecialMons++] = SPECIES_LATIAS;
                if (gMain_saveData.pokedexFlags[SPECIES_LATIAS] < SPECIES_CAUGHT)
                    gCurrentPinballGame->currentSpecies = SPECIES_LATIAS;
            }

            if (gCurrentPinballGame->currentSpecies == 0)
            {
                rand = GetTimeAdjustedRandom();
                rand %= numSpecialMons;
                gCurrentPinballGame->currentSpecies = specialMons[rand];
            }
        }
        else
        {
            s16 threeArrows;
            if (gCurrentPinballGame->catchModeArrows == 3)
                threeArrows = 1;
            else
                threeArrows = 0;

            rand = GetTimeAdjustedRandom();
            rand %= gCurrentPinballGame->totalWeight;
            for (i = 0; i < WILD_MON_LOCATION_COUNT && gCurrentPinballGame->speciesWeights[i] <= rand; i++);

            gCurrentPinballGame->currentSpecies = GetWildMonForSelectedGeneration(gCurrentPinballGame->area, threeArrows, i);
        }
    }

    gCurrentPinballGame->lastCatchSpecies = gCurrentPinballGame->currentSpecies;
}

static s16 GetEggEncounterCount(void)
{
    return gSelectedGeneration == GENERATION_RANDOM ? 75 : 25;
}

static s16 GetEggEncounterWeight(u16 species)
{
    s16 weight, evolutionWeight, j;
    u16 target = species;

    if (species >= SPECIES_NONE || species == gCurrentPinballGame->lastEggSpecies)
        return 0;
    if (species == SPECIES_ODDISH)
        return gCommonAndEggWeights[GetSavedPokedexFlag(GetEvolutionTargetForCurrentContext(SPECIES_GLOOM))];

    weight = gCommonAndEggWeights[GetSavedPokedexFlag(species)];
    for (j = 0; j < 2; j++)
    {
        target = GetEvolutionTargetForCurrentContext(target);
        if (target >= SPECIES_NONE)
            break;
        evolutionWeight = gCommonAndEggWeights[GetSavedPokedexFlag(target)];
        if (weight < evolutionWeight)
            weight = evolutionWeight;
    }
    if (gCurrentPinballGame->caughtMonCount == 0
     && gSpeciesInfo[species].evolutionTarget >= SPECIES_NONE)
        return 0;
    return weight;
}

void BuildSpeciesWeightsForEggMode(void)
{
    s16 i;
    gCurrentPinballGame->totalWeight = 0;
    // RANDOM spans three tables. Walk weights instead of enlarging the saved
    // 25-element catch/egg array and shifting the rest of PinballGame.
    for (i = 0; i < GetEggEncounterCount(); i++)
        gCurrentPinballGame->totalWeight += GetEggEncounterWeight(
            GetEggMonForSelectedGeneration(gMain.selectedField, i));
}

void PickSpeciesForEggMode(void)
{
    s16 i;
    u32 rand;
    u16 species;
    s16 weight;

    if (gCurrentPinballGame->debugForcedEggSpecies < SPECIES_NONE)
    {
        gCurrentPinballGame->currentSpecies = gCurrentPinballGame->debugForcedEggSpecies;
        gCurrentPinballGame->debugForcedEggSpecies = SPECIES_NONE;
        gCurrentPinballGame->lastEggSpecies = gCurrentPinballGame->currentSpecies;
        return;
    }

    if (gCurrentPinballGame->manaphyEggActive)
    {
        gCurrentPinballGame->currentSpecies = SPECIES_MANAPHY;
        gCurrentPinballGame->lastEggSpecies = SPECIES_MANAPHY;
        return;
    }

    rand = GetTimeAdjustedRandom();
    if (gMain.eReaderBonuses[EREADER_ENCOUNTER_RATE_UP_CARD])
        rand %= 100;
    else
        rand %= 50;

    if (gCurrentPinballGame->lastEggSpecies == SPECIES_PICHU)
        rand = 1;

    if (gSelectedGeneration != GENERATION_4
     && ((rand == 0 && gCurrentPinballGame->caughtMonCount >= 5) || gCurrentPinballGame->forcePichuEgg))
    {
        gCurrentPinballGame->currentSpecies = SPECIES_PICHU;
    }
    else
    {
        BuildSpeciesWeightsForEggMode();
        rand = gCurrentPinballGame->totalWeight
             ? GetTimeAdjustedRandom() % gCurrentPinballGame->totalWeight : 0;
        gCurrentPinballGame->currentSpecies = GetEggMonForSelectedGeneration(gMain.selectedField, 0);
        for (i = 0; i < GetEggEncounterCount(); i++)
        {
            species = GetEggMonForSelectedGeneration(gMain.selectedField, i);
            weight = GetEggEncounterWeight(species);
            if (rand < (u32)weight)
            {
                gCurrentPinballGame->currentSpecies = species;
                break;
            }
            rand -= weight;
        }
    }

    gCurrentPinballGame->lastEggSpecies = gCurrentPinballGame->currentSpecies;
}
