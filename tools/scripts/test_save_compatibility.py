"""Run the real save reader/writer against emulated SRAM, never edit an input .sav."""

import argparse
import hashlib
import json
import os
from pathlib import Path
import re
import shutil
import subprocess
import tempfile

ROOT = Path(__file__).resolve().parents[2]


def validate_schema():
    schema = json.loads((ROOT / 'docs/save_schema_v1.json').read_text())
    species = (ROOT / 'include/constants/species.h').read_text()
    ids = {name: int(value) for name, value in re.findall(
        r'^#define\s+(SPECIES_\w+)\s+(\d+)\s*$', species, re.M)}
    count = ids.pop('SPECIES_NONE')
    for name, value in schema['species_ids'].items():
        if ids.get(name) != value:
            raise SystemExit(f'Save compatibility: {name} must keep ID {value}.')
    if sorted(ids.values()) != list(range(count)):
        raise SystemExit('Species IDs must be unique, contiguous and end before SPECIES_NONE.')
    if not re.search(r'^#define\s+NUM_SAVE_SPECIES\s+205\s*$', species, re.M):
        raise SystemExit('NUM_SAVE_SPECIES must remain 205.')
    if count - 205 > 2048:
        raise SystemExit('Extra Dex capacity exceeded: a new save format/migration is required.')
    header = (ROOT / 'include/global.h').read_text()
    layout = header[header.index('struct PinballGame\n'):header.index('struct ReplayInputFrame')]
    layout = re.sub(r'/\*.*?\*/|//[^\n]*', '', layout, flags=re.S)
    digest = hashlib.sha256(re.sub(r'\s+', '', layout).encode()).hexdigest()
    if digest != schema['pinball_game_layout_sha256']:
        raise SystemExit('PinballGame changed: implement a save migration before updating the schema lock.')
    header = (ROOT / 'include/main.h').read_text()
    layout = header[header.index('struct HighScoreEntry'):header.index('struct Main\n')]
    layout = re.sub(r'/\*.*?\*/|//[^\n]*', '', layout, flags=re.S)
    digest = hashlib.sha256(re.sub(r'\s+', '', layout).encode()).hexdigest()
    if digest != schema['base_layout_sha256']:
        raise SystemExit('Base SaveData changed: implement a migration, do not resize or rearrange it.')
    print(f'PASS: stable saved IDs and PinballGame layout ({count} species).')


def without_includes(source):
    return re.sub(r'^#include[^\n]*\n', '', source, flags=re.M)


def game_fixture():
    # Exact persisted ARM offsets, including 32-bit pointers (test with x86 MSVC).
    fields = [
        (0, 4, 'u32 saveDataValid'), (0x13, 1, 's8 boardState'),
        (0x30, 1, 's8 numLives'), (0x44, 4, 'u32 scoreLo'), (0x48, 4, 'u32 scoreHi'),
        (0x66, 2, 'u16 activeBallIndex'), (0x94, 4, 'u32 legendaryEncounterMagic'),
        (0x98, 4, 'u32 legendaryCaughtMask'), (0x270, 16, 'u8 evolvablePartySpecies[16]'),
        (0x281, 1, 's8 evolvablePartySize'),
        (0x598, 2, 'u16 currentSpecies'), (0x59A, 2, 'u16 evoTargetSpecies'),
        (0x59C, 2, 'u16 lastCatchSpecies'), (0x59E, 2, 'u16 lastEggSpecies'),
        (0x5A0, 2, 'u16 preEvoSpecies'), (0x5A2, 2, 'u16 postEvoSpecies'),
        (0x5F0, 2, 'u16 caughtMonCount'), (0x73E, 2, 'u16 debugForcedEggSpecies'),
        (0x742, 2, 'u16 debugForcedCatchSpecies'), (0xF4C, 4, 'struct SongHeader *savedBgmSongHeader'),
        (0x10FD, 1, 'u8 savedField'), (0x10FE, 1, 'u8 savedTempField'),
        (0x10FF, 1, 'u8 savedIsBonusField'), (0x132C, 4, 'struct BallState *ball'),
        (0x1330, 4, 'struct BallState *cameraBall'), (0x1334, 0x88, 'struct BallState ballStates[2]'),
        (0x1410, 16, 'u8 evolvablePartySpeciesHighBytes[16]'),
        (0x1420, 4, 'u32 evolvablePartySpeciesStorageMagic'),
    ]
    code, end = 'struct PinballGame {\n', 0
    for offset, size, declaration in fields:
        if offset > end:
            code += f'    u8 gap{end:X}[{offset - end}];\n'
        code += f'    {declaration};\n'
        end = offset + size
    return code + '};\n'


