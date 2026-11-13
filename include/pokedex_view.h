#ifndef GUARD_POKEDEX_VIEW_H
#define GUARD_POKEDEX_VIEW_H

#define DEX_WINDOW_EMPTY_TILE (0x1800 / 32)
#define DEX_NAME_PALETTE 4

void PokedexView_Init(u16 total);
bool8 PokedexView_IsInitialized(void);
bool8 PokedexView_IsShiny(void);
u16 PokedexView_Count(void);
u16 PokedexView_Species(s16 position);
bool8 PokedexView_MoveGeneration(s16 direction);
void PokedexView_ToggleShiny(void);
void PokedexView_LoadGraphics(void);
void PokedexView_VBlank(void);
void PokedexView_Draw(s16 firstObject, u8 promptFrame);
void PokedexView_SetWindowRow(u16 *row, bool8 bottom);
void PokedexView_OutlineName(u16 *tiles);
void PokedexView_UpdateTotals(void);

#endif
