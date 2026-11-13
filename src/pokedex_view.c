#include "global.h"
#include "main.h"
#include "shiny.h"
#include "pokedex_view.h"

struct DexTheme
{
    const u16 *tiles, *map, *palette;
    u16 tileBytes;
};

#include "data/pokedex_view_assets.h"

#define DEX_GENERATION_COUNT ARRAY_COUNT(sDexThemes)
#define DEX_LABEL_TILE 0x3C0
#define DEX_BUTTON_TILE (DEX_LABEL_TILE + 8)
#define DEX_PROMPT_TILE (DEX_BUTTON_TILE + 8)

static EWRAM_DATA struct
{
    u16 species[NUM_SPECIES];
    u16 starts[DEX_GENERATION_COUNT], counts[DEX_GENERATION_COUNT];
    u32 nameMask[18][10];
    u8 generation, loadedGeneration;
    bool8 shiny, initialized;
} sDexView = {0};

bool8 PokedexView_IsInitialized(void) { return sDexView.initialized; }
bool8 PokedexView_IsShiny(void) { return sDexView.shiny; }
u16 PokedexView_Count(void) { return sDexView.counts[sDexView.generation]; }

u16 PokedexView_Species(s16 position)
{
    if (position < 0) position = 0;
    return position < PokedexView_Count()
        ? sDexView.species[sDexView.starts[sDexView.generation] + position] : SPECIES_NONE;
}

void PokedexView_Init(u16 total)
{
    u16 position, species, offset = 0;
    u8 gen;

    memset(&sDexView, 0, sizeof(sDexView));
    sDexView.loadedGeneration = DEX_GENERATION_COUNT;
    sDexView.initialized = TRUE;
    for (position = 0; position < total; position++)
    {
        gen = Shiny_GetGeneration(PokedexListPositionToSpecies(position));
        if (gen < DEX_GENERATION_COUNT)
            sDexView.counts[gen]++;
    }
    for (gen = 0; gen < DEX_GENERATION_COUNT; gen++)
    {
        sDexView.starts[gen] = offset;
        offset += sDexView.counts[gen];
        sDexView.counts[gen] = 0;
    }
    for (position = 0; position < total; position++)
    {
        species = PokedexListPositionToSpecies(position);
        gen = Shiny_GetGeneration(species);
        if (gen < DEX_GENERATION_COUNT)
            sDexView.species[sDexView.starts[gen] + sDexView.counts[gen]++] = species;
    }
}

bool8 PokedexView_MoveGeneration(s16 direction)
{
    u8 gen = sDexView.generation;
    do
    {
        if (direction < 0)
            gen = gen == 0 ? DEX_GENERATION_COUNT - 1 : gen - 1;
        else
            gen = gen == DEX_GENERATION_COUNT - 1 ? 0 : gen + 1;
        if (gen == sDexView.generation)
            return FALSE;
    } while (!sDexView.counts[gen]);
    sDexView.generation = gen;
    return TRUE;
}

void PokedexView_ToggleShiny(void)
{
    sDexView.shiny = !sDexView.shiny;
}

void PokedexView_VBlank(void)
{
    const struct DexTheme *theme, *previous;
    u16 firstBytes;
    if (!sDexView.initialized || sDexView.loadedGeneration == sDexView.generation)
        return;

    theme = &sDexThemes[sDexView.generation];
    previous = sDexView.loadedGeneration < DEX_GENERATION_COUNT ? &sDexThemes[sDexView.loadedGeneration] : NULL;
    if (!previous || theme->tiles != previous->tiles)
    {
        // BG tiles occupy the gaps after the detail tiles and after BG1 text.
        firstBytes = min(theme->tileBytes, (256 - DEX_BG_FIRST_TILE) * 64);
        DmaCopy32(3, theme->tiles, (void *)(BG_VRAM + DEX_BG_FIRST_TILE * 64), firstBytes);
        if (theme->tileBytes > firstBytes)
        {
            DmaCopy32(3, theme->tiles + firstBytes / 2, (void *)(BG_VRAM + DEX_BG_SECOND_TILE * 64),
                      theme->tileBytes - firstBytes);
        }
    }
    if (!previous || theme->map != previous->map)
        DmaCopy32(3, theme->map, (void *)BG_SCREEN_ADDR(2), BG_SCREEN_SIZE);
    DmaCopy32(3, theme->palette, BG_PLTT, BG_PLTT_SIZE);
    DmaCopy32(3, sDexControlLabels + sDexView.generation * 128,
              (void *)(OBJ_VRAM0 + DEX_LABEL_TILE * 32), 256);
    sDexView.loadedGeneration = sDexView.generation;
}

