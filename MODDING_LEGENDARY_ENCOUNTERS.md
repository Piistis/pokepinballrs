# Legendary encounters: generations 1 and 2

Natural encounters are selected in `PickSpeciesForCatchEmMode`, after the
explicit debug override and before the existing special guests/ordinary catch
selection. Other generations' existing events and Manaphy's egg are unchanged.
The eleven species below have been removed from `data/mon_locations.inc` and
remain excluded from RANDOM's ordinary pool. Their old slots now contain
nonlegendary Pokemon of the same generation; row sizes are unchanged.

## Rules

All progress thresholds use the existing `caughtMonCount`, including evolutions.
Ten means ten completed captures/evolutions: the next encounter can get the boost.
The prerequisites use saved Pokedex CAUGHT flags, not SEEN, and include the
extended species flags. They can be fulfilled in previous games or other boards.

| Species | Generation | Board | Requirements | Chance per catch encounter |
| --- | --- | --- | --- | --- |
| Articuno, Zapdos, Moltres | 1 | Sapphire | Any area, any progress | Shared 5% |
| Articuno | 1 | Sapphire | Ice Cave, 10+ | 20%; other available birds share 5% |
| Zapdos | 1 | Sapphire | Plains Sapphire, 10+ | 20%; other available birds share 5% |
| Moltres | 1 | Sapphire | Wilderness, 10+ | 20%; other available birds share 5% |
| Mew | 1 | Both | National Dex 1-150 caught, 15+, any area | 25% |
| Mewtwo | 1 | Both | Three birds caught in Pokedex, 20+, any area | 25% |
| Suicune, Raikou, Entei | 2 | Ruby | Any area, any progress | Shared 5% |
| Suicune | 2 | Ruby | Ocean Ruby, 10+ | 20%; other available beasts share 5% |
| Raikou | 2 | Ruby | Safari Zone, 10+ | 20%; other available beasts share 5% |
| Entei | 2 | Ruby | Volcano, 10+ | 20%; other available beasts share 5% |
| Ho-oh | 2 | Ruby | Three beasts caught in Pokedex, 20+, any area | 25% |
| Lugia | 2 | Sapphire | Three beasts caught in Pokedex, 20+, any area | 25% |
| Celebi | 2 | Both | Forest, 15+ | 25% |

RANDOM enables both generations' rules, without removing board restrictions.
The lottery uses disjoint buckets, not successive percentage rolls, so earlier
checks do not reduce later species' chances. There are 1200 possible rolls:
300 = 25%, 240 = 20%, 60 = 5%. A shared bucket is divided equally between its
remaining eligible members. If a favored member was already caught, its 20%
returns to ordinary encounters; the other members still share 5%.

When all four specials are eligible in RANDOM Forest, preserve the trio's 5%
and give each special 285/1200 = 23.75%, as agreed. If the whole trio was already
caught, each of the four specials can retain 25%. Unused probability falls back
to the game's existing encounter selection.

## Once per game and saves

Each of these eleven legendaries can be caught naturally once per game.
Selecting or losing an encounter never consumes its opportunity. Only successful
capture registration sets the species' bit; debug-forced captures count too,
although debug forcing itself intentionally bypasses natural restrictions.
Already owning it in the global Pokedex does not prevent a new game's encounter.

`PinballGame` uses six bytes of the old 0x094..0x0BB padding:

- 0x094: `u32 legendaryEncounterMagic` (0x4C454731).
- 0x098: `u16 legendaryCaughtMask` (eleven bits).
- 0x09A..0x0BB: remaining padding, 0x22 bytes.

Do not grow the structure or shift `jirachiTargetX` at 0x0BC. Saving/continuing and
bonus-board transitions copy these fields along with the existing state. New
games clear them. Old saves get an empty mask on first use; their earlier
captures cannot be reconstructed from the shared Pokedex.

Mew checks the existing national ordering via `PokedexListPositionToSpecies`.
Never check internal species IDs 0-149: these are not National Dex 1-150.
Keep `.rodata` for the picker in `ld_script.txt` if compiler-generated switch
tables or future encounter constants use that section.

## Verification

```sh
python tools/scripts/test_legendary_encounters.py
python tools/scripts/test_manaphy_egg.py
make -j$(nproc)
```

The host tests enumerate the lottery and exercise the actual C selector, but do
not replace the ARM ROM build or emulator testing. In the emulator check natural
encounters at 9/10, 14/15 and 19/20; a lost legendary; a successful capture followed
by save/continue; a new game; and RANDOM Forest with all prerequisites unlocked.
The debug force-catch menu is an override, not a test of natural probability.
