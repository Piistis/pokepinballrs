#include "global.h"
#include "shiny.h"
#include "data/shiny_palettes.h"

EWRAM_DATA u8 gShinySeen[SHINY_DEX_BYTES] = {0};
EWRAM_DATA u8 gShinyCaught[SHINY_DEX_BYTES] = {0};
EWRAM_DATA struct ShinyRunState gShinyRunState = {0};

void Shiny_ResetPokedex(void)
{
    memset(gShinySeen, 0, sizeof(gShinySeen));
    memset(gShinyCaught, 0, sizeof(gShinyCaught));
}

void Shiny_ResetRunState(void)
{
    memset(&gShinyRunState, 0, sizeof(gShinyRunState));
    gShinyRunState.species = SPECIES_NONE;
}

u8 Shiny_GetPokedexFlag(u16 species)
{
    u8 mask;
    if (species >= NUM_SPECIES)
        return SPECIES_UNSEEN;
    mask = 1 << (species & 7);
    if (gShinyCaught[species / 8] & mask)
        return SPECIES_CAUGHT;
    return gShinySeen[species / 8] & mask ? SPECIES_SEEN : SPECIES_UNSEEN;
}

bool8 Shiny_SetPokedexFlag(u16 species, u8 flag)
{
    u8 mask;
    if (species >= NUM_SPECIES || (flag != SPECIES_SEEN && flag != SPECIES_CAUGHT)
     || Shiny_GetPokedexFlag(species) >= flag)
        return FALSE;
    mask = 1 << (species & 7);
    gShinySeen[species / 8] |= mask;
    if (flag == SPECIES_CAUGHT)
        gShinyCaught[species / 8] |= mask;
    return TRUE;
}

u16 Shiny_GetOddsDenominator(u16 captures, bool8 generationComplete)
{
    u16 denominator = 1024;
    if (captures >= 50)
        denominator = 64;
    else if (captures >= 30)
        denominator = 128;
    else if (captures >= 20)
        denominator = 256;
    return generationComplete ? denominator / 2 : denominator;
}

const u16 *Shiny_GetPalette(u8 kind, u16 index)
{
    switch (kind)
    {
    case SHINY_PALETTE_PORTRAIT:
        return index < ARRAY_COUNT(sShinyPortraitPalettes) ? sShinyPortraitPalettes[index] : NULL;
    case SHINY_PALETTE_CATCH:
        return index < ARRAY_COUNT(sShinyCatchPalettes) ? sShinyCatchPalettes[index] : NULL;
    case SHINY_PALETTE_HATCH:
        return index < ARRAY_COUNT(sShinyHatchPalettes) ? sShinyHatchPalettes[index] : NULL;
    case SHINY_PALETTE_BONUS:
        return index < ARRAY_COUNT(sShinyBonusPalettes) ? sShinyBonusPalettes[index] : NULL;
    }
    return NULL;
}

bool8 Shiny_IsPaletteReady(u8 kind, u16 index)
{
    switch (kind)
    {
    case SHINY_PALETTE_PORTRAIT:
        return index < ARRAY_COUNT(sShinyPortraitReady) && sShinyPortraitReady[index];
    case SHINY_PALETTE_CATCH:
        return index < ARRAY_COUNT(sShinyCatchReady) && sShinyCatchReady[index];
    case SHINY_PALETTE_HATCH:
        return index < ARRAY_COUNT(sShinyHatchReady) && sShinyHatchReady[index];
    case SHINY_PALETTE_BONUS:
        return index < ARRAY_COUNT(sShinyBonusReady) && sShinyBonusReady[index];
    }
    return FALSE;
}
