#include "global.h"
#include "main.h"
#include "m4a.h"
#include "encounters.h"
#include "constants/bg_music.h"

#include "data/encounters_assets.h"

extern const u16 gLocation_Pals[];
extern const s16 gAreaPortraitIndexes[];

// Only BG VRAM 0..0x9FFF and BG palettes are borrowed. OBJ graphics stay intact.
struct EncountersScreen
{
    u16 vram[0xA000 / 2];
    u16 palette[256];
    u16 species[ENCOUNTERS_CAPACITY];
    u16 count, page, pageCount;
    u16 bg0cnt, dispcnt, xOffset, yOffset;
    u16 blendControl, blendAlpha, blendBrightness;
    bool8 blendEnabled;
    bool8 active;
};

static EWRAM_DATA struct EncountersScreen sEncounters = {0};
static EWRAM_DATA struct
{
    u16 tiles[128];
    struct OamData oam[2];
    u16 ids[2];
    bool8 active;
} sPauseLabel = {0};

static const u8 sDigits[11][5] = {
    {7,5,5,5,7}, {2,6,2,2,7}, {7,1,7,4,7}, {7,1,7,1,7},
    {5,5,7,1,1}, {7,4,7,1,7}, {7,4,7,5,7}, {7,1,1,1,1},
    {7,5,7,5,7}, {7,5,7,1,7}, {1,1,2,4,4}
};

static const u8 sPauseLetters[10][7] = {
    {31,16,16,30,16,16,31}, {17,25,25,21,19,19,17},
    {14,17,16,16,16,17,14}, {14,17,17,17,17,17,14},
    {17,17,17,17,17,17,14}, {17,25,25,21,19,19,17},
    {31,4,4,4,4,4,4}, {31,16,16,30,16,16,31},
    {30,17,17,30,20,18,17}, {15,16,16,14,1,1,30}
};

bool8 Encounters_IsOpen(void)
{
    return sEncounters.active;
}

static void PutPixel(s16 x, s16 y, u8 color)
{
    u32 offset;
    vu16 *dest;
    if (x < 0 || x >= 240 || y < 0 || y >= 160)
        return;
    offset = ((y / 8) * 30 + x / 8) * 64 + (y % 8) * 8 + x % 8;
    dest = (vu16 *)VRAM + offset / 2;
    // GBA VRAM does not support byte stores.
    if (offset & 1)
        *dest = (*dest & 0x00FF) | (color << 8);
    else
        *dest = (*dest & 0xFF00) | color;
}

static void DrawImage(const u16 *runs, s16 width, s16 height, s16 x, s16 y, s16 firstRow, s16 rows, bool8 transparent)
{
    s16 row, col;
    u16 remaining = 0;
    u8 color = 0;
    for (row = 0; row < height; row++)
    {
        for (col = 0; col < width; col++)
        {
            if (remaining == 0)
            {
                color = *runs & 255;
                remaining = *runs++ >> 8;
            }
            remaining--;
            if (row >= firstRow && row < firstRow + rows && (!transparent || color))
                PutPixel(x + col, y + row - firstRow, color);
        }
    }
}

static bool8 IsCaught(u16 species)
{
    if (species >= NUM_SPECIES)
        return FALSE;
    if (species >= NUM_SAVE_SPECIES)
        return gExtraPokedexFlags[species - NUM_SAVE_SPECIES] == SPECIES_CAUGHT;
    return gMain_saveData.pokedexFlags[species] == SPECIES_CAUGHT;
}

static void DrawPortrait(const u8 *tiles, const u16 *palette, s16 x, s16 y, s16 bank, bool8 caught)
{
    s16 row, col, index, i;
    u8 color;
    for (i = 0; i < 16; i++)
        ((vu16 *)BG_PLTT)[bank * 16 + i] = caught ? palette[i] : (i == 15 ? 0x7FFF : 0);
    for (row = 0; row < 32; row++)
    {
        for (col = 0; col < 48; col++)
        {
            index = ((row / 8) * 6 + col / 8) * 32 + (row % 8) * 4 + (col % 8) / 2;
            color = (tiles[index] >> ((col & 1) * 4)) & 15;
            PutPixel(x + col, y + row, color || bank == 2 ? bank * 16 + color : 2);
        }
    }
}

static void DrawDigit(s16 digit, s16 x)
{
    s16 y, col;
    for (y = 0; y < 5; y++)
        for (col = 0; col < 3; col++)
            if (sDigits[digit][y] & (4 >> col))
                PutPixel(x + col, 56 + y, 1);
}

