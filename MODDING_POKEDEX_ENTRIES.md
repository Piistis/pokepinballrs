# Pokedex Entry Update Workflow

Use this checklist each time a new generation is added to the expanded National Dex.

## Data to Fill

Each entry lives in `data/pokedex_entries/dex.inc` and must include:

- National Dex number in the first three `.2byte` values.
- Height and weight digits in the remaining `.2byte` values.
- `.dexName` using the in-game species name.
- `.dexCategory` with the official genus minus the word `Pokemon`, capped at 11 characters.
- Exactly six `.dexText` lines.
- `.dexText` in normal sentence case, not full uppercase.
- `data/pokedex_entries/pokedex_order.inc` sorted by National Dex number for the visible list.

## Text Limits

The Pokedex detail renderer reads two pages, each with three lines of 42 characters:

- Maximum line length: 42 characters.
- Maximum visible text per page: 3 lines.
- Maximum entry text: 6 `.dexText` lines.
- Empty lines should remain as `.dexText ""` until there are exactly six lines.

## Source Policy

Use official game Pokedex entries. Prefer Gen 3 text when available because this project is based on Pokemon Pinball Ruby & Sapphire:

1. Emerald
2. FireRed / LeafGreen
3. Ruby / Sapphire
4. Crystal / Gold / Silver
5. Red / Blue / Yellow

Do not invent descriptions. Only adapt official entries for formatting:

- Rewrap lines to 42 characters or less.
- Use regular capitalization instead of all-caps text.
- Convert apostrophes to the existing in-game backtick style.
- Remove invisible soft hyphens.
- Avoid unsupported smart quotes.

## Validation

Before committing, validate every newly added entry:

- It has exactly 12 `.2byte` values.
- The name is at most 10 characters.
- The category is at most 11 characters.
- It has exactly six `.dexText` lines.
- No `.dexText` line is longer than 42 characters.
- No `Temporary National Dex entry.`, `placeholder graphics`, or `.dexCategory "TEMP"` remains for inserted Pokemon.
- No category ends with `Pokemon`, `POKEMON`, or a truncated `POK...` suffix, because the UI appends Pokemon itself.
- Any species with a new `SPECIES_RS_*` has a matching cry row, tone-bank entry, and direct-sound sample.

## Debug Review

The title screen and Pokedex have a hidden review shortcut:

- Press `L + R`.
- This marks the full Pokedex as caught and saves it.
- Use it only for debug/review saves.
