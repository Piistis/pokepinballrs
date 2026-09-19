"""Execute the actual event C functions in a small, hardware-free fixture."""

import os
from pathlib import Path
import shutil
import struct
import subprocess
import tempfile


ROOT = Path(__file__).resolve().parents[2]
picker = (ROOT / "src/main_board_catch_hatch_picker.c").read_text()
graphics = (ROOT / "src/main_board_to_be_split.c").read_text()
event_code = picker[picker.index("#define MANAPHY_EGG_STATE_MAGIC"):
                    picker.index("extern const u16 gWildMonLocations")]
pick_code = picker[picker.index("void PickSpeciesForEggMode(void)"):]
graphics_code = graphics[graphics.index("void LoadHatchEggFrame(s16 frame)"):
                         graphics.index("// This is the 'Gravity Well'")]

FIXTURE = r'''
#include "constants/generations.h"
#include "constants/areas.h"
#include "constants/fields.h"
#include "constants/species.h"
#include "gba/io_reg.h"
#include "gba/macro.h"
typedef unsigned char u8;
typedef unsigned char bool8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
#define TRUE 1
#define FALSE 0
#define STATE_GAME_IDLE 99
#define STATE_GAME_MAIN 1
#define EWRAM_DATA
#define SG_RUBY_TOTODILE_EGG_DELIVERY 0
#define EREADER_ENCOUNTER_RATE_UP_CARD 0
#define MON_CAPTURE_SPECIAL_STATE_INACTIVE 0
#define MODE_CHANGE_END_OF_BALL 1
#define MODE_CHANGE_END_OF_GAME 2
#define MODE_CHANGE_BALL_SAVER 4
u16 paletteMemory[16][16];
#define OBJ_PLTT_SLOT(n) ((void *)paletteMemory[n])
#define PLTT_SLOT_SIZE 32
struct Game {
    u32 manaphyEggStateMagic;
    u8 manaphyEggCatchCount, manaphyEggActive;
    u8 manaphyEggPrepared, manaphyEggStarted, fadeSubState;
    u16 debugForcedEggSpecies, currentSpecies, lastEggSpecies;
    u16 caughtMonCount, totalWeight, speciesWeights[26];
    u8 forcePichuEgg, area, eggAnimationPhase, captureState;
} game;
struct Game *gCurrentPinballGame = &game;
struct SpriteGroup { int active; struct { int oamId; } oam[6]; };
struct Main {
    int mainState, selectedField, modeChangeFlags, gameExitState;
    u8 eReaderBonuses[1];
    struct SpriteGroup spriteGroups[1];
} gMain;
int gSelectedGeneration;
struct OamData { int x, y, paletteNum, tileNum, bpp, affineMode, shape, size; } gOamBuffer[128];
u8 gEggFrameTilesGfx[7][0x200], gManaphyEggFrameTilesGfx[7][0x200];
u16 gManaphyEggPalette[16];
const void *lastSource;
void *lastDestination;
int dmaCalls, lastSize;
void HostDmaCopy16(int channel, const void *source, void *destination, int size)
{
    int i;
    (void)channel;
    lastSource = source;
    lastDestination = destination;
    lastSize = size;
    dmaCalls++;
    if (destination != (void *)0x06011CE0)
        for (i = 0; i < size / 2; i++)
            ((u16 *)destination)[i] = ((const u16 *)source)[i];
}
/* Keep DmaSet's bare block: a function stub hides unbraced if/else errors. */
#undef DmaSet
#define DmaSet(channel, source, destination, control) \
{ \
    HostDmaCopy16(channel, source, destination, ((control) & 0xFFFF) * 2); \
}
u32 GetTimeAdjustedRandom(void) { return 7; }
u16 GetEggMonForSelectedGeneration(int field, int index)
{
    (void)field;
    (void)index;
    return SPECIES_WURMPLE;
}
'''

