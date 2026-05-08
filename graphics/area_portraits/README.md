# Area portraits

These are the travel roulette area portraits extracted from:

```asm
gPortraitGenericGraphics:: @ 0x0848D68C
gPortraitGenericPalettes:: @ 0x081C00E4
```

Each portrait is `48x32` and occupies `0x300` bytes as 4bpp tiled graphics.
They use the same layout as Pokemon portraits: `width = 6`, `mwidth = 2`,
`mheight = 2`.
The order matches `gAreaPortraitIndexes` in `data/rom_1.s`:

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
`test_area` is a mod-added portrait used by `AREA_TEST`.

The palette files used by the build are `.gbapal.bin` because some original
palette colors have the unused high bit set. Regular `.pal -> .gbapal`
conversion would drop that bit and stop this extraction from being byte-exact.
The `.pal` files are provided as editable JASC references.
