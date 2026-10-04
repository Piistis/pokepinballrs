# Encounters pause screen

## Scope and controls

- On Ruby and Sapphire, START opens the usual pause menu with a third option,
  ENCOUNTERS. Bonus boards retain the original two options.
- A opens the area overview. L/R change pages with wraparound. B or START returns
  to the pause menu without resuming the game.
- Each page contains eight portraits, in two rows of four. Caught Pokemon use
  their own palettes; both unseen and seen-but-not-caught Pokemon are silhouettes.
- The list combines both normal capture tables (two and three arrows) without
  duplicates. It follows the selected generation and the current RANDOM tables.
- Eggs, evolutions and special/legendary encounters are deliberately excluded for
  this first version. Empty slots stay white. No encounters or catch rates change.
- Current normal tables allow at most 16 unique Pokemon, so at most two pages.

## Graphics

Source PNGs in `graphics/options`:

- `Encounters.png`: 240 x 160 background.
- `Encounters_Frames.png`: 54 x 80; area frame first, Pokemon frame second.
  Each frame is 54 x 40 with a 48 x 32 portrait at offset (3, 5).
- `Encounters_Buttons.png`: 16 x 32; R first, L second.
- `Encounters_Word.png`: 80 x 8 pause label, white on transparent-key green.

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
8bpp BG0 tiles (currently 95 tiles, including four private page-counter tiles).
The tilemap starts at screen block 8 (0x4000). No runtime full-screen pixel loop
or forced blank is used. The old paused board/page remains visible until VBlank.

Portraits use native 4bpp OBJ graphics, six 16 x 16 objects per portrait, with
1D mapping. **Both portrait manifests specify `mwidth: 2, mheight: 2`.** Never
interpret their data as a flat sequence of 8 x 8 tiles: it scrambles both area
art and Pokemon, even when a synthetic test using the same wrong order passes.
OBJ palettes 0..8 belong to the area and eight Pokemon. Uncaught palettes are
black except white index 15. Transparent Pokemon index 0 reveals white underneath;
the area reveals its own palette color 0 via BG color 32.

Opening snapshots BG VRAM 0x06000000..0x060047FF, OBJ VRAM
0x06010000..0x06011AFF, all palettes and OAM, BG0 configuration and blending.
`Encounters_VBlank` uploads prepared changes between `VBlankIntrWait` and the
normal OAM/register upload. Page changes transfer at most 6656 bytes; the static
background and area do not reload. Closing restores the snapshots in VBlank.

The pause label borrows six non-pause OAM entries: three 32 x 8 objects for the
image and three border extensions. Its 384 OBJ bytes at 0x06017E80 are restored
on unpause, and OAM matrix words are preserved. The label aligns with SAVE's
visible origin, accounting for double-size affine padding, 24 pixels below it.
This puts it on the third row alongside the cursor, not on the bottom border.

The screen and label state use about 28 KiB of separate EWRAM (less than the old
42 KiB renderer). No SaveData, PinballGame or persistent save layout changes.
The linker checks the final live EWRAM pointer against the 256 KiB hardware limit
(not the unused historical filler following it).

While open, PinballGameMain does not advance board logic. The opening frame also
skips subsequent board VRAM updates. VCount HUD scrolling and the Manaphy palette
hook are suppressed until returning to pause.

## Verification

`test_encounters_screen.py` compiles the real renderer, pause animation and input
handler on the host against simulated video memory, using the pause sprite
definitions from `data/rom_2.s`. It covers 0..16 entries, wrapping,
repeated opening/closing, register/VRAM/palette/OAM restoration, affine matrix
preservation, capture flags and bonus-board guards. It renders native-code
previews into `build/encounters-preview`. Fixture tiles follow the actual JSON
metatile settings; an independent BG/OAM decoder compares every portrait pixel
against the original PNG, including silhouettes and empty slots. It also verifies
L/R coordinates, pause label placement, VBlank-only transfers, transfer sizes and
the absence of forced blank. These checks guard the original rendering failures.
`test_gen4_encounters.py` verifies list contents against the real encounter tables,
including RANDOM. These host checks do not replace a GBA build/emulator test.

Before release, test both boards in Gen 1..4 and RANDOM: open from several camera
positions and modes, cycle pages, return to pause, resume, and save/load. Confirm
the timer/ball do not advance and the board/Manaphy egg colors return unchanged.
