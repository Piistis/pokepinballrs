#include "global.h"
#include "functions.h"
#include "main.h"
#include "variables.h"
#include "constants/ereader.h"
#include "constants/fields.h"
#include "constants/generations.h"
#include "constants/species.h"
#include "constants/pinball_game.h"

extern const u16 gWildMonLocations[AREA_COUNT][2][WILD_MON_LOCATION_COUNT];
extern const u16 gWildMonLocationsGen1[AREA_COUNT][2][WILD_MON_LOCATION_COUNT];
extern const u16 gWildMonLocationsGen2[AREA_COUNT][2][WILD_MON_LOCATION_COUNT];
extern const u16 gWildMonLocationsGen4[AREA_COUNT][2][WILD_MON_LOCATION_COUNT];
extern const u16 gEggLocations[MAIN_FIELD_COUNT][26];
extern const u16 gEggLocationsGen2[MAIN_FIELD_COUNT][26];

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
            SaveFile_SetPokedexFlags(gCurrentPinballGame->currentSpecies, SPECIES_CAUGHT);

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

    if (gCurrentPinballGame->debugForcedCatchSpecies < SPECIES_NONE)
    {
        gCurrentPinballGame->currentSpecies = gCurrentPinballGame->debugForcedCatchSpecies;
        gCurrentPinballGame->debugForcedCatchSpecies = SPECIES_NONE;
        gCurrentPinballGame->lastCatchSpecies = gCurrentPinballGame->currentSpecies;
        return;
    }

    if (gMain.eReaderBonuses[EREADER_SPECIAL_GUESTS_CARD])
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

        if ((rand == 0 && gCurrentPinballGame->caughtMonCount >= 5) || gCurrentPinballGame->forceSpecialMons)
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

void BuildSpeciesWeightsForEggMode(void)
{
    s16 i;
    s16 currentSpecies;
    s16 weight;
    s16 j;
    s16 evolutionWeight;

    gCurrentPinballGame->totalWeight = 0;

    for (i = 0; i < 25; i++)
    {
        currentSpecies = GetEggMonForSelectedGeneration(gMain.selectedField, i);

        if (currentSpecies == SPECIES_ODDISH)
        {
            weight = gCommonAndEggWeights[GetSavedPokedexFlag(GetEvolutionTargetForCurrentContext(SPECIES_GLOOM))];
        }
        else
        {
            weight = gCommonAndEggWeights[GetSavedPokedexFlag(currentSpecies)];

            for (j = 0; j < 2; j++)
            {
                currentSpecies = GetEvolutionTargetForCurrentContext(currentSpecies);
                if (currentSpecies < SPECIES_NONE)
                {
                    evolutionWeight = gCommonAndEggWeights[GetSavedPokedexFlag(currentSpecies)];
                    if (weight < evolutionWeight)
                        weight = evolutionWeight;
                }
                else
                {
                    break;
                }
            }

            currentSpecies = GetEggMonForSelectedGeneration(gMain.selectedField, i);
            if (gCurrentPinballGame->caughtMonCount == 0)
            {
                if (gSpeciesInfo[currentSpecies].evolutionTarget >= SPECIES_NONE)
                {
                    weight = 0;
                }
            }
        }

        if (gCurrentPinballGame->lastEggSpecies == currentSpecies)
        {
            weight = 0;
        }

        gCurrentPinballGame->totalWeight += weight;
        gCurrentPinballGame->speciesWeights[i] = gCurrentPinballGame->totalWeight;
    }
}

void PickSpeciesForEggMode(void)
{
    s16 i;
    u32 rand;

    if (gCurrentPinballGame->debugForcedEggSpecies < SPECIES_NONE)
    {
        gCurrentPinballGame->currentSpecies = gCurrentPinballGame->debugForcedEggSpecies;
        gCurrentPinballGame->debugForcedEggSpecies = SPECIES_NONE;
        gCurrentPinballGame->lastEggSpecies = gCurrentPinballGame->currentSpecies;
        return;
    }

    rand = GetTimeAdjustedRandom();
    if (gMain.eReaderBonuses[EREADER_ENCOUNTER_RATE_UP_CARD])
        rand %= 100;
    else
        rand %= 50;

    if (gCurrentPinballGame->lastEggSpecies == SPECIES_PICHU)
        rand = 1;

    if ((rand == 0 && gCurrentPinballGame->caughtMonCount >= 5) || gCurrentPinballGame->forcePichuEgg)
    {
        gCurrentPinballGame->currentSpecies = SPECIES_PICHU;
    }
    else
    {
        rand = GetTimeAdjustedRandom();
        rand %= gCurrentPinballGame->totalWeight;

        for (i = 0; i < 25 && gCurrentPinballGame->speciesWeights[i] <= rand; i++);

        gCurrentPinballGame->currentSpecies = GetEggMonForSelectedGeneration(gMain.selectedField, i);
    }

    gCurrentPinballGame->lastEggSpecies = gCurrentPinballGame->currentSpecies;
}
