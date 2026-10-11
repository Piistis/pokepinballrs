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
#define ENCOUNTERS_HEADER_BYTES 0x900
#define PAUSE_LABEL_OBJECTS 6
#define PAUSE_LABEL_TILES ((void *)0x06017E80)

enum { TRANSFER_NONE, TRANSFER_OPEN, TRANSFER_PAGE, TRANSFER_MODE, TRANSFER_CLOSE };

struct EncountersScreen
{
    u16 bgBackup[ENCOUNTERS_BG_BYTES / 2];
    u16 objBackup[(ENCOUNTERS_PORTRAITS * 0x300 + ENCOUNTERS_HEADER_BYTES) / 2];
    u16 paletteBackup[512];
    struct OamData oamBackup[128];
    const u8 *portraits[ENCOUNTERS_PORTRAITS];
    u16 portraitPalettes[ENCOUNTERS_PORTRAITS][16];
    u16 pageTiles[128];
    u16 headerTiles[3][384];
    u16 tilemap[1024];
    u16 species[ENCOUNTERS_EGG_CAPACITY];
    u8 catchArrows[ENCOUNTERS_CAPACITY];
    u16 count, page, pageCount, caughtCount;
    u16 bg0cnt, dispcnt, xOffset, yOffset;
    u16 blendControl, blendAlpha, blendBrightness;
    bool8 blendEnabled;
    bool8 active;
    bool8 eggMode;
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

static const char *const sAreaNames[AREA_COUNT + 1] = {
    "Forest", "Forest", "Plains", "Plains", "Ocean", "Ocean", "Cave", "Cave",
    "Safari Zone", "Volcano", "Lake", "Wilderness", "Ruins", "Ruins", "City", "Ice Cave", "Eggs"
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

static void HeaderPixel(u16 *tiles, s16 x, s16 y, u8 color)
{
    s16 offset, shift;
    u8 *bytes = (u8 *)tiles;
    if (x < 0 || x >= 96 || y < 0 || y >= 16)
        return;
    offset = (x / 32) * 256 + (y / 8) * 128 + ((x % 32) / 8) * 32 + (y % 8) * 4 + (x % 8) / 2;
    shift = (x & 1) * 4;
    bytes[offset] = (bytes[offset] & ~(15 << shift)) | (color << shift);
}

static void PrepareHeaderText(s16 label, const char *text)
{
    s16 i, x, y, dx, dy, pass, cursor, width = 0;
    u16 glyph;
    memset(sEncounters.headerTiles[label], 0, sizeof(sEncounters.headerTiles[label]));
    for (i = 0; text[i]; i++)
        width += sEncountersFontWidths[text[i] - 32];
    // Draw the complete one-pixel outline before the white foreground.
    for (pass = 0; pass < 2; pass++)
    {
        cursor = (88 - width) / 2;
        for (i = 0; text[i]; i++)
        {
            glyph = text[i] - 32;
            for (y = 0; y < 16; y++)
                for (x = 0; x < 8; x++)
                    if (sEncountersFont[glyph * 16 + y] & (1 << x))
                    {
                        if (pass)
                            HeaderPixel(sEncounters.headerTiles[label], cursor + x, y, 2);
                        else
                            for (dy = -1; dy <= 1; dy++)
                                for (dx = -1; dx <= 1; dx++)
                                    HeaderPixel(sEncounters.headerTiles[label], cursor + x + dx, y + dy, 1);
                    }
            cursor += sEncountersFontWidths[glyph];
        }
    }
}

static s16 AppendNumber(char *text, s16 pos, u16 value)
{
    if (value >= 100)
        text[pos++] = '0' + value / 100;
    if (value >= 10)
        text[pos++] = '0' + (value / 10) % 10;
    text[pos++] = '0' + value % 10;
    return pos;
}

static void PrepareHeader(void)
{
    s16 label, i, pos = 0;
    char text[20];
    struct OamData *oam;
    PrepareHeaderText(0, sAreaNames[sEncounters.eggMode ? AREA_COUNT : gCurrentPinballGame->area]);
    pos = AppendNumber(text, pos, sEncounters.caughtCount);
    text[pos++] = '/';
    pos = AppendNumber(text, pos, sEncounters.count);
    text[pos++] = ' ';
    text[pos++] = '(';
    pos = AppendNumber(text, pos, sEncounters.count ? sEncounters.caughtCount * 100 / sEncounters.count : 0);
    text[pos++] = '%';
    text[pos++] = ')';
    text[pos] = 0;
    PrepareHeaderText(1, text);
    memcpy(sEncounters.headerTiles[2], sEncountersModeGuides + (sEncounters.eggMode ? 384 : 0), 0x300);
    for (label = 0; label < 3; label++)
        for (i = 0; i < 3; i++)
        {
            oam = &gOamBuffer[ENCOUNTERS_PORTRAITS * 6 + label * 3 + i];
            memset(oam, 0, sizeof(*oam));
            oam->x = (label == 0 ? 0 : label == 1 ? 144 : 160) + i * 32;
            oam->y = label == 0 ? 24 : label == 1 ? 12 : 36;
            oam->shape = ST_OAM_H_RECTANGLE;
            oam->size = ST_OAM_SIZE_2;
            oam->tileNum = ENCOUNTERS_PORTRAITS * 24 + label * 24 + i * 8;
            oam->paletteNum = 9;
        }
}

static void PreparePage(void)
{
    s16 slot, index, i, row, tx, ty, red;
    u16 species;
    memcpy(sEncounters.pageTiles, sEncountersBgTiles + ENCOUNTERS_PAGE_TILE * 32, sizeof(sEncounters.pageTiles));
    if (sEncounters.page + 1 >= 10)
        PrepareDigit((sEncounters.page + 1) / 10, 2);
    PrepareDigit((sEncounters.page + 1) % 10, 6);
    PrepareDigit(10, 14);
    if (sEncounters.pageCount >= 10)
        PrepareDigit(sEncounters.pageCount / 10, 20);
    PrepareDigit(sEncounters.pageCount % 10, sEncounters.pageCount >= 10 ? 24 : 22);
    memcpy(sEncounters.tilemap, sEncountersTilemap, sizeof(sEncounters.tilemap));
    for (slot = 0; slot < ENCOUNTERS_PER_PAGE; slot++)
    {
        index = sEncounters.page * ENCOUNTERS_PER_PAGE + slot;
        red = !sEncounters.eggMode && index < sEncounters.count && sEncounters.catchArrows[index] == 2;
        tx = (10 + (slot % 4) * 56) / 8;
        ty = (66 + (slot / 4) * 47) / 8;
        for (row = 0; row < 6; row++)
            memcpy(&sEncounters.tilemap[(ty + row) * 32 + tx],
                &sEncountersFrameMaps[(red * ENCOUNTERS_PER_PAGE + slot) * 42 + row * 7], 14);
        sEncounters.portraits[slot + 1] = NULL;
        for (i = 0; i < 6; i++)
            gOamBuffer[(slot + 1) * 6 + i].affineMode = ST_OAM_AFFINE_ERASE;
        if (index < sEncounters.count)
        {
            species = sEncounters.species[index];
            PreparePortrait(slot + 1,
                gMonPortraitGroupGfx[species / 15] + (species % 15) * 0x300,
                gMonPortraitGroupPals[species / 15][species % 15],
                13 + (slot % 4) * 56, 71 + (slot / 4) * 47, IsCaught(species));
        }
    }
}

static void PrepareView(void)
{
    s16 i, area;
    sEncounters.count = sEncounters.eggMode ? GetCurrentEggEncounters(sEncounters.species)
                                          : GetCurrentAreaCatchEncounters(sEncounters.species);
    sEncounters.page = 0;
    sEncounters.caughtCount = 0;
    for (i = 0; i < sEncounters.count; i++)
    {
        if (IsCaught(sEncounters.species[i]))
            sEncounters.caughtCount++;
        if (!sEncounters.eggMode)
            sEncounters.catchArrows[i] = GetCurrentAreaCatchArrows(sEncounters.species[i]);
    }
    sEncounters.pageCount = (sEncounters.count + ENCOUNTERS_PER_PAGE - 1) / ENCOUNTERS_PER_PAGE;
    if (!sEncounters.pageCount)
        sEncounters.pageCount = 1;
    if (sEncounters.eggMode)
        PreparePortrait(0, (const u8 *)sEncountersEggTiles, sEncountersEggPalette, 96, 18, TRUE);
    else
    {
        area = gAreaPortraitIndexes[gCurrentPinballGame->area];
        PreparePortrait(0, gLocationPortraitGfx[area], &gLocation_Pals[area * 16], 96, 18, TRUE);
    }
    PrepareHeader();
    PreparePage();
}

void Encounters_Open(void)
{
    s16 i;
    if (sEncounters.active || gMain.selectedField >= MAIN_FIELD_COUNT
     || gCurrentPinballGame->area >= AREA_COUNT || !(gMain.modeChangeFlags & MODE_CHANGE_PAUSE))
        return;
    sEncounters.eggMode = FALSE;
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
    PrepareView();
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
    else if (JOY_NEW(SELECT_BUTTON))
    {
        sEncounters.eggMode = !sEncounters.eggMode;
        PrepareView();
        sEncounters.transfer = TRANSFER_MODE;
        gMain.newKeys &= ~SELECT_BUTTON;
        m4aSongNumStart(SE_MENU_SELECT);
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
            DmaCopy16(3, sEncountersPalette, BG_PLTT, sizeof(sEncountersPalette));
            REG_BG0CNT = BGCNT_SCREENBASE(8) | BGCNT_256COLOR | BGCNT_TXT256x256;
            gMain.dispcntBackup = DISPCNT_MODE_0 | DISPCNT_BG0_ON | DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP;
            gMain.bgOffsets[0].xOffset = 0;
            gMain.bgOffsets[0].yOffset = 0;
            gMain.blendEnabled = TRUE;
            gMain.blendControl = 0;
            gMain.blendAlpha = 0;
            gMain.blendBrightness = 0;
        }
        if (sEncounters.transfer != TRANSFER_PAGE)
        {
            DmaCopy16(3, sEncounters.headerTiles, (u8 *)OBJ_VRAM0 + ENCOUNTERS_PORTRAITS * 0x300, ENCOUNTERS_HEADER_BYTES);
            DmaCopy16(3, sEncountersHeaderPalette, (u16 *)OBJ_PLTT + 9 * 16, 32);
            DmaCopy16(3, &sEncounters.portraitPalettes[0][0], (u16 *)BG_PLTT + 32, 2);
        }
        for (slot = sEncounters.transfer == TRANSFER_PAGE ? 1 : 0; slot < ENCOUNTERS_PORTRAITS; slot++)
        {
            if (sEncounters.portraits[slot])
            {
                DmaCopy16(3, sEncounters.portraits[slot], (u8 *)OBJ_VRAM0 + slot * 0x300, 0x300);
                DmaCopy16(3, sEncounters.portraitPalettes[slot], (u16 *)OBJ_PLTT + slot * 16, 32);
            }
        }
        DmaCopy16(3, sEncounters.pageTiles, (u8 *)VRAM + ENCOUNTERS_PAGE_TILE * 64, sizeof(sEncounters.pageTiles));
        DmaCopy16(3, sEncounters.tilemap, BG_SCREEN_ADDR(8), sizeof(sEncounters.tilemap));
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
