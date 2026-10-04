#include "global.h"
#include "main.h"
#include "m4a.h"
#include "encounters.h"
#include "constants/bg_music.h"

#include "data/encounters_assets.h"

extern const u16 gLocation_Pals[];
extern const s16 gAreaPortraitIndexes[];

#define ENCOUNTERS_BG_BYTES 0x4800
#define ENCOUNTERS_PORTRAITS (ENCOUNTERS_PER_PAGE + 1)
#define PAUSE_LABEL_OBJECTS 6
#define PAUSE_LABEL_TILES ((void *)0x06017E80)

enum { TRANSFER_NONE, TRANSFER_OPEN, TRANSFER_PAGE, TRANSFER_CLOSE };

struct EncountersScreen
{
    u16 bgBackup[ENCOUNTERS_BG_BYTES / 2];
    u16 objBackup[ENCOUNTERS_PORTRAITS * 0x300 / 2];
    u16 paletteBackup[512];
    struct OamData oamBackup[128];
    const u8 *portraits[ENCOUNTERS_PORTRAITS];
    u16 portraitPalettes[ENCOUNTERS_PORTRAITS][16];
    u16 pageTiles[128];
    u16 species[ENCOUNTERS_CAPACITY];
    u16 count, page, pageCount;
    u16 bg0cnt, dispcnt, xOffset, yOffset;
    u16 blendControl, blendAlpha, blendBrightness;
    bool8 blendEnabled;
    bool8 active;
    u8 transfer;
};

static EWRAM_DATA struct EncountersScreen sEncounters = {0};
static EWRAM_DATA struct
{
    u16 tiles[192];
    struct OamData oam[PAUSE_LABEL_OBJECTS];
    u16 ids[PAUSE_LABEL_OBJECTS];
    bool8 active;
} sPauseLabel = {0};

static const u8 sDigits[11][5] = {
    {7,5,5,5,7}, {2,6,2,2,7}, {7,1,7,4,7}, {7,1,7,1,7},
    {5,5,7,1,1}, {7,4,7,1,7}, {7,4,7,5,7}, {7,1,1,1,1},
    {7,5,7,5,7}, {7,5,7,1,7}, {1,1,2,4,4}
};

bool8 Encounters_IsOpen(void)
{
    return sEncounters.active;
}

static bool8 IsCaught(u16 species)
{
    if (species >= NUM_SPECIES)
        return FALSE;
    if (species >= NUM_SAVE_SPECIES)
        return gExtraPokedexFlags[species - NUM_SAVE_SPECIES] == SPECIES_CAUGHT;
    return gMain_saveData.pokedexFlags[species] == SPECIES_CAUGHT;
}

static void PreparePortrait(s16 slot, const u8 *tiles, const u16 *palette, s16 x, s16 y, bool8 caught)
{
    s16 i;
    struct OamData *oam;
    sEncounters.portraits[slot] = tiles;
    for (i = 0; i < 16; i++)
        sEncounters.portraitPalettes[slot][i] = caught ? palette[i] : (i == 15 ? 0x7FFF : 0);
    // The build uses -mwidth 2 -mheight 2: six native 16x16 OBJ blocks.
    for (i = 0; i < 6; i++)
    {
        oam = &gOamBuffer[slot * 6 + i];
        memset(oam, 0, sizeof(*oam));
        oam->x = x + (i % 3) * 16;
        oam->y = y + (i / 3) * 16;
        oam->size = ST_OAM_SIZE_1;
        oam->tileNum = slot * 24 + i * 4;
        oam->paletteNum = slot;
    }
}

static void PrepareDigit(s16 digit, s16 x)
{
    s16 y, col, pixel;
    u8 *tiles = (u8 *)sEncounters.pageTiles;
    for (y = 0; y < 5; y++)
        for (col = 0; col < 3; col++)
            if (sDigits[digit][y] & (4 >> col))
            {
                pixel = x + col;
                tiles[(pixel / 8) * 64 + y * 8 + pixel % 8] = 1;
            }
}

static void PreparePage(void)
{
    s16 slot, index, i;
    u16 species;
    memcpy(sEncounters.pageTiles, sEncountersBgTiles + ENCOUNTERS_PAGE_TILE * 32, sizeof(sEncounters.pageTiles));
    PrepareDigit(sEncounters.page + 1, 6);
    PrepareDigit(10, 14);
    PrepareDigit(sEncounters.pageCount, 22);
    for (slot = 0; slot < ENCOUNTERS_PER_PAGE; slot++)
    {
        index = sEncounters.page * ENCOUNTERS_PER_PAGE + slot;
        sEncounters.portraits[slot + 1] = NULL;
        for (i = 0; i < 6; i++)
            gOamBuffer[(slot + 1) * 6 + i].affineMode = ST_OAM_AFFINE_ERASE;
        if (index < sEncounters.count)
        {
            species = sEncounters.species[index];
            PreparePortrait(slot + 1,
                gMonPortraitGroupGfx[species / 15] + (species % 15) * 0x300,
                gMonPortraitGroupPals[species / 15][species % 15],
                13 + (slot % 4) * 56, 70 + (slot / 4) * 47, IsCaught(species));
        }
    }
}

