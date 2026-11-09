#include "global.h"
#include "m4a.h"
#include "agb_sram.h"
#include "main.h"
#include "constants/species_rs.h"
#include "constants/bg_music.h"
#include "constants/generations.h"
#include "save_storage.h"
#include "shiny.h"
#include "constants/debug.h"
#include <stddef.h>

static bool16 LoadSaveDataFromSram(void);
static void LoadExtraPokedexFlagsFromSram(void);
static void SaveExtraPokedexFlagsToSram(void);
static void LoadShinyPokedexFromSram(void);
static void SaveShinyPokedexToSram(void);

#define EXTRA_POKEDEX_FLAGS_COUNT (NUM_SPECIES - NUM_SAVE_SPECIES)
#define EXTRA_POKEDEX_SAVE_MAGIC 0x58444550
#define EXTRA_POKEDEX_SAVE_OFFSET 0x1A00
#define EXTRA_POKEDEX_SAVE_BACKUP_OFFSET 0x1B00

/* Bonus-stage BG tilemaps use IWRAM through 0x03007400. Keep Dex flags separate. */
EWRAM_DATA u8 gExtraPokedexFlags[EXTRA_POKEDEX_FLAGS_COUNT] = {0};

struct LegacyPokedexHeader
{
    u32 magic;
    u16 count;
    u16 checksum;
};

struct SavedGameInfo
{
    u16 speciesCount;
    u16 song;
    u8 ballIndex;
    u8 cameraIndex;
    u8 generation;
    u8 reserved;
};

struct SavedShinyGameInfo
{
    struct SavedGameInfo base;
    struct ShinyRunState shiny;
};

struct SavedShinyDexInfo
{
    u16 speciesCount;
    u16 bytes;
};

static EWRAM_DATA u8 sShinySaveBuffer[2 * SHINY_DEX_BYTES] = {0};

typedef char SaveDexCapacityCheck[EXTRA_POKEDEX_FLAGS_COUNT <= SAVE_DEX_CAPACITY ? 1 : -1];
typedef char SaveGameSizeCheck[sizeof(struct PinballGame) == SAVE_GAME_LAYOUT_SIZE ? 1 : -1];
typedef char SaveGameInfoSizeCheck[sizeof(struct SavedGameInfo) == 8 ? 1 : -1];
typedef char SaveBaseSizeCheck[sizeof(struct SaveData) == 0x274 ? 1 : -1];
typedef char SaveGameMusicCheck[offsetof(struct PinballGame, savedBgmSongHeader) == 0xF4C ? 1 : -1];
typedef char SaveGameBallCheck[offsetof(struct PinballGame, ball) == 0x132C ? 1 : -1];
typedef char SaveGameSpeciesCheck[offsetof(struct PinballGame, currentSpecies) == 0x598 ? 1 : -1];
typedef char SaveShinyStateSizeCheck[sizeof(struct ShinyRunState) == 8 ? 1 : -1];
typedef char SaveShinyCapacityCheck[4 + 2 * ((NUM_SAVE_SPECIES + SAVE_DEX_CAPACITY + 7) / 8)
                                  <= SAVE_SHINY_SLOT_SIZE - sizeof(struct SaveRecordHeader) ? 1 : -1];
typedef char SaveShinyGameCapacityCheck[sizeof(struct SavedShinyGameInfo) + sizeof(struct PinballGame)
                                      <= SAVE_GAME_SLOT_SIZE - sizeof(struct SaveRecordHeader) ? 1 : -1];

static bool8 IsSramBlank(void)
{
    u8 buffer[32];
    u32 offset;
    u16 i;

    for (offset = 0; offset < 0x8000; offset += sizeof(buffer))
    {
        SaveRecord_Read(offset, buffer, sizeof(buffer));
        for (i = 0; i < sizeof(buffer); i++)
            if (buffer[i] != 0 && buffer[i] != 0xFF)
                return FALSE;
    }
    return TRUE;
}

