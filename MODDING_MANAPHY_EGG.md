# Manaphy egg event

## Rules

- Capture five Pokemon hatched from eggs in the current game, in any area.
- Failed ordinary hatches, wild catches and evolutions do not increment progress.
- Progress saturates at five. Ordinary eggs outside the ocean do not spend it.
- In Generation 4 or RANDOM, the next delivered egg is Manaphy's egg if progress
  is 5/5 and the current area is AREA_OCEAN_RUBY (ID 4) on Ruby, or
  AREA_OCEAN_SAPPHIRE (ID 5) on Sapphire. AREA_LAKE does not qualify.
- Selection happens when delivery begins: Aerodactyl/Totodile on Ruby, and
  the replacement egg elevator on Sapphire. The special art is visible during
  delivery, while waiting and while opening.
- A delivered egg keeps its identity across travel. An ordinary egg delivered
  outside the ocean does not turn special when entering the ocean later.
- Opening the special egg spends all five captures. Catching Manaphy does not
  count toward the next cycle. If it escapes, earn another five egg captures.
- Progress persists across balls, bonus boards and save/continue. A new game
  resets it. A delivered, unopened Manaphy egg survives ball loss. Old saves
  from the opening-only version preserve progress and any active attempt.

## Artwork

Edit `graphics/stage/main/egg_manaphy.png`: 32x224 pixels, seven vertical 32x32
frames, indexed to 16 colors. The file now contains the custom blue egg art.
Both 4-bit and 8-bit indexed PNG storage are accepted with a 16-color palette;
the game graphics converter generates 4bpp tiles in either case.
Keep index 0 transparent and keep the frame layout, including shell fragments.
The build generates both graphics and palette directly from this PNG. Do not
add a separate `.pal` file: it would override palette generation from the PNG.

The normal egg uses OBJ palette 11, shared with other board elements. The special
egg borrows an OBJ palette bank unused by other visible sprites after the board
has finished drawing. Restore only the software OAM palette indices before the
next board update; keep the displayed egg palette intact during that update.
`DefaultMainCallback` calls `RenderManaphyEggPalette` after `VBlankIntrWait` and
before uploading OAM, returning the previous bank and applying the next one
together. Never restore the hardware palette at the start of every game frame:
the displayed OAM still points to it, causing a black or flickering egg.
If board code has already replaced a borrowed bank, retain those new colors
instead of restoring stale backup data. Pause/save explicitly release the bank
before their palette snapshots, and paused/debug rendering applies the same
2/5 RGB darkening as `PauseGame`. This avoids recoloring delivery
animations (bank 14), portraits, the cave, elevator or launcher. If every bank
is occupied, the renderer hides the egg for that frame rather than corrupting
another sprite's palette. Manaphy's Pokemon animation remains in
`graphics/mon_hatch_sprites/manaphy_hatch.png`.

## Debug testing

With `DEBUG_TOOLS_ENABLED` enabled in `include/constants/debug.h`, open the
in-game debug menu and select `EGG COUNT 0/5 +1`. A adds one successful egg
capture to the counter, up to five. Close the menu and have a NEW egg delivered
in the ocean in Generation 4 or RANDOM to test the complete event. A normal egg
already waiting on the board is not retroactively changed by this debug option.
Open that ordinary egg first, then request the replacement at 5/5 in the ocean.

`FORCE HATCH` overrides natural selection, so forcing another species will not
trigger Manaphy even at 5/5. Forcing Manaphy previews its special egg, bypasses
the area/generation rules and does not spend natural event progress.

Verify on both boards:

1. At 4/5, an egg delivered in the ocean remains ordinary.
2. At 5/5 outside the ocean, a new egg is ordinary and progress stays at five.
3. At 5/5 in the ocean, Generation 4 and RANDOM deliver the blue egg. Its counter
   stays at five until opening, then resets to zero.
4. Generations 1, 2 and 3 do not trigger the event in the ocean.
5. Let Manaphy escape, then capture five ordinary egg Pokemon to retry.
6. Catch Manaphy: the counter stays at zero, not one.
7. Save/continue during delivery, while waiting and during opening; verify
   progress, species and colors. Travel after delivery and verify no reroll.
8. After editing the PNG, verify cracks and fragments, pause/unpause, capture,
   ball loss and the next ordinary egg without recoloring board elements.

## Implementation notes

The event uses the original eight padding bytes at PinballGame offsets
0xF50..0xF57. Do not increase or shift the structure: the memory and save layouts
depend on its existing size. A magic value validates this state for older saves.
Selection is latched at delivery and checked before the
ordinary Pichu/random egg selection. Only the successful egg-capture path adds
progress; cleanup clears the active event without adding another capture.
The prepared/started flags occupy 0xF56/0xF57 without changing the structure size.
Palette scratch data requires explicit `ewram_data` AND `.bss` entries for
`src/main_board_to_be_split.o` in the EWRAM block of `ld_script.txt`. agbcc can
emit zero-initialized static data in `.bss` despite the `EWRAM_DATA` annotation.
The linker's final `/DISCARD/` rejects any section not explicitly included.
Keep both entries, as for `src/main_board_catch_hatch_picker.o`; the host test
checks their presence but does not run the ARM linker.

Run the host regression checks with:

```sh
python tools/scripts/test_manaphy_egg.py
```

These checks execute the event's C functions with a minimal host fixture; they
do not replace compiling the ROM or testing the animation in an emulator.
