"""Audit normal catch/egg -> evolution routes without transferring between boards.

Uses the real C lotteries, evolution selector and Dex registration. Legendary
events are tested separately by test_legendary_encounters/test_manaphy_egg.
"""

import json
import ctypes
import os
from pathlib import Path
import re
import shutil
import subprocess
import tempfile

import generate_encounter_guide as guide
import test_gen4_encounters as runtime

ROOT = guide.ROOT

AUDIT = r'''
#ifdef _WIN32
#define EXPORT __declspec(dllexport)
#else
#define EXPORT
#endif
static u8 reachable[4][MAIN_FIELD_COUNT][NUM_SPECIES];
static u8 *activeReachable;
static int changed;

void SetDex(u16 species, u8 flag)
{
    if (species >= SPECIES_NONE) return;
    if (species < NUM_SAVE_SPECIES) gMain_saveData.pokedexFlags[species] = flag;
    else gExtraPokedexFlags[species - NUM_SAVE_SPECIES] = flag;
    if (flag == SPECIES_CAUGHT && activeReachable && !activeReachable[species])
    {
        activeReachable[species] = 1;
        changed = 1;
    }
}

EXPORT void AuditRoutes(void)
{
    int gen, field, slot, arrows, roll, total, mon;
    u16 species;
    gMain.mainState = 1;
    game.debugForcedCatchSpecies = SPECIES_NONE;
    game.debugForcedEggSpecies = SPECIES_NONE;
    game.caughtMonCount = 20;
    /* No legendary interception: normal routes only, without DEBUG/e-Reader. */
    do
    {
        changed = 0;
        for (gen = GENERATION_1; gen <= GENERATION_4; gen++)
        for (field = FIELD_RUBY; field <= FIELD_SAPPHIRE; field++)
        {
            gSelectedGeneration = gen;
            gMain.selectedField = field;
            activeReachable = reachable[gen - GENERATION_1][field];
            /* Explore each context from its own fresh Dex. Otherwise a branch
             * caught in the previous context can hide a valid first-time route. */
            for (mon = 0; mon < NUM_SPECIES; mon++)
                SetDex((u16)mon, activeReachable[mon] ? SPECIES_CAUGHT : SPECIES_UNSEEN);
            for (slot = 0; slot < (int)ARRAY_COUNT(auditAreas[field]); slot++)
            {
                game.area = auditAreas[field][slot];
                game.lastCatchSpecies = SPECIES_NONE;
                for (arrows = 2; arrows <= 3; arrows++)
                {
                    game.catchModeArrows = (s16)arrows;
                    BuildSpeciesWeightsForCatchEmMode();
                    total = game.totalWeight;
                    gMain.mainState = STATE_GAME_IDLE;
                    /* Freeze Dex weights for this lottery, then register its outcomes. */
                    for (roll = 0; roll < total; roll++)
                    {
                        nextRoll = (u32)roll;
                        PickSpeciesForCatchEmMode();
                        species = game.currentSpecies;
                        if (species < SPECIES_NONE && !activeReachable[species])
                        {
                            activeReachable[species] = 1;
                            changed = 1;
                        }
                    }
                    gMain.mainState = 1;
                }
                game.lastEggSpecies = SPECIES_NONE;
                BuildSpeciesWeightsForEggMode();
                total = game.totalWeight;
                /* The picker recalculates weights; keep Dex fixed through this loop. */
                for (roll = 0; roll < total * 50; roll++)
                {
                    nextRoll = (u32)roll;
                    game.lastEggSpecies = SPECIES_NONE;
                    PickSpeciesForEggMode();
                    species = game.currentSpecies;
                    if (species < SPECIES_NONE && !activeReachable[species])
                    {
                        activeReachable[species] = 1;
                        changed = 1;
                    }
                }
                for (mon = 0; mon < NUM_SPECIES; mon++)
                {
                    if (!activeReachable[mon]) continue;
                    SetDex((u16)mon, SPECIES_CAUGHT);
                    /* Match the game's eligibility for adding a Pokemon to the party. */
                    if (!gSpeciesInfo[mon].evolutionMethod
                     || gSpeciesInfo[mon].evolutionTarget >= SPECIES_NONE) continue;
                    if (GetEvolutionMethodForCurrentContext((u16)mon) <= 0) continue;
                    game.currentSpecies = (u16)mon;
                    RegisterCaptureOrEvolution(1);
                }
            }
        }
    } while (changed);
}

EXPORT int HasRoute(u16 species)
{
    int gen, field;
    for (gen = 0; gen < 4; gen++)
    for (field = 0; field < MAIN_FIELD_COUNT; field++)
        if (reachable[gen][field][species]) return 1;
    return 0;
}

EXPORT int HasContextRoute(int gen, int field, u16 species)
{
    return reachable[gen][field][species];
}
'''


