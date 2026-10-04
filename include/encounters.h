#ifndef GUARD_ENCOUNTERS_H
#define GUARD_ENCOUNTERS_H

#include "gba/types.h"
#include "constants/pinball_game.h"

#define ENCOUNTERS_PER_PAGE 8
#define ENCOUNTERS_CAPACITY (2 * WILD_MON_LOCATION_COUNT)

u16 GetCurrentAreaCatchEncounters(u16 *species);
bool8 Encounters_IsOpen(void);
void Encounters_Open(void);
void Encounters_Update(void);
void Encounters_VBlank(void);
void EncountersPause_Begin(void);
void EncountersPause_End(void);
void EncountersPause_Draw(void);

#endif