void SaveFile_LoadGameData(void)
{
    SetSramFastFunc();
    gMain.sramError = FALSE;
    Shiny_ResetPokedex();
    Shiny_ResetRunState();
    if (LoadSaveDataFromSram() == FALSE)
    {
        /* Do not turn an unrecognized/damaged existing save into a fresh one. */
        if (!IsSramBlank())
        {
            gMain.sramError = TRUE;
            ResetSaveFile();
            return;
        }
        ResetSaveFile();
        SaveFile_WriteToSram();
        if (LoadSaveDataFromSram() == FALSE)
        {
            gMain.sramError = TRUE;
            ResetSaveFile();
        }
    }
    else
    {
        SetButtonConfigInputs(gMain_saveData.buttonConfigType);
        LoadExtraPokedexFlagsFromSram();
        if (!gMain.sramError)
            LoadShinyPokedexFromSram();
    }
}

extern u8 gSaveFileSignature[];

static bool16 LoadSaveDataFromSram(void)
{
    u16 isOk = FALSE;
    u16 fileNum;
    u16 i;
    u32 checksum;

    // Looks like there are two copies of the save data, one used as a backup?
    for (fileNum = 0; fileNum < 2; fileNum++)
    {
        u16 *saveData = (u16 *)&gMain_saveData;
        size_t size = sizeof(gMain_saveData);

        ReadSramFast((void *)(SRAM + 0x4 + fileNum * 672), (u8 *)saveData, size);

        // Verify signature
        for (i = 0; i < 10; i++)
        {
            if (gMain_saveData.signature[i] != gSaveFileSignature[i])
                break;
        }
        if (i != 10)
            continue;

        // Verify checksum
        checksum = 0;
        while (size > 1)
        {
            checksum += *saveData++;
            size -= 2;
        }
        if (size != 0)  // never happens (size is even)
            checksum += *saveData & 0xFF00;
        checksum = (checksum & 0xFFFF) + (checksum >> 16);
        if (checksum == 0xFFFF)
        {
            isOk = TRUE;
            break;
        }
    }
    return isOk;
}

static bool8 ReadLegacyPokedex(u32 offset, struct LegacyPokedexHeader *header)
{
    u16 i, sum;
    u8 flag;

    SaveRecord_Read(offset, header, sizeof(*header));
    if (header->magic != EXTRA_POKEDEX_SAVE_MAGIC
     || header->count == 0 || header->count > SAVE_DEX_CAPACITY)
        return FALSE;
    sum = (u16)(header->magic & 0xFFFF) + (u16)(header->magic >> 16) + header->count;
    for (i = 0; i < header->count; i++)
    {
        SaveRecord_Read(offset + sizeof(*header) + i, &flag, 1);
        if (flag > SPECIES_CAUGHT)
            return FALSE;
        sum += flag;
    }
    return header->checksum == (u16)~sum;
}

static u32 FindLegacyPokedex(struct LegacyPokedexHeader *header)
{
    if (ReadLegacyPokedex(EXTRA_POKEDEX_SAVE_OFFSET, header))
        return EXTRA_POKEDEX_SAVE_OFFSET;
    if (ReadLegacyPokedex(EXTRA_POKEDEX_SAVE_BACKUP_OFFSET, header))
        return EXTRA_POKEDEX_SAVE_BACKUP_OFFSET;
    return 0;
}

