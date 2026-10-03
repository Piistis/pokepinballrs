"""Exercise the real live/restored evolution preview code without GBA hardware."""

import os
from pathlib import Path
import re
import shutil
import subprocess
import tempfile

import generate_encounter_guide as guide

ROOT = guide.ROOT

FIXTURE = r'''
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
#define TRUE 1
#define FALSE 0
#define PLTT_SLOT_SIZE 0x20
#define BG_SCREEN_SIZE 0x800
#include "constants/species.h"
u16 gBG0TilemapBuffer[0xC00];
u16 gKyogreWaterBackgroundTilemap[0x400];
DEX_STORAGE
struct { u8 pokedexFlags[NUM_SAVE_SPECIES]; } gMain_saveData;
struct Game { u16 currentSpecies, evoTargetSpecies, evoChainPosition; } game;
struct Game *gCurrentPinballGame = &game;
u8 gPokedexSprites_Gfx[0x6000];
u16 gPokedexSprites_Pals[16];
u8 gMonPortraitGroupGfx[(NUM_SPECIES + 14) / 15][15 * 0x300];
u16 gMonPortraitGroupPals[(NUM_SPECIES + 14) / 15][16][16];
const void *loadedGraphics, *loadedPalette;
int copyCount;
void RecordCopy(const void *source, int size)
{
    copyCount++;
    if (size == 0x300) loadedGraphics = source;
    if (size == 0x20) loadedPalette = source;
}
/* Drop hardware destination expressions, retaining actual source selection. */
#define DmaCopy16(channel, source, dest, size) RecordCopy(source, size)
'''

TESTS = r'''
#define CHECK(x) do { if (!(x)) return __LINE__; } while (0)
void SetFlag(u16 species, u8 flag)
{
    if (species < NUM_SAVE_SPECIES) gMain_saveData.pokedexFlags[species] = flag;
    else gExtraPokedexFlags[species - NUM_SAVE_SPECIES] = flag;
}
int main(void)
{
    int species, flag, result, stage;
    for (species = 0; species < 0x400; species++) gKyogreWaterBackgroundTilemap[species] = 0x9000 + species;
    for (stage = 0; stage < 3; stage++)
    {
        for (species = 0; species < NUM_SPECIES; species++) SetFlag(species, species % 5);
        SetFlag(SPECIES_KIRLIA, SPECIES_UNSEEN);
        SetFlag(SPECIES_MISMAGIUS, SPECIES_UNSEEN);
        if (stage == 0) InitSphealTilemap();
        if (stage == 1) RestoreSphealTilemap();
        if (stage == 2) AnimateKyogreTilemap();
        CHECK(GetEvolutionTargetPokedexFlag(SPECIES_KIRLIA) == SPECIES_UNSEEN);
        CHECK(GetEvolutionTargetPokedexFlag(SPECIES_MISMAGIUS) == SPECIES_UNSEEN);
        for (species = 0; species < NUM_SPECIES; species++)
            CHECK(GetEvolutionTargetPokedexFlag(species) ==
                  (species == SPECIES_KIRLIA || species == SPECIES_MISMAGIUS ? SPECIES_UNSEEN : species % 5));
    }
    for (species = 0; species < NUM_SPECIES; species++)
    {
        /* Opposite parent/target flags catch queries for the wrong species. */
        game.currentSpecies = species == SPECIES_KIRLIA ? SPECIES_RALTS : SPECIES_MISDREAVUS;
        if (game.currentSpecies == species) game.currentSpecies = SPECIES_RALTS;
        game.evoTargetSpecies = species;
        for (flag = SPECIES_UNSEEN; flag <= SPECIES_CAUGHT; flag++)
        {
            SetFlag(game.currentSpecies, flag == SPECIES_CAUGHT ? SPECIES_UNSEEN : SPECIES_CAUGHT);
            SetFlag(species, flag);
            CHECK(GetEvolutionTargetPokedexFlag(species) == flag);
            for (game.evoChainPosition = 1; game.evoChainPosition <= 2; game.evoChainPosition++)
            {
                copyCount = 0;
                Preview();
                CHECK(copyCount == 2);
                if (flag == SPECIES_UNSEEN)
                {
                    CHECK(loadedGraphics == gPokedexSprites_Gfx + 0x5C00);
                    CHECK(loadedPalette == gPokedexSprites_Pals);
                }
                else
                {
                    CHECK(loadedGraphics == gMonPortraitGroupGfx[species / 15] + species % 15 * 0x300);
                    CHECK(loadedPalette == (flag < SPECIES_CAUGHT ? gMonPortraitGroupPals[0][15]
                          : gMonPortraitGroupPals[species / 15][species % 15]));
                }
            }
            game.evoChainPosition = 0;
            Preview();
            result = game.currentSpecies;
            CHECK(loadedGraphics == gMonPortraitGroupGfx[result / 15] + result % 15 * 0x300);
            CHECK(loadedPalette == gMonPortraitGroupPals[result / 15][result % 15]);
        }
    }
    CHECK(GetEvolutionTargetPokedexFlag(NUM_SPECIES) == SPECIES_UNSEEN);
    CHECK(GetEvolutionTargetPokedexFlag(0xFFFF) == SPECIES_UNSEEN);
    return 0;
}
'''


