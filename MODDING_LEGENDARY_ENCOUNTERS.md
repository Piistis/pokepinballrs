# Legendary encounters: generations 1 through 4

Natural encounters are selected in `PickSpeciesForCatchEmMode`, after the
explicit debug override and before the existing special guests/ordinary catch
selection. Existing bonus-board events and Manaphy's egg are unchanged.
The species handled here cannot appear through `data/mon_locations.inc` or
RANDOM's ordinary pool. Their old slots now contain
nonlegendary Pokemon of the same generation; row sizes are unchanged.

## Rules

All progress thresholds use the existing `caughtMonCount`, including evolutions.
Ten means ten completed captures/evolutions: the next encounter can get the boost.
The prerequisites use saved Pokedex CAUGHT flags, not SEEN, and include the
extended species flags. Pokedex requirements can be fulfilled in previous games
or other boards; requirements explicitly marked "this game" cannot.

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
| Deoxys | 3 | Both | Ruin, Rayquaza captured this game | 20% |
| Uxie and Azelf | 4 | Sapphire | Lake, 10+ | Shared 20% |
| Mesprit | 4 | Both | Any area; no capture threshold | 5%, or 20% in Lake |
| Dialga | 4 | Sapphire | Three lake guardians caught in Pokedex, 20+, any area | 25% |
| Palkia | 4 | Ruby | Three lake guardians caught in Pokedex, 20+, any area | 25% |
| Heatran | 4 | Ruby | Volcano, 15+ | 25% |
| Regigigas | 4 | Both | Ruin, Regirock/Regice/Registeel caught in Pokedex | 25% |
| Giratina | 4 | Both | Dialga/Palkia caught in Pokedex, 20+, any area | 25% |
| Cresselia | 4 | Both | Any area; no capture threshold | 5% |
| Phione | 4 | Both | Ocean, Manaphy captured this game | 25% |
| Darkrai | 4 | Both | Cresselia captured this game, 15+, any area | 25% |
| Shaymin | 4 | Both | Forest, 15+ | 25% |
| Arceus | 4 | Both | Dialga/Palkia/Giratina caught in Pokedex, 30+, any area | 25% |

Forest, Ocean and Ruin use the corresponding area's ID for each board.
Normal generation games enable all rules belonging to that generation.
The lottery uses disjoint buckets, not successive percentage rolls, so earlier
checks do not reduce later species' chances. There are 1200 possible rolls:
300 = 25%, 240 = 20%, 60 = 5%. A shared bucket is divided equally between its
remaining eligible members. If a favored member was already caught, its 20%
returns to ordinary encounters; the other members still share 5%.

If the eligible weights exceed 100%, all eligible individual species share the
entire 100% equally, including roamers. Five receive 20% each; six receive
16.666...% each. This also applies to Uxie/Azelf individually during overflow.
Integer cumulative rounding keeps the sum at 1200 rolls (individual weights can
differ by one roll). Otherwise original percentages are retained and unused
probability falls back to the game's existing encounter selection.

## RANDOM selection

At the start of a RANDOM game, choose two distinct roaming groups and two
distinct special groups, filtered for the selected board. The four roaming
groups are the birds, the beasts, Mesprit and Cresselia. Because of the original
board restrictions, Sapphire chooses from birds/Mesprit/Cresselia and Ruby from
beasts/Mesprit/Cresselia. Only the chosen groups can spawn naturally this game.

Special groups are the other entries in the rule table; Uxie and Azelf are a
single group. Darkrai can only be selected if the Cresselia roamer group was
selected. Saved Pokedex prerequisites and this-game progress are still required:
selection does not grant captures or unlock the encounter. Rayquaza's bonus-board
capture and Manaphy's independent egg event can unlock Deoxys and Phione.

The choices remain fixed across area changes, captures, ball loss, bonus boards
and save/continue. Capturing a selected legendary does not select a replacement.
Only a new game gets new choices. The existing legacy guest/bonus events that
have not been assigned a rule here are not part of this pool.

Group IDs and the two selection counts live in
`include/constants/legendary_encounters.h`; board/generation/threshold/weight
metadata lives in `sLegendarySpecialRules`, and roamer board masks in
`sLegendaryRoamerFields`. Add future rules there and update the explicit
conditions, capture-bit mapping, random blacklist and tests. Keep group IDs and
capture-bit meanings stable for existing saves, and stay within mask capacities.

## Once per game and saves

Each legendary handled by this catch selector can be caught naturally once per game.
Selecting or losing an encounter never consumes its opportunity. Only successful
capture registration sets the species' bit; debug-forced captures count too,
although debug forcing itself intentionally bypasses natural restrictions.
Already owning it in the global Pokedex does not prevent a new game's encounter.

Rayquaza and Manaphy are tracked as prerequisite captures, without changing
their existing bonus-board/egg encounter mechanisms.

`PinballGame` uses sixteen bytes of the old 0x094..0x0BB padding:

- 0x094: `u32 legendaryEncounterMagic` (0x4C454732).
- 0x098: `u32 legendaryCaughtMask` (27 bits; original eleven unchanged).
- 0x09C: `u32 randomLegendarySpecialMask`.
- 0x0A0: `u8 randomLegendaryRoamerMask`.
- 0x0A1: `u8 legendaryGeneration` (also restored for normal generation games).
- 0x0A2: `u8 legendarySelectionField` (home board, not the current bonus board).
- 0x0A3: `bool8 legendarySelectionReady`.
- 0x0A4..0x0BB: remaining padding, 0x18 bytes.

Do not grow the structure or shift `jirachiTargetX` at 0x0BC. Saving/continuing and
bonus-board transitions copy these fields along with the existing state. New
games clear them. Version-1 saves (0x4C454731) retain their original eleven
capture bits; new bits start clear, ignoring the former padding's contents.
Older saves get an empty capture mask. The first eligible main-board update
chooses a pool for saves that did not store one. The generation in such old saves
cannot be recovered if it was never stored. Previously untracked captures of
Rayquaza, Manaphy or Cresselia cannot be inferred from the global Pokedex.

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
encounters at 9/10, 14/15, 19/20 and 29/30; a lost legendary; a successful capture
followed by save/continue; a new game; and a 4th-generation Forest with enough
eligible species to exercise equal-probability overflow. Verify RANDOM selections
survive pause/save/continue and bonus-board visits, and do not change on capture.
The debug force-catch menu is an override, not a test of natural probability.
