#include "global.h"
#include "main.h"
#include "m4a.h"
#include "constants/bg_music.h"
#include "constants/generations.h"

enum GenerationSelectState
{
    GENERATION_SELECT_STATE_LOAD,
    GENERATION_SELECT_STATE_INPUT,
    GENERATION_SELECT_STATE_EXIT,
};

EWRAM_DATA u8 gSelectedGeneration = DEFAULT_GENERATION;
static EWRAM_DATA u8 sGenerationCursor = DEFAULT_GENERATION;
static EWRAM_DATA u8 sGenerationNextMainState = STATE_FIELD_SELECT;

static void LoadGenerationSelectGraphics(void);
static void LoadGenerationSelectBackground(void);
static void HandleGenerationSelectInput(void);
static void ExitGenerationSelect(void);
static void RenderGenerationSelectScreen(void);
static void DrawGenerationSelectText(void);
static void DrawGenerationCell(s16 generation, s16 selected);
static void DrawRandomCell(s16 selected);
static bool8 IsGenerationOptionDisabled(u8 generation);
static void LoadGenerationSelectFont(void);
static void DrawGenerationString(const u8 *text, s16 y, s16 x);
static void DrawGenerationChar(u8 ch, s16 y, s16 x);
static const u8 *GetGenerationGlyph(u8 ch);
static bool8 GetGenerationGlyphPixel(const u8 *glyph, s16 row, s16 pixel, s16 yOffset);

extern const u8 gGenerationSelectBackground_Gfx[];
extern const u16 gGenerationSelectBackground_Pals[];

static const u8 sDisabledGenerationOptions[] = {
    GENERATION_5,
    GENERATION_6,
    GENERATION_7,
    GENERATION_8,
    GENERATION_9,
    GENERATION_10,
};

void GenerationSelectMain(void)
{
    switch (gMain.subState)
    {
    case GENERATION_SELECT_STATE_LOAD:
        LoadGenerationSelectGraphics();
        break;
    case GENERATION_SELECT_STATE_INPUT:
        HandleGenerationSelectInput();
        break;
    default:
        ExitGenerationSelect();
        break;
    }
}

static void LoadGenerationSelectGraphics(void)
{
    ResetDisplayState();

    REG_DISPCNT = DISPCNT_MODE_0 | DISPCNT_FORCED_BLANK;
    REG_BG0CNT = BGCNT_CHARBASE(1) | BGCNT_SCREENBASE(0) | BGCNT_PRIORITY(0) | BGCNT_TXT256x256;
    REG_BG1CNT = BGCNT_CHARBASE(2) | BGCNT_SCREENBASE(1) | BGCNT_PRIORITY(1) | BGCNT_TXT256x256;
    REG_DISPCNT |= DISPCNT_BG0_ON | DISPCNT_BG1_ON;
    gMain.dispcntBackup = REG_DISPCNT;

    LoadGenerationSelectBackground();
    ((u16 *)PLTT)[0xF1] = 0x7FFF;
    ((u16 *)PLTT)[0xF2] = 0x0000;
    ((u16 *)PLTT)[0xF3] = 0x03FF;
    LoadGenerationSelectFont();

    if (gSelectedGeneration >= GENERATION_SELECT_OPTION_COUNT)
        sGenerationCursor = DEFAULT_GENERATION;
    else
        sGenerationCursor = gSelectedGeneration;
    sGenerationNextMainState = STATE_FIELD_SELECT;
    DrawGenerationSelectText();
    RenderGenerationSelectScreen();
    EnableVBlankInterrupts();
    FadeInScreen();
    m4aSongNumStart(MUS_TABLE_SELECT);
    gMain.subState = GENERATION_SELECT_STATE_INPUT;
}

