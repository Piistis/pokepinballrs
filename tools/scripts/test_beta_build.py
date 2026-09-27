"""Check release gates using real C Dex/debug entry points and encounter sources."""

import os
from pathlib import Path
import re
import shutil
import subprocess
import tempfile

import generate_encounter_guide as guide
from test_save_compatibility import validate_schema

ROOT = guide.ROOT
PARKED = {'SPECIES_BLITZLE', 'SPECIES_ZEBSTRIKA', 'SPECIES_AXEW', 'SPECIES_AMAURA',
          'SPECIES_ROWLET', 'SPECIES_APPLIN', 'SPECIES_FUECOCO'}


def main():
    validate_schema()
    debug_config = guide.read(ROOT, 'include/constants/debug.h')
    content_config = guide.read(ROOT, 'include/constants/content.h')
    assert '#define DEBUG_TOOLS_ENABLED FALSE' in debug_config
    assert '#define POST_GEN4_SPECIES_ENABLED FALSE' in content_config
    info, _, _, reachable = guide.build()
    assert not PARKED & reachable, 'Post-Gen 4 species has a natural acquisition route'
    assert {mon for mon, data in info.items() if data['enabled']} <= reachable
    order = guide.read(ROOT, 'data/pokedex_entries/pokedex_order.inc').split('#if POST_GEN4_SPECIES_ENABLED')[0]
    assert [info[mon]['number'] for mon in re.findall(r'SPECIES_\w+', order)] == list(range(1, 494))
    for table in guide.catch_tables(ROOT).values():
        for _, _, _, mons in table:
            assert not PARKED.intersection(mons)
    for table in guide.egg_tables(ROOT).values():
        for mons in table.values():
            assert not PARKED.intersection(mons)
    for parent, data in info.items():
        if parent not in PARKED:
            assert data['evolutionTarget'] not in PARKED

    dex = guide.read(ROOT, 'src/pokedex.c')
    title = guide.read(ROOT, 'src/titlescreen.c')
    menu = guide.read(ROOT, 'src/all_board_mode_change_and_debug_menu.c')
    process = guide.read(ROOT, 'src/all_board_process1.c')
    restore = guide.read(ROOT, 'src/save_and_restore_game.c')
    assert 'gPokedexListEntryCount = ARRAY_COUNT(gPokedexOrder);' in dex
    entry = guide.function(process, 'AllBoardProcess_1B_47160')
    gate = entry[entry.index('#if DEBUG_TOOLS_ENABLED'):entry.index('#endif')]
    assert 'DebugTools_OpenMenu();' in gate and 'DebugTools_TryOpenMenu();' in gate
    assert 'JOY_NEW(START_BUTTON)' in entry[entry.index('#endif'):]
    assert 'DebugMenu_RenderAndHandleInput();' not in guide.function(menu, 'BonusStage_HandleModeChangeFlags')
    assert '#define DEBUG_SOUND_TEST_ENABLED (DEBUG_TOOLS_ENABLED && FALSE)' in title
    assert 'gMain.modeChangeFlags &= ~MODE_CHANGE_DEBUG;' in restore
    disabled = guide.read(ROOT, 'src/generation_select.c').split('sDisabledGenerationOptions[] = {')[1].split('};')[0]
    assert re.findall(r'GENERATION_\d+', disabled) == [f'GENERATION_{i}' for i in range(5, 11)]

    code = r'''
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned char bool8;
#define TRUE 1
#define FALSE 0
#define ARRAY_COUNT(a) (sizeof(a) / sizeof((a)[0]))
#define SPECIES_UNSEEN 0
#define SPECIES_SHARED 1
#define SPECIES_SEEN 2
#define SPECIES_SHARED_AND_SEEN 3
#define SPECIES_CAUGHT 4
#define POKEDEX_RAM_FLAG_COUNT 232
#include "constants/species.h"
#include "constants/content.h"
#include "constants/debug.h"
#if DEBUG_TOOLS_ENABLED
#error Release entry point test requires debug disabled
#endif
u8 gPokedexFlags[232], gExtraPokedexFlags[NUM_SPECIES - NUM_SAVE_SPECIES];
struct { u8 pokedexFlags[NUM_SAVE_SPECIES]; } gMain_saveData;
int gPokedexNumSeen, gPokedexNumOwned;
'''
    array = dex[dex.index('static const s16 gPokedexOrder'):dex.index('static s16 GetPokedexFlag')]
    code += array.replace('#include "../data/pokedex_entries/pokedex_order.inc"',
                          guide.read(ROOT, 'data/pokedex_entries/pokedex_order.inc'))
    for text, name in ((dex, 'GetPokedexFlag'), (dex, 'LoadPokedexFlagsFromSave'),
                       (dex, 'Pokedex_CheckDebugCompleteComboPressed'),
                       (title, 'TitleScreen_CheckDebugPokedexCompleteComboPressed'),
                       (menu, 'DebugTools_OpenMenu'), (menu, 'DebugTools_TryOpenMenu')):
        code += guide.function(text, name) + '\n'
    code += r'''
#define CHECK(x) do { if (!(x)) return __LINE__; } while (0)
int main(void)
{
    int i, j, expected = POST_GEN4_SPECIES_ENABLED ? 500 : 493;
    u16 parked[] = {SPECIES_BLITZLE, SPECIES_ZEBSTRIKA, SPECIES_AXEW, SPECIES_AMAURA,
                    SPECIES_ROWLET, SPECIES_APPLIN, SPECIES_FUECOCO};
    CHECK(ARRAY_COUNT(gPokedexOrder) == expected);
    CHECK(PokedexListPositionToSpecies(-1) == SPECIES_BULBASAUR);
    CHECK(PokedexListPositionToSpecies(492) == SPECIES_ARCEUS);
    CHECK(PokedexListPositionToSpecies(500) == (POST_GEN4_SPECIES_ENABLED ? SPECIES_FUECOCO : SPECIES_ARCEUS));
    for (i = 0; i < expected; i++)
    {
        for (j = i + 1; j < expected; j++) CHECK(gPokedexOrder[i] != gPokedexOrder[j]);
        if (!POST_GEN4_SPECIES_ENABLED)
            for (j = 0; j < 7; j++) CHECK(gPokedexOrder[i] != parked[j]);
    }
    for (i = 0; i < NUM_SAVE_SPECIES; i++) gMain_saveData.pokedexFlags[i] = 4;
    for (i = 0; i < NUM_SPECIES - NUM_SAVE_SPECIES; i++) gExtraPokedexFlags[i] = 4;
    LoadPokedexFlagsFromSave(); CHECK(gPokedexNumOwned == expected && gPokedexNumSeen == expected);
    for (i = 0; i < NUM_SAVE_SPECIES; i++) gMain_saveData.pokedexFlags[i] = 0;
    for (i = 0; i < NUM_SPECIES - NUM_SAVE_SPECIES; i++) gExtraPokedexFlags[i] = 0;
    for (i = 0; i < 7; i++) gExtraPokedexFlags[parked[i] - NUM_SAVE_SPECIES] = 4;
    LoadPokedexFlagsFromSave(); CHECK(gPokedexNumOwned == (POST_GEN4_SPECIES_ENABLED ? 7 : 0));
    for (i = 0; i < 7; i++) CHECK(gExtraPokedexFlags[parked[i] - NUM_SAVE_SPECIES] == 4);
    CHECK(!Pokedex_CheckDebugCompleteComboPressed());
    CHECK(!TitleScreen_CheckDebugPokedexCompleteComboPressed());
    DebugTools_OpenMenu(); DebugTools_TryOpenMenu();
    return 0;
}
'''
    candidates = sorted(Path('C:/Program Files/Microsoft Visual Studio').glob(
        '*/Community/VC/Tools/MSVC/*/bin/Hostx64/x86/cl.exe')) if os.name == 'nt' else []
    compiler = str(candidates[-1]) if candidates else os.environ.get('CC') or shutil.which('cc')
    if not compiler:
        raise SystemExit('A host C compiler is required.')
    with tempfile.TemporaryDirectory(prefix='beta-tests-') as temporary:
        work = Path(temporary)
        source = work / 'test.c'
        source.write_text(code)
        exe = work / ('test.exe' if os.name == 'nt' else 'test')
        for expanded in (0, 1):
            if candidates:
                command = [compiler, '/nologo', '/W3', '/WX', '/GS-', '/Od',
                           f'/DPOST_GEN4_SPECIES_ENABLED={expanded}', f'/I{ROOT / "include"}', str(source),
                           '/link', '/nodefaultlib', '/entry:main', '/subsystem:console', f'/out:{exe}']
            else:
                command = [compiler, '-std=gnu89', '-Wimplicit', '-Wparentheses', '-Werror',
                           f'-DPOST_GEN4_SPECIES_ENABLED={expanded}', '-I', str(ROOT / 'include'),
                           str(source), '-o', str(exe)]
            subprocess.run(command, cwd=work, check=True)
            result = subprocess.run([str(exe)], cwd=work)
            if result.returncode:
                raise SystemExit(f'Beta C regression failed at line/status {result.returncode}')
    print('PASS: beta Dex 493 / re-enabled 500, totals, scroll limits, retained save flags, '
          'debug entry points disabled, START pause retained and no post-Gen 4 acquisition routes.')


if __name__ == '__main__':
    main()