def sample(source, ids):
    compiler = os.environ.get('CC') or shutil.which('cc') or shutil.which('cl')
    if not compiler and os.name == 'nt':
        candidates = sorted(Path('C:/Program Files/Microsoft Visual Studio').glob(
            '*/Community/VC/Tools/MSVC/*/bin/Hostx64/x64/cl.exe'))
        if candidates:
            compiler = str(candidates[-1])
    if not compiler:
        raise SystemExit('A host C compiler (cc or MSVC cl) is required.')
    with tempfile.TemporaryDirectory(prefix='evolution-routes-') as temporary:
        work = Path(temporary)
        path = work / 'audit.c'
        path.write_text(source)
        library = work / ('audit.dll' if os.name == 'nt' else 'audit.so')
        env = os.environ.copy()
        if Path(compiler).name.lower() in ('cl', 'cl.exe'):
            env['PATH'] = str(Path(compiler).parent) + os.pathsep + env['PATH']
            command = [compiler, '/nologo', '/W3', '/WX', '/GS-', '/Od', '/LD',
                       f'/I{ROOT / "include"}', str(path), '/link', '/nodefaultlib',
                       '/noentry', f'/out:{library}']
        else:
            command = [compiler, '-std=c99', '-Wall', '-Wextra', '-Werror', '-shared', '-fPIC',
                       '-I', str(ROOT / 'include'), str(path), '-o', str(library)]
        subprocess.run(command, cwd=work, env=env, check=True)
        lib = ctypes.CDLL(str(library))
        try:
            lib.AuditRoutes.argtypes = []
            lib.AuditRoutes.restype = None
            lib.HasRoute.argtypes = [ctypes.c_uint16]
            lib.HasRoute.restype = ctypes.c_int
            lib.HasContextRoute.argtypes = [ctypes.c_int, ctypes.c_int, ctypes.c_uint16]
            lib.HasContextRoute.restype = ctypes.c_int
            lib.AuditRoutes()
            obtainable = {mon for mon, number in ids.items() if lib.HasRoute(number)}
            contexts = {(gen, field, mon) for gen in range(4) for field in range(2)
                        for mon, number in ids.items() if lib.HasContextRoute(gen, field, number)}
            return obtainable, contexts
        finally:
            if os.name == 'nt':
                import _ctypes
                _ctypes.FreeLibrary(lib._handle)


def main():
    info = guide.species_data(ROOT)
    ids = {name: int(number) for name, number in re.findall(
        r'#define (SPECIES_\w+)\s+(\d+)', guide.read(ROOT, 'include/constants/species.h'))
           if name in info}
    manual = json.loads(guide.read(ROOT, guide.MANUAL))
    specials = {entry['species'] for entry in manual['specials']}
    # These also have ordinary routes (Pichu's rare egg is covered by the real picker).
    specials -= {'SPECIES_PICHU', 'SPECIES_CHIKORITA', 'SPECIES_CYNDAQUIL',
                 'SPECIES_TOTODILE', 'SPECIES_AERODACTYL'}
    roulette = guide.read(ROOT, 'data/rom_1.s').split('gAreaRouletteTable::', 1)[1].split('.include', 1)[0]
    areas = re.findall(r'\.2byte (AREA_\w+)', roulette)
    assert len(areas) == 16, 'Update audit for changed roulette size'
    source = runtime.build_source()
    source += 'static const s16 auditAreas[2][8] = {{%s}, {%s}};\n' % (
        ', '.join(areas[:8]), ', '.join(areas[8:]))
    source += AUDIT
    expected = {mon for mon, data in info.items() if data['enabled'] and mon not in specials}
    obtainable, contexts = sample(source, ids)
    assert not expected - obtainable, f'No playable route: {sorted(expected - obtainable)}'
    assert (2, 0, 'SPECIES_HUNTAIL') in contexts
    assert (2, 1, 'SPECIES_GOREBYSS') in contexts
    assert (0, 0, 'SPECIES_POLIWRATH') in contexts
    # Preserve Gen 4's stronger guarantee: its ordinary species work on EACH board.
    for mon in expected:
        if 387 <= info[mon]['number'] <= 493:
            for field in range(2):
                assert (3, field, mon) in contexts, (field, mon)
    # Reproduce both bugs in memory, without changing files on disk.
    for table, mon, target in (('gWildMonLocations', 'SPECIES_CLAMPERL', 'SPECIES_HUNTAIL'),
                               ('gWildMonLocationsGen1', 'SPECIES_POLIWAG', 'SPECIES_POLIWRATH')):
        start = source.index(f'const u16 {table}[AREA_COUNT]')
        end = source.index('\n};', start)
        lines = source[start:end].splitlines()
        rows = guide.catch_tables(ROOT)[table]
        for area in range(16):
            if rows[area * 2][1] == 'Ruby':
                lines[area + 1] = lines[area + 1].replace(mon, 'SPECIES_NONE')
        broken = source[:start] + '\n'.join(lines) + source[end:]
        assert broken != source
        broken_routes, _ = sample(broken, ids)
        assert target not in broken_routes, f'Audit failed to detect blocked {target}'
    print(f'PASS: {len(expected)} ordinary species obtainable across Gen 1-4 and the two boards;')
    print('      real positive-weight catches/eggs, reachable roulette areas, contextual evolutions;')
    print('      Dex progression per context, no cross-board parties; Huntail/Ruby and Gorebyss/Sapphire.')
    print('      Gen 4 on each board; removing Clamperl/Poliwag from Ruby reproduces both blockers.')


if __name__ == '__main__':
    main()