static void LoadExtraPokedexFlagsFromSram(void)
{
    struct SaveRecordHeader header;
    struct LegacyPokedexHeader legacy;
    u32 offset;
    u16 i, species;
    u8 flag;

    for (i = 0; i < EXTRA_POKEDEX_FLAGS_COUNT; i++)
        gExtraPokedexFlags[i] = SPECIES_UNSEEN;
    offset = SaveRecord_Find(SAVE_DEX_SLOT_A, SAVE_DEX_SLOT_B, SAVE_DEX_SLOT_SIZE, SAVE_DEX_MAGIC, &header);
    if (offset)
    {
        if (header.version != SAVE_RECORD_VERSION || header.size > EXTRA_POKEDEX_FLAGS_COUNT)
        {
            gMain.sramError = TRUE;
            return;
        }
        for (i = 0; i < header.size; i++)
        {
            SaveRecord_Read(offset + sizeof(header) + i, &flag, 1);
            if (flag > SPECIES_CAUGHT)
            {
                gMain.sramError = TRUE;
                return;
            }
            gExtraPokedexFlags[i] = flag;
        }
        return;
    }
    if (SaveRecord_HasMarker(SAVE_DEX_SLOT_A, SAVE_DEX_SLOT_B, SAVE_DEX_MAGIC))
    {
        gMain.sramError = TRUE;
        return;
    }
    offset = FindLegacyPokedex(&legacy);
    if (!offset)
    {
        if (SaveRecord_HasMarker(EXTRA_POKEDEX_SAVE_OFFSET, EXTRA_POKEDEX_SAVE_BACKUP_OFFSET, EXTRA_POKEDEX_SAVE_MAGIC))
            gMain.sramError = TRUE;
        return;
    }
    if (legacy.count > EXTRA_POKEDEX_FLAGS_COUNT)
    {
        gMain.sramError = TRUE;
        return;
    }
    for (i = 0; i < legacy.count; i++)
    {
        SaveRecord_Read(offset + sizeof(legacy) + i, &flag, 1);
        species = NUM_SAVE_SPECIES + i;
        if (legacy.count <= 2)
            species = i == 0 ? SPECIES_BLITZLE : SPECIES_ZEBSTRIKA;
        else if (legacy.count == 182)
        {
            if (i == 0)
            {
                if (flag && LEGACY_387_LAYOUT == 0)
                {
                    gMain.sramError = TRUE;
                    return;
                }
                species = LEGACY_387_LAYOUT == 1 ? SPECIES_BLITZLE : SPECIES_DEOXYS;
            }
            else if (i == 1)
                species = SPECIES_ZEBSTRIKA;
        }
        else if (legacy.count < 183)
        {
            gMain.sramError = TRUE;
            return;
        }
        gExtraPokedexFlags[species - NUM_SAVE_SPECIES] = flag;
    }
    /* The old blocks are retained intact, including the overlapping backup. */
    SaveExtraPokedexFlagsToSram();
}

static void SaveExtraPokedexFlagsToSram(void)
{
    if (gMain.sramError)
        return;
    if (!SaveRecord_Write(SAVE_DEX_SLOT_A, SAVE_DEX_SLOT_B, SAVE_DEX_SLOT_SIZE, SAVE_DEX_MAGIC,
                          NULL, 0, gExtraPokedexFlags, EXTRA_POKEDEX_FLAGS_COUNT))
        gMain.sramError = TRUE;
}

static void LoadShinyPokedexFromSram(void)
{
    struct SaveRecordHeader header;
    struct SavedShinyDexInfo info;
    u32 offset;
    u16 i;
    u8 mask;

    Shiny_ResetPokedex();
    offset = SaveRecord_Find(SAVE_SHINY_SLOT_A, SAVE_SHINY_SLOT_B, SAVE_SHINY_SLOT_SIZE, SAVE_SHINY_MAGIC, &header);
    if (!offset)
    {
        if (SaveRecord_HasMarker(SAVE_SHINY_SLOT_A, SAVE_SHINY_SLOT_B, SAVE_SHINY_MAGIC))
            gMain.sramError = TRUE;
        return;
    }
    SaveRecord_Read(offset + sizeof(header), &info, sizeof(info));
    if (header.version != SAVE_RECORD_VERSION || info.speciesCount < NUM_SAVE_SPECIES
     || info.speciesCount > NUM_SPECIES || info.bytes != (info.speciesCount + 7) / 8
     || header.size != sizeof(info) + 2 * info.bytes)
    {
        gMain.sramError = TRUE;
        return;
    }
    SaveRecord_Read(offset + sizeof(header) + sizeof(info), gShinySeen, info.bytes);
    SaveRecord_Read(offset + sizeof(header) + sizeof(info) + info.bytes, gShinyCaught, info.bytes);
    for (i = 0; i < info.bytes; i++)
    {
        mask = i == info.bytes - 1 && (info.speciesCount & 7)
             ? (1 << (info.speciesCount & 7)) - 1 : 255;
        if ((gShinySeen[i] & ~mask) || (gShinyCaught[i] & ~gShinySeen[i]))
        {
            Shiny_ResetPokedex();
            gMain.sramError = TRUE;
            return;
        }
    }
}