static void LoadGenerationSelectBackground(void)
{
    s16 y;
    s16 x;
    u16 *tilemap = (u16 *)BG_SCREEN_ADDR(1);

    DmaCopy16(3, gGenerationSelectBackground_Pals, (void *)PLTT, 0x20);
    DmaCopy16(3, gGenerationSelectBackground_Gfx, (void *)BG_CHAR_ADDR(2), 0x4B00);

    for (y = 0; y < 20; y++)
    {
        for (x = 0; x < 30; x++)
            tilemap[y * 32 + x] = y * 30 + x;

        tilemap[y * 32 + 30] = 0;
        tilemap[y * 32 + 31] = 0;
    }
}

static void HandleGenerationSelectInput(void)
{
    if (JOY_NEW(DPAD_LEFT) && sGenerationCursor > 0)
    {
        sGenerationCursor--;
        m4aSongNumStart(SE_DEX_INFO_FIELD_SELECT_MOVE);
        DrawGenerationSelectText();
        RenderGenerationSelectScreen();
    }
    else if (JOY_NEW(DPAD_RIGHT) && sGenerationCursor < GENERATION_SELECT_OPTION_COUNT - 1)
    {
        sGenerationCursor++;
        m4aSongNumStart(SE_DEX_INFO_FIELD_SELECT_MOVE);
        DrawGenerationSelectText();
        RenderGenerationSelectScreen();
    }
    else if (JOY_NEW(DPAD_UP) && sGenerationCursor == GENERATION_RANDOM)
    {
        sGenerationCursor = GENERATION_8;
        m4aSongNumStart(SE_DEX_INFO_FIELD_SELECT_MOVE);
        DrawGenerationSelectText();
        RenderGenerationSelectScreen();
    }
    else if (JOY_NEW(DPAD_UP) && sGenerationCursor >= 5)
    {
        sGenerationCursor -= 5;
        m4aSongNumStart(SE_DEX_INFO_FIELD_SELECT_MOVE);
        DrawGenerationSelectText();
        RenderGenerationSelectScreen();
    }
    else if (JOY_NEW(DPAD_DOWN) && sGenerationCursor < 5)
    {
        sGenerationCursor += 5;
        m4aSongNumStart(SE_DEX_INFO_FIELD_SELECT_MOVE);
        DrawGenerationSelectText();
        RenderGenerationSelectScreen();
    }
    else if (JOY_NEW(DPAD_DOWN) && sGenerationCursor < GENERATION_COUNT)
    {
        sGenerationCursor = GENERATION_RANDOM;
        m4aSongNumStart(SE_DEX_INFO_FIELD_SELECT_MOVE);
        DrawGenerationSelectText();
        RenderGenerationSelectScreen();
    }

    if (JOY_NEW(A_BUTTON | START_BUTTON))
    {
        if (IsGenerationOptionDisabled(sGenerationCursor))
        {
            m4aSongNumStart(SE_FAILURE);
        }
        else
        {
            gSelectedGeneration = sGenerationCursor;
            sGenerationNextMainState = STATE_FIELD_SELECT;
            m4aSongNumStart(SE_MENU_SELECT);
            gMain.subState = GENERATION_SELECT_STATE_EXIT;
        }
    }
    else if (JOY_NEW(B_BUTTON))
    {
        sGenerationNextMainState = STATE_TITLE;
        m4aSongNumStart(SE_MENU_CANCEL);
        gMain.subState = GENERATION_SELECT_STATE_EXIT;
    }
}

static void ExitGenerationSelect(void)
{
    FadeOutScreen();
    m4aMPlayAllStop();
    DisableVBlankInterrupts();
    SetMainGameState(sGenerationNextMainState);
}

static void RenderGenerationSelectScreen(void)
{
    DmaCopy16(3, gBG0TilemapBuffer, (void *)VRAM, 0x800);
}

static void DrawGenerationSelectText(void)
{
    s16 i;

    DmaFill16(3, 0, gBG0TilemapBuffer, 0x800);
    DrawGenerationString((u8 *)"SELECT GENERATION", 2, 7);
    DrawGenerationString((u8 *)"A OK   B BACK", 16, 8);

    for (i = 0; i < GENERATION_COUNT; i++)
        DrawGenerationCell(i, i == sGenerationCursor);

    DrawRandomCell(sGenerationCursor == GENERATION_RANDOM);
}

