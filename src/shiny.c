#include "global.h"
#include "shiny.h"
#include "main.h"
#include "constants/content.h"
#include "constants/fields.h"
#include "constants/debug.h"
#include "constants/shiny.h"
#include "m4a.h"
#include "encounters.h"
#include "data/shiny_palettes.h"

EWRAM_DATA u8 gShinySeen[SHINY_DEX_BYTES] = {0};
EWRAM_DATA u8 gShinyCaught[SHINY_DEX_BYTES] = {0};
EWRAM_DATA struct ShinyRunState gShinyRunState = {0};
static EWRAM_DATA Palette sShinyBossPalettesRam[3][16] = {0};
static EWRAM_DATA Palette *sShinyBossOriginal[3] = {0};
static EWRAM_DATA bool8 sDebugForceNextShiny = FALSE;

extern struct SongHeader se_shiny_emerald;

static const u8 sShinyObjectTileSizes[3][4][2] = {
    {{1,1},{2,2},{4,4},{8,8}}, {{2,1},{4,1},{4,2},{8,4}}, {{1,2},{1,4},{2,4},{4,8}}
};

static EWRAM_DATA struct
{
    struct OamData oam[10];
    u16 ids[10];
    u16 tiles[96];
    u16 palette[16];
    // The system stack has only 0x300 bytes above SoundMainRAM_Buffer.
    u32 usedTiles[32];
    u16 tileBase, paletteBank, count;
    s16 x[5], y[5], frame;
    bool8 active, borrowed;
} sShinyFx = {0};

static bool8 Shiny_EqualHalfwords(const u16 *a, const u16 *b, s16 count)
{
    s16 i;
    for (i = 0; i < count; i++)
        if (a[i] != b[i]) return FALSE;
    return TRUE;
}

void Shiny_StopEffects(void)
{
    sShinyFx.active = FALSE;
}

void Shiny_Reveal(s16 x, s16 y)
{
    s16 i;
    if (!gShinyRunState.isShiny || gShinyRunState.effectPlayed || gMain.mainState != STATE_GAME_MAIN)
        return;
    gShinyRunState.effectPlayed = TRUE;
    SaveFile_SetShinyPokedexFlag(gShinyRunState.species, SPECIES_SEEN);
    for (i = 0; i < 5; i++)
    {
        sShinyFx.x[i] = x;
        sShinyFx.y[i] = y;
    }
    sShinyFx.frame = 0;
    sShinyFx.active = TRUE;
}

void Shiny_UpdateEffects(void)
{
    s16 star;
    if (!sShinyFx.active || Encounters_IsOpen() || (gMain.modeChangeFlags & (MODE_CHANGE_PAUSE | MODE_CHANGE_DEBUG)))
        return;
    if (gMain.mainState != STATE_GAME_MAIN)
    {
        Shiny_StopEffects();
        return;
    }
    sShinyFx.frame++;
    if (sShinyFx.frame >= 60 && sShinyFx.frame <= 76 && sShinyFx.frame % 4 == 0)
    {
        star = (sShinyFx.frame - 60) / 4;
        if (gShinyRunState.kind == SHINY_ENCOUNTER_HATCH)
        {
            sShinyFx.x[star] = gCurrentPinballGame->walkMonXPos / 10 + 12;
            sShinyFx.y[star] = gCurrentPinballGame->walkMonYPos / 10 + 14;
        }
        else if (gShinyRunState.kind == SHINY_ENCOUNTER_BONUS)
        {
            sShinyFx.x[star] = gCurrentPinballGame->catchTargetX;
            sShinyFx.y[star] = gCurrentPinballGame->catchTargetY;
        }
        else if (gShinyRunState.species == SPECIES_JIRACHI)
        {
            sShinyFx.x[star] = gCurrentPinballGame->jirachiDisplayX / 10 + 120;
            sShinyFx.y[star] = gCurrentPinballGame->jirachiDisplayY / 10 + 312;
        }
    }
    if (sShinyFx.frame == 60)
        MPlayStart(&gMPlayInfo_SE1, &se_shiny_emerald);
    if (sShinyFx.frame >= 98)
        Shiny_StopEffects();
}

