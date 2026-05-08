# Area portraits

These are the travel roulette area portraits used by:

```asm
gPortraitGenericGraphics:: @ 0x0848D68C
gPortraitGenericPalettes:: @ 0x081C00E4
```

Each portrait is `48x32` and occupies `0x300` bytes as 4bpp tiled graphics.
Mod-added portraits use the same layout as Pokemon portraits: `width = 6`,
`mwidth = 2`, `mheight = 2`.

The original 13 portraits are intentionally still included from `baserom.gba`.
The extracted PNGs for those originals look like noise and are not used by
the build. Mod-added portraits are appended after the original block.

The runtime order matches `gAreaPortraitIndexes` in `data/rom_1.s`:

1. `forest_ruby`
2. `forest_sapphire`
3. `plains_ruby`
4. `plains_sapphire`
5. `ocean_ruby`
6. `ocean_sapphire`
7. `cave_ruby`
8. `cave_sapphire`
9. `safari_zone`
10. `volcano`
11. `lake`
12. `wilderness`
13. `ruin`
14. `test_area`

Ruby and Sapphire ruins share the same portrait index.
`test_area` is the first mod-added portrait and is used by `AREA_TEST`.

Mod-added palettes can be referenced as `.gbapal`; `make` generates them from
the indexed PNG using the generic `%.gbapal: %.png` rule. Use `.gbapal.bin`
only for byte-exact original palettes that must preserve unusual bits.
