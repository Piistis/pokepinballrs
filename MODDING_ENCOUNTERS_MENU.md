# Encounters pause screen

## Scope and controls

- On Ruby and Sapphire, START opens the usual pause menu with a third option,
  ENCOUNTERS. Bonus boards retain the original two options.
- A opens the area overview. L/R change pages with wraparound. B or START returns
  to the pause menu without resuming the game.
- SELECT switches between area and egg lists, resetting to page one. Each view
  shows its name and caught/total (integer percentage, rounded down) for the whole
  list, using saved Pokedex capture flags rather than captures in this run.
- Each page contains eight portraits, in two rows of four. Caught Pokemon use
  their own palettes; both unseen and seen-but-not-caught Pokemon are silhouettes.
- The list combines both normal capture tables (two and three arrows) without
  duplicates. It follows the selected generation and the current RANDOM tables.
- Pokemon exclusive to three arrows have red frames. Pokemon available with two
  arrows, including those also available with three, retain gold frames.
- The egg view combines and deduplicates the actual egg tables for the current
  board/generation (all three egg tables in RANDOM). Pichu is included outside
  Gen 4 when forced or after five captures/evos unless it was the last egg.
  Manaphy is included in Gen 4/RANDOM once five eggs have been caught in this run
  and the board is in its Ocean area, or while the Manaphy egg is already active.
- This is an inventory, not a prediction of the next roll: ordinary eggs stay
  listed despite temporary last-egg/first-capture weight restrictions. Merely
  viewing the egg list never consumes RNG, increments counters or prepares an egg.
- Evolutions and special wild/legendary encounters remain excluded. Empty slots
  stay white. No encounter tables, catch rates or special requirements change.
- Current normal tables allow at most 16 unique Pokemon, so at most two pages.
- Egg storage allows up to 77 entries (75 table slots plus two special eggs),
  although deduplication makes the actual list shorter. Pagination supports ten pages.

## Graphics

Source PNGs in `graphics/options`:

- `Encounters.png`: 240 x 160 background.
- `Encounters_Frames.png`: 54 x 120; area frame, gold Pokemon frame, red frame.
  Each frame is 54 x 40 with a 48 x 32 portrait at offset (3, 5).
- `Encounters_Buttons.png`: 16 x 32; R first, L second.
- `Encounters_Word.png`: 80 x 8 pause label, white on transparent-key green.
- `changemode.png`: 72 x 32; two 72 x 16 guides, Egg first and Area second.
- `egg.png`: 48 x 32 portrait with its own indexed palette (at most 16 colors).
- Header labels use the existing proportional Pokedex font with a one-pixel
  black outline and white foreground. The generator reads `text_glyphs.png` and
  the preprocessor's `dexEncoding`; slash/percent have small explicit glyphs.

Keep these PNGs indexed (4 or 8 bits), non-interlaced. Pure green (0, 255, 0)
is the transparent key for frames/buttons. The combined UI palette may use up to
32 colors. The existing native portraits remain untouched. L/R cells start at
(16, 49) and (208, 49), two pixels above the first implementation.

`make` regenerates `src/data/encounters_assets.h` when a source PNG changes.
Commit the generated header together with any artwork changes:

```sh
python3 tools/scripts/generate_encounters_assets.py
make check-encounters-screen
```

## Runtime and memory

The build script precomposes the background, frames and buttons as deduplicated
8bpp BG0 tiles (currently 122 tiles, including four private page-counter tiles
and prebuilt gold/red tilemap variants).
The tilemap starts at screen block 8 (0x4000). No runtime full-screen pixel loop
or forced blank is used. The old paused board/page remains visible until VBlank.

Portraits use native 4bpp OBJ graphics, six 16 x 16 objects per portrait, with
1D mapping. **Both portrait manifests specify `mwidth: 2, mheight: 2`.** Never
interpret their data as a flat sequence of 8 x 8 tiles: it scrambles both area
art and Pokemon, even when a synthetic test using the same wrong order passes.
OBJ palettes 0..8 belong to the area/egg and eight Pokemon; palette 9 is reserved
for the header labels and guide (nine 32 x 16 OBJ blocks). Uncaught palettes are
black except white index 15. Transparent Pokemon index 0 reveals white underneath;
the area reveals its own palette color 0 via BG color 32.

Opening snapshots BG VRAM 0x06000000..0x060047FF, OBJ VRAM
0x06010000..0x060123FF, all palettes and OAM, BG0 configuration and blending.
`Encounters_VBlank` uploads prepared changes between `VBlankIntrWait` and the
normal OAM/register upload. Page changes transfer at most 8704 bytes; the static
background, header and area do not reload. SELECT updates the header and portraits
in the same VBlank (less than 13 KiB). Closing restores the snapshots in VBlank.

The pause label borrows six non-pause OAM entries: three 32 x 8 objects for the
image and three border extensions. Its 384 OBJ bytes at 0x06017E80 are restored
on unpause, and OAM matrix words are preserved. The label aligns with SAVE's
visible origin, accounting for double-size affine padding, 24 pixels below it.
This puts it on the third row alongside the cursor, not on the bottom border.

The screen and label state use about 35 KiB of separate EWRAM (less than the old
42 KiB renderer). No SaveData, PinballGame or persistent save layout changes.
The linker checks the final live EWRAM pointer against the 256 KiB hardware limit
(not the unused historical filler following it).

While open, PinballGameMain does not advance board logic. The opening frame also
skips subsequent board VRAM updates. VCount HUD scrolling and the Manaphy palette
hook are suppressed until returning to pause.