void Shiny_RestoreEffectOam(void)
{
    s16 i;
    for (i = 0; i < sShinyFx.count; i++)
        gOamBuffer[sShinyFx.ids[i]] = sShinyFx.oam[i];
    sShinyFx.count = 0;
}

// Temporary graphics are restored only if board code has not replaced them.
static void Shiny_RestoreEffectGraphics(void)
{
    if (!sShinyFx.borrowed)
        return;
    if (Shiny_EqualHalfwords((u16 *)OBJ_VRAM0 + sShinyFx.tileBase * 16, sEmeraldStarTiles, 96))
        DmaCopy16(3, sShinyFx.tiles, (u8 *)OBJ_VRAM0 + sShinyFx.tileBase * 32, sizeof(sShinyFx.tiles));
    if (Shiny_EqualHalfwords((u16 *)OBJ_PLTT + sShinyFx.paletteBank * 16, sEmeraldStarPalette, 16))
        DmaCopy16(3, sShinyFx.palette, (u16 *)OBJ_PLTT + sShinyFx.paletteBank * 16, sizeof(sShinyFx.palette));
    sShinyFx.borrowed = FALSE;
}

static bool8 Shiny_IsOamVisible(const struct OamData *oam)
{
    s16 width, height, x, y;
    if (oam->affineMode == ST_OAM_AFFINE_ERASE || oam->shape >= 3)
        return FALSE;
    width = sShinyObjectTileSizes[oam->shape][oam->size][0] * 8;
    height = sShinyObjectTileSizes[oam->shape][oam->size][1] * 8;
    if (oam->affineMode == ST_OAM_AFFINE_DOUBLE)
    {
        width *= 2;
        height *= 2;
    }
    x = oam->x;
    y = oam->y;
    if (x >= 240) x -= 512;
    if (y >= 160) y -= 256;
    return x < 240 && y < 160 && x + width > 0 && y + height > 0;
}