TESTS = r'''
#define CHECK(expr) do { if (!(expr)) return __LINE__; } while (0)
void Reset(void)
{
    int i, j;
    RestoreManaphyEggPalette();
    game.manaphyEggStateMagic = 0;
    NormalizeManaphyEggState();
    game.debugForcedEggSpecies = SPECIES_NONE;
    game.lastEggSpecies = SPECIES_NONE;
    game.currentSpecies = SPECIES_NONE;
    game.caughtMonCount = 0;
    game.forcePichuEgg = 0;
    game.totalWeight = 25;
    for (i = 0; i < 26; i++) game.speciesWeights[i] = i + 1;
    game.area = AREA_OCEAN_RUBY;
    game.eggAnimationPhase = 2;
    game.captureState = 0;
    game.fadeSubState = 1;
    gMain.mainState = 1;
    gMain.selectedField = FIELD_RUBY;
    gMain.modeChangeFlags = 0;
    gMain.gameExitState = 0;
    gSelectedGeneration = GENERATION_4;
    gMain.spriteGroups[0].active = FALSE;
    for (i = 0; i < 6; i++) gMain.spriteGroups[0].oam[i].oamId = i;
    for (i = 0; i < 128; i++)
    {
        gOamBuffer[i].x = gOamBuffer[i].y = 0;
        gOamBuffer[i].bpp = gOamBuffer[i].shape = gOamBuffer[i].size = 0;
        gOamBuffer[i].paletteNum = gOamBuffer[i].tileNum = 0;
        gOamBuffer[i].affineMode = 2;
    }
    for (i = 0; i < 16; i++)
    {
        gManaphyEggPalette[i] = 1000 + i;
        for (j = 0; j < 16; j++) paletteMemory[i][j] = i * 16 + j;
    }
    dmaCalls = 0;
}

int main(void)
{
    int field, generation, area, count, i, eligible;
    struct Game saved;

    for (field = 0; field < 3; field++)
    for (generation = GENERATION_1; generation <= GENERATION_RANDOM; generation++)
    for (area = 0; area < AREA_COUNT; area++)
    for (count = 0; count <= 5; count++)
    {
        Reset();
        gMain.selectedField = field;
        gSelectedGeneration = generation;
        game.area = area;
        for (i = 0; i < count; i++) AddManaphyEggCapture();
        eligible = field < MAIN_FIELD_COUNT && count == 5
            && (generation == GENERATION_4 || generation == GENERATION_RANDOM)
            && ((field == FIELD_RUBY && area == AREA_OCEAN_RUBY)
             || (field == FIELD_SAPPHIRE && area == AREA_OCEAN_SAPPHIRE));
        PrepareManaphyEgg();
        CHECK(game.manaphyEggActive == eligible);
        CHECK(game.manaphyEggCatchCount == count && !game.manaphyEggStarted);
        LoadHatchEggFrame(0);
        CHECK(lastSource == (eligible ? gManaphyEggFrameTilesGfx[0] : gEggFrameTilesGfx[0]));
        game.area = AREA_CITY; /* The delivery decision survives travel. */
        BeginManaphyEggAttempt();
        CHECK(game.manaphyEggActive == eligible);
        CHECK(game.manaphyEggCatchCount == (eligible ? 0 : count));
        PickSpeciesForEggMode();
        CHECK(game.currentSpecies == (eligible ? SPECIES_MANAPHY : SPECIES_WURMPLE));
        CHECK(game.lastEggSpecies == game.currentSpecies);
    }

    Reset();
    for (i = 0; i < 20; i++) AddManaphyEggCapture();
    CHECK(game.manaphyEggCatchCount == 5);
    game.area = AREA_CITY;
    BeginManaphyEggAttempt();
    AddManaphyEggCapture();
    CHECK(!game.manaphyEggActive && game.manaphyEggCatchCount == 5);
    game.area = AREA_OCEAN_RUBY;
    BeginManaphyEggAttempt();
    CHECK(!game.manaphyEggActive); /* An ordinary delivered egg cannot reroll. */
    PrepareManaphyEgg(); /* Deliver the next egg in the ocean. */
    CHECK(game.manaphyEggActive && game.manaphyEggCatchCount == 5);
    saved = game;
    Reset();
    game = saved;
    NormalizeManaphyEggState();
    CHECK(game.manaphyEggCatchCount == 5);
    BeginManaphyEggAttempt();
    game.area = AREA_CITY; /* The chosen event is latched before the reveal. */
    saved = game;
    Reset();
    game = saved;
    NormalizeManaphyEggState();
    game.totalWeight = 0; /* The special event must bypass random weights. */
    PickSpeciesForEggMode();
    CHECK(game.currentSpecies == SPECIES_MANAPHY);
    AddManaphyEggCapture();
    CHECK(game.manaphyEggCatchCount == 0); /* Manaphy never counts as egg #1. */
    game.manaphyEggActive = FALSE; /* End of attempt, caught or escaped. */
    game.area = AREA_OCEAN_RUBY;
    for (i = 0; i < 4; i++) AddManaphyEggCapture();
    PrepareManaphyEgg();
    BeginManaphyEggAttempt();
    CHECK(!game.manaphyEggActive && game.manaphyEggCatchCount == 4);
    AddManaphyEggCapture();
    PrepareManaphyEgg();
    BeginManaphyEggAttempt();
    CHECK(game.manaphyEggActive && game.manaphyEggCatchCount == 0);

    Reset();
    game.manaphyEggCatchCount = 5;
    gMain.mainState = STATE_GAME_IDLE;
    BeginManaphyEggAttempt();
    CHECK(!game.manaphyEggActive && game.manaphyEggCatchCount == 5);
    gMain.mainState = 1;
    game.debugForcedEggSpecies = SPECIES_BUDEW;
    PrepareManaphyEgg();
    BeginManaphyEggAttempt();
    PickSpeciesForEggMode();
    CHECK(game.currentSpecies == SPECIES_BUDEW && !game.manaphyEggActive);
    CHECK(game.manaphyEggCatchCount == 5 && game.debugForcedEggSpecies == SPECIES_NONE);
    game.debugForcedEggSpecies = SPECIES_MANAPHY;
    PrepareManaphyEgg();
    BeginManaphyEggAttempt();
    PickSpeciesForEggMode();
    CHECK(game.currentSpecies == SPECIES_MANAPHY && game.manaphyEggActive);
    CHECK(game.manaphyEggCatchCount == 5);

    game.manaphyEggStateMagic = 0;
    NormalizeManaphyEggState();
    CHECK(!game.manaphyEggActive && game.manaphyEggCatchCount == 0);
    game.manaphyEggCatchCount = 255;
    NormalizeManaphyEggState();
    CHECK(game.manaphyEggCatchCount == 0);

    game.manaphyEggStateMagic = 0x4D414E41;
    game.manaphyEggActive = TRUE;
    NormalizeManaphyEggState();
    CHECK(game.manaphyEggActive && game.manaphyEggPrepared && game.manaphyEggStarted);

    Reset();
    for (i = 0; i < 7; i++)
    {
        LoadHatchEggFrame(i);
        CHECK(lastSource == gEggFrameTilesGfx[i] && lastSize == 0x200);
        game.manaphyEggActive = TRUE;
        LoadHatchEggFrame(i);
        CHECK(lastSource == gManaphyEggFrameTilesGfx[i] && lastSize == 0x200);
        game.manaphyEggActive = FALSE;
    }
    LoadHatchEggFrame(7);
    CHECK(lastSource == gEggFrameTilesGfx[0]);
    game.manaphyEggActive = TRUE;
    LoadHatchEggFrame(-1);
    CHECK(lastSource == gManaphyEggFrameTilesGfx[0]);
    gOamBuffer[0].affineMode = 0;
    gOamBuffer[0].tileNum = 0xE7;
    gOamBuffer[0].paletteNum = 11;
    gOamBuffer[0].size = 2;
    /* Delivery art already uses bank 14; a second portrait uses bank 15. */
    gOamBuffer[1].affineMode = gOamBuffer[2].affineMode = 0;
    gOamBuffer[1].paletteNum = 14;
    gOamBuffer[2].paletteNum = 15;
    RenderManaphyEggPalette();
    CHECK(lastSource == gManaphyEggPalette && lastDestination == OBJ_PLTT_SLOT(13));
    CHECK(gOamBuffer[0].paletteNum == 13);
    CHECK(paletteMemory[14][5] == 14 * 16 + 5 && paletteMemory[15][5] == 15 * 16 + 5);
    CHECK(paletteMemory[13][5] == gManaphyEggPalette[5]);
    RestoreManaphyEggPalette();
    CHECK(gOamBuffer[0].paletteNum == 11 && paletteMemory[13][5] == 13 * 16 + 5);
    /* Pause/unpause repeats must restore, then reacquire a bank. */
    for (i = 0; i < 5; i++)
    {
        RenderManaphyEggPalette();
        CHECK(gOamBuffer[0].paletteNum == 13);
        RestoreManaphyEggPalette();
    }
    gOamBuffer[2].y = 200; /* Now bank 15 is offscreen and available. */
    RenderManaphyEggPalette();
    CHECK(gOamBuffer[0].paletteNum == 15);
    RestoreManaphyEggPalette();
    /* Wrapped sprites at y=250 are partly visible and must retain their bank. */
    gOamBuffer[2].y = 250;
    RenderManaphyEggPalette();
    CHECK(gOamBuffer[0].paletteNum == 13);
    RestoreManaphyEggPalette();
    /* Totodile's split egg must use the custom frame too. */
    gMain.spriteGroups[0].active = TRUE;
    gOamBuffer[0].tileNum = 0x308;
    gOamBuffer[0].x = 20;
    gOamBuffer[1].tileNum = 0x30C;
    RenderManaphyEggPalette();
    CHECK(gOamBuffer[0].tileNum == 0xE7 && gOamBuffer[0].x == 12);
    CHECK(gOamBuffer[0].shape == 0 && gOamBuffer[0].size == 2);
    CHECK(gOamBuffer[1].affineMode == 2);
    RestoreManaphyEggPalette();
    gMain.spriteGroups[0].active = FALSE;
    game.manaphyEggActive = FALSE;
    dmaCalls = 0;
    RenderManaphyEggPalette();
    CHECK(dmaCalls == 0);
    /* Exhausted palettes hide the egg without modifying other sprites' colors. */
    game.manaphyEggActive = TRUE;
    for (i = 0; i < 16; i++)
    {
        gOamBuffer[i + 1].affineMode = 0;
        gOamBuffer[i + 1].tileNum = 0;
        gOamBuffer[i + 1].y = 0;
        gOamBuffer[i + 1].paletteNum = i;
    }
    RenderManaphyEggPalette();
    CHECK(dmaCalls == 0 && gOamBuffer[0].y == 200);
    return 0;
}
'''