static void SaveShinyPokedexToSram(void)
{
    struct SavedShinyDexInfo info;
    if (gMain.sramError)
        return;
    info.speciesCount = NUM_SPECIES;
    info.bytes = SHINY_DEX_BYTES;
    memcpy(sShinySaveBuffer, gShinySeen, SHINY_DEX_BYTES);
    memcpy(sShinySaveBuffer + SHINY_DEX_BYTES, gShinyCaught, SHINY_DEX_BYTES);
    if (!SaveRecord_Write(SAVE_SHINY_SLOT_A, SAVE_SHINY_SLOT_B, SAVE_SHINY_SLOT_SIZE, SAVE_SHINY_MAGIC,
                          &info, sizeof(info), sShinySaveBuffer, sizeof(sShinySaveBuffer)))
        gMain.sramError = TRUE;
}

void SaveFile_SetShinyPokedexFlag(u16 species, u8 flag)
{
    if (gMain.sramError || !Shiny_SetPokedexFlag(species, flag))
        return;
    SaveShinyPokedexToSram();
}

void SaveFile_WriteToSram(void)
{
    u32 checksum;
    u16 *saveData = (u16 *)&gMain_saveData;
    size_t size = sizeof(gMain_saveData);

    if (gMain.sramError)
        return;
    gMain_saveData.saveChangeCounter++;
    gMain_saveData.checksum = 0;

    checksum = 0;
    while (size > 1)
    {
        checksum += *saveData++;
        size -= 2;
    }
    if (size != 0)  // never happens (size is even)
        checksum += *saveData & 0xFF00;
    checksum = (checksum & 0xFFFF) + (checksum >> 16);
    gMain_saveData.checksum = ~((checksum >> 16) + checksum);

    if (WriteAndVerifySramFast((u8 *)&gMain_saveData, (void *)(SRAM + 0x4), sizeof(gMain_saveData))
     || WriteAndVerifySramFast((u8 *)&gMain_saveData, (void *)(SRAM + 0x2A4), sizeof(gMain_saveData)))
    {
        gMain.sramError = TRUE;
        return;
    }
    SaveExtraPokedexFlagsToSram();
    SaveShinyPokedexToSram();
}

void SaveFile_SetPokedexFlags(s16 species, u8 flag)
{
    u16 *saveData = (u16 *)&gMain_saveData;
    size_t size = sizeof(gMain_saveData);
    u32 checksum;

    if (species < 0 || species >= NUM_SPECIES || flag > SPECIES_CAUGHT || gMain.sramError)
        return;
    if (species >= NUM_SAVE_SPECIES && species < NUM_SPECIES)
    {
        if (gExtraPokedexFlags[species - NUM_SAVE_SPECIES] < flag)
        {
            gExtraPokedexFlags[species - NUM_SAVE_SPECIES] = flag;
            SaveExtraPokedexFlagsToSram();
        }
        return;
    }

    if (gMain_saveData.pokedexFlags[species] < flag)
    {
        gMain_saveData.saveChangeCounter++;
        gMain_saveData.pokedexFlags[species] = flag;
        gMain_saveData.checksum = 0;

        checksum = 0;
        while (size > 1)
        {
            checksum += *saveData++;
            size -= 2;
        }
        if (size != 0)  // never happens (size is even)
            checksum += *saveData & 0xFF00;
        checksum = (checksum & 0xFFFF) + (checksum >> 16);
        gMain_saveData.checksum = ~((checksum >> 16) + checksum);

        if (WriteAndVerifySramFast((u8 *)&gMain_saveData, (void *)(SRAM + 0x4), sizeof(gMain_saveData))
         || WriteAndVerifySramFast((u8 *)&gMain_saveData, (void *)(SRAM + 0x2A4), sizeof(gMain_saveData)))
            gMain.sramError = TRUE;
    }
}