void Shiny_RenderEffects(void)
{
    u16 palettes = 0;
    s16 i, j, tiles, base, bank, group, star, age, x, y, id;
    u16 affine;
    struct OamData *oam;
    Shiny_RestoreEffectGraphics();
    if (!sShinyFx.active || gMain.mainState != STATE_GAME_MAIN || Encounters_IsOpen()
     || (gMain.modeChangeFlags & (MODE_CHANGE_PAUSE | MODE_CHANGE_DEBUG)) || sShinyFx.frame < 60)
        return;
    memset(sShinyFx.usedTiles, 0, sizeof(sShinyFx.usedTiles));
    for (i = 0; i < 128; i++)
    {
        oam = &gOamBuffer[i];
        if (!Shiny_IsOamVisible(oam))
            continue;
        palettes |= oam->bpp ? 0xFFFF : 1 << oam->paletteNum;
        tiles = sShinyObjectTileSizes[oam->shape][oam->size][0] * sShinyObjectTileSizes[oam->shape][oam->size][1] * (oam->bpp ? 2 : 1);
        for (j = oam->tileNum; j < oam->tileNum + tiles && j < 1024; j++)
            sShinyFx.usedTiles[j / 32] |= 1u << (j & 31);
    }
    for (bank = 15; bank >= 0 && (palettes & (1 << bank)); bank--);
    for (base = 1016; base >= 0; base -= 2)
    {
        for (j = 0; j < 6 && !(sShinyFx.usedTiles[(base + j) / 32] & (1u << ((base + j) & 31))); j++);
        if (j == 6) break;
    }
    if (base < 0 || bank < 0)
        return;
    sShinyFx.tileBase = base;
    sShinyFx.paletteBank = bank;
    memcpy(sShinyFx.tiles, (u8 *)OBJ_VRAM0 + base * 32, sizeof(sShinyFx.tiles));
    memcpy(sShinyFx.palette, (u16 *)OBJ_PLTT + bank * 16, sizeof(sShinyFx.palette));
    DmaCopy16(3, sEmeraldStarTiles, (u8 *)OBJ_VRAM0 + base * 32, sizeof(sShinyFx.tiles));
    DmaCopy16(3, sEmeraldStarPalette, (u16 *)OBJ_PLTT + bank * 16, sizeof(sShinyFx.palette));
    sShinyFx.borrowed = TRUE;
    id = 127;
    for (group = 0; group < 2; group++)
        for (star = 0; star < 5; star++)
        {
            age = sShinyFx.frame - 60 - star * 4;
            if (age < 0 || (group == 0 ? age >= 21 : age < 4 || age >= 16)) continue;
            // Native empty OAM entries are ordinary sprites parked off-screen.
            while (id >= 0 && Shiny_IsOamVisible(&gOamBuffer[id])) id--;
            if (id < 0) return;
            x = sShinyFx.x[star] - gCurrentPinballGame->cameraXOffset;
            y = sShinyFx.y[star] - gCurrentPinballGame->cameraYOffset;
            if (!group)
            {
                x += (sEmeraldStarSine[(age * 12) & 255] * 24) >> 8;
                y += (sEmeraldStarSine[(age * 12 + 64) & 255] * 24) >> 8;
            }
            else
            {
                x += -32 + (age - 3) * 5;
                y += 32 - (age - 3) * 5;
            }
            oam = &gOamBuffer[id];
            sShinyFx.ids[sShinyFx.count] = id--;
            sShinyFx.oam[sShinyFx.count++] = *oam;
            affine = oam->affineParam;
            memset(oam, 0, sizeof(*oam));
            oam->affineParam = affine;
            oam->x = x - (star == 0 ? 8 : 4);
            oam->y = y - (star == 0 ? 8 : 4);
            oam->tileNum = base + (star == 0 ? 0 : star == 4 ? 5 : 4);
            oam->size = star == 0 ? ST_OAM_SIZE_1 : ST_OAM_SIZE_0;
            oam->paletteNum = bank;
        }
}

void Shiny_ResetPokedex(void)
{
    memset(gShinySeen, 0, sizeof(gShinySeen));
    memset(gShinyCaught, 0, sizeof(gShinyCaught));
}

void Shiny_ResetRunState(void)
{
    Shiny_StopEffects();
    sDebugForceNextShiny = FALSE;
    memset(&gShinyRunState, 0, sizeof(gShinyRunState));
    gShinyRunState.species = SPECIES_NONE;
}

u16 Shiny_GetNationalNumber(u16 species)
{
    return species < ARRAY_COUNT(sShinyNationalNumbers) ? sShinyNationalNumbers[species] : 0;
}

u8 Shiny_GetGeneration(u16 species)
{
    u16 number = Shiny_GetNationalNumber(species);
    if (number == 0) return 255;
    if (number <= 151) return 0;
    if (number <= 251) return 1;
    if (number <= 386) return 2;
    if (number <= 493) return 3;
    if (number <= 649) return 4;
    if (number <= 721) return 5;
    if (number <= 809) return 6;
    if (number <= 905) return 7;
    return 8;
}

bool8 Shiny_IsGenerationComplete(u8 generation)
{
    static const u16 totals[] = {151, 100, 135, 107, 156, 72, 88, 96, 120};
    u16 species, count = 0;
    u8 flag;
    if (generation >= ARRAY_COUNT(totals))
        return FALSE;
    for (species = 0; species < NUM_SPECIES; species++)
    {
        if (Shiny_GetGeneration(species) != generation)
            continue;
        count++;
        flag = species < NUM_SAVE_SPECIES ? gMain_saveData.pokedexFlags[species]
                                         : gExtraPokedexFlags[species - NUM_SAVE_SPECIES];
        if (flag != SPECIES_CAUGHT)
            return FALSE;
    }
    return count == totals[generation];
}

