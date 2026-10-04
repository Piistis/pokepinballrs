"""Precompose the encounters UI into deduplicated native BG tiles and an OBJ label."""

import argparse
import hashlib
from pathlib import Path
import struct
import zlib

ROOT = Path(__file__).resolve().parents[2]
OUTPUT = ROOT / 'src/data/encounters_assets.h'


def read_png(path, indexed=False):
    data = path.read_bytes()
    assert data[:8] == b'\x89PNG\r\n\x1a\n'
    w, h, depth, mode, compression, filtering, interlace = struct.unpack('>IIBBBBB', data[16:29])
    assert depth in (4, 8) and mode == 3 and compression == filtering == interlace == 0, path
    pos, compressed, palette = 8, b'', []
    while pos < len(data):
        size = struct.unpack('>I', data[pos:pos + 4])[0]
        kind, chunk = data[pos + 4:pos + 8], data[pos + 8:pos + 8 + size]
        if kind == b'IDAT':
            compressed += chunk
        if kind == b'PLTE':
            palette = [tuple(chunk[i:i + 3]) for i in range(0, size, 3)]
        pos += size + 12
    raw = zlib.decompress(compressed)
    stride = (w * depth + 7) // 8
    assert len(raw) == h * (stride + 1)
    previous, pixels = [0] * stride, []
    for y in range(h):
        kind = raw[y * (stride + 1)]
        row = list(raw[y * (stride + 1) + 1:(y + 1) * (stride + 1)])
        for x in range(stride):
            a, b, c = row[x - 1] if x else 0, previous[x], previous[x - 1] if x else 0
            p = a + b - c
            paeth = min((a, b, c), key=lambda v: abs(p - v))
            row[x] = (row[x] + (0, a, b, (a + b) // 2, paeth)[kind]) & 255
        indices = row if depth == 8 else [v for byte in row for v in (byte >> 4, byte & 15)][:w]
        pixels.extend(indices)
        previous = row
    if indexed:
        return w, h, pixels, palette
    return w, h, [palette[index] for index in pixels]


def generate():
    colors = [(0, 255, 0), (0, 0, 0), (255, 255, 255)]
    images, comments = {}, []
    for name, filename, size in (
        ('Background', 'Encounters.png', (240, 160)),
        ('Frames', 'Encounters_Frames.png', (54, 80)),
        ('Buttons', 'Encounters_Buttons.png', (16, 32)),
    ):
        path = ROOT / 'graphics/options' / filename
        w, h, pixels = read_png(path)
        assert (w, h) == size, path
        indices = []
        for color in pixels:
            if color not in colors:
                colors.append(color)
            indices.append(colors.index(color))
        images[name] = indices
        comments.append(f'/* {filename}: {hashlib.sha256(path.read_bytes()).hexdigest()} */')
    assert len(colors) <= 32, 'UI palette exceeds 32 entries'
    screen = images['Background'][:]
    def blit(name, width, first, rows, left, top):
        for y in range(rows):
            for x in range(width):
                color = images[name][(y + first) * width + x]
                if color:
                    screen[(top + y) * 240 + left + x] = color
    def clear_portrait(left, top, color=2):
        for y in range(32):
            screen[(top+y)*240+left:(top+y)*240+left+48] = [color] * 48
    blit('Frames', 54, 0, 40, 93, 13)
    clear_portrait(96, 18, 32)
    for slot in range(8):
        x, y = 10 + slot % 4 * 56, 66 + slot // 4 * 47
        blit('Frames', 54, 40, 40, x, y)
        clear_portrait(x + 3, y + 5)
    blit('Buttons', 16, 16, 16, 16, 49)
    blit('Buttons', 16, 0, 16, 208, 49)
    tiles, tilemap = [], [0] * 1024
    def tile_at(tx, ty):
        return tuple(screen[(ty*8+y)*240+tx*8+x] for y in range(8) for x in range(8))
    for ty in range(20):
        for tx in range(30):
            tile = tile_at(tx, ty)
            if tile not in tiles:
                tiles.append(tile)
            tilemap[ty*32+tx] = tiles.index(tile)
    # Give the page number four private tiles so no shared background is edited.
    page_tile = len(tiles)
    for tx in range(13, 17):
        tilemap[7*32+tx] = len(tiles)
        tiles.append(tile_at(tx, 7))
    assert len(tiles) <= 256, 'BG tiles must fit below screen block 8'

    path = ROOT / 'graphics/options/Encounters_Word.png'
    w, h, word = read_png(path)
    assert (w, h) == (80, 8), path
    assert all(c == (0, 255, 0) or min(c) >= 248 for c in word), 'Pause label must be white on green'
    comments.append(f'/* {path.name}: {hashlib.sha256(path.read_bytes()).hexdigest()} */')
    # Three 32x8 objects; palette 9 color 12 is already kept white by PauseGame.
    word_tiles = []
    for tx in range(12):
        for y in range(8):
            for x in range(0, 8, 2):
                pixels = [12 if tx*8+x+i < w and word[y*w+tx*8+x+i] != (0,255,0) else 0
                          for i in range(2)]
                word_tiles.append(pixels[0] | (pixels[1] << 4))
    def halfwords(data):
        return [data[i] | data[i+1] << 8 for i in range(0, len(data), 2)]
    def array(name, values):
        return ('static const u16 ' + name + '[] = {\n'
                + '\n'.join('    ' + ', '.join(f'0x{v:04X}' for v in values[i:i+12]) + ','
                            for i in range(0, len(values), 12)) + '\n};\n')
    colors += [(0, 0, 0)] * (32 - len(colors))
    palette = [(r >> 3) | ((g >> 3) << 5) | ((b >> 3) << 10) for r, g, b in colors]
    return ('/* Generated by tools/scripts/generate_encounters_assets.py. */\n'
            + '\n'.join(comments) + f'\n#define ENCOUNTERS_PAGE_TILE {page_tile}\n'
            + array('sEncountersPalette', palette)
            + array('sEncountersBgTiles', halfwords([p for tile in tiles for p in tile]))
            + array('sEncountersTilemap', tilemap)
            + array('sEncountersWord', halfwords(word_tiles)))


if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('--check', action='store_true')
    args = parser.parse_args()
    output = generate()
    if args.check:
        assert OUTPUT.read_text() == output, 'Regenerate encounters assets'
    else:
        OUTPUT.write_text(output, encoding='ascii')
    print('PASS: encounters PNG dimensions, shared palette and generated assets')