void SaveFile_DebugCompletePokedex(void)
{
#if DEBUG_TOOLS_ENABLED
    s16 i;

    for (i = 0; i < NUM_SAVE_SPECIES; i++)
        gMain_saveData.pokedexFlags[i] = SPECIES_CAUGHT;

    for (i = NUM_SAVE_SPECIES; i < NUM_SPECIES; i++)
        gExtraPokedexFlags[i - NUM_SAVE_SPECIES] = SPECIES_CAUGHT;

    SaveFile_WriteToSram();
    SaveFile_ReadSavedGamePresent();
#endif
}

static u16 SavedBoardSong(u8 field)
{
    static const u16 songs[] = {
        MUS_FIELD_RUBY, MUS_FIELD_SAPPHIRE, MUS_BONUS_FIELD_DUSCLOPS,
        MUS_BONUS_FIELD_KECLEON, MUS_BONUS_FIELD_KYOGRE, MUS_BONUS_FIELD_GROUDON,
        MUS_BONUS_FIELD_RAYQUAZA, MUS_BONUS_FIELD_SPHEAL
    };
    return field < ARRAY_COUNT(songs) ? songs[field] : MUS_FIELD_RUBY;
}

static bool8 IsSavedGameInfoCompatible(const struct SaveRecordHeader *header, const struct SavedGameInfo *info)
{
    return ((header->version == SAVE_RECORD_VERSION && header->size == sizeof(*info) + sizeof(*gCurrentPinballGame))
         || (header->version == SAVE_GAME_SHINY_VERSION && header->size == sizeof(struct SavedShinyGameInfo) + sizeof(*gCurrentPinballGame)))
        && info->speciesCount >= NUM_SAVE_SPECIES && info->speciesCount <= NUM_SPECIES
        && info->ballIndex < 2 && info->cameraIndex < 2
        && info->generation <= GENERATION_RANDOM
        && info->song <= MUS_UNKNOWN_0x5D;
}

bool8 SaveFile_WriteGameState(void)
{
    struct SavedGameInfo info;
    struct SavedShinyGameInfo extended;
    u16 song;

    if (gMain.sramError)
        return FALSE;
    NormalizeEvolvablePartySpeciesStorage();
    info.speciesCount = NUM_SPECIES;
    info.song = 0;
    info.ballIndex = gCurrentPinballGame->ball == &gCurrentPinballGame->ballStates[1];
    info.cameraIndex = gCurrentPinballGame->cameraBall == &gCurrentPinballGame->ballStates[1];
    info.generation = gSelectedGeneration;
    info.reserved = 0;
    if (gCurrentPinballGame->savedBgmSongHeader)
    {
        for (song = 1; song <= MUS_UNKNOWN_0x5D; song++)
        {
            if (gCurrentPinballGame->savedBgmSongHeader == gSongTable[song].header)
            {
                info.song = song;
                break;
            }
        }
        if (!info.song)
            info.song = SavedBoardSong(gCurrentPinballGame->savedField);
    }
    gCurrentPinballGame->saveDataValid = TRUE;
    extended.base = info;
    extended.shiny = gShinyRunState;
    if (!SaveRecord_WriteVersioned(SAVE_GAME_SLOT_A, SAVE_GAME_SLOT_B, SAVE_GAME_SLOT_SIZE, SAVE_GAME_MAGIC,
                                   SAVE_GAME_SHINY_VERSION, &extended, sizeof(extended), gCurrentPinballGame, sizeof(*gCurrentPinballGame)))
    {
        gMain.sramError = TRUE;
        return FALSE;
    }
    return TRUE;
}