void Encounters_Open(void)
{
    s16 i, area;
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
    // Read-only snapshots do not require blanking the visible paused board.
    DmaCopy16(3, VRAM, sEncounters.bgBackup, sizeof(sEncounters.bgBackup));
    DmaCopy16(3, OBJ_VRAM0, sEncounters.objBackup, sizeof(sEncounters.objBackup));
    DmaCopy16(3, BG_PLTT, sEncounters.paletteBackup, sizeof(sEncounters.paletteBackup));
    memcpy(sEncounters.oamBackup, gOamBuffer, sizeof(sEncounters.oamBackup));
    memset(gOamBuffer, 0, sizeof(sEncounters.oamBackup));
    for (i = 0; i < 128; i++)
        gOamBuffer[i].affineMode = ST_OAM_AFFINE_ERASE;
    area = gAreaPortraitIndexes[gCurrentPinballGame->area];
    PreparePortrait(0, gLocationPortraitGfx[area], &gLocation_Pals[area * 16], 96, 17, TRUE);
    PreparePage();
    sEncounters.active = TRUE;
    sEncounters.transfer = TRANSFER_OPEN;
    m4aSongNumStart(SE_MENU_SELECT);
}

void Encounters_Update(void)
{
    if (sEncounters.transfer != TRANSFER_NONE)
        return;
    if (JOY_NEW(B_BUTTON | START_BUTTON))
    {
        sEncounters.transfer = TRANSFER_CLOSE;
        gMain.newKeys &= ~(B_BUTTON | START_BUTTON);
        m4aSongNumStart(SE_MENU_CANCEL);
    }
    else if (JOY_NEW(L_BUTTON | R_BUTTON) && sEncounters.pageCount > 1)
    {
        if (JOY_NEW(L_BUTTON))
            sEncounters.page = sEncounters.page ? sEncounters.page - 1 : sEncounters.pageCount - 1;
        else
            sEncounters.page = (sEncounters.page + 1) % sEncounters.pageCount;
        PreparePage();
        sEncounters.transfer = TRANSFER_PAGE;
        m4aSongNumStart(SE_DEX_INFO_FIELD_SELECT_MOVE);
    }
}