static void DrawGenerationCell(s16 generation, s16 selected)
{
    s16 row = generation / 5;
    s16 col = generation % 5;
    s16 y = 6 + row * 4;
    s16 x = 4 + col * 5;
    u8 text[5];

    text[0] = selected ? '[' : ' ';
    text[1] = 'G';
    if (generation == GENERATION_10)
    {
        text[2] = 'X';
    }
    else
    {
        text[2] = '1' + generation;
    }
    text[3] = selected ? ']' : ' ';
    text[4] = '\0';
    DrawGenerationString(text, y, x);
}

static void DrawRandomCell(s16 selected)
{
    u8 text[9];

    text[0] = selected ? '[' : ' ';
    text[1] = 'R';
    text[2] = 'A';
    text[3] = 'N';
    text[4] = 'D';
    text[5] = 'O';
    text[6] = 'M';
    text[7] = selected ? ']' : ' ';
    text[8] = '\0';

    DrawGenerationString(text, 13, 11);
}

static bool8 IsGenerationOptionDisabled(u8 generation)
{
    s16 i;

    for (i = 0; i < sizeof(sDisabledGenerationOptions); i++)
    {
        if (sDisabledGenerationOptions[i] == generation)
            return TRUE;
    }

    return FALSE;
}

static void LoadGenerationSelectFont(void)
{
    s16 tile;
    s16 row;
    u32 *dest = (u32 *)BG_CHAR_ADDR(1);

    for (tile = 0; tile < 0x60; tile++)
    {
        const u8 *glyph = GetGenerationGlyph(tile + 32);
        for (row = 0; row < 16; row++)
        {
            u32 packed = 0;
            s16 pixel;

            for (pixel = 0; pixel < 8; pixel++)
            {
                s16 outline;
                s16 neighborRow;
                s16 neighborPixel;
                u8 color = 0;

                if (GetGenerationGlyphPixel(glyph, row, pixel, 3))
                {
                    color = 1;
                }
                else
                {
                    outline = 0;
                    for (neighborRow = row - 1; neighborRow <= row + 1; neighborRow++)
                    {
                        if (neighborRow < 0 || neighborRow >= 16)
                            continue;

                        for (neighborPixel = pixel - 1; neighborPixel <= pixel + 1; neighborPixel++)
                        {
                            if (neighborPixel < 0 || neighborPixel >= 8)
                                continue;

                            if (GetGenerationGlyphPixel(glyph, neighborRow, neighborPixel, 3))
                                outline = 1;
                        }
                    }

                    if (outline)
                        color = 2;
                }

                packed |= color << (pixel * 4);
            }
            *dest++ = packed;
        }
    }
}

static bool8 GetGenerationGlyphPixel(const u8 *glyph, s16 row, s16 pixel, s16 yOffset)
{
    row -= yOffset;

    if (row < 0 || row >= 8)
        return FALSE;

    return glyph[row] & (0x80 >> pixel);
}

static void DrawGenerationString(const u8 *text, s16 y, s16 x)
{
    while (*text)
    {
        DrawGenerationChar(*text, y, x);
        text++;
        x++;
    }
}

static void DrawGenerationChar(u8 ch, s16 y, s16 x)
{
    if (ch < 32 || ch >= 32 + 0x60)
        ch = ' ';
    gBG0TilemapBuffer[y * 32 + x] = ((ch - 32) * 2) | (0xF << 12);
    gBG0TilemapBuffer[(y + 1) * 32 + x] = ((ch - 32) * 2 + 1) | (0xF << 12);
}