PRELUDE = r'''
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned char bool8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned short bool16;
typedef unsigned int u32;
typedef int s32;
typedef unsigned int size_t;
typedef unsigned int uintptr_t;
#ifdef _MSC_VER
#define offsetof(type, member) ((size_t)&(((type *)0)->member))
#else
#define offsetof(type, member) __builtin_offsetof(type, member)
#endif
#define TRUE 1
#define FALSE 0
#define NULL ((void *)0)
#define SPECIES_UNSEEN 0
#define SPECIES_CAUGHT 4
#define ARRAY_COUNT(a) (sizeof(a) / sizeof((a)[0]))
#include "constants/species.h"
#include "constants/generations.h"
#include "constants/fields.h"
#include "constants/bg_music.h"
#include "constants/high_scores.h"
#include "constants/pinball_inputs.h"
#include "constants/pinball_game.h"
#include "save_storage.h"
#ifdef FUTURE_SPECIES_COUNT
#undef NUM_SPECIES
#undef SPECIES_NONE
#define NUM_SPECIES FUTURE_SPECIES_COUNT
#define SPECIES_NONE FUTURE_SPECIES_COUNT
#endif
u8 sram[32768], before[32768];
#define SRAM ((uintptr_t)sram)
int writeBudget = -1, writes, outOfRange;
void *memcpy(void *dst, const void *src, size_t size)
{
    u8 *d = dst;
    const u8 *s = src;
    while (size--) *d++ = *s++;
    return dst;
}
void *memset(void *dst, int c, size_t size)
{
    u8 *d = dst;
    while (size--) *d++ = (u8)c;
    return dst;
}
void ReadSramFast(const u8 *src, u8 *dst, u32 size)
{
    if (src < sram || src + size > sram + sizeof(sram)) { outOfRange = 1; return; }
    memcpy(dst, src, size);
}
u32 WriteAndVerifySramFast(const u8 *src, u8 *dst, u32 size)
{
    if (dst < sram || dst + size > sram + sizeof(sram)) { outOfRange = 1; return 1; }
    while (size--)
    {
        if (writeBudget == 0) return 1;
        if (writeBudget > 0) writeBudget--;
        *dst++ = *src++;
        writes++;
    }
    return 0;
}
void SetSramFastFunc(void) {}
struct SongHeader { u8 dummy; } songs[94];
struct Song { struct SongHeader *header; } gSongTable[94];
struct BallState { u8 bytes[0x44]; };
'''

GLOBALS = r'''
struct PinballGame game;
struct PinballGame *gCurrentPinballGame = &game;
struct SaveData gMain_saveData;
struct { u8 sramError; u32 hasSavedGame; } gMain;
u8 gExtraPokedexFlags[NUM_SPECIES - NUM_SAVE_SPECIES];
u8 gSelectedGeneration;
u8 gSaveFileSignature[] = "POKEPINAGB";
void SetButtonConfigInputs(int n) { (void)n; }
void SetDefaultHighScores(void) {}
void ResetPokedex(void)
{
    memset(gMain_saveData.pokedexFlags, 0, sizeof(gMain_saveData.pokedexFlags));
    memset(gExtraPokedexFlags, 0, sizeof(gExtraPokedexFlags));
}
void ResetSaveFile(void);
void SaveFile_WriteToSram(void);
void SaveFile_ReadSavedGamePresent(void);
'''

