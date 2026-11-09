#ifndef GUARD_POKEDEX_VIEW_H
#define GUARD_POKEDEX_VIEW_H

void PokedexView_Init(u16 total);
bool8 PokedexView_IsInitialized(void);
bool8 PokedexView_IsShiny(void);
u16 PokedexView_Count(void);
u16 PokedexView_Species(s16 position);
bool8 PokedexView_MoveGeneration(s16 direction);
void PokedexView_ToggleShiny(void);
void PokedexView_ApplyTheme(void);
void PokedexView_Draw(bool8 visible);
void PokedexView_UpdateTotals(void);

#endif