void Shiny_BeginEncounter(u16 species, u8 kind, bool8 eligible)
{
    u16 denominator;
    Shiny_EndEncounter();
    gShinyRunState.species = species;
    gShinyRunState.kind = kind;
    if (!eligible || species >= NUM_SPECIES || gMain.mainState == STATE_GAME_IDLE)
        return;
    denominator = Shiny_GetOddsDenominator(gCurrentPinballGame->caughtMonCount,
                                         Shiny_IsGenerationComplete(Shiny_GetGeneration(species)));
    gShinyRunState.isShiny = (Random() & (denominator - 1)) == 0;
#if DEBUG_TOOLS_ENABLED
    if (sDebugForceNextShiny && gMain.mainState == STATE_GAME_MAIN)
    {
        gShinyRunState.isShiny = TRUE;
        sDebugForceNextShiny = FALSE;
    }
#endif
#if DEBUG_TOOLS_ENABLED && DEBUG_SHINY_FORCE_ENCOUNTERS
    gShinyRunState.isShiny = TRUE;
#endif
}

void Shiny_DebugSetNextForced(bool8 enabled)
{
#if DEBUG_TOOLS_ENABLED
    sDebugForceNextShiny = enabled != FALSE;
#endif
}

bool8 Shiny_DebugNextIsForced(void)
{
#if DEBUG_TOOLS_ENABLED
    return sDebugForceNextShiny;
#else
    return FALSE;
#endif
}

void Shiny_BeginBonusEncounter(u16 species)
{
    bool8 eligible = species == SPECIES_RAYQUAZA ? gCurrentPinballGame->numCompletedBonusStages % 10 == 9
                                                : gCurrentPinballGame->numCompletedBonusStages % 5 == 3;
    Shiny_BeginEncounter(species, SHINY_ENCOUNTER_BONUS, eligible);
}

void Shiny_SetCurrentForm(u16 species, bool8 shiny)
{
    if (gShinyRunState.species != species)
    {
        Shiny_StopEffects();
        gShinyRunState.effectPlayed = FALSE;
    }
    gShinyRunState.species = species;
    gShinyRunState.kind = SHINY_ENCOUNTER_CATCH;
    gShinyRunState.isShiny = shiny;
}

bool8 Shiny_IsCurrentSpecies(u16 species)
{
    return species < NUM_SPECIES && gShinyRunState.species == species && gShinyRunState.isShiny;
}

bool8 Shiny_IsPartyMember(s16 index)
{
    return index >= 0 && index < gCurrentPinballGame->evolvablePartySize
        && (gShinyRunState.partyMask & (1 << index)) != 0;
}

void Shiny_PartyAdd(s16 size)
{
    u16 mask;
    if (size >= MAX_EVOLVABLE_PARTY_SIZE)
    {
        gShinyRunState.partyMask >>= 1;
        size = MAX_EVOLVABLE_PARTY_SIZE - 1;
    }
    mask = 1 << size;
    gShinyRunState.partyMask &= ~mask;
    if (Shiny_IsCurrentSpecies(gCurrentPinballGame->currentSpecies))
        gShinyRunState.partyMask |= mask;
}

void Shiny_PartyRemove(s16 index)
{
    u16 lower;
    if (index < 0 || index >= gCurrentPinballGame->evolvablePartySize)
        return;
    lower = (1 << index) - 1;
    gShinyRunState.partyMask = (gShinyRunState.partyMask & lower)
        | ((gShinyRunState.partyMask >> 1) & ~lower);
}

void Shiny_RecordCaught(u16 species, bool8 shiny)
{
    if (shiny && gMain.mainState != STATE_GAME_IDLE)
        SaveFile_SetShinyPokedexFlag(species, SPECIES_CAUGHT);
}

void Shiny_EndEncounter(void)
{
    Shiny_StopEffects();
    gShinyRunState.species = SPECIES_NONE;
    gShinyRunState.kind = SHINY_ENCOUNTER_NONE;
    gShinyRunState.isShiny = FALSE;
    gShinyRunState.effectPlayed = FALSE;
}