TESTS = r'''
#define CHECK(x) do { if (!(x)) return __LINE__; } while (0)
int Equal(const void *a, const void *b, u32 size)
{
    const u8 *aa = a, *bb = b;
    while (size--) if (*aa++ != *bb++) return 0;
    return 1;
}
void Fresh(void)
{
    int i;
    memset(sram, 255, sizeof(sram)); memset(&game, 0, sizeof(game));
    memset(&gMain_saveData, 0, sizeof(gMain_saveData));
    memset(gExtraPokedexFlags, 0, sizeof(gExtraPokedexFlags));
    gMain.sramError = FALSE; gMain.hasSavedGame = FALSE;
    writeBudget = -1; writes = 0;
    for (i = 0; i < 94; i++) gSongTable[i].header = &songs[i];
}
void MakeLegacy(u16 count, u8 flag)
{
    struct LegacyPokedexHeader h;
    u8 flags[SAVE_DEX_CAPACITY];
    h.magic = EXTRA_POKEDEX_SAVE_MAGIC; h.count = count;
    memset(flags, flag, count);
    h.checksum = (u16)~((u16)h.magic + (u16)(h.magic >> 16) + count + count * flag);
    memcpy(sram + 0x1A00, &h, 8); memcpy(sram + 0x1A08, flags, count);
    memcpy(sram + 0x1B00, &h, 8); memcpy(sram + 0x1B08, flags, count);
}
int TestDex(void)
{
    int i, cut;
    struct SaveRecordHeader h;
    struct LegacyPokedexHeader legacy;
    u32 offset;
    u8 flags[SAVE_DEX_CAPACITY];
    Fresh(); MakeLegacy(295, 4);
    CHECK(!ReadLegacyPokedex(0x1A00, &legacy));
    CHECK(ReadLegacyPokedex(0x1B00, &legacy));
    memcpy(before, sram, sizeof(sram));
    LoadExtraPokedexFlagsFromSram(); CHECK(!gMain.sramError);
    for (i = 0; i < 295; i++) CHECK(gExtraPokedexFlags[i] == 4);
    for (; i < EXTRA_POKEDEX_FLAGS_COUNT; i++) CHECK(gExtraPokedexFlags[i] == 0);
    CHECK(Equal(before, sram, 0x2000));
    CHECK(Equal(before + 0x4000, sram + 0x4000, 0x4000));
    CHECK(ReadSaveRecord(SAVE_DEX_SLOT_A, SAVE_DEX_SLOT_SIZE, SAVE_DEX_MAGIC, &h));
    CHECK(ReadSaveRecord(SAVE_DEX_SLOT_B, SAVE_DEX_SLOT_SIZE, SAVE_DEX_MAGIC, &h));
    sram[SAVE_DEX_SLOT_A + 30] ^= 1;
    memset(gExtraPokedexFlags, 0, sizeof(gExtraPokedexFlags));
    LoadExtraPokedexFlagsFromSram(); CHECK(gExtraPokedexFlags[294] == 4 && !gMain.sramError);
    sram[SAVE_DEX_SLOT_B + 30] ^= 1;
    memcpy(before, sram, sizeof(sram));
    LoadExtraPokedexFlagsFromSram(); CHECK(gMain.sramError);
    SaveFile_WriteToSram(); CHECK(Equal(before, sram, sizeof(sram)));

    Fresh(); MakeLegacy(183, 3); LoadExtraPokedexFlagsFromSram();
    CHECK(!gMain.sramError);
    CHECK(gExtraPokedexFlags[SPECIES_ZEBSTRIKA - NUM_SAVE_SPECIES] == 3);
    CHECK(gExtraPokedexFlags[SPECIES_TURTWIG - NUM_SAVE_SPECIES] == 0);
    Fresh(); MakeLegacy(182, 4); memcpy(before, sram, sizeof(sram));
    LoadExtraPokedexFlagsFromSram(); CHECK(gMain.sramError);
    CHECK(Equal(before, sram, sizeof(sram)));
    Fresh(); MakeLegacy(2, 4); LoadExtraPokedexFlagsFromSram();
    CHECK(!gMain.sramError);
    CHECK(gExtraPokedexFlags[SPECIES_BLITZLE - NUM_SAVE_SPECIES] == 4);
    CHECK(gExtraPokedexFlags[SPECIES_ZEBSTRIKA - NUM_SAVE_SPECIES] == 4);
    CHECK(gExtraPokedexFlags[SPECIES_DEOXYS - NUM_SAVE_SPECIES] == 0);

    Fresh(); memset(flags, 2, sizeof(flags));
    CHECK(SaveRecord_Write(SAVE_DEX_SLOT_A, SAVE_DEX_SLOT_B, SAVE_DEX_SLOT_SIZE, SAVE_DEX_MAGIC, NULL, 0, flags, 183));
    LoadExtraPokedexFlagsFromSram(); CHECK(!gMain.sramError);
    CHECK(gExtraPokedexFlags[182] == 2 && gExtraPokedexFlags[183] == 0);
    CHECK(SaveRecord_Write(SAVE_DEX_SLOT_A, SAVE_DEX_SLOT_B, SAVE_DEX_SLOT_SIZE, SAVE_DEX_MAGIC, NULL, 0, flags, SAVE_DEX_CAPACITY));
    memcpy(before, sram, sizeof(sram));
    LoadExtraPokedexFlagsFromSram(); CHECK(gMain.sramError);
    SaveExtraPokedexFlagsToSram(); CHECK(Equal(before, sram, sizeof(sram)));

    /* Every possible interrupted byte in a two-copy Dex update leaves old or new data. */
    Fresh(); memset(flags, 1, sizeof(flags));
    CHECK(SaveRecord_Write(SAVE_DEX_SLOT_A, SAVE_DEX_SLOT_B, SAVE_DEX_SLOT_SIZE, SAVE_DEX_MAGIC, NULL, 0, flags, 295));
    memcpy(before, sram, sizeof(sram)); memset(flags, 4, sizeof(flags));
    for (cut = 0; cut <= 630; cut++)
    {
        memcpy(sram, before, sizeof(sram)); writeBudget = cut;
        SaveRecord_Write(SAVE_DEX_SLOT_A, SAVE_DEX_SLOT_B, SAVE_DEX_SLOT_SIZE, SAVE_DEX_MAGIC, NULL, 0, flags, 295);
        offset = SaveRecord_Find(SAVE_DEX_SLOT_A, SAVE_DEX_SLOT_B, SAVE_DEX_SLOT_SIZE, SAVE_DEX_MAGIC, &h);
        CHECK(offset != 0);
        for (i = 0; i < 295; i++) CHECK(sram[offset + 16 + i] == sram[offset + 16]);
        CHECK(sram[offset + 16] == 1 || sram[offset + 16] == 4);
    }
    writeBudget = -1;
    return 0;
}
int TestSnapshots(void)
{
    struct SavedGameInfo info;
    struct SaveRecordHeader h;
    u32 offset;
    int cut, cuts[] = {0, 1, 4, 12, 100, 5000, 5175, 5179, 5180, 5184, 5190, 10360, 10368};
    Fresh();
    game.scoreLo = 12345678; game.scoreHi = 12; game.caughtMonCount = 30;
    game.numLives = 3; game.savedField = FIELD_SAPPHIRE;
    game.activeBallIndex = 1; game.ball = &game.ballStates[1]; game.cameraBall = &game.ballStates[0];
    game.savedBgmSongHeader = gSongTable[MUS_CATCH_EM_MODE].header;
    game.currentSpecies = SPECIES_GIRATINA; game.lastCatchSpecies = SPECIES_NONE;
    game.evolvablePartySpecies[0] = SPECIES_EEVEE & 255;
    game.evolvablePartySpeciesHighBytes[0] = SPECIES_EEVEE >> 8;
    game.evolvablePartySize = 1;
    game.evolvablePartySpeciesStorageMagic = EVOLVABLE_PARTY_SPECIES_STORAGE_MAGIC;
    game.legendaryCaughtMask = 0x4321;
    gSelectedGeneration = GENERATION_RANDOM;
    CHECK(SaveFile_WriteGameState());
    SaveFile_ReadSavedGamePresent(); CHECK(gMain.hasSavedGame);
    /* A relocated ROM song table must be used instead of the persisted address. */
    gSongTable[MUS_CATCH_EM_MODE].header = &songs[0];
    memset(&game, 0, sizeof(game));
    CHECK(SaveFile_ReadGameState());
    CHECK(game.scoreLo == 12345678 && game.scoreHi == 12 && game.numLives == 3);
    CHECK(game.caughtMonCount == 30 && game.legendaryCaughtMask == 0x4321);
    CHECK(game.ball == &game.ballStates[1] && game.cameraBall == &game.ballStates[0]);
    CHECK(game.savedBgmSongHeader == &songs[0] && gSelectedGeneration == GENERATION_RANDOM);
    CHECK(game.currentSpecies == SPECIES_GIRATINA && game.lastCatchSpecies == SPECIES_NONE);
    CHECK((game.evolvablePartySpecies[0] | game.evolvablePartySpeciesHighBytes[0] << 8) == SPECIES_EEVEE);

    offset = SaveRecord_Find(SAVE_GAME_SLOT_A, SAVE_GAME_SLOT_B, SAVE_GAME_SLOT_SIZE, SAVE_GAME_MAGIC, &h);
    SaveRecord_Read(offset + 16, &info, sizeof(info));
    info.speciesCount = 500; game.lastCatchSpecies = 500;
    CHECK(SaveRecord_Write(SAVE_GAME_SLOT_A, SAVE_GAME_SLOT_B, SAVE_GAME_SLOT_SIZE, SAVE_GAME_MAGIC, &info, sizeof(info), &game, sizeof(game)));
    CHECK(SaveFile_ReadGameState()); CHECK(game.lastCatchSpecies == SPECIES_NONE);

    memcpy(before, sram, sizeof(sram));
    game.scoreLo = 999999;
    for (cut = 0; cut < (int)ARRAY_COUNT(cuts); cut++)
    {
        memcpy(sram, before, sizeof(sram)); writeBudget = cuts[cut]; gMain.sramError = FALSE;
        SaveFile_WriteGameState();
        CHECK(SaveRecord_Find(SAVE_GAME_SLOT_A, SAVE_GAME_SLOT_B, SAVE_GAME_SLOT_SIZE, SAVE_GAME_MAGIC, &h));
        CHECK(SaveFile_ReadGameState()); CHECK(game.scoreLo == 12345678 || game.scoreLo == 999999);
        game.scoreLo = 999999;
    }
    writeBudget = -1; gMain.sramError = FALSE;
    SaveFile_ClearGameState(); CHECK(!gMain.sramError);
    SaveFile_ReadSavedGamePresent(); CHECK(!gMain.hasSavedGame);
    CHECK(!SaveFile_ReadGameState());

    Fresh(); MakeLegacy(295, 4); memset(&game, 0, sizeof(game));
    game.saveDataValid = TRUE; game.scoreLo = 7654321; game.caughtMonCount = 21;
    game.currentSpecies = SPECIES_BUDEW; game.lastCatchSpecies = 500;
    game.savedField = FIELD_RUBY; game.activeBallIndex = 1;
    game.savedBgmSongHeader = (void *)0x08001234;
    game.ball = (void *)0x02001111; game.cameraBall = (void *)0x02002222;
    memcpy(sram + 0x544, &game, sizeof(game)); memset(&game, 0, sizeof(game));
    SaveFile_ReadSavedGamePresent(); CHECK(gMain.hasSavedGame);
    CHECK(SaveFile_ReadGameState()); CHECK(game.scoreLo == 7654321 && game.caughtMonCount == 21);
    CHECK(game.ball == &game.ballStates[1] && game.cameraBall == game.ball);
    CHECK(game.savedBgmSongHeader == gSongTable[MUS_FIELD_RUBY].header);
    CHECK(game.lastCatchSpecies == SPECIES_NONE);
    return 0;
}
int TestProtection(void)
{
    struct SaveRecordHeader h;
    u8 flag = 4;
    u32 offset;

    Fresh(); SaveFile_LoadGameData();
    SaveFile_SetPokedexFlags(SPECIES_TREECKO, 4);
    sram[4] ^= 1;
    SaveFile_LoadGameData(); CHECK(!gMain.sramError);
    CHECK(gMain_saveData.pokedexFlags[SPECIES_TREECKO] == 4);
    sram[0x2A4] ^= 1;
    memcpy(before, sram, sizeof(sram));
    SaveFile_LoadGameData(); CHECK(gMain.sramError);
    SaveFile_WriteToSram(); CHECK(Equal(before, sram, sizeof(sram)));

    Fresh(); SaveFile_LoadGameData(); writeBudget = 10;
    SaveFile_SetPokedexFlags(SPECIES_TREECKO, 4); CHECK(gMain.sramError);
    writeBudget = -1; SaveFile_LoadGameData(); CHECK(!gMain.sramError);
    CHECK(gMain_saveData.pokedexFlags[SPECIES_TREECKO] == 0);

    Fresh();
    CHECK(SaveRecord_Write(SAVE_DEX_SLOT_A, SAVE_DEX_SLOT_B, SAVE_DEX_SLOT_SIZE, SAVE_DEX_MAGIC, NULL, 0, &flag, 1));
    offset = SaveRecord_Find(SAVE_DEX_SLOT_A, SAVE_DEX_SLOT_B, SAVE_DEX_SLOT_SIZE, SAVE_DEX_MAGIC, &h);
    CHECK(offset != 0);
    h.version++; h.sequence++;
    h.checksum = ~UpdateSaveCrc(UpdateSaveCrc(0xFFFFFFFF, (u8 *)&h, 12), &flag, 1);
    CHECK(WriteSaveRecord(SAVE_DEX_SLOT_B, &h, NULL, 0, &flag, 1));
    memcpy(before, sram, sizeof(sram));
    LoadExtraPokedexFlagsFromSram(); CHECK(gMain.sramError);
    CHECK(!SaveRecord_Write(SAVE_DEX_SLOT_A, SAVE_DEX_SLOT_B, SAVE_DEX_SLOT_SIZE, SAVE_DEX_MAGIC, NULL, 0, &flag, 1));
    CHECK(Equal(before, sram, sizeof(sram)));

    Fresh(); h.magic = SAVE_DEX_MAGIC; h.size = 65535;
    memcpy(sram + SAVE_DEX_SLOT_A, &h, sizeof(h));
    CHECK(!ReadSaveRecord(SAVE_DEX_SLOT_A, SAVE_DEX_SLOT_SIZE, SAVE_DEX_MAGIC, &h));
    CHECK(!outOfRange);

    Fresh(); h.magic = SAVE_DEX_MAGIC; h.version = SAVE_RECORD_VERSION;
    h.size = 1; h.sequence = 0xFFFFFFFF;
    h.checksum = ~UpdateSaveCrc(UpdateSaveCrc(0xFFFFFFFF, (u8 *)&h, 12), &flag, 1);
    CHECK(WriteSaveRecord(SAVE_DEX_SLOT_A, &h, NULL, 0, &flag, 1));
    CHECK(SaveRecord_Write(SAVE_DEX_SLOT_A, SAVE_DEX_SLOT_B, SAVE_DEX_SLOT_SIZE, SAVE_DEX_MAGIC, NULL, 0, &flag, 1));
    CHECK(SaveRecord_Find(SAVE_DEX_SLOT_A, SAVE_DEX_SLOT_B, SAVE_DEX_SLOT_SIZE, SAVE_DEX_MAGIC, &h));
    CHECK(h.sequence == 0);

    Fresh(); SaveFile_ClearGameState(); CHECK(!gMain.sramError);
    sram[SAVE_GAME_SLOT_A + 12] ^= 1;
    SaveFile_ReadSavedGamePresent(); CHECK(!gMain.hasSavedGame && !gMain.sramError);
    Fresh(); memset(sram, 0, sizeof(sram));
    SaveFile_LoadGameData(); CHECK(!gMain.sramError);
    return 0;
}
int main(void)
{
    int result, i;
    struct SaveRecordHeader h;
    u8 crcText[] = "123456789";
    CHECK(~UpdateSaveCrc(0xFFFFFFFF, crcText, 9) == 0xCBF43926);
    result = TestDex(); if (result) return result;
    result = TestSnapshots(); if (result) return result;
    result = TestProtection(); if (result) return result;
    Fresh(); SaveFile_LoadGameData(); CHECK(!gMain.sramError);
    SaveFile_DebugCompletePokedex(); CHECK(!gMain.hasSavedGame);
    for (i = 0; i < NUM_SPECIES; i++)
    {
        if (i < NUM_SAVE_SPECIES) CHECK(gMain_saveData.pokedexFlags[i] == 4);
        else CHECK(gExtraPokedexFlags[i - NUM_SAVE_SPECIES] == 4);
    }
    memcpy(before, sram, sizeof(sram));
    SaveFile_SetPokedexFlags(-1, 4); SaveFile_SetPokedexFlags(SPECIES_NONE, 4);
    CHECK(Equal(before, sram, sizeof(sram)));
    CHECK(SaveRecord_Find(SAVE_DEX_SLOT_A, SAVE_DEX_SLOT_B, SAVE_DEX_SLOT_SIZE, SAVE_DEX_MAGIC, &h));
    CHECK(!outOfRange);
    return TestUserSave();
}
'''


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--save', type=Path, help='Read-only 500-species legacy fixture, no suspended game (32 KiB)')
    parser.add_argument('--schema-only', action='store_true', help='Check compatibility without a C compiler')
    args = parser.parse_args()
    validate_schema()
    if args.schema_only:
        return
    source = (ROOT / 'src/save.c').read_text()
    storage = (ROOT / 'src/save_storage.c').read_text()
    main_header = (ROOT / 'include/main.h').read_text()
    save_structs = main_header[main_header.index('struct HighScoreEntry'):main_header.index('struct Main\n')]
    picker = (ROOT / 'src/main_board_catch_hatch_picker.c').read_text()
    party_magic = re.search(r'^#define EVOLVABLE_PARTY_SPECIES_STORAGE_MAGIC[^\n]+', picker, re.M).group()
    party_code = picker[picker.index('void NormalizeEvolvablePartySpeciesStorage(void)'):
                        picker.index('u16 GetEvolvablePartySpecies(s16 index)')]
    user_code = 'int TestUserSave(void) { return 0; }\n'
    original = args.save.read_bytes() if args.save else None
    if original is not None:
        if len(original) != 32768:
            raise SystemExit('Expected a 32768-byte SRAM .sav, not an emulator save state.')
        user_code = 'const u8 userSave[32768] = {' + ','.join(map(str, original)) + '};\n'
        user_code += r'''
int TestUserSave(void)
{
    int i;
    struct SaveRecordHeader h;
    Fresh(); memcpy(sram, userSave, sizeof(sram));
    SaveFile_LoadGameData(); CHECK(!gMain.sramError);
    CHECK(Equal(sram, userSave, 0x2000));
    CHECK(Equal(sram + 0x4000, userSave + 0x4000, 0x4000));
    CHECK(Equal(&gMain_saveData, userSave + 4, sizeof(gMain_saveData)));
    for (i = 0; i < 295; i++) CHECK(gExtraPokedexFlags[i] == userSave[0x1B08 + i]);
    for (; i < EXTRA_POKEDEX_FLAGS_COUNT; i++) CHECK(gExtraPokedexFlags[i] == 0);
    CHECK(ReadSaveRecord(SAVE_DEX_SLOT_A, SAVE_DEX_SLOT_SIZE, SAVE_DEX_MAGIC, &h));
    CHECK(ReadSaveRecord(SAVE_DEX_SLOT_B, SAVE_DEX_SLOT_SIZE, SAVE_DEX_MAGIC, &h));
    SaveFile_ReadSavedGamePresent(); CHECK(!gMain.hasSavedGame);
    memset(gExtraPokedexFlags, 0, sizeof(gExtraPokedexFlags));
    SaveFile_LoadGameData(); CHECK(!gMain.sramError);
    for (i = 0; i < 295; i++) CHECK(gExtraPokedexFlags[i] == userSave[0x1B08 + i]);
    return 0;
}
'''
    code = (PRELUDE + game_fixture() + save_structs + GLOBALS + party_magic + '\n' + party_code + without_includes(storage)
            + without_includes(source) + 'int TestUserSave(void);\n' + TESTS + user_code)
    candidates = sorted(Path('C:/Program Files/Microsoft Visual Studio').glob(
        '*/Community/VC/Tools/MSVC/*/bin/Hostx64/x86/cl.exe')) if os.name == 'nt' else []
    compiler = str(candidates[-1]) if candidates else os.environ.get('CC') or shutil.which('cc')
    if not compiler:
        raise SystemExit('Need x86 MSVC or a C compiler with 32-bit support.')
    with tempfile.TemporaryDirectory(prefix='save-tests-') as temporary:
        work = Path(temporary)
        cfile = work / 'test.c'
        cfile.write_text(code)
        exe = work / ('test.exe' if os.name == 'nt' else 'test')
        for count in (500, 520):
            if candidates:
                command = [compiler, '/nologo', '/W3', '/WX', '/GS-', '/Od',
                           f'/DFUTURE_SPECIES_COUNT={count}', f'/I{ROOT / "include"}', str(cfile),
                           '/link', '/nodefaultlib', '/entry:main', '/subsystem:console', f'/out:{exe}']
            else:
                command = [compiler, '-m32', '-std=gnu89', '-Wimplicit', '-Wparentheses', '-Werror',
                           '-fno-builtin', f'-DFUTURE_SPECIES_COUNT={count}', '-I', str(ROOT / 'include'),
                           str(cfile), '-o', str(exe)]
            subprocess.run(command, cwd=work, check=True)
            result = subprocess.run([str(exe)], cwd=work)
            if result.returncode:
                line = result.returncode
                detail = code.splitlines()[line - 1] if 0 < line <= len(code.splitlines()) else ''
                raise SystemExit(f'Save regression failed at line/status {line}: {detail}')
            print(f'PASS ({count} species): legacy and versioned saves, backup recovery, torn writes, '
                  'snapshot pointers, totals, sentinel migration and deletion.')
    if original is not None:
        assert args.save.read_bytes() == original, 'Input save was modified!'
        print(f'PASS: real save migrated/reloaded without modifying input; SHA256 {hashlib.sha256(original).hexdigest()}')


if __name__ == '__main__':
    main()