static u16 RestoreSavedSpecies(u16 species, u16 oldCount)
{
    return species < oldCount ? species : SPECIES_NONE;
}

bool8 SaveFile_ReadGameState(void)
{
    struct SaveRecordHeader header;
    struct LegacyPokedexHeader legacy;
    struct SavedGameInfo info;
    u32 offset;
    u16 oldCount;
    u16 prefixSize;
    struct ShinyRunState shiny;

    Shiny_ResetRunState();

    offset = SaveRecord_Find(SAVE_GAME_SLOT_A, SAVE_GAME_SLOT_B, SAVE_GAME_SLOT_SIZE, SAVE_GAME_MAGIC, &header);
    if (offset)
    {
        if (header.size == 0 && (header.version == SAVE_RECORD_VERSION || header.version == SAVE_GAME_SHINY_VERSION))
            return FALSE;
        SaveRecord_Read(offset + sizeof(header), &info, sizeof(info));
        if (!IsSavedGameInfoCompatible(&header, &info))
            return FALSE;
        prefixSize = sizeof(info);
        if (header.version == SAVE_GAME_SHINY_VERSION)
        {
            SaveRecord_Read(offset + sizeof(header) + sizeof(info), &shiny, sizeof(shiny));
            if (shiny.species > info.speciesCount || shiny.isShiny > TRUE || shiny.effectPlayed > TRUE
             || shiny.kind > SHINY_ENCOUNTER_BONUS || shiny.reserved
             || (shiny.kind == SHINY_ENCOUNTER_NONE && (shiny.isShiny || shiny.species != info.speciesCount))
             || (shiny.kind != SHINY_ENCOUNTER_NONE && shiny.species >= info.speciesCount))
                return FALSE;
            prefixSize += sizeof(shiny);
        }
        SaveRecord_Read(offset + sizeof(header) + prefixSize, gCurrentPinballGame, sizeof(*gCurrentPinballGame));
        oldCount = info.speciesCount;
        gSelectedGeneration = info.generation;
    }
    else
    {
        if (SaveRecord_HasMarker(SAVE_GAME_SLOT_A, SAVE_GAME_SLOT_B, SAVE_GAME_MAGIC)
         || !FindLegacyPokedex(&legacy) || legacy.count < 183
         || legacy.count > EXTRA_POKEDEX_FLAGS_COUNT)
            return FALSE;
        SaveRecord_Read(0x544, gCurrentPinballGame, sizeof(*gCurrentPinballGame));
        oldCount = NUM_SAVE_SPECIES + legacy.count;
        info.song = SavedBoardSong(gCurrentPinballGame->savedField);
        info.ballIndex = gCurrentPinballGame->activeBallIndex == 1;
        info.cameraIndex = info.ballIndex;
    }
    if (gCurrentPinballGame->saveDataValid != TRUE
     || gCurrentPinballGame->savedField > FIELD_SPHEAL
     || gCurrentPinballGame->savedTempField > FIELD_SPHEAL
     || gCurrentPinballGame->savedIsBonusField > 1
     || gCurrentPinballGame->boardState < 0 || gCurrentPinballGame->boardState > 8
     || gCurrentPinballGame->activeBallIndex > 1)
        return FALSE;
    /* Never dereference a pointer copied from an earlier ROM/RAM layout. */
    gCurrentPinballGame->savedBgmSongHeader = info.song ? gSongTable[info.song].header : NULL;
    gCurrentPinballGame->ball = &gCurrentPinballGame->ballStates[info.ballIndex];
    gCurrentPinballGame->cameraBall = &gCurrentPinballGame->ballStates[info.cameraIndex];
    gCurrentPinballGame->currentSpecies = RestoreSavedSpecies(gCurrentPinballGame->currentSpecies, oldCount);
    gCurrentPinballGame->evoTargetSpecies = RestoreSavedSpecies(gCurrentPinballGame->evoTargetSpecies, oldCount);
    gCurrentPinballGame->lastCatchSpecies = RestoreSavedSpecies(gCurrentPinballGame->lastCatchSpecies, oldCount);
    gCurrentPinballGame->lastEggSpecies = RestoreSavedSpecies(gCurrentPinballGame->lastEggSpecies, oldCount);
    gCurrentPinballGame->preEvoSpecies = RestoreSavedSpecies(gCurrentPinballGame->preEvoSpecies, oldCount);
    gCurrentPinballGame->postEvoSpecies = RestoreSavedSpecies(gCurrentPinballGame->postEvoSpecies, oldCount);
    gCurrentPinballGame->debugForcedCatchSpecies = SPECIES_NONE;
    gCurrentPinballGame->debugForcedEggSpecies = SPECIES_NONE;
    NormalizeEvolvablePartySpeciesStorage();
    if (offset && header.version == SAVE_GAME_SHINY_VERSION)
    {
        shiny.species = RestoreSavedSpecies(shiny.species, oldCount);
        gShinyRunState = shiny;
    }
    return TRUE;
}

