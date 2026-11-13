"""Assemble editable Dex PNGs and compile them into native GBA BG/OBJ assets."""

import argparse
import re
import struct
import zlib

from generate_encounters_assets import ROOT, header_font, pack_obj, read_png

DEX = ROOT / 'graphics/pokedex'
OUTPUT = ROOT / 'src/data/pokedex_view_assets.h'
GENERATIONS = range(1, 10)
WIDTH, HEIGHT = 240, 160
ART_PALETTE_START = 80  # Banks 0-3: original UI. Bank 4: outlined names.
FIRST_TILE = 0x1940 // 64
SECOND_TILE = 0x8400 // 64
WINDOW_TILE = 0x1800 // 32


def rgb555(color):
    r, g, b = color
    return (r >> 3) | ((g >> 3) << 5) | ((b >> 3) << 10)


def theme(gen):
    lines = (DEX / f'generations/gen{gen}.pal').read_text().splitlines()
    assert lines[:3] == ['JASC-PAL', '0100', '256'] and len(lines) == 259
    return [tuple(map(int, line.split())) for line in lines[3:]]


def write_indexed(path, width, height, pixels, palette, transparent=False):
    def chunk(kind, data):
        return struct.pack('>I', len(data)) + kind + data + struct.pack('>I', zlib.crc32(kind + data))

    rows = b''.join(b'\0' + bytes(pixels[i:i + width]) for i in range(0, len(pixels), width))
    data = b'\x89PNG\r\n\x1a\n' + chunk(b'IHDR', struct.pack('>IIBBBBB', width, height, 8, 3, 0, 0, 0))
    data += chunk(b'PLTE', bytes(c for color in palette for c in color))
    if transparent:
        data += chunk(b'tRNS', b'\0')
    path.write_bytes(data + chunk(b'IDAT', zlib.compress(rows, 9)) + chunk(b'IEND', b''))


