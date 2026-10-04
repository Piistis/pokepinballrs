"""Compile the real encounters UI against simulated video memory and render previews."""

import ctypes
import os
from pathlib import Path
import re
import shutil
import struct
import subprocess
import tempfile
import zlib

import generate_encounter_guide as guide
import generate_encounters_assets as assets

ROOT = guide.ROOT

PRELUDE = r'''
typedef unsigned char u8, bool8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef volatile u16 vu16;
typedef u16 Palette[16];
#define TRUE 1
#define FALSE 0
#define EWRAM_DATA
#define DEBUG_TOOLS_ENABLED 0
#include "constants/species.h"
#include "constants/areas.h"
#include "constants/fields.h"
#include "constants/bg_music.h"
#include "constants/pinball_game.h"
#define ENCOUNTERS_PER_PAGE 8
#define ENCOUNTERS_CAPACITY (2 * WILD_MON_LOCATION_COUNT)
#define SPECIES_CAUGHT 4
#define ST_OAM_AFFINE_ERASE 2
#define ST_OAM_H_RECTANGLE 1
#define ST_OAM_SIZE_1 1
#define DISPCNT_MODE_0 0
#define DISPCNT_FORCED_BLANK 128
#define DISPCNT_BG0_ON 256
#define BGCNT_CHARBASE(n) ((n) << 2)
#define BGCNT_SCREENBASE(n) ((n) << 8)
#define BGCNT_256COLOR 128
#define BGCNT_TXT256x256 0
#define MODE_CHANGE_NONE 0
#define MODE_CHANGE_PAUSE 2
#define MODE_CHANGE_DEBUG 4
#define MODE_CHANGE_END_OF_GAME 32
#define MODE_CHANGE_BALL_SAVER 8
#define STATE_GAME_IDLE 99
#define A_BUTTON 1
#define B_BUTTON 2
#define SELECT_BUTTON 4
#define START_BUTTON 8
#define DPAD_UP 64
#define DPAD_DOWN 128
#define R_BUTTON 256
#define L_BUTTON 512
#define JOY_NEW(k) (gMain.newKeys & (k))
#define JOY_HELD(k) (gMain.heldKeys & (k))
#define REG_BG0CNT regs[0]
#define REG_DISPCNT regs[1]
u16 regs[2], video[0x18000 / 2], palettes[512];
u16 beforeVideo[0x18000 / 2], beforePalette[512];
#define VRAM ((void *)video)
#define BG_PLTT ((void *)palettes)
#define BG_SCREEN_ADDR(n) ((u8 *)video + 0x800 * (n))
struct OamData { u32 y:8, affineMode:2, objMode:2, mosaic:1, bpp:1, shape:2;
    u32 x:9, matrixNum:3, hFlip:1, vFlip:1, size:2;
    u16 tileNum:10, priority:2, paletteNum:4; u16 affineParam; };
struct OamData gOamBuffer[128], beforeOam[128];
struct { int selectedField, modeChangeFlags, blendEnabled, blendControl, blendAlpha,
    blendBrightness, dispcntBackup, newKeys, heldKeys, mainState, gameExitState,
    modeChangeDelayTimer, pendingModeChangeType;
    struct { u16 xOffset, yOffset; } bgOffsets[4];
    struct { struct { s16 oamId; } oam[16]; } spriteGroups[3]; } gMain;
struct { u16 area, pauseAnimTimer, pauseMenuCursorIndex, startButtonDisabled,
    debugMenuSelection, activePortraitType; } game;
#define gCurrentPinballGame (&game)
struct { u8 pokedexFlags[NUM_SAVE_SPECIES]; } gMain_saveData;
u8 gExtraPokedexFlags[NUM_SPECIES - NUM_SAVE_SPECIES];
int candidateCount = 16, lastSound;
u16 candidates[16];
void m4aSongNumStart(int sound) { lastSound = sound; }
u16 GetCurrentAreaCatchEncounters(u16 *out) {
    int i; for (i = 0; i < candidateCount; i++) out[i] = candidates[i]; return candidateCount;
}
#ifdef _MSC_VER
typedef unsigned __int64 host_size;
#define EXPORT __declspec(dllexport)
#else
typedef unsigned long host_size;
#define EXPORT
#endif
void *memset(void *dst, int value, host_size size) {
    u8 *p = dst; while (size--) *p++ = value; return dst;
}
void *memcpy(void *dst, const void *src, host_size size) {
    u8 *d = dst; const u8 *s = src; while (size--) *d++ = *s++; return dst;
}
void *Map(void *ptr) {
    host_size p = (host_size)ptr;
    if (p >= 0x06000000 && p < 0x06018000) return (u8 *)video + p - 0x06000000;
    return ptr;
}
#define DmaCopy16(ch, src, dst, size) memcpy(Map((void *)(dst)), Map((void *)(src)), size)
void EncountersPause_Begin(void);
void EncountersPause_End(void);
void EncountersPause_Draw(void);
void PauseGame(void) { game.pauseMenuCursorIndex = 1; EncountersPause_Begin(); }
void UnpauseGame(void) { EncountersPause_End(); }
void PositionPauseMenuSprites(void) {}
void AnimatePauseMenuOverlay(void) { EncountersPause_Draw(); }
'''