def main():
    variables = guide.read(ROOT, 'include/variables.h')
    if '#define gExtraPokedexFlags gUnknown_03006C00' in variables:
        # Recreate the actual IWRAM overlap before the fix.
        symbols = guide.read(ROOT, 'sym_bss.txt')
        addresses = dict(re.findall(r'(\w+): @ (0x[0-9A-Fa-f]+)', symbols))
        offset = int(addresses['gUnknown_03006C00'], 16) - int(addresses['gBG0TilemapBuffer'], 16)
        storage = f'#define gExtraPokedexFlags ((u8 *)gBG0TilemapBuffer + {offset})'
    else:
        assert 'extern u8 gExtraPokedexFlags[NUM_SPECIES - NUM_SAVE_SPECIES];' in variables
        storage = re.search(r'EWRAM_DATA u8 gExtraPokedexFlags\[[^;]+;', guide.read(ROOT, 'src/save.c'))[0]
        storage = '#define EWRAM_DATA\n#define EXTRA_POKEDEX_FLAGS_COUNT (NUM_SPECIES - NUM_SAVE_SPECIES)\n' + storage
        linker = guide.read(ROOT, 'ld_script.txt').split('/* start of iwram */')[0]
        assert 'src/save.o(ewram_data);' in linker
    spheal = guide.read(ROOT, 'src/spheal_process3.c')
    fill_start = spheal.index('for (i = 0; i < 0x800; i++)')
    fill_end = spheal.index('gMain.blendControl', fill_start)
    overlay_start = spheal.index('for (i = 0; i < 0x140; i++)', fill_end)
    overlay_end = spheal.index('gMain.bgOffsets', overlay_start)
    init_spheal = ('void InitSphealTilemap(void) { s16 i;\n'
                   + spheal[fill_start:fill_end] + spheal[overlay_start:overlay_end] + '}\n')
    restore = guide.function(guide.read(ROOT, 'src/save_and_restore_game.c'), 'RestoreSphealBonusGraphics')
    fill_start = restore.index('for (i = 0; i < 0x800; i++)')
    fill_end = restore.index('gMain.blendControl', fill_start)
    overlay_start = restore.index('for (i = 0; i < 0x140; i++)', fill_end)
    overlay_end = restore.index('gMain.bgOffsets', overlay_start)
    init_spheal += ('void RestoreSphealTilemap(void) { s16 i; int var0; u16 var1;\n'
                    + restore[fill_start:fill_end] + restore[overlay_start:overlay_end] + '}\n')
    kyogre = guide.read(ROOT, 'src/kyogre_process3.c')
    start = kyogre.index('for (i = 0; i < 0x400; i++)\n        gBG0TilemapBuffer[0x800 + i]')
    end = kyogre.index('DmaCopy16', start)
    init_spheal += 'void AnimateKyogreTilemap(void) { s16 i; int index = 3;\n' + kyogre[start:end] + '}\n'
    constants = '\n'.join(re.findall(r'^#define SPECIES_\w+ \d+$',
                                     guide.read(ROOT, 'include/variables.h'), re.M))
    candidates = list(Path('C:/Program Files/Microsoft Visual Studio/2022/Community/VC/Tools/MSVC')
                      .glob('*/bin/Hostx64/x86/cl.exe')) if os.name == 'nt' else []
    compiler = str(sorted(candidates)[-1]) if candidates else shutil.which('cc')
    if not compiler:
        raise SystemExit('A host C compiler is required.')
    for filename, start, end in (
        ('src/all_board_portrait_display.c', 'case PORTRAIT_STATE_EVO_PREVIEW:',
         'case PORTRAIT_STATE_TRAVEL_RAMP_INDICATOR:'),
        ('src/save_and_restore_game.c', 'case 9:\n            useQuestionPortrait', 'case 3:'),
    ):
        source = guide.read(ROOT, filename)
        begin = source.index(start)
        branch = source[begin:source.index(end, begin)].split(':', 1)[1]
        code = FIXTURE.replace('DEX_STORAGE', storage) + constants + '\n' + init_spheal
        for name, result_type in (('GetPortraitGfxIndexForSpecies', 'u16'),
                                  ('GetEvolutionTargetPokedexFlag', 's16')):
            code += result_type + ' ' + guide.function(source, name) + '\n'
        code += 'void Preview(void) { u16 portraitGfxIndex = 0; s16 pokedexFlag, useQuestionPortrait;\n'
        code += 'switch (9) { case 9:' + branch + '} }\n' + TESTS
        with tempfile.TemporaryDirectory(prefix='evolution-portraits-') as temporary:
            work = Path(temporary)
            cfile = work / 'test.c'
            cfile.write_text(code)
            exe = work / ('test.exe' if os.name == 'nt' else 'test')
            if candidates:
                command = [compiler, '/nologo', '/W3', '/WX', '/GS-', '/Od',
                           f'/I{ROOT / "include"}', str(cfile), '/link', '/nodefaultlib',
                           '/entry:main', '/subsystem:console', f'/out:{exe}']
            else:
                command = [compiler, '-std=gnu89', '-Wall', '-Werror', '-I', str(ROOT / 'include'),
                           str(cfile), '-o', str(exe)]
            subprocess.run(command, cwd=work, check=True)
            result = subprocess.run([str(exe)], cwd=work)
            if result.returncode:
                line = code.splitlines()[result.returncode - 1] if os.name == 'nt' else ''
                raise SystemExit(f'{filename}: C regression failed at line/status {result.returncode}: {line.strip()}')
        print(f'PASS: {filename}: Spheal/Kyogre tilemap isolation, all species/Dex states, both evolution stages and parent portrait.')


if __name__ == '__main__':
    main()
