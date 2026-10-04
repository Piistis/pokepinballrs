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
  Each frame is 54 x 40 with a 48 x 32 portrait at offset (3, 4).
- `Encounters_Buttons.png`: 16 x 32; R first, L second.

Keep these PNGs indexed (4 or 8 bits), non-interlaced. Pure green (0, 255, 0)
is the transparent key for frames/buttons. The combined UI palette may use up to
32 colors. The existing native portraits remain untouched.

`make` regenerates `src/data/encounters_assets.h` when a source PNG changes.
Commit the generated header together with any artwork changes:

```sh
python3 tools/scripts/generate_encounters_assets.py
make check-encounters-screen
```

## Runtime and memory

`src/encounters.c` renders a temporary 8bpp BG0 screen. It backs up and restores
VRAM 0x06000000..0x06009FFF, BG palettes, BG0 configuration/offsets and blending.
The bitmap occupies 600 tiles; its tilemap starts at screen block 19 (0x9800).
All VRAM pixel writes are 16-bit, as required by GBA hardware.

UI colors use entries 0..31, the area portrait uses bank 2, and the eight Pokemon
use banks 3..10. Portrait index 15 is the silhouette's white background; index 0
is drawn white for Pokemon portraits and retains its color for area portraits.

The small pause label temporarily borrows two non-pause OAM entries and 256 bytes
at OBJ VRAM 0x06017F00, restoring both on unpause. OAM matrix words are preserved.
The screen backup and label state use about 42 KiB of separate EWRAM, explicitly
included by the linker. No SaveData, PinballGame or persistent save layout changes.
The linker checks the final live EWRAM pointer against the 256 KiB hardware limit
(not the unused historical filler following it).

While open, PinballGameMain does not advance board logic. The opening frame also
skips subsequent board VRAM updates. VCount HUD scrolling and the Manaphy palette
hook are suppressed until returning to pause.

## Verification

`test_encounters_screen.py` compiles the real renderer and pause input handler on
the host against simulated video memory. It covers 0..16 entries, wrapping,
repeated opening/closing, register/VRAM/palette/OAM restoration, affine matrix
preservation, capture flags and bonus-board guards. It renders native-code
previews into `build/encounters-preview` and checks silhouette/empty-slot colors.
`test_gen4_encounters.py` verifies list contents against the real encounter tables,
including RANDOM. These host checks do not replace a GBA build/emulator test.

Before release, test both boards in Gen 1..4 and RANDOM: open from several camera
positions and modes, cycle pages, return to pause, resume, and save/load. Confirm
the timer/ball do not advance and the board/Manaphy egg colors return unchanged.