TESTS = r'''
#define CHECK(x) do { if (!(x)) return __LINE__; } while (0)
int Equal(const void *a, const void *b, int size) {
    const u8 *x = a, *y = b; while (size--) if (*x++ != *y++) return 0; return 1;
}
void ResetFixture(void) {
    int i, j, id = 0;
    memset(&gMain, 0, sizeof(gMain)); memset(&game, 0, sizeof(game));
    memset(gMain_saveData.pokedexFlags, 0, sizeof(gMain_saveData.pokedexFlags));
    memset(gExtraPokedexFlags, 0, sizeof(gExtraPokedexFlags));
    for (i = 0; i < 128; i++) {
        memset(&gOamBuffer[i], 0, sizeof(gOamBuffer[i]));
        gOamBuffer[i].affineMode = 2; gOamBuffer[i].affineParam = i + 256;
    }
    for (i = 0; i < 3; i++) for (j = 0; j < (i == 0 ? 11 : i == 1 ? 2 : 3); j++) gMain.spriteGroups[i].oam[j].oamId = id++;
    for (i = 0; i < 0x18000 / 2; i++) video[i] = i ^ 0x1357;
    for (i = 0; i < 512; i++) palettes[i] = i;
    gMain.dispcntBackup = regs[1] = 0x1F40; regs[0] = 0x1508;
    gMain.bgOffsets[0].xOffset = 12; gMain.bgOffsets[0].yOffset = 352;
    gMain.blendControl = 0xCF; gMain.blendBrightness = 10; gMain.blendEnabled = 1;
    gMain.heldKeys = 0; candidateCount = 16; game.pauseAnimTimer = 24;
}
EXPORT int TestScreen(void) {
    int n, i, repeat;
    InitAssets();
    for (repeat = 0; repeat < 3; repeat++)
    for (n = 0; n <= 16; n++) {
        ResetFixture(); candidateCount = n;
        gMain.newKeys = START_BUTTON; AllBoardProcess_1B_47160();
        CHECK(gMain.modeChangeFlags == MODE_CHANGE_PAUSE && game.pauseMenuCursorIndex == 1);
        CHECK(sPauseLabel.active);
        memcpy(beforeVideo, video, sizeof(video)); memcpy(beforePalette, palettes, sizeof(palettes));
        memcpy(beforeOam, gOamBuffer, sizeof(gOamBuffer));
        gMain.newKeys = DPAD_DOWN; AllBoardProcess_1B_47160(); CHECK(game.pauseMenuCursorIndex == 2);
        for (i = 0; i < 128; i++) CHECK(gOamBuffer[i].affineParam == i + 256);
        gMain.newKeys = A_BUTTON; AllBoardProcess_1B_47160(); CHECK(Encounters_IsOpen());
        CHECK(sEncounters.pageCount == (n > 8 ? 2 : 1)); CHECK(sEncounters.page == 0);
        CHECK(gMain.modeChangeFlags == MODE_CHANGE_PAUSE && !gMain.gameExitState);
        CHECK(gMain.dispcntBackup == 256 && gMain.bgOffsets[0].yOffset == 0);
        gMain.newKeys = L_BUTTON; Encounters_Update(); CHECK(sEncounters.page == sEncounters.pageCount - 1);
        gMain.newKeys = R_BUTTON; Encounters_Update(); CHECK(sEncounters.page == 0);
        for (i = 0; i < 6; i++) { gMain.newKeys = R_BUTTON; Encounters_Update(); }
        gMain.newKeys = repeat & 1 ? START_BUTTON : B_BUTTON; Encounters_Update();
        CHECK(!Encounters_IsOpen() && gMain.modeChangeFlags == MODE_CHANGE_PAUSE);
        CHECK(Equal(beforeVideo, video, sizeof(video)) && Equal(beforePalette, palettes, sizeof(palettes)));
        CHECK(Equal(beforeOam, gOamBuffer, sizeof(gOamBuffer)));
        CHECK(regs[0] == 0x1508 && gMain.dispcntBackup == 0x1F40);
        CHECK(gMain.bgOffsets[0].xOffset == 12 && gMain.bgOffsets[0].yOffset == 352);
        CHECK(gMain.blendControl == 0xCF && gMain.blendBrightness == 10);
        gMain.newKeys = B_BUTTON; AllBoardProcess_1B_47160(); CHECK(!sPauseLabel.active);
        CHECK(!gMain.modeChangeFlags);
        for (i = 0; i < 128; i++) CHECK(video[0x17F00 / 2 + i] == ((0x17F00 / 2 + i) ^ 0x1357));
    }
    ResetFixture(); gMain.selectedField = MAIN_FIELD_COUNT;
    gMain.modeChangeFlags = MODE_CHANGE_PAUSE; Encounters_Open(); CHECK(!Encounters_IsOpen());
    game.pauseMenuCursorIndex = 1; gMain.newKeys = DPAD_DOWN; AllBoardProcess_1B_47160();
    CHECK(game.pauseMenuCursorIndex == 0 && !sPauseLabel.active);
    ResetFixture(); gMain.modeChangeFlags = MODE_CHANGE_PAUSE;
    game.area = AREA_COUNT; Encounters_Open(); CHECK(!Encounters_IsOpen());
    game.area = 0; gMain.modeChangeFlags = 0; Encounters_Open(); CHECK(!Encounters_IsOpen());
    for (i = 0; i < NUM_SPECIES; i++) {
        CHECK(!IsCaught(i));
        if (i < NUM_SAVE_SPECIES) gMain_saveData.pokedexFlags[i] = 1;
        else gExtraPokedexFlags[i - NUM_SAVE_SPECIES] = 1;
        CHECK(!IsCaught(i));
        if (i < NUM_SAVE_SPECIES) gMain_saveData.pokedexFlags[i] = 4;
        else gExtraPokedexFlags[i - NUM_SAVE_SPECIES] = 4;
        CHECK(IsCaught(i));
    }
    CHECK(!IsCaught(NUM_SPECIES));
    return 0;
}
EXPORT void Preview(int page) {
    int i, mon; ResetFixture(); InitAssets(); gMain.modeChangeFlags = MODE_CHANGE_PAUSE;
    candidateCount = 12;
    for (i = 0; i < candidateCount; i++) if (i % 3 != 1) {
        mon = candidates[i];
        if (mon < NUM_SAVE_SPECIES) gMain_saveData.pokedexFlags[mon] = 4;
        else gExtraPokedexFlags[mon - NUM_SAVE_SPECIES] = 4;
    }
    sEncounters.active = 0; Encounters_Open(); sEncounters.page = page; RenderEncounters();
}
EXPORT void *Video(void) { return video; }
EXPORT void *Palettes(void) { return palettes; }
'''