void PokedexView_LoadGraphics(void)
{
    DmaCopy16(3, sDexWindowTiles, (void *)BG_TILE_ADDR(DEX_WINDOW_EMPTY_TILE), sizeof(sDexWindowTiles));
    DmaCopy16(3, sDexControlButtons, (void *)(OBJ_VRAM0 + DEX_BUTTON_TILE * 32), sizeof(sDexControlButtons));
    DmaCopy16(3, sDexPromptTiles, (void *)(OBJ_VRAM0 + DEX_PROMPT_TILE * 32), sizeof(sDexPromptTiles));
    DmaCopy16(3, sDexControlPalette, OBJ_PLTT_SLOT(15), PLTT_SLOT_SIZE);
    DmaCopy16(3, sDexPromptPalette, OBJ_PLTT_SLOT(14), PLTT_SLOT_SIZE);
    PokedexView_VBlank();
}

void PokedexView_SetWindowRow(u16 *row, bool8 bottom)
{
    DmaCopy16(3, bottom ? sDexWindowBottomRow : sDexWindowMiddleRow, row, sizeof(sDexWindowMiddleRow));
}

void PokedexView_OutlineName(u16 *tiles)
{
    int x, y;
    u32 pixel, mask, left, right, ink;
    const u32 *above, *here, *below;
    u16 *src;
    // One bit per 4bpp pixel; use the original ink mask for every neighbor.
    for (y = 0; y < 16; y++)
    {
        src = tiles + (y / 8) * 0x200 + (y % 8) * 2;
        for (x = 0; x < 8; x++, src += 16)
        {
            pixel = src[0] | ((u32)src[1] << 16);
            sDexView.nameMask[y + 1][x + 1] = (pixel | (pixel >> 1) | (pixel >> 2) | (pixel >> 3)) & 0x11111111;
        }
    }
    for (y = 0; y < 16; y++)
    {
        src = tiles + (y / 8) * 0x200 + (y % 8) * 2;
        above = sDexView.nameMask[y];
        here = sDexView.nameMask[y + 1];
        below = sDexView.nameMask[y + 2];
        for (x = 1; x <= 8; x++, src += 16)
        {
            mask = above[x] | here[x] | below[x];
            left = above[x - 1] | here[x - 1] | below[x - 1];
            right = above[x + 1] | here[x + 1] | below[x + 1];
            ink = here[x];
            mask |= (mask << 4) | (mask >> 4) | (left >> 28) | (right << 28);
            pixel = ink | ((mask & ~ink) << 1);
            src[0] = pixel;
            src[1] = pixel >> 16;
        }
    }
}

void PokedexView_UpdateTotals(void)
{
    u16 i, species, flag, count = PokedexView_Count();
    gPokedexNumOwned = gPokedexNumSeen = 0;
    for (i = 0; i < count; i++)
    {
        species = sDexView.species[sDexView.starts[sDexView.generation] + i];
        flag = sDexView.shiny ? Shiny_GetPokedexFlag(species)
             : species < NUM_SAVE_SPECIES ? gMain_saveData.pokedexFlags[species]
             : gExtraPokedexFlags[species - NUM_SAVE_SPECIES];
        if (flag == SPECIES_CAUGHT) gPokedexNumOwned++;
        if (flag == SPECIES_CAUGHT || flag == SPECIES_SEEN || flag == SPECIES_SHARED_AND_SEEN) gPokedexNumSeen++;
    }
    gPokedexShowCompletionBadge = count && gPokedexNumOwned == count;
}

static void DrawDexObject(struct OamData *oam, u16 x, u8 y, u16 tile, u8 palette, u8 shape, u8 size)
{
    u16 affine = oam->affineParam;
    memset(oam, 0, sizeof(*oam));
    oam->affineParam = affine;
    oam->x = x;
    oam->y = y;
    oam->tileNum = tile;
    oam->paletteNum = palette;
    oam->shape = shape;
    oam->size = size;
}

void PokedexView_Draw(s16 firstObject, u8 promptFrame)
{
    struct OamData *oam;
    u16 prompt = DEX_PROMPT_TILE + (sDexView.shiny * 2 + (promptFrame & 1)) * 9;
    if (firstObject > 128 - 6)
        return;
    oam = &gOamBuffer[firstObject];
    DrawDexObject(oam++, 32, 0, DEX_LABEL_TILE, 15, ST_OAM_H_RECTANGLE, ST_OAM_SIZE_2);
    DrawDexObject(oam++, 8, 62, DEX_BUTTON_TILE + 4, 15, ST_OAM_SQUARE, ST_OAM_SIZE_1);
    DrawDexObject(oam++, 216, 62, DEX_BUTTON_TILE, 15, ST_OAM_SQUARE, ST_OAM_SIZE_1);
    DrawDexObject(oam++, 158, 148, prompt, 14, ST_OAM_H_RECTANGLE, ST_OAM_SIZE_1);
    DrawDexObject(oam++, 190, 148, prompt + 4, 14, ST_OAM_H_RECTANGLE, ST_OAM_SIZE_1);
    DrawDexObject(oam, 222, 148, prompt + 8, 14, ST_OAM_SQUARE, ST_OAM_SIZE_0);
}