def main():
    png = (ROOT / "graphics/stage/main/egg_manaphy.png").read_bytes()
    assert png[:8] == b"\x89PNG\r\n\x1a\n"
    width, height, depth, color_type = struct.unpack(">IIBB", png[16:26])
    assert (width, height, color_type) == (32, 224, 3)
    assert depth in (4, 8)  # gbagfx packs indexed 8-bit PNGs into 4bpp tiles.
    offset = 8
    palette_size = None
    while offset < len(png):
        length = struct.unpack(">I", png[offset:offset + 4])[0]
        if png[offset + 4:offset + 8] == b"PLTE":
            palette_size = length
        offset += length + 12
    assert palette_size == 16 * 3
    compiler = os.environ.get("CC") or shutil.which("cc") or shutil.which("cl")
    if not compiler and os.name == "nt":
        candidates = sorted(Path("C:/Program Files/Microsoft Visual Studio").glob(
            "*/Community/VC/Tools/MSVC/*/bin/Hostx64/x64/cl.exe"))
        if candidates:
            compiler = str(candidates[-1])
    if not compiler:
        raise SystemExit("A host C compiler (cc or MSVC cl) is required.")
    with tempfile.TemporaryDirectory(prefix="manaphy-test-") as temporary:
        work = Path(temporary)
        source = work / "test.c"
        source.write_text(FIXTURE + event_code + pick_code + graphics_code + TESTS)
        executable = work / ("test.exe" if os.name == "nt" else "test")
        env = os.environ.copy()
        if Path(compiler).name.lower() in ("cl", "cl.exe"):
            env["PATH"] = str(Path(compiler).parent) + os.pathsep + env["PATH"]
            command = [compiler, "/nologo", "/W3", "/WX", "/GS-", "/Od",
                       f"/I{ROOT / 'include'}", str(source), "/link", "/nodefaultlib",
                       "/entry:main", "/subsystem:console", f"/out:{executable}"]
        else:
            command = [compiler, "-std=c99", "-Wall", "-Wextra", "-Werror",
                       "-I", str(ROOT / "include"), str(source), "-o", str(executable)]
        subprocess.run(command, cwd=work, env=env, check=True)
        result = subprocess.run([str(executable)], cwd=work)
        if result.returncode:
            raise SystemExit(f"C regression check failed (source line/status {result.returncode})")
    print("PASS: delivery selection, travel, retry, save migration, debug override,")
    print("      all fields/generations/areas/counts, palette borrowing/restoration,")
    print("      Totodile delivery, frame selection and indexed PNG layout.")


if __name__ == "__main__":
    main()