def pack_portrait(path):
    w, h, pixels, palette = assets.read_png(path, indexed=True)
    assert (w, h) == (48, 32) and max(pixels) < 16
    tiles = []
    for ty in range(4):
        for tx in range(6):
            for y in range(8):
                for x in range(0, 8, 2):
                    p = (ty * 8 + y) * w + tx * 8 + x
                    tiles.append(pixels[p] | (pixels[p + 1] << 4))
    colors = [(r >> 3) | ((g >> 3) << 5) | ((b >> 3) << 10) for r, g, b in palette[:16]]
    return tiles, colors + [0] * (16 - len(colors))


def array(values):
    return '{' + ','.join(str(v) for v in values) + '}'


def fixture_assets():
    info = guide.species_data(ROOT)
    ids = dict((name, int(number)) for name, number in re.findall(
        r'#define (SPECIES_\w+)\s+(\d+)', guide.read(ROOT, 'include/constants/species.h')))
    names = ['SPECIES_EEVEE', 'SPECIES_RALTS', 'SPECIES_MISDREAVUS', 'SPECIES_TURTWIG',
             'SPECIES_CHIMCHAR', 'SPECIES_PIPLUP', 'SPECIES_SHINX', 'SPECIES_BUIZEL',
             'SPECIES_GIBLE', 'SPECIES_STUNKY', 'SPECIES_GLAMEOW', 'SPECIES_SPIRITOMB',
             'SPECIES_SNEASEL', 'SPECIES_SNOVER', 'SPECIES_ABSOL', 'SPECIES_SLAKOTH']
    data, palettes = [], []
    for name in names:
        path = next((ROOT / 'graphics/mon_portraits').glob(f'{info[name]["number"]}_*_portrait.png'))
        gfx, pal = pack_portrait(path)
        data.append(array(gfx)); palettes.append(array(pal))
    forest, pal = pack_portrait(ROOT / 'graphics/area_portraits/loc00_ruby_forest.png')
    result = 'const u8 gLocationPortraitGfx[15][0x300] = {' + array(forest) + '};\n'
    result += 'const u16 gLocation_Pals[240] = ' + array(pal) + ';\n'
    result += 'const s16 gAreaPortraitIndexes[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,12,13,14};\n'
    result += 'u8 monTiles[34][15*0x300]; u16 monPals[34][16][16];\n'
    result += 'u8 *gMonPortraitGroupGfx[34]; const Palette *gMonPortraitGroupPals[34];\n'
    result += 'const u8 samples[16][0x300] = {' + ','.join(data) + '};\n'
    result += 'const u16 samplePals[16][16] = {' + ','.join(palettes) + '};\n'
    result += 'const u16 sampleIds[16] = ' + array([ids[n] for n in names]) + ';\n'
    result += '''void InitAssets(void) { int i, id;
        for (i = 0; i < 34; i++) { gMonPortraitGroupGfx[i] = monTiles[i]; gMonPortraitGroupPals[i] = monPals[i]; }
        for (i = 0; i < 16; i++) { id = sampleIds[i]; candidates[i] = id;
            memcpy(monTiles[id/15] + (id%15)*0x300, samples[i], 0x300);
            memcpy(monPals[id/15][id%15], samplePals[i], 32); }
    }\n'''
    return result