def original_backdrop():
    width, _, pixels, _ = read_png(DEX / 'bg.png', indexed=True)
    screen = [0] * (WIDTH * HEIGHT)
    for layer in (3, 2):
        tilemap = list(struct.unpack('<1024H', (DEX / f'bg{layer}_tilemap.bin').read_bytes()))
        if layer == 2:
            tilemap[0x134] = 0x59
        for y in range(HEIGHT):
            for x in range(WIDTH):
                attr = tilemap[y // 8 * 32 + x // 8]
                tile = attr & 0x3ff
                px = tile % (width // 8) * 8 + ((x % 8) ^ (7 if attr & 0x400 else 0))
                py = tile // (width // 8) * 8 + ((y % 8) ^ (7 if attr & 0x800 else 0))
                color = pixels[py * width + px] & 15
                if color:
                    screen[y * WIDTH + x] = (attr >> 12) * 16 + color
    return screen


def original_prompt():
    w, h, pixels, palette = read_png(DEX / 'sprites_press_start_trans.png', indexed=True)
    assert (w, h) == (24, 32)
    return [p for start in (1, 3) for y in range(8) for row in (0, start, 2)
            for p in pixels[(row * 8 + y) * w:(row * 8 + y + 1) * w]], palette


def prompt_template(original, word):
    glyphs = dict(S=(7, 4, 7, 1, 7), H=(5, 5, 7, 5, 5), I=(7, 2, 2, 2, 7),
                  N=(5, 7, 7, 7, 5), Y=(5, 5, 2, 2, 2), O=(7, 5, 5, 5, 7),
                  R=(6, 5, 6, 5, 5), M=(5, 7, 7, 5, 5), A=(2, 5, 7, 5, 5),
                  L=(4, 4, 4, 4, 7))
    pixels = original[:]
    for frame in range(2):
        top = frame * 8
        for y in range(top, top + 8):
            pixels[y * 72 + 48:y * 72 + 72] = [0] * 24
        left = 48 + (24 - (len(word) * 4 - 1)) // 2
        points = [(left + i * 4 + x, top + 1 + y) for i, char in enumerate(word)
                  for y, row in enumerate(glyphs[char]) for x in range(3) if row & (4 >> x)]
        for x, y in points:
            for dy in (-1, 0, 1):
                for dx in (-1, 0, 1):
                    if 48 <= x + dx < 72:
                        pixels[(y + dy) * 72 + x + dx] = 15
        for x, y in points:
            pixels[y * 72 + x] = 1
    return pixels


def create_templates():
    pixels = original_backdrop()
    original, palette = original_prompt()
    for gen in GENERATIONS:
        path = DEX / f'generations/gen{gen}.png'
        if not path.exists():
            write_indexed(path, WIDTH, HEIGHT, pixels, theme(gen))
    for mode, word in (('shiny', 'SHINY'), ('normal', 'NORMAL')):
        path = DEX / f'press_start_{mode}.png'
        if not path.exists():
            write_indexed(path, 72, 16, prompt_template(original, word), palette, transparent=True)


def compile_background(gen):
    path = DEX / f'generations/gen{gen}.png'
    w, h, colors = read_png(path, alpha=True)
    assert (w, h) == (WIDTH, HEIGHT) and None not in colors, f'{path}: use an opaque 240x160 PNG'
    rgb = list(map(rgb555, colors))
    # Number colors by first pixel so recolors can share identical tile data.
    indices = {color: i + ART_PALETTE_START for i, color in enumerate(dict.fromkeys(rgb))}
    assert len(indices) <= 256 - ART_PALETTE_START, f'{path}: {len(indices)} colors; maximum 176 (RGB555)'
    pixels = bytes(indices[color] for color in rgb)
    palette = list(map(rgb555, theme(gen)[:64])) + [0, 0x7fff, 0] + [0] * 13 + list(indices)
    palette += [0] * (256 - len(palette))

    tiles, seen, tilemap = [], {}, [0] * 1024
    for ty in range(20):
        for tx in range(30):
            tile = b''.join(pixels[(ty * 8 + y) * WIDTH + tx * 8:(ty * 8 + y) * WIDTH + tx * 8 + 8]
                            for y in range(8))
            if tile not in seen:
                slot = len(tiles) + FIRST_TILE
                seen[tile] = slot if slot < 256 else slot - 256 + SECOND_TILE
                tiles.append(tile)
            tilemap[ty * 32 + tx] = seen[tile]
    assert max(tilemap) < 1024, path
    return b''.join(tiles), tuple(tilemap), palette


def compile_window():
    asm = (ROOT / 'data/rom_1.s').read_text()
    rows = [[int(value, 16) for value in re.findall(r'0x[0-9A-Fa-f]+', asm.split(
        f'gDexInfoWindow{name}RowTiles::', 1)[1].split('\n', 1)[1].split('\n\n', 1)[0])]
        for name in ('Middle', 'Bottom')]
    assert all(len(row) == 32 for row in rows)
    tile_ids = sorted({attr & 1023 for row in rows for attr in row})
    width, _, pixels, _ = read_png(DEX / 'bg.png', indexed=True)
    tiles = []
    for tile in tile_ids:
        x, y = tile % (width // 8) * 8, tile // (width // 8) * 8
        tiles += pack_obj([pixels[(y + dy) * width + x + dx] & 15
                           for dy in range(8) for dx in range(8)], 8, 8, 8, 8)
    assert WINDOW_TILE * 32 + len(tiles) <= FIRST_TILE * 64 and not any(tiles[:32])
    remap = {tile: WINDOW_TILE + i for i, tile in enumerate(tile_ids)}
    return tiles, [[(attr & ~1023) | remap[attr & 1023] for attr in row] for row in rows]


def controls():
    palette = [0, 0, 0x7fff]
    w, h, colors = read_png(ROOT / 'graphics/options/Encounters_Buttons.png', alpha=True)
    assert (w, h) == (16, 32)
    buttons = []
    for color in colors:
        if color is None or color == (0, 255, 0):
            buttons.append(0)
        else:
            native = rgb555(color)
            if native not in palette[1:]:
                palette.append(native)
            buttons.append(palette.index(native, 1))
    assert len(palette) <= 16
    font, widths = header_font()
    labels = []
    for gen in GENERATIONS:
        label = f'Gen {gen}'
        cursor = (32 - sum(widths[ord(c) - 32] for c in label)) // 2
        points = []
        for char in label:
            glyph = ord(char) - 32
            points.extend((cursor + x, y) for y in range(16) for x in range(8)
                          if font[glyph * 16 + y] & (1 << x))
            cursor += widths[glyph]
        pixels = [0] * (32 * 16)
        for x, y in points:
            for dy in (-1, 0, 1):
                for dx in (-1, 0, 1):
                    if 0 <= x + dx < 32 and 0 <= y + dy < 16:
                        pixels[(y + dy) * 32 + x + dx] = 1
        for x, y in points:
            pixels[y * 32 + x] = 2
        labels.append(pack_obj(pixels, 32, 16, 32, 16))
    return palette + [0] * (16 - len(palette)), pack_obj(buttons, 16, 32, 16, 16), labels


def compile_prompts():
    palette = [0]
    tiles = []
    for mode in ('shiny', 'normal'):
        path = DEX / f'press_start_{mode}.png'
        w, h, colors = read_png(path, alpha=True)
        assert (w, h) == (72, 16), f'{path}: expected two 72x8 frames, stacked vertically'
        pixels = []
        for color in colors:
            if color is None or color == (255, 0, 255):
                pixels.append(0)
            else:
                native = rgb555(color)
                if native not in palette[1:]:
                    palette.append(native)
                pixels.append(palette.index(native, 1))
        assert len(palette) <= 16, f'{path}: both prompts share 15 opaque colors'
        tiles.extend(pack_obj(pixels, w, h, 8, 8))
    return palette + [0] * (16 - len(palette)), tiles


def generate():
    lines = ['/* Generated by tools/scripts/generate_pokedex_assets.py. */',
             f'#define DEX_BG_FIRST_TILE {FIRST_TILE}', f'#define DEX_BG_SECOND_TILE {SECOND_TILE}']

    def array(name, values):
        lines.append(f'static const u16 {name}[{len(values)}] ALIGNED(4) = {{')
        for i in range(0, len(values), 16):
            lines.append('    ' + ', '.join(f'0x{value:04x}' for value in values[i:i + 16]) + ',')
        lines.append('};')

    def tile_array(name, values):
        array(name, struct.unpack(f'<{len(values)//2}H', bytes(values)))

    unique_tiles, unique_maps, themes = {}, {}, []
    for gen in GENERATIONS:
        tiles, tilemap, palette = compile_background(gen)
        if tiles not in unique_tiles:
            unique_tiles[tiles] = f'sDexBgTiles{gen}'
            tile_array(unique_tiles[tiles], tiles)
        if tilemap not in unique_maps:
            unique_maps[tilemap] = f'sDexBgMap{gen}'
            array(unique_maps[tilemap], tilemap)
        array(f'sDexBgPalette{gen}', palette)
        themes.append(f'    {{ {unique_tiles[tiles]}, {unique_maps[tilemap]}, sDexBgPalette{gen}, {len(tiles)} }},')
    lines += ['static const struct DexTheme sDexThemes[] = {', *themes, '};']
    tiles, rows = compile_window()
    tile_array('sDexWindowTiles', tiles)
    array('sDexWindowMiddleRow', rows[0])
    array('sDexWindowBottomRow', rows[1])
    palette, buttons, labels = controls()
    array('sDexControlPalette', palette)
    tile_array('sDexControlButtons', buttons)
    tile_array('sDexControlLabels', sum(labels, []))
    palette, prompts = compile_prompts()
    array('sDexPromptPalette', palette)
    tile_array('sDexPromptTiles', prompts)
    return '\n'.join(lines) + '\n'


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--create-templates', action='store_true', help='assemble missing editable PNGs')
    parser.add_argument('--check', action='store_true', help='verify generated C data is current')
    args = parser.parse_args()
    if args.create_templates:
        create_templates()
    output = generate()
    if args.check:
        assert OUTPUT.read_text() == output, 'Regenerate Pokedex view assets'
    else:
        OUTPUT.write_text(output, encoding='ascii')


if __name__ == '__main__':
    main()