static const u8 *GetGenerationGlyph(u8 ch)
{
    static const u8 blank[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    static const u8 a[8] = {0x38, 0x44, 0x44, 0x7C, 0x44, 0x44, 0x44, 0};
    static const u8 b[8] = {0x78, 0x44, 0x44, 0x78, 0x44, 0x44, 0x78, 0};
    static const u8 c[8] = {0x38, 0x44, 0x40, 0x40, 0x40, 0x44, 0x38, 0};
    static const u8 d[8] = {0x78, 0x44, 0x44, 0x44, 0x44, 0x44, 0x78, 0};
    static const u8 e[8] = {0x7C, 0x40, 0x40, 0x78, 0x40, 0x40, 0x7C, 0};
    static const u8 g[8] = {0x38, 0x44, 0x40, 0x5C, 0x44, 0x44, 0x38, 0};
    static const u8 i[8] = {0x38, 0x10, 0x10, 0x10, 0x10, 0x10, 0x38, 0};
    static const u8 k[8] = {0x44, 0x48, 0x50, 0x60, 0x50, 0x48, 0x44, 0};
    static const u8 l[8] = {0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x7C, 0};
    static const u8 m[8] = {0x44, 0x6C, 0x54, 0x54, 0x44, 0x44, 0x44, 0};
    static const u8 n[8] = {0x44, 0x64, 0x54, 0x54, 0x4C, 0x44, 0x44, 0};
    static const u8 o[8] = {0x38, 0x44, 0x44, 0x44, 0x44, 0x44, 0x38, 0};
    static const u8 r[8] = {0x78, 0x44, 0x44, 0x78, 0x50, 0x48, 0x44, 0};
    static const u8 s[8] = {0x3C, 0x40, 0x40, 0x38, 0x04, 0x04, 0x78, 0};
    static const u8 t[8] = {0x7C, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0};
    static const u8 x[8] = {0x44, 0x44, 0x28, 0x10, 0x28, 0x44, 0x44, 0};
    static const u8 d0[8] = {0x38, 0x44, 0x4C, 0x54, 0x64, 0x44, 0x38, 0};
    static const u8 d1[8] = {0x10, 0x30, 0x10, 0x10, 0x10, 0x10, 0x38, 0};
    static const u8 d2[8] = {0x38, 0x44, 0x04, 0x18, 0x20, 0x40, 0x7C, 0};
    static const u8 d3[8] = {0x38, 0x44, 0x04, 0x18, 0x04, 0x44, 0x38, 0};
    static const u8 d4[8] = {0x08, 0x18, 0x28, 0x48, 0x7C, 0x08, 0x08, 0};
    static const u8 d5[8] = {0x7C, 0x40, 0x78, 0x04, 0x04, 0x44, 0x38, 0};
    static const u8 d6[8] = {0x38, 0x40, 0x40, 0x78, 0x44, 0x44, 0x38, 0};
    static const u8 d7[8] = {0x7C, 0x04, 0x08, 0x10, 0x20, 0x20, 0x20, 0};
    static const u8 d8[8] = {0x38, 0x44, 0x44, 0x38, 0x44, 0x44, 0x38, 0};
    static const u8 d9[8] = {0x38, 0x44, 0x44, 0x3C, 0x04, 0x04, 0x38, 0};
    static const u8 open[8] = {0x3C, 0x20, 0x20, 0x20, 0x20, 0x20, 0x3C, 0};
    static const u8 close[8] = {0x3C, 0x04, 0x04, 0x04, 0x04, 0x04, 0x3C, 0};

    switch (ch)
    {
    case 'A': return a;
    case 'B': return b;
    case 'C': return c;
    case 'D': return d;
    case 'E': return e;
    case 'G': return g;
    case 'I': return i;
    case 'K': return k;
    case 'L': return l;
    case 'M': return m;
    case 'N': return n;
    case 'O': return o;
    case 'R': return r;
    case 'S': return s;
    case 'T': return t;
    case 'X': return x;
    case '0': return d0;
    case '1': return d1;
    case '2': return d2;
    case '3': return d3;
    case '4': return d4;
    case '5': return d5;
    case '6': return d6;
    case '7': return d7;
    case '8': return d8;
    case '9': return d9;
    case '[': return open;
    case ']': return close;
    default: return blank;
    }
}