def write_png(path, lib):
    lib.Video.restype = lib.Palettes.restype = ctypes.c_void_p
    video = ctypes.string_at(lib.Video(), 0xA000)
    palette = struct.unpack('<256H', ctypes.string_at(lib.Palettes(), 512))
    def portrait_colors(slot):
        left, top = 13 + (slot % 4) * 56, 70 + (slot // 4) * 47
        return {palette[video[((y // 8) * 30 + x // 8) * 64 + (y % 8) * 8 + x % 8]]
                for y in range(top, top + 32) for x in range(left, left + 48)}
    if path.stem == 'page-1':
        assert len(portrait_colors(0)) > 2, 'Caught portrait must retain its colors'
        assert portrait_colors(1) == {0, 0x7fff}, 'Uncaught portrait must be a black silhouette'
    else:
        assert portrait_colors(5) == {0x7fff}, 'Unused slots must remain empty'
    raw = bytearray()
    for y in range(160):
        raw.append(0)
        for x in range(240):
            index = video[((y // 8) * 30 + x // 8) * 64 + (y % 8) * 8 + x % 8]
            color = palette[index]
            raw.extend(((color & 31) * 255 // 31, ((color >> 5) & 31) * 255 // 31, ((color >> 10) & 31) * 255 // 31))
    def chunk(kind, data):
        return struct.pack('>I', len(data)) + kind + data + struct.pack('>I', zlib.crc32(kind + data))
    path.write_bytes(b'\x89PNG\r\n\x1a\n' + chunk(b'IHDR', struct.pack('>IIBBBBB', 240, 160, 8, 2, 0, 0, 0))
                     + chunk(b'IDAT', zlib.compress(raw)) + chunk(b'IEND', b''))


def main():
    assert assets.OUTPUT.read_text() == assets.generate()
    main_source = guide.read(ROOT, 'src/main.c')
    vcount = guide.function(main_source, 'VCountIntr')
    assert vcount.index('Encounters_IsOpen()') < vcount.index('REG_BG0VOFS')
    assert re.search(r'if \(!Encounters_IsOpen\(\)\)\s+RenderManaphyEggPalette\(\);', main_source)
    frame = guide.function(guide.read(ROOT, 'src/all_board_pinball_game_main.c'), 'MainGameFrameUpdate')
    assert (frame.index('CurrentBoardProcPairs_020028D8[1].updateFunc();')
            < frame.index('Encounters_IsOpen()') < frame.index('UpdateScrollingBackgroundTiles'))
    linker = guide.read(ROOT, 'ld_script.txt')
    for section in ('ewram_data', '.text', '.rodata'):
        assert f'src/encounters.o({section})' in linker
    assert 'ASSERT(VerifySramFast + 4 <= 0x02040000' in linker
    source = guide.read(ROOT, 'src/encounters.c')
    source = re.sub(r'^#include(?! "data/encounters_assets.h")[^\n]*\n', '', source, flags=re.M)
    process = guide.function(guide.read(ROOT, 'src/all_board_process1.c'), 'AllBoardProcess_1B_47160')
    code = PRELUDE + fixture_assets() + source + '\nvoid ' + process + '\n' + TESTS
    candidates = sorted(Path('C:/Program Files/Microsoft Visual Studio').glob('*/Community/VC/Tools/MSVC/*/bin/Hostx64/x64/cl.exe'))
    with tempfile.TemporaryDirectory(prefix='encounters-screen-') as tmp:
        work = Path(tmp); cfile = work / 'test.c'; cfile.write_text(code)
        dll = work / ('test.dll' if os.name == 'nt' else 'test.so')
        if os.name == 'nt':
            command = [str(candidates[-1]), '/nologo', '/W3', '/WX', '/GS-', '/Od', '/LD',
                       f'/I{ROOT / "include"}', f'/I{ROOT / "src"}', str(cfile),
                       '/link', '/nodefaultlib', '/noentry', f'/out:{dll}']
        else:
            command = [shutil.which('cc'), '-shared', '-fPIC', '-fno-builtin', '-std=gnu89', '-Wall', '-Werror',
                       '-I', str(ROOT / 'include'), '-I', str(ROOT / 'src'), str(cfile), '-o', str(dll)]
        subprocess.run(command, cwd=work, check=True)
        lib = ctypes.CDLL(str(dll))
        status = lib.TestScreen()
        assert status == 0, (status, code.splitlines()[status - 1] if status else '')
        output = ROOT / 'build/encounters-preview'; output.mkdir(parents=True, exist_ok=True)
        for page in range(2):
            lib.Preview(page); write_png(output / f'page-{page + 1}.png', lib)
        if os.name == 'nt':
            ctypes.windll.kernel32.FreeLibrary(ctypes.c_void_p(lib._handle))
    print('PASS: real UI C code, 0..16 encounters, L/R wrap, pause navigation, repeated open/close, '
          'VRAM/palette/OAM restoration, capture flags, empty slots and bonus guard.')
    print('Rendered previews:', output)


if __name__ == '__main__':
    main()
