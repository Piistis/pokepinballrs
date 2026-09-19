# Manaphy egg event

## Rules

- Capture five Pokemon hatched from eggs in the current game, in any area.
- Failed ordinary hatches, wild catches and evolutions do not increment progress.
- Progress saturates at five. Ordinary eggs outside the ocean do not spend it.
- In Generation 4 or RANDOM, activating hatch mode in AREA_OCEAN_RUBY or
  AREA_OCEAN_SAPPHIRE turns that egg into Manaphy's egg before it opens.
- The area is checked at activation, not later when the species is revealed.
  The waiting/delivery egg remains ordinary until hatch mode is activated.
- Opening the special egg spends all five captures. Catching Manaphy does not
  count toward the next cycle. If it escapes, earn another five egg captures.
- Progress persists across balls, bonus boards and save/continue. A new game
  resets it. Old saves initialize the previously unused bytes to zero.

## Artwork

Edit `graphics/stage/main/egg_manaphy.png`. It is initially an exact copy of
`egg.png`: 32x224 pixels, seven vertical 32x32 frames, indexed to 16 colors.
Keep index 0 transparent and keep the frame layout, including shell fragments.
The build generates both graphics and palette directly from this PNG. Do not
add a separate `.pal` file: it would override palette generation from the PNG.

The normal egg uses OBJ palette 11, shared with other board elements. The special
egg uses palette 14 during eclosion so editing its colors does not recolor the
cave, elevator or launcher. Shell remnants are hidden when capture or a ball-loss
overlay needs that palette. Manaphy's Pokemon animation remains in
`graphics/mon_hatch_sprites/manaphy_hatch.png`.

## Debug testing

With `DEBUG_TOOLS_ENABLED` enabled in `include/constants/debug.h`, open the
in-game debug menu and select `EGG COUNT 0/5 +1`. A adds one successful egg
capture to the counter, up to five. Close the menu and activate a normal hatch
in the ocean in Generation 4 or RANDOM to test the complete event.

`FORCE HATCH` overrides natural selection, so forcing another species will not
trigger Manaphy even at 5/5. Forcing Manaphy previews its special egg, bypasses
the area/generation rules and does not spend natural event progress.

Verify on both boards:

1. At 4/5, an ocean hatch remains ordinary.
2. At 5/5 outside the ocean, it remains ordinary and progress stays at five.
3. At 5/5 in the ocean, Generation 4 and RANDOM hatch Manaphy and reset to zero.
4. Generations 1, 2 and 3 do not trigger the event in the ocean.
5. Let Manaphy escape, then capture five ordinary egg Pokemon to retry.
6. Catch Manaphy: the counter stays at zero, not one.
7. Save/continue at 5/5 and during opening; verify progress, species and colors.
8. After editing the PNG, verify cracks and fragments, pause/unpause, capture,
   ball loss and the next ordinary egg without recoloring board elements.

## Implementation notes

The event uses the original eight padding bytes at PinballGame offsets
0xF50..0xF57. Do not increase or shift the structure: the memory and save layouts
depend on its existing size. A magic value validates this state for older saves.
Selection is latched before the opening animation and checked before the
ordinary Pichu/random egg selection. Only the successful egg-capture path adds
progress; cleanup clears the active event without adding another capture.

Run the host regression checks with:

```sh
python tools/scripts/test_manaphy_egg.py
```

These checks execute the event's C functions with a minimal host fixture; they
do not replace compiling the ROM or testing the animation in an emulator.