// Called after VBlankIntrWait, before the common OAM/register upload.
void Encounters_VBlank(void)
{
    s16 slot;
    if (sEncounters.transfer == TRANSFER_NONE)
        return;
    if (sEncounters.transfer == TRANSFER_CLOSE)
    {
        DmaCopy16(3, sEncounters.bgBackup, VRAM, sizeof(sEncounters.bgBackup));
        DmaCopy16(3, sEncounters.objBackup, OBJ_VRAM0, sizeof(sEncounters.objBackup));
        DmaCopy16(3, sEncounters.paletteBackup, BG_PLTT, sizeof(sEncounters.paletteBackup));
        memcpy(gOamBuffer, sEncounters.oamBackup, sizeof(sEncounters.oamBackup));
        REG_BG0CNT = sEncounters.bg0cnt;
        gMain.dispcntBackup = sEncounters.dispcnt;
        gMain.bgOffsets[0].xOffset = sEncounters.xOffset;
        gMain.bgOffsets[0].yOffset = sEncounters.yOffset;
        gMain.blendControl = sEncounters.blendControl;
        gMain.blendAlpha = sEncounters.blendAlpha;
        gMain.blendBrightness = sEncounters.blendBrightness;
        gMain.blendEnabled = sEncounters.blendEnabled;
        sEncounters.active = FALSE;
    }
    else
    {
        if (sEncounters.transfer == TRANSFER_OPEN)
        {
            DmaCopy16(3, sEncountersBgTiles, VRAM, sizeof(sEncountersBgTiles));
            DmaCopy16(3, sEncountersTilemap, BG_SCREEN_ADDR(8), sizeof(sEncountersTilemap));
            DmaCopy16(3, sEncountersPalette, BG_PLTT, sizeof(sEncountersPalette));
            ((vu16 *)BG_PLTT)[32] = sEncounters.portraitPalettes[0][0];
            REG_BG0CNT = BGCNT_SCREENBASE(8) | BGCNT_256COLOR | BGCNT_TXT256x256;
            gMain.dispcntBackup = DISPCNT_MODE_0 | DISPCNT_BG0_ON | DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP;
            gMain.bgOffsets[0].xOffset = 0;
            gMain.bgOffsets[0].yOffset = 0;
            gMain.blendEnabled = TRUE;
            gMain.blendControl = 0;
            gMain.blendAlpha = 0;
            gMain.blendBrightness = 0;
        }
        for (slot = sEncounters.transfer == TRANSFER_OPEN ? 0 : 1; slot < ENCOUNTERS_PORTRAITS; slot++)
        {
            if (sEncounters.portraits[slot])
            {
                DmaCopy16(3, sEncounters.portraits[slot], (u8 *)OBJ_VRAM0 + slot * 0x300, 0x300);
                DmaCopy16(3, sEncounters.portraitPalettes[slot], (u16 *)OBJ_PLTT + slot * 16, 32);
            }
        }
        DmaCopy16(3, sEncounters.pageTiles, (u8 *)VRAM + ENCOUNTERS_PAGE_TILE * 64, sizeof(sEncounters.pageTiles));
    }
    sEncounters.transfer = TRANSFER_NONE;
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
    s16 pass, id, i, count = 0;
    if (sPauseLabel.active || gMain.selectedField >= MAIN_FIELD_COUNT || (gMain.modeChangeFlags & MODE_CHANGE_DEBUG))
        return;
    for (pass = 0; pass < 2 && count < PAUSE_LABEL_OBJECTS; pass++)
    {
        for (id = 127; id >= 0 && count < PAUSE_LABEL_OBJECTS; id--)
        {
            if (IsPauseOam(id))
                continue;
            for (i = 0; i < count && sPauseLabel.ids[i] != id; i++);
            if (i != count)
                continue;
            if (pass == 0 && gOamBuffer[id].affineMode != ST_OAM_AFFINE_ERASE && gOamBuffer[id].y < 160)
                continue;
            sPauseLabel.ids[count] = id;
            sPauseLabel.oam[count++] = gOamBuffer[id];
        }
    }
    DmaCopy16(3, PAUSE_LABEL_TILES, sPauseLabel.tiles, sizeof(sPauseLabel.tiles));
    DmaCopy16(3, sEncountersWord, PAUSE_LABEL_TILES, sizeof(sEncountersWord));
    sPauseLabel.active = TRUE;
}

void EncountersPause_End(void)
{
    s16 i;
    if (!sPauseLabel.active)
        return;
    for (i = 0; i < PAUSE_LABEL_OBJECTS; i++)
        gOamBuffer[sPauseLabel.ids[i]] = sPauseLabel.oam[i];
    DmaCopy16(3, sPauseLabel.tiles, PAUSE_LABEL_TILES, sizeof(sPauseLabel.tiles));
    sPauseLabel.active = FALSE;
}

void EncountersPause_Draw(void)
{
    s16 i, x, y;
    u16 affineParam;
    struct OamData *oam, *anchor;
    if (!sPauseLabel.active)
        return;
    anchor = &gOamBuffer[gMain.spriteGroups[SG_PAUSE_PANEL].oam[1].oamId];
    // SAVE uses a double-size affine 8x8 glyph: its visible origin is +4,+4.
    x = (anchor->x + 4) & 511;
    y = (anchor->y + 4 + 24) & 255;
    for (i = 0; i < PAUSE_LABEL_OBJECTS; i++)
    {
        oam = &gOamBuffer[sPauseLabel.ids[i]];
        affineParam = oam->affineParam;
        if (i < 3)
        {
            memset(oam, 0, sizeof(*oam));
            oam->x = x + i * 32;
            oam->y = y;
            oam->shape = ST_OAM_H_RECTANGLE;
            oam->size = ST_OAM_SIZE_1;
            oam->tileNum = 0x3F4 + i * 4;
            oam->paletteNum = 9;
        }
        else if (i == 3)
        {
            anchor = &gOamBuffer[gMain.spriteGroups[SG_PAUSE_TOP_BORDER].oam[1].oamId];
            *oam = *anchor;
            oam->x = (anchor->x + 32) & 511;
        }
        else
        {
            anchor = &gOamBuffer[gMain.spriteGroups[SG_PAUSE_BOTTOM_BORDER].oam[2].oamId];
            *oam = *anchor;
            oam->x = (anchor->x + (i - 3) * 32) & 511;
        }
        oam->affineParam = affineParam;
        if (gCurrentPinballGame->pauseAnimTimer < 24)
            oam->affineMode = ST_OAM_AFFINE_ERASE;
    }
}
