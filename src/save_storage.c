#include "global.h"
#include "agb_sram.h"
#include "save_storage.h"

typedef char SaveHeaderSizeCheck[sizeof(struct SaveRecordHeader) == 16 ? 1 : -1];
typedef char SaveDexSlotsCheck[SAVE_DEX_SLOT_A + SAVE_DEX_SLOT_SIZE <= SAVE_DEX_SLOT_B ? 1 : -1];
typedef char SaveDexGameSlotsCheck[SAVE_DEX_SLOT_B + SAVE_DEX_SLOT_SIZE <= SAVE_GAME_SLOT_A ? 1 : -1];
typedef char SaveGameSlotsCheck[SAVE_GAME_SLOT_A + SAVE_GAME_SLOT_SIZE <= SAVE_GAME_SLOT_B ? 1 : -1];
typedef char SaveSramBoundsCheck[SAVE_GAME_SLOT_B + SAVE_GAME_SLOT_SIZE <= 0x8000 ? 1 : -1];

static u32 UpdateSaveCrc(u32 crc, const u8 *data, u16 size)
{
    u16 i;
    u8 bit;

    for (i = 0; i < size; i++)
    {
        crc ^= data[i];
        for (bit = 0; bit < 8; bit++)
            crc = (crc >> 1) ^ ((crc & 1) ? 0xEDB88320 : 0);
    }
    return crc;
}

void SaveRecord_Read(u32 offset, void *data, u16 size)
{
    ReadSramFast((const u8 *)(SRAM + offset), data, size);
}

static bool8 ReadSaveRecord(u32 offset, u32 slotSize, u32 magic, struct SaveRecordHeader *header)
{
    u8 buffer[32];
    u16 pos, size;
    u32 crc;

    SaveRecord_Read(offset, header, sizeof(*header));
    if (header->magic != magic || header->size > slotSize - sizeof(*header))
        return FALSE;
    crc = UpdateSaveCrc(0xFFFFFFFF, (const u8 *)header, 12);
    for (pos = 0; pos < header->size; pos += size)
    {
        size = header->size - pos;
        if (size > sizeof(buffer))
            size = sizeof(buffer);
        SaveRecord_Read(offset + sizeof(*header) + pos, buffer, size);
        crc = UpdateSaveCrc(crc, buffer, size);
    }
    return ~crc == header->checksum;
}

u32 SaveRecord_Find(u32 a, u32 b, u32 slotSize, u32 magic, struct SaveRecordHeader *header)
{
    struct SaveRecordHeader other;
    bool8 validA = ReadSaveRecord(a, slotSize, magic, header);
    bool8 validB = ReadSaveRecord(b, slotSize, magic, &other);

    if (validB && (!validA || (s32)(other.sequence - header->sequence) > 0))
    {
        *header = other;
        return b;
    }
    return validA ? a : 0;
}

bool8 SaveRecord_HasMarker(u32 a, u32 b, u32 magic)
{
    u32 markerA, markerB;

    SaveRecord_Read(a, &markerA, sizeof(markerA));
    SaveRecord_Read(b, &markerB, sizeof(markerB));
    return markerA == magic || markerB == magic;
}

static bool8 WriteSaveRecord(u32 offset, const struct SaveRecordHeader *header,
                            const void *prefix, u16 prefixSize, const void *data, u16 dataSize)
{
    u32 invalid = 0;

    /* Commit the magic last: a torn write cannot replace the other valid copy. */
    if (WriteAndVerifySramFast((const u8 *)&invalid, (u8 *)(SRAM + offset), 4))
        return FALSE;
    if (prefixSize && WriteAndVerifySramFast(prefix, (u8 *)(SRAM + offset + 16), prefixSize))
        return FALSE;
    if (dataSize && WriteAndVerifySramFast(data, (u8 *)(SRAM + offset + 16 + prefixSize), dataSize))
        return FALSE;
    if (WriteAndVerifySramFast((const u8 *)header + 4, (u8 *)(SRAM + offset + 4), 12))
        return FALSE;
    return WriteAndVerifySramFast((const u8 *)header, (u8 *)(SRAM + offset), 4) == 0;
}

bool8 SaveRecord_Write(u32 a, u32 b, u32 slotSize, u32 magic,
                      const void *prefix, u16 prefixSize, const void *data, u16 dataSize)
{
    struct SaveRecordHeader header;
    u32 current, target, crc;

    if ((u32)prefixSize + dataSize > slotSize - sizeof(header))
        return FALSE;
    current = SaveRecord_Find(a, b, slotSize, magic, &header);
    if (!current && SaveRecord_HasMarker(a, b, magic))
        return FALSE;
    if (current && header.version != SAVE_RECORD_VERSION)
        return FALSE;
    header.sequence = current ? header.sequence + 1 : 1;
    header.magic = magic;
    header.version = SAVE_RECORD_VERSION;
    header.size = prefixSize + dataSize;
    crc = UpdateSaveCrc(0xFFFFFFFF, (const u8 *)&header, 12);
    crc = UpdateSaveCrc(crc, prefix, prefixSize);
    header.checksum = ~UpdateSaveCrc(crc, data, dataSize);
    target = current == a ? b : a;
    if (!WriteSaveRecord(target, &header, prefix, prefixSize, data, dataSize))
        return FALSE;
    return WriteSaveRecord(target == a ? b : a, &header, prefix, prefixSize, data, dataSize);
}
