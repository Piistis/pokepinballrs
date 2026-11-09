#ifndef GUARD_SHINY_H
#define GUARD_SHINY_H

#define SHINY_DEX_BYTES ((NUM_SPECIES + 7) / 8)

enum ShinyEncounterKind
{
    SHINY_ENCOUNTER_NONE,
    SHINY_ENCOUNTER_CATCH,
    SHINY_ENCOUNTER_HATCH,
    SHINY_ENCOUNTER_BONUS
};

enum ShinyPaletteKind
{
    SHINY_PALETTE_PORTRAIT,
    SHINY_PALETTE_CATCH,
    SHINY_PALETTE_HATCH,
    SHINY_PALETTE_BONUS
};

/* Kept outside PinballGame so published save offsets never move. */
struct ShinyRunState
{
    u16 partyMask;
    u16 species;
    u8 isShiny;
    u8 kind;
    u8 effectPlayed;
    u8 reserved;
};

extern u8 gShinySeen[SHINY_DEX_BYTES];
extern u8 gShinyCaught[SHINY_DEX_BYTES];
extern struct ShinyRunState gShinyRunState;

void Shiny_ResetPokedex(void);
void Shiny_ResetRunState(void);
u8 Shiny_GetPokedexFlag(u16 species);
bool8 Shiny_SetPokedexFlag(u16 species, u8 flag);
u16 Shiny_GetOddsDenominator(u16 captures, bool8 generationComplete);
const u16 *Shiny_GetPalette(u8 kind, u16 index);
bool8 Shiny_IsPaletteReady(u8 kind, u16 index);
void SaveFile_SetShinyPokedexFlag(u16 species, u8 flag);
u8 Shiny_GetGeneration(u16 species);
bool8 Shiny_IsGenerationComplete(u8 generation);
void Shiny_BeginEncounter(u16 species, u8 kind, bool8 eligible);
void Shiny_BeginBonusEncounter(u16 species);
void Shiny_SetCurrentForm(u16 species, bool8 shiny);
bool8 Shiny_IsCurrentSpecies(u16 species);
bool8 Shiny_IsPartyMember(s16 index);
void Shiny_PartyAdd(s16 size);
void Shiny_PartyRemove(s16 index);
void Shiny_RecordCaught(u16 species, bool8 shiny);
void Shiny_Reveal(s16 x, s16 y);
void Shiny_EndEncounter(void);
const u16 *Shiny_SelectPalette(u16 species, u8 kind, u16 index, const u16 *normal);
const u16 *Shiny_GetBonusPalette(u8 field, u8 bank);
void Shiny_RenderEffects(void);
void Shiny_UpdateEffects(void);
void Shiny_StopEffects(void);
void Shiny_RestoreEffectOam(void);
void Shiny_ApplyBonusPalettes(void);
void Shiny_CopyBonusAnimationPalette(u8 bank, const u16 *normal, u16 *destination);

#endif