static void RenderEncounters(void)
{
    s16 x, y, slot, index, area;
    u16 species;
    REG_DISPCNT = DISPCNT_MODE_0 | DISPCNT_FORCED_BLANK;
    DmaCopy16(3, sEncountersPalette, BG_PLTT, sizeof(sEncountersPalette));
    DrawImage(sEncountersBackground, 240, 160, 0, 0, 0, 160, FALSE);
    DrawImage(sEncountersFrames, 54, 80, 93, 13, 0, 40, TRUE);
    area = gAreaPortraitIndexes[gCurrentPinballGame->area];
    DrawPortrait(gLocationPortraitGfx[area], &gLocation_Pals[area * 16], 96, 17, 2, TRUE);
    DrawImage(sEncountersButtons, 16, 32, 16, 51, 16, 16, TRUE);
    DrawImage(sEncountersButtons, 16, 32, 208, 51, 0, 16, TRUE);
    DrawDigit(sEncounters.page + 1, 110);
    DrawDigit(10, 118);
    DrawDigit(sEncounters.pageCount, 126);
    for (slot = 0; slot < ENCOUNTERS_PER_PAGE; slot++)
    {
        x = 10 + (slot % 4) * 56;
        y = 66 + (slot / 4) * 47;
        DrawImage(sEncountersFrames, 54, 80, x, y, 40, 40, TRUE);
        index = sEncounters.page * ENCOUNTERS_PER_PAGE + slot;
        if (index < sEncounters.count)
        {
            species = sEncounters.species[index];
            DrawPortrait(gMonPortraitGroupGfx[species / 15] + (species % 15) * 0x300,
                         gMonPortraitGroupPals[species / 15][species % 15],
                         x + 3, y + 4, 3 + slot, IsCaught(species));
        }
        else
        {
            for (index = 0; index < 32; index++)
                for (area = 0; area < 48; area++)
                    PutPixel(x + 3 + area, y + 4 + index, 2);
        }
    }
    for (y = 0; y < 20; y++)
        for (x = 0; x < 32; x++)
            ((vu16 *)BG_SCREEN_ADDR(19))[y * 32 + x] = x < 30 ? y * 30 + x : 0;
    REG_BG0CNT = BGCNT_CHARBASE(0) | BGCNT_SCREENBASE(19) | BGCNT_256COLOR | BGCNT_TXT256x256;
    gMain.dispcntBackup = DISPCNT_MODE_0 | DISPCNT_BG0_ON;
}

void Encounters_Open(void)
{
    if (sEncounters.active || gMain.selectedField >= MAIN_FIELD_COUNT
     || gCurrentPinballGame->area >= AREA_COUNT || !(gMain.modeChangeFlags & MODE_CHANGE_PAUSE))
        return;
    sEncounters.count = GetCurrentAreaCatchEncounters(sEncounters.species);
    sEncounters.page = 0;
    sEncounters.pageCount = (sEncounters.count + ENCOUNTERS_PER_PAGE - 1) / ENCOUNTERS_PER_PAGE;
    if (!sEncounters.pageCount)
        sEncounters.pageCount = 1;
    sEncounters.bg0cnt = REG_BG0CNT;
    sEncounters.dispcnt = gMain.dispcntBackup;
    sEncounters.xOffset = gMain.bgOffsets[0].xOffset;
    sEncounters.yOffset = gMain.bgOffsets[0].yOffset;
    sEncounters.blendControl = gMain.blendControl;
    sEncounters.blendAlpha = gMain.blendAlpha;
    sEncounters.blendBrightness = gMain.blendBrightness;
    sEncounters.blendEnabled = gMain.blendEnabled;
    sEncounters.active = TRUE;
    REG_DISPCNT |= DISPCNT_FORCED_BLANK;
    DmaCopy16(3, VRAM, sEncounters.vram, sizeof(sEncounters.vram));
    DmaCopy16(3, BG_PLTT, sEncounters.palette, sizeof(sEncounters.palette));
    gMain.bgOffsets[0].xOffset = 0;
    gMain.bgOffsets[0].yOffset = 0;
    gMain.blendEnabled = TRUE;
    gMain.blendControl = 0;
    gMain.blendAlpha = 0;
    gMain.blendBrightness = 0;
    m4aSongNumStart(SE_MENU_SELECT);
    RenderEncounters();
}

