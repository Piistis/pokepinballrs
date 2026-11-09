"""Build palette-only shiny assets; optionally copy missing editable templates."""

import argparse
import json
from pathlib import Path
import re
import shutil

from generate_encounters_assets import read_png

ROOT = Path(__file__).resolve().parents[2]
OUTPUT = ROOT / 'src/data/shiny_palettes.h'
SOURCES = (
    ('Portrait', 'data/graphics/mon_portraits.inc'),
    ('Catch', 'data/graphics/mon_catch_sprites.inc'),
    ('Hatch', 'data/graphics/mon_hatch_sprites.inc'),
)


def source_groups():
    groups = []
    for name, relative in SOURCES:
        paths = re.findall(r'\.incbin "([^"]+)\.4bpp"', (ROOT / relative).read_text())
        groups.append((name, [ROOT / (path + '.png') for path in paths]))
    bonus = []
    for boss, sheets in (
        ('kyogre', ('body_first15', 'body_after15', 'surfacing_fx_frames')),
        ('groudon', ()),
        ('rayquaza', ('body_variants', 'entity_flying')),
    ):
        folder = ROOT / 'graphics/stage' / boss
        bonus.extend(folder / (name + '.png') for name in sheets)
        manifest = json.loads((folder / (boss + '_stage_gfx.json')).read_text())
        for entry in manifest['files']:
            if entry['gfx_filename'] != 'intro_sprite':
                continue
            for segment in entry['segments']:
                name = segment['segfile']
                if (boss in name or (boss == 'groudon' and re.search(r'head_|face_', name))):
                    bonus.append(folder / (name + '.png'))
    groups.append(('Bonus', bonus))
    return groups


def variant_path(path):
    return path.with_name(path.stem + '_s.png')


def palette_for(base, shiny):
    width, height, pixels, colors = read_png(base, indexed=True)
    sw, sh, variant, shiny_colors = read_png(shiny, indexed=True)
    if (width, height) != (sw, sh) or max(pixels) >= 16 or len(colors) > 16:
        raise ValueError(f'{shiny}: must preserve dimensions and the base 16-color format')
    mapping = {}
    for position, (index, changed) in enumerate(zip(pixels, variant)):
        color = shiny_colors[changed]
        if index in mapping and mapping[index] != color:
            raise ValueError(f'{shiny}: base color {index} maps to multiple colors at '
                             f'({position % width}, {position // width}); edit colors, not the drawing')
        mapping[index] = color
    # Derive by pixel correspondence, so editor palette reordering is harmless.
    result = [mapping.get(i, colors[i] if i < len(colors) else (0, 0, 0)) for i in range(16)]
    to_gba = lambda c: (c[0] >> 3) | ((c[1] >> 3) << 5) | ((c[2] >> 3) << 10)
    ready = any(i != 0 and to_gba(color) != to_gba(colors[i]) for i, color in mapping.items())
    return [to_gba(color) for color in result], ready


def generate(create_templates=False):
    lines = ['/* Generated palette-only shiny assets. No duplicate sprite tiles. */']
    created, counts, ready_count = [], {}, 0
    for name, paths in source_groups():
        palettes, ready = [], []
        for path in paths:
            shiny = variant_path(path)
            if not shiny.exists():
                if not create_templates:
                    raise ValueError(f'Missing shiny template: {shiny}')
                shutil.copyfile(path, shiny)
                created.append(shiny)
            palette, changed = palette_for(path, shiny)
            palettes.append(palette)
            ready.append(int(changed))
        counts[name] = len(paths)
        ready_count += sum(ready)
        lines.append(f'static const u16 sShiny{name}Palettes[][16] = {{')
        for path, palette in zip(paths, palettes):
            lines.append(f'    /* {path.relative_to(ROOT).as_posix()} */')
            lines.append('    {' + ', '.join(f'0x{v:04X}' for v in palette) + '},')
        lines.append('};')
        lines.append(f'static const u8 sShiny{name}Ready[] = {{')
        for i in range(0, len(ready), 32):
            lines.append('    ' + ', '.join(map(str, ready[i:i+32])) + ',')
        lines.append('};')
    return '\n'.join(lines) + '\n', created, counts, ready_count


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--create-templates', action='store_true')
    parser.add_argument('--check', action='store_true')
    args = parser.parse_args()
    output, created, counts, ready = generate(args.create_templates)
    if args.check:
        if not OUTPUT.exists() or OUTPUT.read_text() != output:
            raise SystemExit('Regenerate shiny palettes')
    elif not OUTPUT.exists() or OUTPUT.read_text() != output:
        OUTPUT.write_text(output, encoding='ascii')
    print(f'Shiny palettes: {counts}; {ready} recolored; {len(created)} templates created.')
    print(f'ROM palette bytes: {sum(counts.values()) * 32}; duplicated sprite tile bytes: 0.')


if __name__ == '__main__':
    main()