void SaveFile_ClearGameState(void)
{
    u32 invalid = FALSE;

    if (gMain.sramError)
        return;
    /* A checksummed tombstone outranks older snapshots; deletion must not revive a backup. */
    if (!SaveRecord_WriteVersioned(SAVE_GAME_SLOT_A, SAVE_GAME_SLOT_B, SAVE_GAME_SLOT_SIZE, SAVE_GAME_MAGIC,
                                   SAVE_GAME_SHINY_VERSION, NULL, 0, NULL, 0)
     || WriteAndVerifySramFast((const u8 *)&invalid, (u8 *)(SRAM + 0x544), sizeof(invalid)))
        gMain.sramError = TRUE;
    gMain.hasSavedGame = FALSE;
}

void SaveFile_ReadSavedGamePresent(void)
{
    struct SaveRecordHeader header;
    struct LegacyPokedexHeader legacy;
    struct SavedGameInfo info;
    u32 offset, present;

    gMain.hasSavedGame = FALSE;
    offset = SaveRecord_Find(SAVE_GAME_SLOT_A, SAVE_GAME_SLOT_B, SAVE_GAME_SLOT_SIZE, SAVE_GAME_MAGIC, &header);
    if (offset)
    {
        if (header.size == 0 && (header.version == SAVE_RECORD_VERSION || header.version == SAVE_GAME_SHINY_VERSION))
            return;
        SaveRecord_Read(offset + sizeof(header), &info, sizeof(info));
        if (!IsSavedGameInfoCompatible(&header, &info))
        {
            gMain.sramError = TRUE;
            return;
        }
        SaveRecord_Read(offset + sizeof(header)
                        + (header.version == SAVE_GAME_SHINY_VERSION ? sizeof(struct SavedShinyGameInfo) : sizeof(info)),
                        &present, sizeof(present));
        gMain.hasSavedGame = present == TRUE;
        return;
    }
    if (SaveRecord_HasMarker(SAVE_GAME_SLOT_A, SAVE_GAME_SLOT_B, SAVE_GAME_MAGIC))
    {
        gMain.sramError = TRUE;
        return;
    }
    SaveRecord_Read(0x544, &present, sizeof(present));
    if (present == TRUE && FindLegacyPokedex(&legacy)
     && legacy.count >= 183 && legacy.count <= EXTRA_POKEDEX_FLAGS_COUNT)
        gMain.hasSavedGame = TRUE;
}

void ResetSaveFile(void)
{
    s16 i;

    for (i = 0; i < 10; i++)
        gMain_saveData.signature[i] = gSaveFileSignature[i];

    gMain_saveData.saveChangeCounter = 0;
    gMain_saveData.rumbleEnabled = FALSE;
    gMain_saveData.ballSpeed = 0;
    SetButtonConfigInputs(BUTTON_CONFIG_RESET);
    SetDefaultHighScores();
    ResetPokedex();
    Shiny_ResetRunState();
    gMain_saveData.buttonConfigType = BUTTON_CONFIG_TYPE_A;
}
