#ifndef GUARD_SAVE_STORAGE_H
#define GUARD_SAVE_STORAGE_H

#define SAVE_DEX_SLOT_A 0x2000
#define SAVE_DEX_SLOT_B 0x3000
#define SAVE_DEX_SLOT_SIZE 0x1000
#define SAVE_DEX_CAPACITY 2048
#define SAVE_DEX_MAGIC 0x32444550
#define SAVE_GAME_SLOT_A 0x4000
#define SAVE_GAME_SLOT_B 0x6000
#define SAVE_GAME_SLOT_SIZE 0x2000
#define SAVE_GAME_MAGIC 0x324D4147
#define SAVE_RECORD_VERSION 1
#define SAVE_GAME_LAYOUT_SIZE 0x1424

/* Only needed for ambiguous, pre-Blitzle-restoration 387-species builds.
 * 0 = protect the save; 1 = slot 205 was Blitzle; 2 = slot 205 was Deoxys. */
#define LEGACY_387_LAYOUT 0

struct SaveRecordHeader
{
    u32 magic;
    u16 version;
    u16 size;
    u32 sequence;
    u32 checksum;
};

u32 SaveRecord_Find(u32 a, u32 b, u32 slotSize, u32 magic, struct SaveRecordHeader *header);
bool8 SaveRecord_HasMarker(u32 a, u32 b, u32 magic);
bool8 SaveRecord_Write(u32 a, u32 b, u32 slotSize, u32 magic,
                      const void *prefix, u16 prefixSize, const void *data, u16 dataSize);
void SaveRecord_Read(u32 offset, void *data, u16 size);

bool8 SaveFile_WriteGameState(void);
bool8 SaveFile_ReadGameState(void);
void SaveFile_ClearGameState(void);

#endif