void Encounters_Update(void)
{
    if (JOY_NEW(B_BUTTON | START_BUTTON))
    {
        REG_DISPCNT |= DISPCNT_FORCED_BLANK;
        DmaCopy16(3, sEncounters.vram, VRAM, sizeof(sEncounters.vram));
        DmaCopy16(3, sEncounters.palette, BG_PLTT, sizeof(sEncounters.palette));
        REG_BG0CNT = sEncounters.bg0cnt;
        gMain.dispcntBackup = sEncounters.dispcnt;
        gMain.bgOffsets[0].xOffset = sEncounters.xOffset;
        gMain.bgOffsets[0].yOffset = sEncounters.yOffset;
        gMain.blendControl = sEncounters.blendControl;
        gMain.blendAlpha = sEncounters.blendAlpha;
        gMain.blendBrightness = sEncounters.blendBrightness;
        gMain.blendEnabled = sEncounters.blendEnabled;
        sEncounters.active = FALSE;
        gMain.newKeys &= ~(B_BUTTON | START_BUTTON);
        m4aSongNumStart(SE_MENU_CANCEL);
    }
    else if (JOY_NEW(L_BUTTON | R_BUTTON))
    {
        if (JOY_NEW(L_BUTTON))
            sEncounters.page = sEncounters.page ? sEncounters.page - 1 : sEncounters.pageCount - 1;
        else
            sEncounters.page = (sEncounters.page + 1) % sEncounters.pageCount;
        m4aSongNumStart(SE_DEX_INFO_FIELD_SELECT_MOVE);
        RenderEncounters();
    }
}

static bool8 IsPauseOam(s16 id)
{
    s16 group, i, count;
    for (group = 0; group < 3; group++)
    {
        count = group == 0 ? 11 : group == 1 ? 2 : 3;
        for (i = 0; i < count; i++)
            if (gMain.spriteGroups[group].oam[i].oamId == id)
                return TRUE;
    }
    return FALSE;
}

void EncountersPause_Begin(void)
{
    s16 pass, id, count = 0, ch, x, y, pixel, offset;
    u16 tiles[128];
    if (gMain.selectedField >= MAIN_FIELD_COUNT || (gMain.modeChangeFlags & MODE_CHANGE_DEBUG))
        return;
    for (pass = 0; pass < 2 && count < 2; pass++)
    {
        for (id = 127; id >= 0 && count < 2; id--)
        {
            if (IsPauseOam(id) || (count && sPauseLabel.ids[0] == id))
                continue;
            if (pass == 0 && gOamBuffer[id].affineMode != ST_OAM_AFFINE_ERASE && gOamBuffer[id].y < 160)
                continue;
            sPauseLabel.ids[count] = id;
            sPauseLabel.oam[count++] = gOamBuffer[id];
        }
    }
    DmaCopy16(3, (void *)0x06017F00, sPauseLabel.tiles, sizeof(sPauseLabel.tiles));
    memset(tiles, 0, sizeof(tiles));
    for (ch = 0; ch < 10; ch++)
        for (y = 0; y < 7; y++)
            for (x = 0; x < 5; x++)
                if (sPauseLetters[ch][y] & (16 >> x))
                {
                    pixel = ch * 6 + x;
                    offset = (pixel / 8) * 32 + y * 4 + (pixel % 8) / 2;
                    tiles[offset / 2] |= 12 << ((pixel % 4) * 4);
                }
    DmaCopy16(3, tiles, (void *)0x06017F00, sizeof(tiles));
    sPauseLabel.active = TRUE;
}

void EncountersPause_End(void)
{
    s16 i;
    if (!sPauseLabel.active)
        return;
    for (i = 0; i < 2; i++)
        gOamBuffer[sPauseLabel.ids[i]] = sPauseLabel.oam[i];
    DmaCopy16(3, sPauseLabel.tiles, (void *)0x06017F00, sizeof(sPauseLabel.tiles));
    sPauseLabel.active = FALSE;
}

void EncountersPause_Draw(void)
{
    s16 i;
    u16 affineParam;
    struct OamData *oam;
    if (!sPauseLabel.active)
        return;
    for (i = 0; i < 2; i++)
    {
        oam = &gOamBuffer[sPauseLabel.ids[i]];
        // OAM matrix words are shared with unrelated affine sprites.
        affineParam = oam->affineParam;
        memset(oam, 0, sizeof(*oam));
        oam->affineParam = affineParam;
        oam->x = 100 + i * 32;
        oam->y = gCurrentPinballGame->pauseAnimTimer >= 24 ? 108 : 160;
        oam->shape = ST_OAM_H_RECTANGLE;
        oam->size = ST_OAM_SIZE_1;
        oam->tileNum = 0x3F8 + i * 4;
        oam->paletteNum = 9;
    }
}