const u16 *Shiny_SelectPalette(u16 species, u8 kind, u16 index, const u16 *normal)
{
    const u16 *palette = Shiny_IsCurrentSpecies(species) ? Shiny_GetPalette(kind, index) : NULL;
    return palette ? palette : normal;
}

const u16 *Shiny_GetBonusPalette(u8 field, u8 bank)
{
    if (field < FIELD_KYOGRE || field > FIELD_RAYQUAZA || bank >= 16
     || !gShinyRunState.isShiny || gShinyRunState.kind != SHINY_ENCOUNTER_BONUS
     || !(sShinyBossBankMasks[field - FIELD_KYOGRE] & (1 << bank)))
        return NULL;
    return sShinyBossPalettes[field - FIELD_KYOGRE][bank];
}

static u16 Shiny_ShadeBonusColor(u8 bank, u8 color, u16 normal)
{
    s16 component, maximum = 0, brightness = 0, base, shade;
    u16 value = 0, original = sShinyBossOriginal[0][bank][color];
    const u16 *palette = Shiny_GetBonusPalette(gMain.selectedField, bank);
    for (component = 0; component < 3; component++)
    {
        base = (original >> (component * 5)) & 31;
        shade = (normal >> (component * 5)) & 31;
        if (base > maximum) maximum = base;
        if (shade > brightness) brightness = shade;
    }
    for (component = 0; component < 3; component++)
    {
        shade = (palette[color] >> (component * 5)) & 31;
        if (maximum) shade = shade * brightness / maximum;
        if (shade > 31) shade = 31;
        value |= shade << (component * 5);
    }
    return value;
}

void Shiny_CopyBonusAnimationPalette(u8 bank, const u16 *normal, u16 *destination)
{
    u16 colors[16];
    s16 color;
    if (!Shiny_GetBonusPalette(gMain.selectedField, bank))
    {
        DmaCopy16(3, normal, destination, PLTT_SLOT_SIZE);
        return;
    }
    memcpy(colors, normal, sizeof(colors));
    for (color = 1; color < 16; color++)
        if (sShinyBossChangedColors[gMain.selectedField - FIELD_KYOGRE][bank] & (1 << color))
            colors[color] = Shiny_ShadeBonusColor(bank, (u8)color, normal[color]);
    DmaCopy16(3, colors, destination, sizeof(colors));
}

void Shiny_ApplyBonusPalettes(void)
{
    s16 level, bank, color;
    if (gBoardConfig.fieldLayout.objPaletteSets[0] == sShinyBossPalettesRam[0])
        for (level = 0; level < 3; level++)
            gBoardConfig.fieldLayout.objPaletteSets[level] = sShinyBossOriginal[level];
    if (gMain.selectedField < FIELD_KYOGRE || gMain.selectedField > FIELD_RAYQUAZA
     || !gShinyRunState.isShiny || gShinyRunState.kind != SHINY_ENCOUNTER_BONUS)
        return;
    for (level = 0; level < 3; level++)
    {
        sShinyBossOriginal[level] = gBoardConfig.fieldLayout.objPaletteSets[level];
        memcpy(sShinyBossPalettesRam[level], sShinyBossOriginal[level], sizeof(sShinyBossPalettesRam[level]));
        for (bank = 0; bank < 16; bank++)
        {
            if (!Shiny_GetBonusPalette(gMain.selectedField, (u8)bank))
                continue;
            for (color = 1; color < 16; color++)
            {
                if (!(sShinyBossChangedColors[gMain.selectedField - FIELD_KYOGRE][bank] & (1 << color)))
                    continue;
                sShinyBossPalettesRam[level][bank][color] = Shiny_ShadeBonusColor((u8)bank, (u8)color, sShinyBossOriginal[level][bank][color]);
            }
        }
    }
    for (level = 0; level < 3; level++)
        gBoardConfig.fieldLayout.objPaletteSets[level] = sShinyBossPalettesRam[level];
    DmaCopy16(3, sShinyBossPalettesRam[0], OBJ_PLTT, OBJ_PLTT_SIZE);
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
