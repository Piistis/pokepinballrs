#include "global.h"
#include "main.h"
#include "shiny.h"
#include "pokedex_view.h"
#include "data/pokedex_view_assets.h"

static EWRAM_DATA struct
{
    u16 species[NUM_SPECIES];
    u16 labels[2][384];
    u16 count, total;
    u8 generation;
    bool8 shiny, initialized;
} sDexView = {0};

bool8 PokedexView_IsInitialized(void) { return sDexView.initialized; }
bool8 PokedexView_IsShiny(void) { return sDexView.shiny; }
u16 PokedexView_Count(void) { return sDexView.count; }

u16 PokedexView_Species(s16 position)
{
    if (position < 0) position = 0;
    return position < sDexView.count ? sDexView.species[position] : SPECIES_NONE;
}

static void DexControlPixel(u16 *tiles, s16 x, s16 y, u8 color)
{
    s16 offset, shift;
    u8 *bytes = (u8 *)tiles;
    if (x < 0 || x >= 96 || y < 0 || y >= 16) return;
    offset = (x/32)*256 + (y/8)*128 + ((x%32)/8)*32 + (y%8)*4 + (x%8)/2;
    shift = (x & 1)*4;
    bytes[offset] = (bytes[offset] & ~(15 << shift)) | (color << shift);
}

static void DexControlText(u16 *tiles, const char *text)
{
    s16 i, x, y, dx, dy, pass, cursor, width = 0;
    u16 glyph;
    memset(tiles, 0, 0x300);
    for (i = 0; text[i]; i++) width += sDexControlWidths[text[i]-32];
    for (pass = 0; pass < 2; pass++)
    {
        cursor = (96-width)/2;
        for (i = 0; text[i]; i++)
        {
            glyph = text[i]-32;
            for (y = 0; y < 16; y++)
                for (x = 0; x < 8; x++)
                    if (sDexControlFont[glyph*16+y] & (1 << x))
                    {
                        if (pass) DexControlPixel(tiles, cursor+x, y, 2);
                        else for (dy = -1; dy <= 1; dy++) for (dx = -1; dx <= 1; dx++)
                            DexControlPixel(tiles, cursor+x+dx, y+dy, 1);
                    }
            cursor += sDexControlWidths[glyph];
        }
    }
}

static void DexControlLabels(void)
{
    char generation[] = "Gen 1";
    generation[4] += sDexView.generation;
    DexControlText(sDexView.labels[0], generation);
    DexControlText(sDexView.labels[1], sDexView.shiny ? "START Normal" : "START Shiny");
    DmaCopy16(3, sDexView.labels, (u8 *)OBJ_VRAM0 + 0x7800, sizeof(sDexView.labels));
    DmaCopy16(3, sDexControlButtons, (u8 *)OBJ_VRAM0 + 0x7E00, sizeof(sDexControlButtons));
    DmaCopy16(3, sDexControlPalette, OBJ_PLTT_SLOT(15), PLTT_SLOT_SIZE);
}

static void BuildDexView(void)
{
    u16 position, species;
    sDexView.count = 0;
    for (position = 0; position < sDexView.total; position++)
    {
        species = PokedexListPositionToSpecies(position);
        if (Shiny_GetGeneration(species) == sDexView.generation)
            sDexView.species[sDexView.count++] = species;
    }
    DexControlLabels();
}

void PokedexView_Init(u16 total)
{
    memset(&sDexView, 0, sizeof(sDexView));
    sDexView.total = total;
    sDexView.initialized = TRUE;
    BuildDexView();
}

bool8 PokedexView_MoveGeneration(s16 direction)
{
    s16 step;
    u8 previous = sDexView.generation;
    for (step = 0; step < 9; step++)
    {
        sDexView.generation = (sDexView.generation + (direction < 0 ? 8 : 1)) % 9;
        BuildDexView();
        if (sDexView.count) return previous != sDexView.generation;
    }
    return FALSE;
}

void PokedexView_ToggleShiny(void)
{
    sDexView.shiny = !sDexView.shiny;
    DexControlLabels();
}

void PokedexView_ApplyTheme(void)
{
    DmaCopy16(3, sDexGenerationPalettes[sDexView.generation], BG_PLTT, BG_PLTT_SIZE);
}

void PokedexView_UpdateTotals(void)
{
    u16 i, species, flag;
    gPokedexNumOwned = gPokedexNumSeen = 0;
    for (i = 0; i < sDexView.count; i++)
    {
        species = sDexView.species[i];
        flag = sDexView.shiny ? Shiny_GetPokedexFlag(species)
             : species < NUM_SAVE_SPECIES ? gMain_saveData.pokedexFlags[species]
             : gExtraPokedexFlags[species - NUM_SAVE_SPECIES];
        if (flag == SPECIES_CAUGHT) gPokedexNumOwned++;
        if (flag == SPECIES_CAUGHT || flag == SPECIES_SEEN || flag == SPECIES_SHARED_AND_SEEN) gPokedexNumSeen++;
    }
    gPokedexShowCompletionBadge = sDexView.count && gPokedexNumOwned == sDexView.count;
}

void PokedexView_Draw(bool8 visible)
{
    s16 object, id = 127, label, piece;
    u16 affine;
    struct OamData *oam;
    if (!visible) return;
    for (object = 0; object < 8; object++)
    {
        while (id >= 0 && gOamBuffer[id].affineMode != ST_OAM_AFFINE_ERASE) id--;
        if (id < 0) return;
        oam = &gOamBuffer[id--];
        affine = oam->affineParam;
        memset(oam, 0, sizeof(*oam));
        oam->affineParam = affine;
        oam->paletteNum = 15;
        if (object < 6)
        {
            label = object/3;
            piece = object%3;
            oam->x = (label ? 144 : 0) + piece*32;
            oam->y = label ? 144 : 0;
            oam->shape = ST_OAM_H_RECTANGLE;
            oam->size = ST_OAM_SIZE_2;
            oam->tileNum = 0x3C0 + label*24 + piece*8;
        }
        else
        {
            oam->x = object == 6 ? 8 : 216;
            oam->y = 62;
            oam->size = ST_OAM_SIZE_1;
            oam->tileNum = 0x3F0 + (object == 6 ? 4 : 0);
        }
    }
}
