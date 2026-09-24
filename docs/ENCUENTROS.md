# Lista de encuentros

Generada desde el codigo. No editar este archivo: los especiales y las ramas
condicionales se mantienen en [encounters_special.json](encounters_special.json).

Especies insertadas: **500**. Sin ruta natural detectada: **7**.

## Como leer los porcentajes

- `ref.` es la probabilidad DENTRO del sorteo normal: candidatos y evoluciones sin registrar,
  al menos una captura/evolucion en partida, sin excluir al ultimo Pokemon y sin mejoras e-Reader.
- Se respetan los pesos de especies raras, no solo el numero de casillas. Los porcentajes estan redondeados.
- La Pokedex, el ultimo encuentro, la primera captura y los eventos especiales cambian el resultado real.
  Si un especial ocupa el 25%, el sorteo normal solo se ejecuta en el 75% restante (salvo otros eventos).
- RANDOM muestra candidatos, NO encuentros garantizados: sus tablas normales se sortean por partida.
  Los huevos RANDOM combinan las tablas original, Gen 2 y Gen 4; sus porcentajes tambien son de referencia.
- La tabla original de huevos se usa actualmente en Gen 1 y Gen 3 y mezcla generaciones: se documenta
  lo que hace el codigo, no una distribucion ideal. La evolucion requiere obtener antes la preevolucion.
- No se cuentan trucos DEBUG como vias naturales. Una ruta detectada no certifica que su sprite este terminado.

## Encuentros normales

| No. | Pokemon | Como se consigue |
| --- | --- | --- |
| 001 | Bulbasaur | Caza: Gen 1, Ambos, Forest, 2 flechas, 12,5% ref.<br>Caza: Gen 1, Ambos, Forest, 3 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ambos, Forest, 2/3 flechas; seleccion y porcentaje variables por partida |
| 002 | Ivysaur | Evolucion de Bulbasaur |
| 003 | Venusaur | Evolucion de Ivysaur |
| 004 | Charmander | Caza: Gen 1, Ruby, Volcano, 2 flechas, 20% ref.<br>Caza: Gen 1, Ruby, Volcano, 3 flechas, 16,67% ref.<br>Candidato a caza: RANDOM, Ruby, Volcano, 2/3 flechas; seleccion y porcentaje variables por partida |
| 005 | Charmeleon | Evolucion de Charmander |
| 006 | Charizard | Evolucion de Charmeleon |
| 007 | Squirtle | Caza: Gen 1, Ambos, Ocean, 2 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ambos, Ocean, 2 flechas; seleccion y porcentaje variables por partida |
| 008 | Wartortle | Evolucion de Squirtle |
| 009 | Blastoise | Evolucion de Wartortle |
| 010 | Caterpie | Caza: Gen 1, Ambos, Forest, 2 flechas, 12,5% ref.<br>Caza: Gen 1, Ambos, Forest, 3 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ambos, Forest, 2/3 flechas; seleccion y porcentaje variables por partida |
| 011 | Metapod | Evolucion de Caterpie |
| 012 | Butterfree | Evolucion de Metapod |
| 013 | Weedle | Caza: Gen 1, Ambos, Forest, 2 flechas, 12,5% ref.<br>Caza: Gen 1, Ambos, Forest, 3 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ambos, Forest, 2/3 flechas; seleccion y porcentaje variables por partida |
| 014 | Kakuna | Evolucion de Weedle |
| 015 | Beedrill | Evolucion de Kakuna |
| 016 | Pidgey | Caza: Gen 1, Ambos, Plains, 2 flechas, 12,5% ref.<br>Caza: Gen 1, Ambos, Plains, 3 flechas, 12,5% ref.<br>Caza: Gen 1, Ruby, City, 2 flechas, 12,5% ref.<br>Caza: Gen 1, Ruby, City, 3 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ruby, City, 2/3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Ambos, Plains, 2/3 flechas; seleccion y porcentaje variables por partida |
| 017 | Pidgeotto | Evolucion de Pidgey |
| 018 | Pidgeot | Evolucion de Pidgeotto |
| 019 | Rattata | Caza: Gen 1, Ambos, Plains, 2 flechas, 12,5% ref.<br>Caza: Gen 1, Ambos, Plains, 3 flechas, 12,5% ref.<br>Caza: Gen 1, Ruby, City, 2 flechas, 12,5% ref.<br>Caza: Gen 1, Ruby, City, 3 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ruby, City, 2/3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Ambos, Plains, 2/3 flechas; seleccion y porcentaje variables por partida |
| 020 | Raticate | Evolucion de Rattata |
| 021 | Spearow | Caza: Gen 1, Ambos, Plains, 2 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ambos, Plains, 2 flechas; seleccion y porcentaje variables por partida |
| 022 | Fearow | Evolucion de Spearow |
| 023 | Ekans | Caza: Gen 1, Ambos, Plains, 2 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ambos, Plains, 2 flechas; seleccion y porcentaje variables por partida |
| 024 | Arbok | Evolucion de Ekans |
| 025 | Pikachu | Caza: Gen 1, Ambos, Forest, 2 flechas, 12,5% ref.<br>Caza: Gen 1, Ambos, Forest, 3 flechas, 12,5% ref.<br>Caza: Gen 1, Ruby, City, 3 flechas, 12,5% ref.<br>Caza: Gen 3, Ruby, Safari Zone, 3 flechas, 16,39% ref.<br>Candidato a caza: RANDOM, Ruby, City, 3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Ambos, Forest, 2/3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Ruby, Safari Zone, 3 flechas; seleccion y porcentaje variables por partida<br>Evolucion de Pichu |
| 026 | Raichu | Evolucion de Pikachu |
| 027 | Sandshrew | Caza: Gen 1, Ambos, Cave, 3 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ambos, Cave, 3 flechas; seleccion y porcentaje variables por partida |
| 028 | Sandslash | Evolucion de Sandshrew |
| 029 | Nidoran F | Caza: Gen 1, Ambos, Plains, 2 flechas, 12,5% ref.<br>Caza: Gen 1, Ambos, Plains, 3 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ambos, Plains, 2/3 flechas; seleccion y porcentaje variables por partida |
| 030 | Nidorina | Evolucion de Nidoran F |
| 031 | Nidoqueen | Evolucion de Nidorina |
| 032 | Nidoran M | Caza: Gen 1, Ambos, Plains, 2 flechas, 12,5% ref.<br>Caza: Gen 1, Ambos, Plains, 3 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ambos, Plains, 2/3 flechas; seleccion y porcentaje variables por partida |
| 033 | Nidorino | Evolucion de Nidoran M |
| 034 | Nidoking | Evolucion de Nidorino |
| 035 | Clefairy | Caza: Gen 1, Ambos, Plains, 2 flechas, 12,5% ref.<br>Caza: Gen 1, Ambos, Plains, 3 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ambos, Plains, 2/3 flechas; seleccion y porcentaje variables por partida<br>Evolucion de Cleffa |
| 036 | Clefable | Evolucion de Clefairy |
| 037 | Vulpix | Caza: Gen 1, Ruby, Volcano, 2 flechas, 20% ref.<br>Caza: Gen 1, Ruby, Volcano, 3 flechas, 16,67% ref.<br>Caza: Gen 3, Ruby, Volcano, 2 flechas, 19,61% ref.<br>Caza: Gen 3, Ruby, Volcano, 3 flechas, 19,61% ref.<br>Candidato a caza: RANDOM, Ruby, Volcano, 2/3 flechas; seleccion y porcentaje variables por partida |
| 038 | Ninetales | Evolucion de Vulpix |
| 039 | Jigglypuff | Caza: Gen 3, Zafiro, Plains, 2 flechas, 16,39% ref.<br>Caza: Gen 3, Zafiro, Plains, 3 flechas, 14,08% ref.<br>Candidato a caza: RANDOM, Zafiro, Plains, 2/3 flechas; seleccion y porcentaje variables por partida<br>Evolucion de Igglybuff |
| 040 | Wigglytuff | Evolucion de Jigglypuff |
| 041 | Zubat | Caza: Gen 1, Ambos, Cave, 2 flechas, 12,5% ref.<br>Caza: Gen 1, Ruby, Cave, 3 flechas, 12,5% ref.<br>Caza: Gen 1, Zafiro, Ice Cave, 2 flechas, 14,29% ref.<br>Caza: Gen 1, Zafiro, Ice Cave, 3 flechas, 12,5% ref.<br>Caza: Gen 3, Zafiro, Ice Cave, 2 flechas, 19,23% ref.<br>Candidato a caza: RANDOM, Ruby, Cave, 2/3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Zafiro, Cave, 2 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Zafiro, Ice Cave, 2/3 flechas; seleccion y porcentaje variables por partida |
| 042 | Golbat | Evolucion de Zubat |
| 043 | Oddish | Caza: Gen 1, Ambos, Forest, 2 flechas, 12,5% ref.<br>Caza: Gen 1, Ambos, Forest, 3 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ambos, Forest, 2/3 flechas; seleccion y porcentaje variables por partida |
| 044 | Gloom | Evolucion de Oddish |
| 045 | Vileplume | Evolucion de Gloom (Ruby) |
| 046 | Paras | Caza: Gen 1, Ambos, Forest, 2 flechas, 12,5% ref.<br>Caza: Gen 1, Ambos, Forest, 3 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ambos, Forest, 2/3 flechas; seleccion y porcentaje variables por partida |
| 047 | Parasect | Evolucion de Paras |
| 048 | Venonat | Caza: Gen 1, Ambos, Forest, 2 flechas, 12,5% ref.<br>Caza: Gen 1, Ambos, Forest, 3 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ambos, Forest, 2/3 flechas; seleccion y porcentaje variables por partida |
| 049 | Venomoth | Evolucion de Venonat |
| 050 | Diglett | Caza: Gen 1, Ambos, Cave, 2 flechas, 12,5% ref.<br>Caza: Gen 1, Ambos, Cave, 3 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ambos, Cave, 2/3 flechas; seleccion y porcentaje variables por partida |
| 051 | Dugtrio | Evolucion de Diglett |
| 052 | Meowth | Caza: Gen 1, Ambos, Plains, 2 flechas, 12,5% ref.<br>Caza: Gen 1, Ambos, Plains, 3 flechas, 12,5% ref.<br>Caza: Gen 1, Ruby, City, 2 flechas, 12,5% ref.<br>Caza: Gen 1, Ruby, City, 3 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ruby, City, 2/3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Ambos, Plains, 2/3 flechas; seleccion y porcentaje variables por partida |
| 053 | Persian | Evolucion de Meowth |
| 054 | Psyduck | Caza: Gen 1, Zafiro, Lake, 2 flechas, 16,67% ref.<br>Caza: Gen 1, Zafiro, Lake, 3 flechas, 14,29% ref.<br>Caza: Gen 3, Ruby, Safari Zone, 2 flechas, 16,39% ref.<br>Candidato a caza: RANDOM, Ruby, Safari Zone, 2 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Zafiro, Lake, 2/3 flechas; seleccion y porcentaje variables por partida |
| 055 | Golduck | Evolucion de Psyduck |
| 056 | Mankey | Caza: Gen 1, Zafiro, Wilderness, 2 flechas, 14,29% ref.<br>Caza: Gen 1, Zafiro, Wilderness, 3 flechas, 14,29% ref.<br>Candidato a caza: RANDOM, Zafiro, Wilderness, 2/3 flechas; seleccion y porcentaje variables por partida |
| 057 | Primeape | Evolucion de Mankey |
| 058 | Growlithe | Caza: Gen 1, Ambos, Plains, 3 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ambos, Plains, 3 flechas; seleccion y porcentaje variables por partida |
| 059 | Arcanine | Evolucion de Growlithe |
| 060 | Poliwag | Caza: Gen 1, Zafiro, Lake, 2 flechas, 16,67% ref.<br>Caza: Gen 1, Zafiro, Lake, 3 flechas, 14,29% ref.<br>Caza: Gen 2, Zafiro, Lake, 2 flechas, 14,29% ref.<br>Caza: Gen 2, Zafiro, Lake, 3 flechas, 14,29% ref.<br>Candidato a caza: RANDOM, Zafiro, Lake, 2/3 flechas; seleccion y porcentaje variables por partida |
| 061 | Poliwhirl | Evolucion de Poliwag |
| 062 | Poliwrath | Evolucion de Poliwhirl (Ruby) |
| 063 | Abra | Caza: Gen 1, Ambos, Cave, 2 flechas, 12,5% ref.<br>Caza: Gen 1, Ambos, Cave, 3 flechas, 12,5% ref.<br>Caza: Gen 1, Ruby, City, 2 flechas, 12,5% ref.<br>Caza: Gen 3, Ruby, Cave, 3 flechas, 19,61% ref.<br>Caza: Gen 3, Zafiro, Cave, 3 flechas, 16,39% ref.<br>Candidato a caza: RANDOM, Ambos, Cave, 2/3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Ruby, City, 2 flechas; seleccion y porcentaje variables por partida |
| 064 | Kadabra | Evolucion de Abra |
| 065 | Alakazam | Evolucion de Kadabra |
| 066 | Machop | Caza: Gen 1, Ambos, Cave, 2 flechas, 12,5% ref.<br>Caza: Gen 1, Ambos, Cave, 3 flechas, 12,5% ref.<br>Caza: Gen 3, Ruby, Cave, 2 flechas, 16,39% ref.<br>Caza: Gen 3, Ruby, Cave, 3 flechas, 19,61% ref.<br>Candidato a caza: RANDOM, Ambos, Cave, 2/3 flechas; seleccion y porcentaje variables por partida |
| 067 | Machoke | Evolucion de Machop |
| 068 | Machamp | Evolucion de Machoke |
| 069 | Bellsprout | Caza: Gen 1, Ambos, Forest, 2 flechas, 12,5% ref.<br>Caza: Gen 1, Ambos, Forest, 3 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ambos, Forest, 2/3 flechas; seleccion y porcentaje variables por partida |
| 070 | Weepinbell | Evolucion de Bellsprout |
| 071 | Victreebel | Evolucion de Weepinbell |
| 072 | Tentacool | Caza: Gen 1, Ambos, Ocean, 2 flechas, 12,5% ref.<br>Caza: Gen 1, Ambos, Ocean, 3 flechas, 12,5% ref.<br>Caza: Gen 3, Ambos, Ocean, 2 flechas, 19,61% ref.<br>Caza: Gen 3, Ambos, Ocean, 3 flechas, 16,39% ref.<br>Candidato a caza: RANDOM, Ambos, Ocean, 2/3 flechas; seleccion y porcentaje variables por partida |
| 073 | Tentacruel | Evolucion de Tentacool |
| 074 | Geodude | Caza: Gen 1, Ambos, Cave, 2 flechas, 12,5% ref.<br>Caza: Gen 1, Ambos, Cave, 3 flechas, 12,5% ref.<br>Caza: Gen 1, Zafiro, Ice Cave, 2 flechas, 14,29% ref.<br>Caza: Gen 1, Zafiro, Ice Cave, 3 flechas, 12,5% ref.<br>Caza: Gen 3, Zafiro, Wilderness, 2 flechas, 19,61% ref.<br>Caza: Gen 3, Zafiro, Wilderness, 3 flechas, 19,61% ref.<br>Candidato a caza: RANDOM, Ambos, Cave, 2/3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Zafiro, Ice Cave, 2/3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Zafiro, Wilderness, 2/3 flechas; seleccion y porcentaje variables por partida |
| 075 | Graveler | Evolucion de Geodude |
| 076 | Golem | Evolucion de Graveler |
| 077 | Ponyta | Caza: Gen 1, Ruby, Volcano, 2 flechas, 20% ref.<br>Caza: Gen 1, Ruby, Volcano, 3 flechas, 16,67% ref.<br>Candidato a caza: RANDOM, Ruby, Volcano, 2/3 flechas; seleccion y porcentaje variables por partida |
| 078 | Rapidash | Evolucion de Ponyta |
| 079 | Slowpoke | Caza: Gen 1, Ambos, Ocean, 2 flechas, 12,5% ref.<br>Caza: Gen 1, Ambos, Ocean, 3 flechas, 12,5% ref.<br>Caza: Gen 1, Zafiro, Lake, 2 flechas, 16,67% ref.<br>Caza: Gen 1, Zafiro, Lake, 3 flechas, 14,29% ref.<br>Caza: Gen 2, Zafiro, Lake, 2 flechas, 14,29% ref.<br>Caza: Gen 2, Zafiro, Lake, 3 flechas, 14,29% ref.<br>Candidato a caza: RANDOM, Ambos, Ocean, 2/3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Zafiro, Lake, 2/3 flechas; seleccion y porcentaje variables por partida |
| 080 | Slowbro | Evolucion de Slowpoke (Ruby) |
| 081 | Magnemite | Caza: Gen 1, Zafiro, Wilderness, 2 flechas, 14,29% ref.<br>Caza: Gen 1, Zafiro, Wilderness, 3 flechas, 14,29% ref.<br>Caza: Gen 1, Ruby, City, 2 flechas, 12,5% ref.<br>Caza: Gen 1, Ruby, City, 3 flechas, 12,5% ref.<br>Caza: Gen 3, Ambos, Plains, 2 flechas, 16,39% ref.<br>Caza: Gen 3, Ruby, Plains, 3 flechas, 19,61% ref.<br>Caza: Gen 3, Zafiro, Plains, 3 flechas, 14,08% ref.<br>Caza: Gen 3, Ruby, City, 2 flechas, 14,08% ref.<br>Caza: Gen 3, Ruby, City, 3 flechas, 16,13% ref.<br>Caza: Gen 4, Ambos, Cave, 2 flechas, 14,08% ref.<br>Caza: Gen 4, Ruby, City, 2 flechas, 12,5% ref.<br>Caza: Gen 4, Ruby, City, 3 flechas, 12,5% ref.<br>Caza: Gen 4, Zafiro, Ice Cave, 2 flechas, 12,5% ref.<br>Caza: Gen 4, Zafiro, Ice Cave, 3 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ambos, Cave, 2 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Ruby, City, 2/3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Ambos, Plains, 2/3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Zafiro, Ice Cave, 2/3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Zafiro, Wilderness, 2/3 flechas; seleccion y porcentaje variables por partida |
| 082 | Magneton | Evolucion de Magnemite |
| 083 | Farfetchd | Caza: Gen 1, Ruby, Plains, 3 flechas, 12,5% ref.<br>Caza: Gen 1, Ruby, City, 3 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ruby, City, 3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Ruby, Plains, 3 flechas; seleccion y porcentaje variables por partida |
| 084 | Doduo | Caza: Gen 1, Ruby, Safari Zone, 2 flechas, 12,5% ref.<br>Caza: Gen 3, Ruby, Safari Zone, 2 flechas, 16,39% ref.<br>Caza: Gen 3, Ruby, Safari Zone, 3 flechas, 16,39% ref.<br>Candidato a caza: RANDOM, Ruby, Safari Zone, 2/3 flechas; seleccion y porcentaje variables por partida |
| 085 | Dodrio | Evolucion de Doduo |
| 086 | Seel | Caza: Gen 1, Ambos, Ocean, 2 flechas, 12,5% ref.<br>Caza: Gen 1, Zafiro, Ice Cave, 2 flechas, 14,29% ref.<br>Caza: Gen 1, Zafiro, Ice Cave, 3 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ambos, Ocean, 2 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Zafiro, Ice Cave, 2/3 flechas; seleccion y porcentaje variables por partida |
| 087 | Dewgong | Evolucion de Seel |
| 088 | Grimer | Caza: Gen 3, Ruby, Cave, 2 flechas, 16,39% ref.<br>Caza: Gen 3, Zafiro, Cave, 2 flechas, 19,61% ref.<br>Candidato a caza: RANDOM, Ambos, Cave, 2 flechas; seleccion y porcentaje variables por partida |
| 089 | Muk | Evolucion de Grimer |
| 090 | Shellder | Caza: Gen 1, Ambos, Ocean, 2 flechas, 12,5% ref.<br>Caza: Gen 1, Zafiro, Ice Cave, 2 flechas, 14,29% ref.<br>Caza: Gen 1, Zafiro, Ice Cave, 3 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ambos, Ocean, 2 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Zafiro, Ice Cave, 2/3 flechas; seleccion y porcentaje variables por partida |
| 091 | Cloyster | Evolucion de Shellder |
| 092 | Gastly | Caza: Gen 1, Ambos, Cave, 2 flechas, 12,5% ref.<br>Caza: Gen 1, Ambos, Cave, 3 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ambos, Cave, 2/3 flechas; seleccion y porcentaje variables por partida |
| 093 | Haunter | Evolucion de Gastly |
| 094 | Gengar | Evolucion de Haunter |
| 095 | Onix | Caza: Gen 1, Ambos, Cave, 2 flechas, 12,5% ref.<br>Caza: Gen 1, Zafiro, Ice Cave, 2 flechas, 14,29% ref.<br>Caza: Gen 1, Zafiro, Ice Cave, 3 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ambos, Cave, 2 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Zafiro, Ice Cave, 2/3 flechas; seleccion y porcentaje variables por partida |
| 096 | Drowzee | Caza: Gen 1, Ruby, City, 2 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ruby, City, 2 flechas; seleccion y porcentaje variables por partida |
| 097 | Hypno | Evolucion de Drowzee |
| 098 | Krabby | Caza: Gen 1, Ambos, Ocean, 2 flechas, 12,5% ref.<br>Caza: Gen 1, Ambos, Ocean, 3 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ambos, Ocean, 2/3 flechas; seleccion y porcentaje variables por partida |
| 099 | Kingler | Evolucion de Krabby |
| 100 | Voltorb | Caza: Gen 1, Zafiro, Wilderness, 2 flechas, 14,29% ref.<br>Caza: Gen 1, Zafiro, Wilderness, 3 flechas, 14,29% ref.<br>Caza: Gen 1, Ruby, City, 2 flechas, 12,5% ref.<br>Caza: Gen 1, Ruby, City, 3 flechas, 12,5% ref.<br>Caza: Gen 3, Ambos, Plains, 2 flechas, 16,39% ref.<br>Caza: Gen 3, Ruby, Plains, 3 flechas, 19,61% ref.<br>Caza: Gen 3, Zafiro, Plains, 3 flechas, 14,08% ref.<br>Caza: Gen 3, Ruby, City, 2 flechas, 14,08% ref.<br>Caza: Gen 3, Ruby, City, 3 flechas, 16,13% ref.<br>Candidato a caza: RANDOM, Ruby, City, 2/3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Ambos, Plains, 2/3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Zafiro, Wilderness, 2/3 flechas; seleccion y porcentaje variables por partida |
| 101 | Electrode | Evolucion de Voltorb |
| 102 | Exeggcute | Caza: Gen 1, Ruby, Safari Zone, 2 flechas, 12,5% ref.<br>Caza: Gen 1, Ruby, Safari Zone, 3 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ruby, Safari Zone, 2/3 flechas; seleccion y porcentaje variables por partida |
| 103 | Exeggutor | Evolucion de Exeggcute |
| 104 | Cubone | Caza: Gen 1, Ambos, Cave, 2 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ambos, Cave, 2 flechas; seleccion y porcentaje variables por partida |
| 105 | Marowak | Evolucion de Cubone |
| 106 | Hitmonlee | Caza: Gen 1, Ruby, Safari Zone, 3 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ruby, Safari Zone, 3 flechas; seleccion y porcentaje variables por partida<br>Evolucion de Tyrogue (segun zona y las ramas pendientes en la Pokedex) |
| 107 | Hitmonchan | Caza: Gen 1, Ruby, Safari Zone, 3 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ruby, Safari Zone, 3 flechas; seleccion y porcentaje variables por partida<br>Evolucion de Tyrogue (segun zona y las ramas pendientes en la Pokedex) |
| 108 | Lickitung | Caza: Gen 1, Ruby, Safari Zone, 2 flechas, 12,5% ref.<br>Caza: Gen 4, Ambos, Plains, 2 flechas, 12,5% ref.<br>Caza: Gen 4, Ruby, Safari Zone, 2 flechas, 12,5% ref.<br>Caza: Gen 4, Ruby, Safari Zone, 3 flechas, 12,5% ref.<br>Caza: Gen 4, Zafiro, Wilderness, 2 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ambos, Plains, 2 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Ruby, Safari Zone, 2/3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Zafiro, Wilderness, 2 flechas; seleccion y porcentaje variables por partida |
| 109 | Koffing | Caza: Gen 1, Ruby, Volcano, 2 flechas, 20% ref.<br>Caza: Gen 1, Ruby, Volcano, 3 flechas, 16,67% ref.<br>Caza: Gen 3, Ruby, Volcano, 2 flechas, 19,61% ref.<br>Caza: Gen 3, Ruby, Volcano, 3 flechas, 19,61% ref.<br>Candidato a caza: RANDOM, Ruby, Volcano, 2/3 flechas; seleccion y porcentaje variables por partida |
| 110 | Weezing | Evolucion de Koffing |
| 111 | Rhyhorn | Caza: Gen 1, Ambos, Cave, 3 flechas, 12,5% ref.<br>Caza: Gen 3, Ruby, Safari Zone, 2 flechas, 16,39% ref.<br>Caza: Gen 3, Ruby, Safari Zone, 3 flechas, 16,39% ref.<br>Caza: Gen 4, Ambos, Cave, 2 flechas, 14,08% ref.<br>Caza: Gen 4, Ruby, Volcano, 2 flechas, 12,5% ref.<br>Caza: Gen 4, Ruby, Volcano, 3 flechas, 14,08% ref.<br>Candidato a caza: RANDOM, Ambos, Cave, 2/3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Ruby, Safari Zone, 2/3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Ruby, Volcano, 2/3 flechas; seleccion y porcentaje variables por partida |
| 112 | Rhydon | Evolucion de Rhyhorn |
| 113 | Chansey | Caza: Gen 1, Ruby, Safari Zone, 3 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ruby, Safari Zone, 3 flechas; seleccion y porcentaje variables por partida<br>Evolucion de Happiny |
| 114 | Tangela | Caza: Gen 1, Zafiro, Wilderness, 2 flechas, 14,29% ref.<br>Caza: Gen 1, Zafiro, Wilderness, 3 flechas, 14,29% ref.<br>Caza: Gen 4, Ambos, Forest, 2 flechas, 12,5% ref.<br>Caza: Gen 4, Ambos, Forest, 3 flechas, 12,5% ref.<br>Caza: Gen 4, Ruby, Safari Zone, 2 flechas, 12,5% ref.<br>Caza: Gen 4, Ruby, Safari Zone, 3 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ambos, Forest, 2/3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Ruby, Safari Zone, 2/3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Zafiro, Wilderness, 2/3 flechas; seleccion y porcentaje variables por partida |
| 115 | Kangaskhan | Caza: Gen 1, Ruby, Safari Zone, 2 flechas, 12,5% ref.<br>Caza: Gen 1, Ruby, Safari Zone, 3 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ruby, Safari Zone, 2/3 flechas; seleccion y porcentaje variables por partida |
| 116 | Horsea | Caza: Gen 1, Ambos, Ocean, 2 flechas, 12,5% ref.<br>Caza: Gen 1, Ambos, Ocean, 3 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ambos, Ocean, 2/3 flechas; seleccion y porcentaje variables por partida |
| 117 | Seadra | Evolucion de Horsea |
| 118 | Goldeen | Caza: Gen 1, Ambos, Ocean, 2 flechas, 12,5% ref.<br>Caza: Gen 1, Zafiro, Lake, 2 flechas, 16,67% ref.<br>Caza: Gen 1, Zafiro, Lake, 3 flechas, 14,29% ref.<br>Caza: Gen 3, Zafiro, Lake, 2 flechas, 19,61% ref.<br>Candidato a caza: RANDOM, Ambos, Ocean, 2 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Zafiro, Lake, 2/3 flechas; seleccion y porcentaje variables por partida |
| 119 | Seaking | Evolucion de Goldeen |
| 120 | Staryu | Caza: Gen 1, Ambos, Ocean, 3 flechas, 12,5% ref.<br>Caza: Gen 1, Zafiro, Lake, 2 flechas, 16,67% ref.<br>Caza: Gen 1, Zafiro, Lake, 3 flechas, 14,29% ref.<br>Caza: Gen 3, Ruby, Ocean, 3 flechas, 16,39% ref.<br>Candidato a caza: RANDOM, Ambos, Ocean, 3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Zafiro, Lake, 2/3 flechas; seleccion y porcentaje variables por partida |
| 121 | Starmie | Evolucion de Staryu |
| 122 | Mr Mime | Caza: Gen 1, Ruby, Safari Zone, 2 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ruby, Safari Zone, 2 flechas; seleccion y porcentaje variables por partida<br>Evolucion de Mime Jr. |
| 123 | Scyther | Caza: Gen 1, Ruby, Safari Zone, 2 flechas, 12,5% ref.<br>Caza: Gen 1, Ruby, Safari Zone, 3 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ruby, Safari Zone, 2/3 flechas; seleccion y porcentaje variables por partida |
| 124 | Jynx | Caza: Gen 1, Zafiro, Cave, 3 flechas, 12,5% ref.<br>Caza: Gen 1, Zafiro, Ice Cave, 2 flechas, 14,29% ref.<br>Caza: Gen 1, Zafiro, Ice Cave, 3 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Zafiro, Cave, 3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Zafiro, Ice Cave, 2/3 flechas; seleccion y porcentaje variables por partida<br>Evolucion de Smoochum |
| 125 | Electabuzz | Caza: Gen 1, Zafiro, Wilderness, 2 flechas, 14,29% ref.<br>Caza: Gen 1, Zafiro, Wilderness, 3 flechas, 14,29% ref.<br>Caza: Gen 1, Ambos, Ruin, 2 flechas, 20% ref.<br>Caza: Gen 1, Ambos, Ruin, 3 flechas, 14,29% ref.<br>Candidato a caza: RANDOM, Ambos, Ruin, 2/3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Zafiro, Wilderness, 2/3 flechas; seleccion y porcentaje variables por partida<br>Evolucion de Elekid |
| 126 | Magmar | Caza: Gen 1, Ruby, Volcano, 2 flechas, 20% ref.<br>Caza: Gen 1, Ruby, Volcano, 3 flechas, 33,33% ref.<br>Candidato a caza: RANDOM, Ruby, Volcano, 2/3 flechas; seleccion y porcentaje variables por partida<br>Evolucion de Magby |
| 127 | Pinsir | Caza: Gen 1, Ruby, Safari Zone, 2 flechas, 12,5% ref.<br>Caza: Gen 1, Ruby, Safari Zone, 3 flechas, 12,5% ref.<br>Caza: Gen 3, Ruby, Safari Zone, 2 flechas, 16,39% ref.<br>Caza: Gen 3, Ruby, Safari Zone, 3 flechas, 16,39% ref.<br>Candidato a caza: RANDOM, Ruby, Safari Zone, 2/3 flechas; seleccion y porcentaje variables por partida |
| 128 | Tauros | Caza: Gen 1, Ruby, Safari Zone, 2 flechas, 12,5% ref.<br>Caza: Gen 1, Ruby, Safari Zone, 3 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ruby, Safari Zone, 2/3 flechas; seleccion y porcentaje variables por partida |
| 129 | Magikarp | Caza: Gen 1, Ambos, Ocean, 3 flechas, 12,5% ref.<br>Caza: Gen 1, Zafiro, Lake, 2 flechas, 16,67% ref.<br>Caza: Gen 1, Zafiro, Lake, 3 flechas, 14,29% ref.<br>Caza: Gen 3, Zafiro, Ocean, 2 flechas, 19,61% ref.<br>Caza: Gen 3, Zafiro, Ocean, 3 flechas, 16,39% ref.<br>Candidato a caza: RANDOM, Ruby, Ocean, 3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Zafiro, Lake, 2/3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Zafiro, Ocean, 2/3 flechas; seleccion y porcentaje variables por partida |
| 130 | Gyarados | Evolucion de Magikarp |
| 131 | Lapras | Caza: Gen 1, Ambos, Ocean, 3 flechas, 12,5% ref.<br>Caza: Gen 1, Ambos, Ruin, 2 flechas, 20% ref.<br>Caza: Gen 1, Ambos, Ruin, 3 flechas, 14,29% ref.<br>Caza: Gen 1, Zafiro, Ice Cave, 2 flechas, 14,29% ref.<br>Caza: Gen 1, Zafiro, Ice Cave, 3 flechas, 25% ref.<br>Candidato a caza: RANDOM, Ambos, Ocean, 3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Ambos, Ruin, 2/3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Zafiro, Ice Cave, 2/3 flechas; seleccion y porcentaje variables por partida |
| 132 | Ditto | Caza: Gen 1, Zafiro, Wilderness, 2 flechas, 14,29% ref.<br>Caza: Gen 1, Zafiro, Wilderness, 3 flechas, 14,29% ref.<br>Caza: Gen 1, Ambos, Ruin, 3 flechas, 14,29% ref.<br>Candidato a caza: RANDOM, Ambos, Ruin, 3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Zafiro, Wilderness, 2/3 flechas; seleccion y porcentaje variables por partida |
| 133 | Eevee | Caza: Gen 1, Zafiro, Plains, 3 flechas, 12,5% ref.<br>Caza: Gen 1, Ruby, City, 2 flechas, 12,5% ref.<br>Caza: Gen 1, Ruby, City, 3 flechas, 12,5% ref.<br>Caza: Gen 2, Ambos, Ruin, 2 flechas, 16,67% ref.<br>Caza: Gen 2, Ambos, Ruin, 3 flechas, 14,08% ref.<br>Caza: Gen 4, Ambos, Forest, 3 flechas, 12,5% ref.<br>Caza: Gen 4, Ambos, Plains, 2 flechas, 12,5% ref.<br>Caza: Gen 4, Ambos, Plains, 3 flechas, 12,5% ref.<br>Caza: Gen 4, Ruby, City, 2 flechas, 12,5% ref.<br>Caza: Gen 4, Ruby, City, 3 flechas, 12,5% ref.<br>Caza: Gen 4, Zafiro, Ice Cave, 2 flechas, 12,5% ref.<br>Caza: Gen 4, Zafiro, Ice Cave, 3 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ruby, City, 2/3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Ambos, Forest, 3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Ambos, Plains, 2/3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Ambos, Ruin, 2/3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Zafiro, Ice Cave, 2/3 flechas; seleccion y porcentaje variables por partida |
| 134 | Vaporeon | Evolucion de Eevee (Ocean de ambos tableros o Lake) |
| 135 | Jolteon | Evolucion de Eevee (resto de zonas, salvo Espeon/Umbreon en Gen 2 o RANDOM y Leafeon/Glaceon en Gen 4 o RANDOM) |
| 136 | Flareon | Evolucion de Eevee (Volcano) |
| 137 | Porygon | Caza: Gen 1, Zafiro, Wilderness, 2 flechas, 14,29% ref.<br>Caza: Gen 4, Ruby, City, 2 flechas, 12,5% ref.<br>Caza: Gen 4, Ruby, City, 3 flechas, 12,5% ref.<br>Caza: Gen 4, Zafiro, Ice Cave, 2 flechas, 12,5% ref.<br>Caza: Gen 4, Zafiro, Ice Cave, 3 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ruby, City, 2/3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Zafiro, Ice Cave, 2/3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Zafiro, Wilderness, 2 flechas; seleccion y porcentaje variables por partida |
| 138 | Omanyte | Caza: Gen 1, Ambos, Ruin, 2 flechas, 20% ref.<br>Caza: Gen 1, Ambos, Ruin, 3 flechas, 14,29% ref.<br>Candidato a caza: RANDOM, Ambos, Ruin, 2/3 flechas; seleccion y porcentaje variables por partida |
| 139 | Omastar | Evolucion de Omanyte |
| 140 | Kabuto | Caza: Gen 1, Ambos, Ruin, 2 flechas, 20% ref.<br>Caza: Gen 1, Ambos, Ruin, 3 flechas, 14,29% ref.<br>Candidato a caza: RANDOM, Ambos, Ruin, 2/3 flechas; seleccion y porcentaje variables por partida |
| 141 | Kabutops | Evolucion de Kabuto |
| 143 | Snorlax | Caza: Gen 1, Zafiro, Wilderness, 3 flechas, 14,29% ref.<br>Caza: Gen 1, Ambos, Ruin, 3 flechas, 14,29% ref.<br>Candidato a caza: RANDOM, Ambos, Ruin, 3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Zafiro, Wilderness, 3 flechas; seleccion y porcentaje variables por partida<br>Evolucion de Munchlax |
| 147 | Dratini | Caza: Gen 1, Ambos, Ocean, 3 flechas, 12,5% ref.<br>Caza: Gen 1, Zafiro, Lake, 3 flechas, 14,29% ref.<br>Candidato a caza: RANDOM, Ambos, Ocean, 3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Zafiro, Lake, 3 flechas; seleccion y porcentaje variables por partida |
| 148 | Dragonair | Evolucion de Dratini |
| 149 | Dragonite | Evolucion de Dragonair |
| 153 | Bayleef | Evolucion de Chikorita |
| 154 | Meganium | Evolucion de Bayleef |
| 156 | Quilava | Evolucion de Cyndaquil |
| 157 | Typhlosion | Evolucion de Quilava |
| 159 | Croconaw | Evolucion de Totodile |
| 160 | Feraligatr | Evolucion de Croconaw |
| 161 | Sentret | Caza: Gen 2, Ambos, Forest, 2 flechas, 12,5% ref.<br>Caza: Gen 2, Ambos, Forest, 3 flechas, 12,5% ref.<br>Caza: Gen 2, Ruby, City, 2 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ruby, City, 2 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Ambos, Forest, 2/3 flechas; seleccion y porcentaje variables por partida |
| 162 | Furret | Evolucion de Sentret |
| 163 | Hoothoot | Caza: Gen 2, Ambos, Forest, 2 flechas, 12,5% ref.<br>Caza: Gen 2, Ambos, Forest, 3 flechas, 12,5% ref.<br>Caza: Gen 2, Ruby, City, 2 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ruby, City, 2 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Ambos, Forest, 2/3 flechas; seleccion y porcentaje variables por partida |
| 164 | Noctowl | Evolucion de Hoothoot |
| 165 | Ledyba | Caza: Gen 2, Ambos, Forest, 2 flechas, 12,5% ref.<br>Caza: Gen 2, Ambos, Forest, 3 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ambos, Forest, 2/3 flechas; seleccion y porcentaje variables por partida |
| 166 | Ledian | Evolucion de Ledyba |
| 167 | Spinarak | Caza: Gen 2, Ambos, Forest, 2 flechas, 12,5% ref.<br>Caza: Gen 2, Ambos, Forest, 3 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ambos, Forest, 2/3 flechas; seleccion y porcentaje variables por partida |
| 168 | Ariados | Evolucion de Spinarak |
| 169 | Crobat | Evolucion de Golbat |
| 170 | Chinchou | Caza: Gen 2, Ambos, Ocean, 2 flechas, 14,29% ref.<br>Caza: Gen 2, Ambos, Ocean, 3 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ambos, Ocean, 2/3 flechas; seleccion y porcentaje variables por partida<br>Huevo: Gen 1, Ruby, Cualquier zona, 4% ref.<br>Huevo: Gen 1, Zafiro, Cualquier zona, 8% ref.<br>Huevo: Gen 2, Ambos, Cualquier zona, 8% ref.<br>Huevo: Gen 3, Ruby, Cualquier zona, 4% ref.<br>Huevo: Gen 3, Zafiro, Cualquier zona, 8% ref.<br>Huevo: RANDOM, Ruby, Cualquier zona, 4% ref.<br>Huevo: RANDOM, Zafiro, Cualquier zona, 5,33% ref. |
| 171 | Lanturn | Evolucion de Chinchou |
| 173 | Cleffa | Caza: Gen 2, Ruby, City, 3 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ruby, City, 3 flechas; seleccion y porcentaje variables por partida<br>Huevo: Gen 2, Ruby, Cualquier zona, 8% ref.<br>Huevo: Gen 2, Zafiro, Cualquier zona, 12% ref.<br>Huevo: RANDOM, Ruby, Cualquier zona, 2,67% ref.<br>Huevo: RANDOM, Zafiro, Cualquier zona, 4% ref. |
| 174 | Igglybuff | Caza: Gen 2, Ruby, City, 3 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ruby, City, 3 flechas; seleccion y porcentaje variables por partida<br>Huevo: Gen 1, Zafiro, Cualquier zona, 4% ref.<br>Huevo: Gen 2, Ambos, Cualquier zona, 8% ref.<br>Huevo: Gen 3, Zafiro, Cualquier zona, 4% ref.<br>Huevo: RANDOM, Ruby, Cualquier zona, 2,67% ref.<br>Huevo: RANDOM, Zafiro, Cualquier zona, 4% ref. |
| 175 | Togepi | Caza: Gen 2, Ambos, Forest, 3 flechas, 12,5% ref.<br>Caza: Gen 2, Ruby, City, 2 flechas, 12,5% ref.<br>Caza: Gen 2, Ruby, City, 3 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ruby, City, 2/3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Ambos, Forest, 3 flechas; seleccion y porcentaje variables por partida<br>Huevo: Gen 2, Ruby, Cualquier zona, 12% ref.<br>Huevo: Gen 2, Zafiro, Cualquier zona, 8% ref.<br>Huevo: Gen 4, Ambos, Cualquier zona, 4% ref.<br>Huevo: RANDOM, Ruby, Cualquier zona, 5,33% ref.<br>Huevo: RANDOM, Zafiro, Cualquier zona, 4% ref. |
| 176 | Togetic | Evolucion de Togepi |
| 177 | Natu | Caza: Gen 2, Ruby, Safari Zone, 2 flechas, 14,08% ref.<br>Caza: Gen 2, Ruby, Safari Zone, 3 flechas, 14,08% ref.<br>Candidato a caza: RANDOM, Ruby, Safari Zone, 2/3 flechas; seleccion y porcentaje variables por partida<br>Huevo: Gen 1, Ambos, Cualquier zona, 4% ref.<br>Huevo: Gen 2, Ambos, Cualquier zona, 8% ref.<br>Huevo: Gen 3, Ambos, Cualquier zona, 4% ref.<br>Huevo: RANDOM, Ambos, Cualquier zona, 4% ref. |
| 178 | Xatu | Caza: Gen 2, Ambos, Ruin, 2 flechas, 16,67% ref.<br>Caza: Gen 2, Ambos, Ruin, 3 flechas, 14,08% ref.<br>Candidato a caza: RANDOM, Ambos, Ruin, 2/3 flechas; seleccion y porcentaje variables por partida<br>Evolucion de Natu |
| 179 | Mareep | Caza: Gen 2, Ambos, Plains, 2 flechas, 12,5% ref.<br>Caza: Gen 2, Ambos, Plains, 3 flechas, 12,5% ref.<br>Caza: Gen 2, Zafiro, Wilderness, 2 flechas, 14,29% ref.<br>Caza: Gen 2, Zafiro, Wilderness, 3 flechas, 12,5% ref.<br>Caza: Gen 2, Ruby, City, 2 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ruby, City, 2 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Ambos, Plains, 2/3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Zafiro, Wilderness, 2/3 flechas; seleccion y porcentaje variables por partida |
| 180 | Flaaffy | Evolucion de Mareep |
| 181 | Ampharos | Caza: Gen 2, Ambos, Cave, 3 flechas, 14,29% ref.<br>Caza: Gen 2, Zafiro, Wilderness, 3 flechas, 12,5% ref.<br>Caza: Gen 2, Ambos, Ruin, 2 flechas, 16,67% ref.<br>Caza: Gen 2, Ambos, Ruin, 3 flechas, 14,08% ref.<br>Candidato a caza: RANDOM, Ambos, Cave, 3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Ambos, Ruin, 2/3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Zafiro, Wilderness, 3 flechas; seleccion y porcentaje variables por partida<br>Evolucion de Flaaffy |
| 182 | Bellossom | Evolucion de Gloom (Zafiro) |
| 183 | Marill | Caza: Gen 2, Zafiro, Lake, 2 flechas, 14,29% ref.<br>Caza: Gen 2, Zafiro, Lake, 3 flechas, 14,29% ref.<br>Caza: Gen 3, Zafiro, Lake, 2 flechas, 19,61% ref.<br>Caza: Gen 3, Zafiro, Lake, 3 flechas, 19,61% ref.<br>Candidato a caza: RANDOM, Zafiro, Lake, 2/3 flechas; seleccion y porcentaje variables por partida<br>Evolucion de Azurill |
| 184 | Azumarill | Evolucion de Marill |
| 185 | Sudowoodo | Caza: Gen 2, Ruby, Safari Zone, 2 flechas, 14,08% ref.<br>Caza: Gen 2, Ruby, Safari Zone, 3 flechas, 14,08% ref.<br>Candidato a caza: RANDOM, Ruby, Safari Zone, 2/3 flechas; seleccion y porcentaje variables por partida<br>Evolucion de Bonsly |
| 186 | Politoed | Evolucion de Poliwhirl (Zafiro) |
| 187 | Hoppip | Caza: Gen 2, Ambos, Forest, 2 flechas, 12,5% ref.<br>Caza: Gen 2, Ambos, Forest, 3 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ambos, Forest, 2/3 flechas; seleccion y porcentaje variables por partida |
| 188 | Skiploom | Evolucion de Hoppip |
| 189 | Jumpluff | Evolucion de Skiploom |
| 190 | Aipom | Caza: Gen 2, Ambos, Plains, 2 flechas, 12,5% ref.<br>Caza: Gen 2, Ambos, Plains, 3 flechas, 12,5% ref.<br>Caza: Gen 2, Ruby, City, 2 flechas, 12,5% ref.<br>Caza: Gen 2, Ruby, City, 3 flechas, 12,5% ref.<br>Caza: Gen 4, Ambos, Forest, 2 flechas, 12,5% ref.<br>Caza: Gen 4, Ambos, Forest, 3 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ruby, City, 2/3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Ambos, Forest, 2/3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Ambos, Plains, 2/3 flechas; seleccion y porcentaje variables por partida |
| 191 | Sunkern | Caza: Gen 2, Ambos, Forest, 2 flechas, 12,5% ref.<br>Caza: Gen 2, Ambos, Forest, 3 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ambos, Forest, 2/3 flechas; seleccion y porcentaje variables por partida |
| 192 | Sunflora | Evolucion de Sunkern |
| 193 | Yanma | Caza: Gen 2, Ruby, Safari Zone, 2 flechas, 14,08% ref.<br>Caza: Gen 2, Ruby, Safari Zone, 3 flechas, 14,08% ref.<br>Caza: Gen 4, Ambos, Plains, 3 flechas, 12,5% ref.<br>Caza: Gen 4, Ruby, Safari Zone, 2 flechas, 12,5% ref.<br>Caza: Gen 4, Ruby, Safari Zone, 3 flechas, 12,5% ref.<br>Caza: Gen 4, Zafiro, Lake, 2 flechas, 12,5% ref.<br>Caza: Gen 4, Zafiro, Lake, 3 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ambos, Plains, 3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Ruby, Safari Zone, 2/3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Zafiro, Lake, 2/3 flechas; seleccion y porcentaje variables por partida |
| 194 | Wooper | Caza: Gen 2, Ambos, Ocean, 2 flechas, 14,29% ref.<br>Caza: Gen 2, Ambos, Ocean, 3 flechas, 12,5% ref.<br>Caza: Gen 2, Zafiro, Lake, 2 flechas, 14,29% ref.<br>Caza: Gen 2, Zafiro, Lake, 3 flechas, 14,29% ref.<br>Candidato a caza: RANDOM, Ambos, Ocean, 2/3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Zafiro, Lake, 2/3 flechas; seleccion y porcentaje variables por partida |
| 195 | Quagsire | Caza: Gen 2, Zafiro, Lake, 3 flechas, 14,29% ref.<br>Caza: Gen 2, Ambos, Ruin, 2 flechas, 16,67% ref.<br>Caza: Gen 2, Ambos, Ruin, 3 flechas, 14,08% ref.<br>Caza: Gen 2, Zafiro, Ice Cave, 3 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ambos, Ruin, 2/3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Zafiro, Ice Cave, 3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Zafiro, Lake, 3 flechas; seleccion y porcentaje variables por partida<br>Evolucion de Wooper |
| 196 | Espeon | Evolucion de Eevee (Gen 2 o RANDOM, Plains de ambos tableros) |
| 197 | Umbreon | Evolucion de Eevee (Gen 2 o RANDOM, Ruin de ambos tableros) |
| 198 | Murkrow | Caza: Gen 2, Ruby, Safari Zone, 2 flechas, 14,08% ref.<br>Caza: Gen 2, Ruby, Safari Zone, 3 flechas, 14,08% ref.<br>Caza: Gen 2, Ruby, City, 2 flechas, 12,5% ref.<br>Caza: Gen 4, Ambos, Ruin, 2 flechas, 12,5% ref.<br>Caza: Gen 4, Ambos, Ruin, 3 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ruby, City, 2 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Ambos, Ruin, 2/3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Ruby, Safari Zone, 2/3 flechas; seleccion y porcentaje variables por partida |
| 199 | Slowking | Evolucion de Slowpoke (Zafiro) |
| 200 | Misdreavus | Caza: Gen 2, Ruby, Safari Zone, 2 flechas, 14,08% ref.<br>Caza: Gen 2, Ruby, Safari Zone, 3 flechas, 14,08% ref.<br>Caza: Gen 4, Ambos, Ruin, 2 flechas, 12,5% ref.<br>Caza: Gen 4, Ambos, Ruin, 3 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ambos, Ruin, 2/3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Ruby, Safari Zone, 2/3 flechas; seleccion y porcentaje variables por partida |
| 201 | Unown | Caza: Gen 2, Ruby, Safari Zone, 2 flechas, 14,08% ref.<br>Caza: Gen 2, Ruby, Safari Zone, 3 flechas, 14,08% ref.<br>Caza: Gen 2, Ambos, Ruin, 2 flechas, 16,67% ref.<br>Caza: Gen 2, Ambos, Ruin, 3 flechas, 14,08% ref.<br>Candidato a caza: RANDOM, Ambos, Ruin, 2/3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Ruby, Safari Zone, 2/3 flechas; seleccion y porcentaje variables por partida |
| 202 | Wobbuffet | Caza: Gen 2, Ruby, Safari Zone, 2 flechas, 1,41% ref.<br>Caza: Gen 2, Ruby, Safari Zone, 3 flechas, 1,41% ref.<br>Caza: Gen 3, Ruby, Safari Zone, 2 flechas, 1,64% ref.<br>Caza: Gen 3, Ruby, Safari Zone, 3 flechas, 1,64% ref.<br>Candidato a caza: RANDOM, Ruby, Safari Zone, 2/3 flechas; seleccion y porcentaje variables por partida<br>Evolucion de Wynaut |
| 203 | Girafarig | Caza: Gen 2, Ambos, Plains, 2 flechas, 12,5% ref.<br>Caza: Gen 2, Ambos, Plains, 3 flechas, 12,5% ref.<br>Caza: Gen 3, Ruby, Safari Zone, 2 flechas, 16,39% ref.<br>Caza: Gen 3, Ruby, Safari Zone, 3 flechas, 16,39% ref.<br>Candidato a caza: RANDOM, Ambos, Plains, 2/3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Ruby, Safari Zone, 2/3 flechas; seleccion y porcentaje variables por partida |
| 204 | Pineco | Caza: Gen 2, Ambos, Forest, 2 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ambos, Forest, 2 flechas; seleccion y porcentaje variables por partida |
| 205 | Forretress | Evolucion de Pineco |
| 206 | Dunsparce | Caza: Gen 2, Ambos, Plains, 2 flechas, 12,5% ref.<br>Caza: Gen 2, Ambos, Plains, 3 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ambos, Plains, 2/3 flechas; seleccion y porcentaje variables por partida |
| 207 | Gligar | Caza: Gen 2, Ambos, Cave, 2 flechas, 14,29% ref.<br>Caza: Gen 2, Ambos, Cave, 3 flechas, 14,29% ref.<br>Caza: Gen 2, Zafiro, Ice Cave, 2 flechas, 12,5% ref.<br>Caza: Gen 2, Zafiro, Ice Cave, 3 flechas, 12,5% ref.<br>Caza: Gen 4, Ambos, Cave, 2 flechas, 14,08% ref.<br>Caza: Gen 4, Ambos, Cave, 3 flechas, 14,08% ref.<br>Caza: Gen 4, Ruby, Volcano, 2 flechas, 12,5% ref.<br>Caza: Gen 4, Ruby, Volcano, 3 flechas, 14,08% ref.<br>Candidato a caza: RANDOM, Ambos, Cave, 2/3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Ruby, Volcano, 2/3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Zafiro, Ice Cave, 2/3 flechas; seleccion y porcentaje variables por partida |
| 208 | Steelix | Evolucion de Onix |
| 209 | Snubbull | Caza: Gen 2, Ambos, Plains, 2 flechas, 12,5% ref.<br>Caza: Gen 2, Ambos, Plains, 3 flechas, 12,5% ref.<br>Caza: Gen 2, Zafiro, Wilderness, 2 flechas, 14,29% ref.<br>Caza: Gen 2, Zafiro, Wilderness, 3 flechas, 12,5% ref.<br>Caza: Gen 2, Ruby, City, 2 flechas, 12,5% ref.<br>Caza: Gen 2, Ruby, City, 3 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ruby, City, 2/3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Ambos, Plains, 2/3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Zafiro, Wilderness, 2/3 flechas; seleccion y porcentaje variables por partida |
| 210 | Granbull | Evolucion de Snubbull |
| 211 | Qwilfish | Caza: Gen 2, Ambos, Ocean, 2 flechas, 14,29% ref.<br>Caza: Gen 2, Ambos, Ocean, 3 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ambos, Ocean, 2/3 flechas; seleccion y porcentaje variables por partida |
| 212 | Scizor | Evolucion de Scyther |
| 213 | Shuckle | Caza: Gen 2, Ambos, Cave, 2 flechas, 14,29% ref.<br>Caza: Gen 2, Ambos, Cave, 3 flechas, 14,29% ref.<br>Caza: Gen 2, Zafiro, Ice Cave, 2 flechas, 12,5% ref.<br>Caza: Gen 2, Zafiro, Ice Cave, 3 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ambos, Cave, 2/3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Zafiro, Ice Cave, 2/3 flechas; seleccion y porcentaje variables por partida |
| 214 | Heracross | Caza: Gen 2, Ruby, Safari Zone, 2 flechas, 14,08% ref.<br>Caza: Gen 2, Ruby, Safari Zone, 3 flechas, 14,08% ref.<br>Caza: Gen 3, Ruby, Safari Zone, 2 flechas, 16,39% ref.<br>Caza: Gen 3, Ruby, Safari Zone, 3 flechas, 16,39% ref.<br>Candidato a caza: RANDOM, Ruby, Safari Zone, 2/3 flechas; seleccion y porcentaje variables por partida |
| 215 | Sneasel | Caza: Gen 2, Ambos, Cave, 2 flechas, 14,29% ref.<br>Caza: Gen 2, Ambos, Cave, 3 flechas, 14,29% ref.<br>Caza: Gen 2, Zafiro, Wilderness, 2 flechas, 14,29% ref.<br>Caza: Gen 2, Zafiro, Wilderness, 3 flechas, 12,5% ref.<br>Caza: Gen 2, Zafiro, Ice Cave, 2 flechas, 12,5% ref.<br>Caza: Gen 2, Zafiro, Ice Cave, 3 flechas, 12,5% ref.<br>Caza: Gen 4, Ambos, Cave, 3 flechas, 14,08% ref.<br>Caza: Gen 4, Zafiro, Ice Cave, 2 flechas, 12,5% ref.<br>Caza: Gen 4, Zafiro, Ice Cave, 3 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ambos, Cave, 2/3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Zafiro, Ice Cave, 2/3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Zafiro, Wilderness, 2/3 flechas; seleccion y porcentaje variables por partida |
| 216 | Teddiursa | Caza: Gen 2, Ambos, Cave, 2 flechas, 14,29% ref.<br>Caza: Gen 2, Ambos, Cave, 3 flechas, 14,29% ref.<br>Caza: Gen 2, Zafiro, Wilderness, 2 flechas, 14,29% ref.<br>Caza: Gen 2, Zafiro, Wilderness, 3 flechas, 12,5% ref.<br>Caza: Gen 2, Zafiro, Ice Cave, 2 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ambos, Cave, 2/3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Zafiro, Ice Cave, 2 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Zafiro, Wilderness, 2/3 flechas; seleccion y porcentaje variables por partida |
| 217 | Ursaring | Evolucion de Teddiursa |
| 218 | Slugma | Caza: Gen 2, Ruby, Volcano, 2 flechas, 20% ref.<br>Caza: Gen 2, Ruby, Volcano, 3 flechas, 19,61% ref.<br>Caza: Gen 3, Ruby, Volcano, 2 flechas, 19,61% ref.<br>Candidato a caza: RANDOM, Ruby, Volcano, 2/3 flechas; seleccion y porcentaje variables por partida |
| 219 | Magcargo | Evolucion de Slugma |
| 220 | Swinub | Caza: Gen 2, Ambos, Cave, 2 flechas, 14,29% ref.<br>Caza: Gen 2, Ambos, Cave, 3 flechas, 14,29% ref.<br>Caza: Gen 2, Zafiro, Ice Cave, 2 flechas, 12,5% ref.<br>Caza: Gen 2, Zafiro, Ice Cave, 3 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ambos, Cave, 2/3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Zafiro, Ice Cave, 2/3 flechas; seleccion y porcentaje variables por partida<br>Huevo: Gen 2, Ambos, Cualquier zona, 8% ref.<br>Huevo: Gen 4, Ambos, Cualquier zona, 4% ref.<br>Huevo: RANDOM, Ambos, Cualquier zona, 4% ref. |
| 221 | Piloswine | Evolucion de Swinub |
| 222 | Corsola | Caza: Gen 2, Ambos, Ocean, 2 flechas, 14,29% ref.<br>Caza: Gen 2, Ambos, Ocean, 3 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ambos, Ocean, 2/3 flechas; seleccion y porcentaje variables por partida<br>Huevo: Gen 1, Ambos, Cualquier zona, 4% ref.<br>Huevo: Gen 2, Ambos, Cualquier zona, 8% ref.<br>Huevo: Gen 3, Ambos, Cualquier zona, 4% ref.<br>Huevo: RANDOM, Ambos, Cualquier zona, 4% ref. |
| 223 | Remoraid | Caza: Gen 2, Ambos, Ocean, 2 flechas, 14,29% ref.<br>Caza: Gen 2, Ambos, Ocean, 3 flechas, 12,5% ref.<br>Caza: Gen 2, Zafiro, Lake, 2 flechas, 14,29% ref.<br>Caza: Gen 2, Zafiro, Lake, 3 flechas, 14,29% ref.<br>Candidato a caza: RANDOM, Ambos, Ocean, 2/3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Zafiro, Lake, 2/3 flechas; seleccion y porcentaje variables por partida |
| 224 | Octillery | Evolucion de Remoraid |
| 225 | Delibird | Caza: Gen 2, Ambos, Cave, 2 flechas, 14,29% ref.<br>Caza: Gen 2, Zafiro, Ice Cave, 2 flechas, 12,5% ref.<br>Caza: Gen 2, Zafiro, Ice Cave, 3 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ambos, Cave, 2 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Zafiro, Ice Cave, 2/3 flechas; seleccion y porcentaje variables por partida |
| 226 | Mantine | Caza: Gen 2, Ambos, Ocean, 2 flechas, 14,29% ref.<br>Caza: Gen 2, Ambos, Ocean, 3 flechas, 25% ref.<br>Caza: Gen 2, Ambos, Ruin, 3 flechas, 14,08% ref.<br>Candidato a caza: RANDOM, Ambos, Ocean, 2/3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Ambos, Ruin, 3 flechas; seleccion y porcentaje variables por partida<br>Evolucion de Mantyke |
| 227 | Skarmory | Caza: Gen 2, Ruby, Volcano, 3 flechas, 1,96% ref.<br>Caza: Gen 2, Ambos, Ruin, 3 flechas, 1,41% ref.<br>Caza: Gen 3, Ruby, Volcano, 2 flechas, 1,96% ref.<br>Caza: Gen 3, Ruby, Volcano, 3 flechas, 1,96% ref.<br>Candidato a caza: RANDOM, Ambos, Ruin, 3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Ruby, Volcano, 2/3 flechas; seleccion y porcentaje variables por partida |
| 228 | Houndour | Caza: Gen 2, Ruby, Volcano, 2 flechas, 20% ref.<br>Caza: Gen 2, Ruby, Volcano, 3 flechas, 19,61% ref.<br>Caza: Gen 2, Zafiro, Wilderness, 2 flechas, 14,29% ref.<br>Caza: Gen 2, Zafiro, Wilderness, 3 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ruby, Volcano, 2/3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Zafiro, Wilderness, 2/3 flechas; seleccion y porcentaje variables por partida |
| 229 | Houndoom | Caza: Gen 2, Ruby, Volcano, 2 flechas, 20% ref.<br>Caza: Gen 2, Ruby, Volcano, 3 flechas, 19,61% ref.<br>Caza: Gen 2, Ambos, Ruin, 2 flechas, 16,67% ref.<br>Caza: Gen 2, Ambos, Ruin, 3 flechas, 14,08% ref.<br>Candidato a caza: RANDOM, Ambos, Ruin, 2/3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Ruby, Volcano, 2/3 flechas; seleccion y porcentaje variables por partida<br>Evolucion de Houndour |
| 230 | Kingdra | Evolucion de Seadra |
| 231 | Phanpy | Caza: Gen 2, Zafiro, Wilderness, 2 flechas, 14,29% ref.<br>Caza: Gen 2, Zafiro, Wilderness, 3 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Zafiro, Wilderness, 2/3 flechas; seleccion y porcentaje variables por partida<br>Huevo: Gen 1, Ambos, Cualquier zona, 8% ref.<br>Huevo: Gen 2, Ambos, Cualquier zona, 8% ref.<br>Huevo: Gen 3, Ambos, Cualquier zona, 8% ref.<br>Huevo: RANDOM, Ambos, Cualquier zona, 5,33% ref. |
| 232 | Donphan | Evolucion de Phanpy |
| 233 | Porygon2 | Evolucion de Porygon |
| 234 | Stantler | Caza: Gen 2, Ambos, Plains, 2 flechas, 12,5% ref.<br>Caza: Gen 2, Ambos, Plains, 3 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ambos, Plains, 2/3 flechas; seleccion y porcentaje variables por partida |
| 235 | Smeargle | Caza: Gen 2, Zafiro, Plains, 3 flechas, 12,5% ref.<br>Caza: Gen 2, Ruby, City, 2 flechas, 12,5% ref.<br>Caza: Gen 2, Ruby, City, 3 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ruby, City, 2/3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Zafiro, Plains, 3 flechas; seleccion y porcentaje variables por partida |
| 236 | Tyrogue | Caza: Gen 2, Ruby, Plains, 3 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ruby, Plains, 3 flechas; seleccion y porcentaje variables por partida<br>Huevo: Gen 2, Ambos, Cualquier zona, 8% ref.<br>Huevo: RANDOM, Ambos, Cualquier zona, 2,67% ref. |
| 237 | Hitmontop | Evolucion de Tyrogue (segun zona y las ramas pendientes en la Pokedex) |
| 238 | Smoochum | Caza: Gen 2, Zafiro, Wilderness, 3 flechas, 12,5% ref.<br>Caza: Gen 2, Zafiro, Ice Cave, 2 flechas, 12,5% ref.<br>Caza: Gen 2, Zafiro, Ice Cave, 3 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Zafiro, Ice Cave, 2/3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Zafiro, Wilderness, 3 flechas; seleccion y porcentaje variables por partida<br>Huevo: Gen 2, Ambos, Cualquier zona, 8% ref.<br>Huevo: RANDOM, Ambos, Cualquier zona, 2,67% ref. |
| 239 | Elekid | Caza: Gen 2, Zafiro, Wilderness, 2 flechas, 14,29% ref.<br>Candidato a caza: RANDOM, Zafiro, Wilderness, 2 flechas; seleccion y porcentaje variables por partida<br>Huevo: Gen 2, Ambos, Cualquier zona, 8% ref.<br>Huevo: Gen 4, Ambos, Cualquier zona, 4% ref.<br>Huevo: RANDOM, Ambos, Cualquier zona, 4% ref. |
| 240 | Magby | Caza: Gen 2, Ruby, Volcano, 2 flechas, 20% ref.<br>Caza: Gen 2, Ruby, Volcano, 3 flechas, 19,61% ref.<br>Candidato a caza: RANDOM, Ruby, Volcano, 2/3 flechas; seleccion y porcentaje variables por partida<br>Huevo: Gen 2, Ambos, Cualquier zona, 8% ref.<br>Huevo: Gen 4, Ambos, Cualquier zona, 4% ref.<br>Huevo: RANDOM, Ambos, Cualquier zona, 4% ref. |
| 241 | Miltank | Caza: Gen 2, Ambos, Plains, 2 flechas, 12,5% ref.<br>Caza: Gen 2, Ambos, Plains, 3 flechas, 12,5% ref.<br>Caza: Gen 2, Ruby, City, 3 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ruby, City, 3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Ambos, Plains, 2/3 flechas; seleccion y porcentaje variables por partida |
| 242 | Blissey | Evolucion de Chansey |
| 246 | Larvitar | Caza: Gen 2, Ambos, Cave, 2 flechas, 14,29% ref.<br>Caza: Gen 2, Ambos, Cave, 3 flechas, 14,29% ref.<br>Caza: Gen 2, Zafiro, Ice Cave, 2 flechas, 12,5% ref.<br>Caza: Gen 2, Zafiro, Ice Cave, 3 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ambos, Cave, 2/3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Zafiro, Ice Cave, 2/3 flechas; seleccion y porcentaje variables por partida |
| 247 | Pupitar | Evolucion de Larvitar |
| 248 | Tyranitar | Evolucion de Pupitar |
| 252 | Treecko | Caza: Gen 3, Ruby, Forest, 3 flechas, 14,08% ref.<br>Candidato a caza: RANDOM, Ruby, Forest, 3 flechas; seleccion y porcentaje variables por partida |
| 253 | Grovyle | Evolucion de Treecko |
| 254 | Sceptile | Evolucion de Grovyle |
| 255 | Torchic | Caza: Gen 3, Ruby, Volcano, 3 flechas, 19,61% ref.<br>Candidato a caza: RANDOM, Ruby, Volcano, 3 flechas; seleccion y porcentaje variables por partida |
| 256 | Combusken | Evolucion de Torchic |
| 257 | Blaziken | Evolucion de Combusken |
| 258 | Mudkip | Caza: Gen 3, Zafiro, Lake, 3 flechas, 19,61% ref.<br>Candidato a caza: RANDOM, Zafiro, Lake, 3 flechas; seleccion y porcentaje variables por partida |
| 259 | Marshtomp | Evolucion de Mudkip |
| 260 | Swampert | Evolucion de Marshtomp |
| 261 | Poochyena | Caza: Gen 3, Ambos, Plains, 2 flechas, 16,39% ref.<br>Caza: Gen 3, Ruby, Plains, 3 flechas, 19,61% ref.<br>Caza: Gen 3, Zafiro, Plains, 3 flechas, 14,08% ref.<br>Candidato a caza: RANDOM, Ambos, Plains, 2/3 flechas; seleccion y porcentaje variables por partida |
| 262 | Mightyena | Evolucion de Poochyena |
| 263 | Zigzagoon | Caza: Gen 3, Ruby, Forest, 2 flechas, 16,39% ref.<br>Caza: Gen 3, Ruby, City, 2 flechas, 14,08% ref.<br>Candidato a caza: RANDOM, Ruby, City, 2 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Ruby, Forest, 2 flechas; seleccion y porcentaje variables por partida |
| 264 | Linoone | Evolucion de Zigzagoon |
| 265 | Wurmple | Huevo: Gen 1, Ambos, Cualquier zona, 4% ref.<br>Huevo: Gen 3, Ambos, Cualquier zona, 4% ref.<br>Huevo: RANDOM, Ambos, Cualquier zona, 1,33% ref. |
| 266 | Silcoon | Caza: Gen 3, Ruby, Forest, 2 flechas, 16,39% ref.<br>Caza: Gen 3, Ambos, Forest, 3 flechas, 14,08% ref.<br>Caza: Gen 3, Zafiro, Forest, 2 flechas, 19,61% ref.<br>Candidato a caza: RANDOM, Ambos, Forest, 2/3 flechas; seleccion y porcentaje variables por partida<br>Evolucion de Wurmple (prioridad si falta en la Pokedex; si ambas ramas estan capturadas, Ruby) |
| 267 | Beautifly | Evolucion de Silcoon |
| 268 | Cascoon | Caza: Gen 3, Ruby, Forest, 2 flechas, 16,39% ref.<br>Caza: Gen 3, Ambos, Forest, 3 flechas, 14,08% ref.<br>Caza: Gen 3, Zafiro, Forest, 2 flechas, 19,61% ref.<br>Candidato a caza: RANDOM, Ambos, Forest, 2/3 flechas; seleccion y porcentaje variables por partida<br>Evolucion de Wurmple (si Silcoon esta capturado y falta Cascoon; si ambas ramas estan capturadas, Zafiro) |
| 269 | Dustox | Evolucion de Cascoon |
| 270 | Lotad | Huevo: Gen 1, Zafiro, Cualquier zona, 4% ref.<br>Huevo: Gen 3, Zafiro, Cualquier zona, 4% ref.<br>Huevo: RANDOM, Zafiro, Cualquier zona, 1,33% ref. |
| 271 | Lombre | Caza: Gen 3, Zafiro, Lake, 2 flechas, 19,61% ref.<br>Caza: Gen 3, Zafiro, Lake, 3 flechas, 19,61% ref.<br>Candidato a caza: RANDOM, Zafiro, Lake, 2/3 flechas; seleccion y porcentaje variables por partida<br>Evolucion de Lotad |
| 272 | Ludicolo | Evolucion de Lombre |
| 273 | Seedot | Huevo: Gen 1, Ruby, Cualquier zona, 4% ref.<br>Huevo: Gen 3, Ruby, Cualquier zona, 4% ref.<br>Huevo: RANDOM, Ruby, Cualquier zona, 1,33% ref. |
| 274 | Nuzleaf | Evolucion de Seedot |
| 275 | Shiftry | Evolucion de Nuzleaf |
| 276 | Taillow | Caza: Gen 3, Ambos, Plains, 2 flechas, 16,39% ref.<br>Caza: Gen 3, Ruby, Plains, 3 flechas, 19,61% ref.<br>Caza: Gen 3, Zafiro, Plains, 3 flechas, 14,08% ref.<br>Caza: Gen 3, Ruby, City, 2 flechas, 14,08% ref.<br>Candidato a caza: RANDOM, Ruby, City, 2 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Ambos, Plains, 2/3 flechas; seleccion y porcentaje variables por partida |
| 277 | Swellow | Evolucion de Taillow |
| 278 | Wingull | Caza: Gen 3, Ambos, Ocean, 2 flechas, 19,61% ref.<br>Candidato a caza: RANDOM, Ambos, Ocean, 2 flechas; seleccion y porcentaje variables por partida |
| 279 | Pelipper | Evolucion de Wingull |
| 280 | Ralts | Huevo: Gen 1, Ambos, Cualquier zona, 4% ref.<br>Huevo: Gen 3, Ambos, Cualquier zona, 4% ref.<br>Huevo: Gen 4, Ambos, Cualquier zona, 4% ref.<br>Huevo: RANDOM, Ambos, Cualquier zona, 2,67% ref. |
| 281 | Kirlia | Evolucion de Ralts |
| 282 | Gardevoir | Evolucion de Kirlia (rama base; en Gen 4/RANDOM se prioriza si falta y se elige en Ruby si ambas estan capturadas) |
| 283 | Surskit | Huevo: Gen 1, Zafiro, Cualquier zona, 4% ref.<br>Huevo: Gen 3, Zafiro, Cualquier zona, 4% ref.<br>Huevo: RANDOM, Zafiro, Cualquier zona, 1,33% ref. |
| 284 | Masquerain | Evolucion de Surskit |
| 285 | Shroomish | Huevo: Gen 1, Ruby, Cualquier zona, 4% ref.<br>Huevo: Gen 3, Ruby, Cualquier zona, 4% ref.<br>Huevo: RANDOM, Ruby, Cualquier zona, 1,33% ref. |
| 286 | Breloom | Evolucion de Shroomish |
| 287 | Slakoth | Caza: Gen 3, Ruby, Forest, 2 flechas, 16,39% ref.<br>Caza: Gen 3, Ambos, Forest, 3 flechas, 14,08% ref.<br>Caza: Gen 3, Zafiro, Forest, 2 flechas, 19,61% ref.<br>Candidato a caza: RANDOM, Ambos, Forest, 2/3 flechas; seleccion y porcentaje variables por partida |
| 288 | Vigoroth | Evolucion de Slakoth |
| 289 | Slaking | Evolucion de Vigoroth |
| 290 | Nincada | Caza: Gen 3, Ambos, Forest, 3 flechas, 14,08% ref.<br>Candidato a caza: RANDOM, Ambos, Forest, 3 flechas; seleccion y porcentaje variables por partida |
| 291 | Ninjask | Evolucion de Nincada (se registra al evolucionar Nincada) |
| 292 | Shedinja | Evolucion de Nincada (se registra adicionalmente al evolucionar Nincada) |
| 293 | Whismur | Huevo: Gen 1, Ambos, Cualquier zona, 4% ref.<br>Huevo: Gen 3, Ambos, Cualquier zona, 4% ref.<br>Huevo: RANDOM, Ambos, Cualquier zona, 1,33% ref. |
| 294 | Loudred | Caza: Gen 3, Ruby, Cave, 2 flechas, 16,39% ref.<br>Caza: Gen 3, Ruby, Cave, 3 flechas, 19,61% ref.<br>Caza: Gen 3, Zafiro, Cave, 2 flechas, 19,61% ref.<br>Caza: Gen 3, Zafiro, Cave, 3 flechas, 16,39% ref.<br>Candidato a caza: RANDOM, Ambos, Cave, 2/3 flechas; seleccion y porcentaje variables por partida<br>Evolucion de Whismur |
| 295 | Exploud | Evolucion de Loudred |
| 296 | Makuhita | Caza: Gen 3, Zafiro, Cave, 2 flechas, 19,61% ref.<br>Caza: Gen 3, Zafiro, Cave, 3 flechas, 16,39% ref.<br>Candidato a caza: RANDOM, Zafiro, Cave, 2/3 flechas; seleccion y porcentaje variables por partida |
| 297 | Hariyama | Evolucion de Makuhita |
| 298 | Azurill | Huevo: Gen 1, Zafiro, Cualquier zona, 8% ref.<br>Huevo: Gen 3, Zafiro, Cualquier zona, 8% ref.<br>Huevo: RANDOM, Zafiro, Cualquier zona, 2,67% ref. |
| 299 | Nosepass | Caza: Gen 3, Ruby, Cave, 2 flechas, 1,64% ref.<br>Caza: Gen 3, Ruby, Cave, 3 flechas, 1,96% ref.<br>Caza: Gen 3, Zafiro, Cave, 2 flechas, 1,96% ref.<br>Caza: Gen 3, Zafiro, Cave, 3 flechas, 1,64% ref.<br>Caza: Gen 3, Zafiro, Ice Cave, 2 flechas, 1,92% ref.<br>Caza: Gen 3, Zafiro, Ice Cave, 3 flechas, 1,61% ref.<br>Caza: Gen 4, Ambos, Cave, 2 flechas, 1,41% ref.<br>Caza: Gen 4, Ambos, Cave, 3 flechas, 1,41% ref.<br>Caza: Gen 4, Ruby, Volcano, 3 flechas, 1,41% ref.<br>Candidato a caza: RANDOM, Ambos, Cave, 2/3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Ruby, Volcano, 3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Zafiro, Ice Cave, 2/3 flechas; seleccion y porcentaje variables por partida |
| 300 | Skitty | Caza: Gen 3, Ruby, City, 2 flechas, 14,08% ref.<br>Candidato a caza: RANDOM, Ruby, City, 2 flechas; seleccion y porcentaje variables por partida<br>Huevo: Gen 1, Ruby, Cualquier zona, 8% ref.<br>Huevo: Gen 3, Ruby, Cualquier zona, 8% ref.<br>Huevo: RANDOM, Ruby, Cualquier zona, 2,67% ref. |
| 301 | Delcatty | Evolucion de Skitty |
| 302 | Sableye | Caza: Gen 3, Zafiro, Cave, 3 flechas, 16,39% ref.<br>Candidato a caza: RANDOM, Zafiro, Cave, 3 flechas; seleccion y porcentaje variables por partida |
| 303 | Mawile | Caza: Gen 3, Ruby, Cave, 2 flechas, 16,39% ref.<br>Candidato a caza: RANDOM, Ruby, Cave, 2 flechas; seleccion y porcentaje variables por partida |
| 304 | Aron | Caza: Gen 3, Zafiro, Ice Cave, 2 flechas, 19,23% ref.<br>Caza: Gen 3, Zafiro, Ice Cave, 3 flechas, 16,13% ref.<br>Candidato a caza: RANDOM, Zafiro, Ice Cave, 2/3 flechas; seleccion y porcentaje variables por partida<br>Huevo: Gen 1, Ambos, Cualquier zona, 4% ref.<br>Huevo: Gen 3, Ambos, Cualquier zona, 4% ref.<br>Huevo: RANDOM, Ambos, Cualquier zona, 1,33% ref. |
| 305 | Lairon | Caza: Gen 3, Zafiro, Ice Cave, 3 flechas, 16,13% ref.<br>Candidato a caza: RANDOM, Zafiro, Ice Cave, 3 flechas; seleccion y porcentaje variables por partida<br>Evolucion de Aron |
| 306 | Aggron | Evolucion de Lairon |
| 307 | Meditite | Caza: Gen 3, Zafiro, Wilderness, 2 flechas, 19,61% ref.<br>Caza: Gen 3, Zafiro, Wilderness, 3 flechas, 19,61% ref.<br>Candidato a caza: RANDOM, Zafiro, Wilderness, 2/3 flechas; seleccion y porcentaje variables por partida |
| 308 | Medicham | Evolucion de Meditite |
| 309 | Electrike | Caza: Gen 3, Ambos, Plains, 2 flechas, 16,39% ref.<br>Caza: Gen 3, Ruby, City, 2 flechas, 14,08% ref.<br>Caza: Gen 3, Ruby, City, 3 flechas, 16,13% ref.<br>Candidato a caza: RANDOM, Ruby, City, 2/3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Ambos, Plains, 2 flechas; seleccion y porcentaje variables por partida |
| 310 | Manectric | Evolucion de Electrike |
| 311 | Plusle | Caza: Gen 3, Ruby, City, 3 flechas, 16,13% ref.<br>Candidato a caza: RANDOM, Ruby, City, 3 flechas; seleccion y porcentaje variables por partida<br>Huevo: Gen 1, Ruby, Cualquier zona, 4% ref.<br>Huevo: Gen 3, Ruby, Cualquier zona, 4% ref.<br>Huevo: RANDOM, Ruby, Cualquier zona, 1,33% ref. |
| 312 | Minun | Caza: Gen 3, Ruby, City, 3 flechas, 16,13% ref.<br>Candidato a caza: RANDOM, Ruby, City, 3 flechas; seleccion y porcentaje variables por partida<br>Huevo: Gen 1, Ruby, Cualquier zona, 4% ref.<br>Huevo: Gen 3, Ruby, Cualquier zona, 4% ref.<br>Huevo: RANDOM, Ruby, Cualquier zona, 1,33% ref. |
| 313 | Volbeat | Caza: Gen 3, Zafiro, Plains, 3 flechas, 14,08% ref.<br>Candidato a caza: RANDOM, Zafiro, Plains, 3 flechas; seleccion y porcentaje variables por partida |
| 314 | Illumise | Caza: Gen 3, Ruby, Plains, 2 flechas, 16,39% ref.<br>Candidato a caza: RANDOM, Ruby, Plains, 2 flechas; seleccion y porcentaje variables por partida |
| 315 | Roselia | Caza: Gen 3, Ruby, Forest, 2 flechas, 16,39% ref.<br>Caza: Gen 3, Ambos, Forest, 3 flechas, 14,08% ref.<br>Caza: Gen 3, Zafiro, Forest, 2 flechas, 19,61% ref.<br>Candidato a caza: RANDOM, Ambos, Forest, 2/3 flechas; seleccion y porcentaje variables por partida<br>Evolucion de Budew |
| 316 | Gulpin | Caza: Gen 3, Ruby, City, 2 flechas, 14,08% ref.<br>Candidato a caza: RANDOM, Ruby, City, 2 flechas; seleccion y porcentaje variables por partida<br>Huevo: Gen 1, Zafiro, Cualquier zona, 8% ref.<br>Huevo: Gen 3, Zafiro, Cualquier zona, 8% ref.<br>Huevo: RANDOM, Zafiro, Cualquier zona, 2,67% ref. |
| 317 | Swalot | Evolucion de Gulpin |
| 318 | Carvanha | Caza: Gen 3, Ambos, Ocean, 2 flechas, 19,61% ref.<br>Caza: Gen 3, Ambos, Ocean, 3 flechas, 16,39% ref.<br>Candidato a caza: RANDOM, Ambos, Ocean, 2/3 flechas; seleccion y porcentaje variables por partida |
| 319 | Sharpedo | Evolucion de Carvanha |
| 320 | Wailmer | Caza: Gen 3, Ruby, Ocean, 2 flechas, 19,61% ref.<br>Caza: Gen 3, Ruby, Ocean, 3 flechas, 16,39% ref.<br>Candidato a caza: RANDOM, Ruby, Ocean, 2/3 flechas; seleccion y porcentaje variables por partida |
| 321 | Wailord | Evolucion de Wailmer |
| 322 | Numel | Caza: Gen 3, Ruby, Volcano, 2 flechas, 19,61% ref.<br>Caza: Gen 3, Ruby, Volcano, 3 flechas, 19,61% ref.<br>Candidato a caza: RANDOM, Ruby, Volcano, 2/3 flechas; seleccion y porcentaje variables por partida |
| 323 | Camerupt | Evolucion de Numel |
| 324 | Torkoal | Caza: Gen 3, Ruby, Volcano, 2 flechas, 19,61% ref.<br>Caza: Gen 3, Ruby, Volcano, 3 flechas, 19,61% ref.<br>Candidato a caza: RANDOM, Ruby, Volcano, 2/3 flechas; seleccion y porcentaje variables por partida |
| 325 | Spoink | Huevo: Gen 1, Ruby, Cualquier zona, 8% ref.<br>Huevo: Gen 1, Zafiro, Cualquier zona, 4% ref.<br>Huevo: Gen 3, Ruby, Cualquier zona, 8% ref.<br>Huevo: Gen 3, Zafiro, Cualquier zona, 4% ref.<br>Huevo: RANDOM, Ruby, Cualquier zona, 2,67% ref.<br>Huevo: RANDOM, Zafiro, Cualquier zona, 1,33% ref. |
| 326 | Grumpig | Evolucion de Spoink |
| 327 | Spinda | Caza: Gen 3, Ruby, City, 3 flechas, 16,13% ref.<br>Candidato a caza: RANDOM, Ruby, City, 3 flechas; seleccion y porcentaje variables por partida<br>Huevo: Gen 1, Ambos, Cualquier zona, 4% ref.<br>Huevo: Gen 3, Ambos, Cualquier zona, 4% ref.<br>Huevo: RANDOM, Ambos, Cualquier zona, 1,33% ref. |
| 328 | Trapinch | Huevo: Gen 1, Ambos, Cualquier zona, 4% ref.<br>Huevo: Gen 3, Ambos, Cualquier zona, 4% ref.<br>Huevo: RANDOM, Ambos, Cualquier zona, 1,33% ref. |
| 329 | Vibrava | Caza: Gen 3, Zafiro, Wilderness, 2 flechas, 19,61% ref.<br>Caza: Gen 3, Zafiro, Wilderness, 3 flechas, 19,61% ref.<br>Candidato a caza: RANDOM, Zafiro, Wilderness, 2/3 flechas; seleccion y porcentaje variables por partida<br>Evolucion de Trapinch |
| 330 | Flygon | Evolucion de Vibrava |
| 331 | Cacnea | Caza: Gen 3, Zafiro, Wilderness, 2 flechas, 19,61% ref.<br>Caza: Gen 3, Zafiro, Wilderness, 3 flechas, 19,61% ref.<br>Candidato a caza: RANDOM, Zafiro, Wilderness, 2/3 flechas; seleccion y porcentaje variables por partida |
| 332 | Cacturne | Evolucion de Cacnea |
| 333 | Swablu | Caza: Gen 3, Zafiro, Wilderness, 3 flechas, 19,61% ref.<br>Candidato a caza: RANDOM, Zafiro, Wilderness, 3 flechas; seleccion y porcentaje variables por partida |
| 334 | Altaria | Evolucion de Swablu |
| 335 | Zangoose | Caza: Gen 3, Ruby, Plains, 3 flechas, 19,61% ref.<br>Candidato a caza: RANDOM, Ruby, Plains, 3 flechas; seleccion y porcentaje variables por partida |
| 336 | Seviper | Caza: Gen 3, Zafiro, Plains, 3 flechas, 14,08% ref.<br>Candidato a caza: RANDOM, Zafiro, Plains, 3 flechas; seleccion y porcentaje variables por partida |
| 337 | Lunatone | Caza: Gen 3, Zafiro, Cave, 2 flechas, 19,61% ref.<br>Caza: Gen 3, Zafiro, Cave, 3 flechas, 16,39% ref.<br>Candidato a caza: RANDOM, Zafiro, Cave, 2/3 flechas; seleccion y porcentaje variables por partida |
| 338 | Solrock | Caza: Gen 3, Ruby, Cave, 2 flechas, 16,39% ref.<br>Caza: Gen 3, Ruby, Cave, 3 flechas, 19,61% ref.<br>Candidato a caza: RANDOM, Ruby, Cave, 2/3 flechas; seleccion y porcentaje variables por partida |
| 339 | Barboach | Caza: Gen 3, Zafiro, Lake, 2 flechas, 19,61% ref.<br>Caza: Gen 3, Zafiro, Lake, 3 flechas, 19,61% ref.<br>Candidato a caza: RANDOM, Zafiro, Lake, 2/3 flechas; seleccion y porcentaje variables por partida |
| 340 | Whiscash | Evolucion de Barboach |
| 341 | Corphish | Caza: Gen 3, Zafiro, Lake, 2 flechas, 19,61% ref.<br>Caza: Gen 3, Zafiro, Lake, 3 flechas, 19,61% ref.<br>Candidato a caza: RANDOM, Zafiro, Lake, 2/3 flechas; seleccion y porcentaje variables por partida |
| 342 | Crawdaunt | Evolucion de Corphish |
| 343 | Baltoy | Caza: Gen 3, Zafiro, Wilderness, 2 flechas, 19,61% ref.<br>Candidato a caza: RANDOM, Zafiro, Wilderness, 2 flechas; seleccion y porcentaje variables por partida |
| 344 | Claydol | Evolucion de Baltoy |
| 345 | Lileep | Caza: Gen 3, Ruby, Ocean, 2 flechas, 1,96% ref.<br>Caza: Gen 3, Ruby, Ocean, 3 flechas, 1,64% ref.<br>Candidato a caza: RANDOM, Ruby, Ocean, 2/3 flechas; seleccion y porcentaje variables por partida |
| 346 | Cradily | Evolucion de Lileep |
| 347 | Anorith | Caza: Gen 3, Zafiro, Ocean, 2 flechas, 1,96% ref.<br>Caza: Gen 3, Zafiro, Ocean, 3 flechas, 1,64% ref.<br>Candidato a caza: RANDOM, Zafiro, Ocean, 2/3 flechas; seleccion y porcentaje variables por partida |
| 348 | Armaldo | Evolucion de Anorith |
| 349 | Feebas | Caza: Gen 3, Zafiro, Lake, 2 flechas, 1,96% ref.<br>Caza: Gen 3, Zafiro, Lake, 3 flechas, 1,96% ref.<br>Candidato a caza: RANDOM, Zafiro, Lake, 2/3 flechas; seleccion y porcentaje variables por partida |
| 350 | Milotic | Evolucion de Feebas |
| 351 | Castform | Caza: Gen 3, Ambos, Plains, 2 flechas, 1,64% ref.<br>Caza: Gen 3, Ruby, Plains, 3 flechas, 1,96% ref.<br>Caza: Gen 3, Zafiro, Plains, 3 flechas, 1,41% ref.<br>Caza: Gen 3, Ruby, City, 3 flechas, 1,61% ref.<br>Candidato a caza: RANDOM, Ruby, City, 3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Ambos, Plains, 2/3 flechas; seleccion y porcentaje variables por partida |
| 352 | Kecleon | Caza: Gen 3, Ruby, Forest, 2 flechas, 1,64% ref.<br>Caza: Gen 3, Ambos, Forest, 3 flechas, 1,41% ref.<br>Caza: Gen 3, Zafiro, Forest, 2 flechas, 1,96% ref.<br>Caza: Gen 3, Ruby, City, 2 flechas, 1,41% ref.<br>Caza: Gen 3, Ruby, City, 3 flechas, 1,61% ref.<br>Candidato a caza: RANDOM, Ruby, City, 2/3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Ambos, Forest, 2/3 flechas; seleccion y porcentaje variables por partida |
| 353 | Shuppet | Huevo: Gen 1, Ambos, Cualquier zona, 4% ref.<br>Huevo: Gen 3, Ambos, Cualquier zona, 4% ref.<br>Huevo: RANDOM, Ambos, Cualquier zona, 1,33% ref. |
| 354 | Banette | Evolucion de Shuppet |
| 355 | Duskull | Caza: Gen 3, Ruby, Forest, 2 flechas, 16,39% ref.<br>Caza: Gen 3, Ambos, Forest, 3 flechas, 14,08% ref.<br>Caza: Gen 3, Zafiro, Forest, 2 flechas, 19,61% ref.<br>Caza: Gen 4, Zafiro, Cave, 3 flechas, 14,08% ref.<br>Caza: Gen 4, Ambos, Ruin, 2 flechas, 12,5% ref.<br>Caza: Gen 4, Ambos, Ruin, 3 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ambos, Forest, 2/3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Ambos, Ruin, 2/3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Zafiro, Cave, 3 flechas; seleccion y porcentaje variables por partida |
| 356 | Dusclops | Evolucion de Duskull |
| 357 | Tropius | Caza: Gen 3, Zafiro, Forest, 3 flechas, 14,08% ref.<br>Candidato a caza: RANDOM, Zafiro, Forest, 3 flechas; seleccion y porcentaje variables por partida |
| 358 | Chimecho | Huevo: Gen 1, Ambos, Cualquier zona, 4% ref.<br>Huevo: Gen 3, Ambos, Cualquier zona, 4% ref.<br>Huevo: RANDOM, Ambos, Cualquier zona, 1,33% ref.<br>Evolucion de Chingling |
| 359 | Absol | Caza: Gen 3, Zafiro, Wilderness, 2 flechas, 1,96% ref.<br>Caza: Gen 3, Zafiro, Wilderness, 3 flechas, 1,96% ref.<br>Caza: Gen 3, Zafiro, Ice Cave, 2 flechas, 1,92% ref.<br>Caza: Gen 3, Zafiro, Ice Cave, 3 flechas, 1,61% ref.<br>Candidato a caza: RANDOM, Zafiro, Ice Cave, 2/3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Zafiro, Wilderness, 2/3 flechas; seleccion y porcentaje variables por partida |
| 360 | Wynaut | Huevo: Gen 1, Ruby, Cualquier zona, 4% ref.<br>Huevo: Gen 3, Ruby, Cualquier zona, 4% ref.<br>Huevo: RANDOM, Ruby, Cualquier zona, 1,33% ref. |
| 361 | Snorunt | Caza: Gen 3, Zafiro, Ice Cave, 2 flechas, 19,23% ref.<br>Caza: Gen 3, Zafiro, Ice Cave, 3 flechas, 16,13% ref.<br>Candidato a caza: RANDOM, Zafiro, Ice Cave, 2/3 flechas; seleccion y porcentaje variables por partida<br>Huevo: Gen 1, Ambos, Cualquier zona, 4% ref.<br>Huevo: Gen 3, Ambos, Cualquier zona, 4% ref.<br>Huevo: Gen 4, Ambos, Cualquier zona, 4% ref.<br>Huevo: RANDOM, Ambos, Cualquier zona, 2,67% ref. |
| 362 | Glalie | Caza: Gen 3, Zafiro, Ice Cave, 3 flechas, 16,13% ref.<br>Candidato a caza: RANDOM, Zafiro, Ice Cave, 3 flechas; seleccion y porcentaje variables por partida<br>Evolucion de Snorunt (rama base; en Gen 4/RANDOM se prioriza si falta y se elige en Ruby si ambas estan capturadas) |
| 363 | Spheal | Caza: Gen 3, Zafiro, Ice Cave, 2 flechas, 19,23% ref.<br>Caza: Gen 3, Zafiro, Ice Cave, 3 flechas, 16,13% ref.<br>Candidato a caza: RANDOM, Zafiro, Ice Cave, 2/3 flechas; seleccion y porcentaje variables por partida<br>Huevo: Gen 1, Ambos, Cualquier zona, 4% ref.<br>Huevo: Gen 3, Ambos, Cualquier zona, 4% ref.<br>Huevo: RANDOM, Ambos, Cualquier zona, 1,33% ref. |
| 364 | Sealeo | Evolucion de Spheal |
| 365 | Walrein | Evolucion de Sealeo |
| 366 | Clamperl | Caza: Gen 3, Zafiro, Ocean, 3 flechas, 16,39% ref.<br>Candidato a caza: RANDOM, Zafiro, Ocean, 3 flechas; seleccion y porcentaje variables por partida |
| 367 | Huntail | Evolucion de Clamperl (Ruby) |
| 368 | Gorebyss | Evolucion de Clamperl (Zafiro) |
| 369 | Relicanth | Caza: Gen 3, Ambos, Ocean, 3 flechas, 16,39% ref.<br>Candidato a caza: RANDOM, Ambos, Ocean, 3 flechas; seleccion y porcentaje variables por partida |
| 370 | Luvdisc | Caza: Gen 3, Ambos, Ocean, 2 flechas, 19,61% ref.<br>Caza: Gen 3, Ambos, Ocean, 3 flechas, 16,39% ref.<br>Candidato a caza: RANDOM, Ambos, Ocean, 2/3 flechas; seleccion y porcentaje variables por partida |
| 371 | Bagon | Huevo: Gen 1, Ambos, Cualquier zona, 4% ref.<br>Huevo: Gen 3, Ambos, Cualquier zona, 4% ref.<br>Huevo: RANDOM, Ambos, Cualquier zona, 1,33% ref. |
| 372 | Shelgon | Caza: Gen 3, Ruby, Cave, 2 flechas, 16,39% ref.<br>Caza: Gen 3, Ruby, Cave, 3 flechas, 19,61% ref.<br>Caza: Gen 3, Zafiro, Cave, 2 flechas, 19,61% ref.<br>Caza: Gen 3, Zafiro, Cave, 3 flechas, 16,39% ref.<br>Candidato a caza: RANDOM, Ambos, Cave, 2/3 flechas; seleccion y porcentaje variables por partida<br>Evolucion de Bagon |
| 373 | Salamence | Evolucion de Shelgon |
| 374 | Beldum | Caza: Gen 3, Ambos, Ruin, 2 flechas, 33,33% ref.<br>Caza: Gen 3, Ambos, Ruin, 3 flechas, 25% ref.<br>Caza: Gen 3, Zafiro, Ice Cave, 2 flechas, 19,23% ref.<br>Caza: Gen 3, Zafiro, Ice Cave, 3 flechas, 16,13% ref.<br>Candidato a caza: RANDOM, Ambos, Ruin, 2/3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Zafiro, Ice Cave, 2/3 flechas; seleccion y porcentaje variables por partida |
| 375 | Metang | Evolucion de Beldum |
| 376 | Metagross | Evolucion de Metang |
| 377 | Regirock | Caza: Gen 3, Ambos, Ruin, 2 flechas, 33,33% ref.<br>Caza: Gen 3, Ambos, Ruin, 3 flechas, 25% ref. |
| 378 | Regice | Caza: Gen 3, Ambos, Ruin, 2 flechas, 33,33% ref.<br>Caza: Gen 3, Ambos, Ruin, 3 flechas, 25% ref. |
| 379 | Registeel | Caza: Gen 3, Ambos, Ruin, 3 flechas, 25% ref. |
| 387 | Turtwig | Caza: Gen 4, Ambos, Forest, 2 flechas, 12,5% ref.<br>Caza: Gen 4, Ambos, Forest, 3 flechas, 12,5% ref.<br>Caza: Gen 4, Zafiro, Plains, 3 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ambos, Forest, 2/3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Zafiro, Plains, 3 flechas; seleccion y porcentaje variables por partida |
| 388 | Grotle | Evolucion de Turtwig |
| 389 | Torterra | Evolucion de Grotle |
| 390 | Chimchar | Caza: Gen 4, Ruby, Plains, 3 flechas, 12,5% ref.<br>Caza: Gen 4, Ruby, Volcano, 2 flechas, 12,5% ref.<br>Caza: Gen 4, Ruby, Volcano, 3 flechas, 14,08% ref.<br>Caza: Gen 4, Zafiro, Wilderness, 2 flechas, 12,5% ref.<br>Caza: Gen 4, Zafiro, Wilderness, 3 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ruby, Plains, 3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Ruby, Volcano, 2/3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Zafiro, Wilderness, 2/3 flechas; seleccion y porcentaje variables por partida |
| 391 | Monferno | Evolucion de Chimchar |
| 392 | Infernape | Evolucion de Monferno |
| 393 | Piplup | Caza: Gen 4, Ambos, Ocean, 2 flechas, 12,5% ref.<br>Caza: Gen 4, Ambos, Ocean, 3 flechas, 25% ref.<br>Caza: Gen 4, Zafiro, Lake, 2 flechas, 12,5% ref.<br>Caza: Gen 4, Zafiro, Lake, 3 flechas, 12,5% ref.<br>Caza: Gen 4, Zafiro, Ice Cave, 2 flechas, 12,5% ref.<br>Caza: Gen 4, Zafiro, Ice Cave, 3 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ambos, Ocean, 2/3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Zafiro, Ice Cave, 2/3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Zafiro, Lake, 2/3 flechas; seleccion y porcentaje variables por partida |
| 394 | Prinplup | Evolucion de Piplup |
| 395 | Empoleon | Evolucion de Prinplup |
| 396 | Starly | Caza: Gen 4, Ambos, Plains, 2 flechas, 12,5% ref.<br>Caza: Gen 4, Ruby, City, 2 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ruby, City, 2 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Ambos, Plains, 2 flechas; seleccion y porcentaje variables por partida |
| 397 | Staravia | Evolucion de Starly |
| 398 | Staraptor | Evolucion de Staravia |
| 399 | Bidoof | Caza: Gen 4, Ambos, Plains, 2 flechas, 12,5% ref.<br>Caza: Gen 4, Ambos, Ocean, 2 flechas, 12,5% ref.<br>Caza: Gen 4, Ruby, Safari Zone, 2 flechas, 12,5% ref.<br>Caza: Gen 4, Zafiro, Lake, 2 flechas, 12,5% ref.<br>Caza: Gen 4, Zafiro, Lake, 3 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ambos, Ocean, 2 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Ambos, Plains, 2 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Ruby, Safari Zone, 2 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Zafiro, Lake, 2/3 flechas; seleccion y porcentaje variables por partida |
| 400 | Bibarel | Evolucion de Bidoof |
| 401 | Kricketot | Caza: Gen 4, Ambos, Forest, 2 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ambos, Forest, 2 flechas; seleccion y porcentaje variables por partida |
| 402 | Kricketune | Evolucion de Kricketot |
| 403 | Shinx | Caza: Gen 4, Ambos, Plains, 2 flechas, 12,5% ref.<br>Caza: Gen 4, Ambos, Plains, 3 flechas, 12,5% ref.<br>Caza: Gen 4, Zafiro, Wilderness, 2 flechas, 12,5% ref.<br>Caza: Gen 4, Zafiro, Wilderness, 3 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ambos, Plains, 2/3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Zafiro, Wilderness, 2/3 flechas; seleccion y porcentaje variables por partida |
| 404 | Luxio | Evolucion de Shinx |
| 405 | Luxray | Evolucion de Luxio |
| 406 | Budew | Huevo: Gen 4, Ambos, Cualquier zona, 12% ref.<br>Huevo: RANDOM, Ambos, Cualquier zona, 4% ref. |
| 407 | Roserade | Evolucion de Roselia |
| 408 | Cranidos | Caza: Gen 4, Ambos, Cave, 2 flechas, 14,08% ref.<br>Caza: Gen 4, Ambos, Cave, 3 flechas, 14,08% ref.<br>Caza: Gen 4, Ruby, Volcano, 2 flechas, 12,5% ref.<br>Caza: Gen 4, Ruby, Volcano, 3 flechas, 14,08% ref.<br>Caza: Gen 4, Ambos, Ruin, 2 flechas, 12,5% ref.<br>Caza: Gen 4, Ambos, Ruin, 3 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ambos, Cave, 2/3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Ambos, Ruin, 2/3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Ruby, Volcano, 2/3 flechas; seleccion y porcentaje variables por partida |
| 409 | Rampardos | Evolucion de Cranidos |
| 410 | Shieldon | Caza: Gen 4, Ambos, Cave, 2 flechas, 14,08% ref.<br>Caza: Gen 4, Ambos, Cave, 3 flechas, 14,08% ref.<br>Caza: Gen 4, Ambos, Ruin, 2 flechas, 12,5% ref.<br>Caza: Gen 4, Ambos, Ruin, 3 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ambos, Cave, 2/3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Ambos, Ruin, 2/3 flechas; seleccion y porcentaje variables por partida |
| 411 | Bastiodon | Evolucion de Shieldon |
| 412 | Burmy | Caza: Gen 4, Ambos, Forest, 2 flechas, 12,5% ref.<br>Caza: Gen 4, Ambos, Forest, 3 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ambos, Forest, 2/3 flechas; seleccion y porcentaje variables por partida |
| 413 | Wormadam | Evolucion de Burmy (rama base; en Gen 4/RANDOM se prioriza si falta y se elige en Ruby si ambas estan capturadas) |
| 414 | Mothim | Evolucion de Burmy (Gen 4/RANDOM: si falta y la otra rama ya esta capturada; si ambas estan capturadas, Zafiro) |
| 415 | Combee | Caza: Gen 4, Ambos, Forest, 2 flechas, 12,5% ref.<br>Caza: Gen 4, Ambos, Forest, 3 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ambos, Forest, 2/3 flechas; seleccion y porcentaje variables por partida |
| 416 | Vespiquen | Evolucion de Combee |
| 417 | Pachirisu | Caza: Gen 4, Ambos, Plains, 2 flechas, 12,5% ref.<br>Caza: Gen 4, Ambos, Plains, 3 flechas, 12,5% ref.<br>Caza: Gen 4, Zafiro, Wilderness, 2 flechas, 12,5% ref.<br>Caza: Gen 4, Zafiro, Wilderness, 3 flechas, 12,5% ref.<br>Caza: Gen 4, Ruby, City, 2 flechas, 12,5% ref.<br>Caza: Gen 4, Ruby, City, 3 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ruby, City, 2/3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Ambos, Plains, 2/3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Zafiro, Wilderness, 2/3 flechas; seleccion y porcentaje variables por partida |
| 418 | Buizel | Caza: Gen 4, Ambos, Ocean, 2 flechas, 12,5% ref.<br>Caza: Gen 4, Ambos, Ocean, 3 flechas, 25% ref.<br>Caza: Gen 4, Zafiro, Lake, 2 flechas, 12,5% ref.<br>Caza: Gen 4, Zafiro, Lake, 3 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ambos, Ocean, 2/3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Zafiro, Lake, 2/3 flechas; seleccion y porcentaje variables por partida |
| 419 | Floatzel | Evolucion de Buizel |
| 420 | Cherubi | Caza: Gen 4, Ambos, Forest, 2 flechas, 12,5% ref.<br>Caza: Gen 4, Ambos, Forest, 3 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ambos, Forest, 2/3 flechas; seleccion y porcentaje variables por partida |
| 421 | Cherrim | Evolucion de Cherubi |
| 422 | Shellos | Caza: Gen 4, Ambos, Ocean, 2 flechas, 25% ref.<br>Caza: Gen 4, Ambos, Ocean, 3 flechas, 12,5% ref.<br>Caza: Gen 4, Zafiro, Lake, 2 flechas, 12,5% ref.<br>Caza: Gen 4, Zafiro, Lake, 3 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ambos, Ocean, 2/3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Zafiro, Lake, 2/3 flechas; seleccion y porcentaje variables por partida |
| 423 | Gastrodon | Evolucion de Shellos |
| 424 | Ambipom | Evolucion de Aipom |
| 425 | Drifloon | Caza: Gen 4, Ambos, Ruin, 2 flechas, 12,5% ref.<br>Caza: Gen 4, Ambos, Ruin, 3 flechas, 12,5% ref.<br>Caza: Gen 4, Ruby, City, 2 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ruby, City, 2 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Ambos, Ruin, 2/3 flechas; seleccion y porcentaje variables por partida |
| 426 | Drifblim | Evolucion de Drifloon |
| 427 | Buneary | Caza: Gen 4, Ambos, Forest, 2 flechas, 12,5% ref.<br>Caza: Gen 4, Ambos, Forest, 3 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ambos, Forest, 2/3 flechas; seleccion y porcentaje variables por partida |
| 428 | Lopunny | Evolucion de Buneary |
| 429 | Mismagius | Evolucion de Misdreavus |
| 430 | Honchkrow | Evolucion de Murkrow |
| 431 | Glameow | Caza: Gen 4, Ambos, Plains, 2 flechas, 12,5% ref.<br>Caza: Gen 4, Ambos, Plains, 3 flechas, 12,5% ref.<br>Caza: Gen 4, Zafiro, Wilderness, 2 flechas, 12,5% ref.<br>Caza: Gen 4, Zafiro, Wilderness, 3 flechas, 12,5% ref.<br>Caza: Gen 4, Ruby, City, 2 flechas, 12,5% ref.<br>Caza: Gen 4, Ruby, City, 3 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ruby, City, 2/3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Ambos, Plains, 2/3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Zafiro, Wilderness, 2/3 flechas; seleccion y porcentaje variables por partida |
| 432 | Purugly | Evolucion de Glameow |
| 433 | Chingling | Huevo: Gen 4, Ambos, Cualquier zona, 8% ref.<br>Huevo: RANDOM, Ambos, Cualquier zona, 2,67% ref. |
| 434 | Stunky | Caza: Gen 4, Ambos, Plains, 2 flechas, 12,5% ref.<br>Caza: Gen 4, Ambos, Plains, 3 flechas, 12,5% ref.<br>Caza: Gen 4, Ruby, Volcano, 2 flechas, 12,5% ref.<br>Caza: Gen 4, Zafiro, Wilderness, 2 flechas, 12,5% ref.<br>Caza: Gen 4, Zafiro, Wilderness, 3 flechas, 12,5% ref.<br>Caza: Gen 4, Ruby, City, 2 flechas, 12,5% ref.<br>Caza: Gen 4, Ruby, City, 3 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ruby, City, 2/3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Ambos, Plains, 2/3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Ruby, Volcano, 2 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Zafiro, Wilderness, 2/3 flechas; seleccion y porcentaje variables por partida |
| 435 | Skuntank | Evolucion de Stunky |
| 436 | Bronzor | Caza: Gen 4, Ambos, Cave, 2 flechas, 14,08% ref.<br>Caza: Gen 4, Ambos, Cave, 3 flechas, 14,08% ref.<br>Caza: Gen 4, Ruby, Volcano, 2 flechas, 12,5% ref.<br>Caza: Gen 4, Ruby, Volcano, 3 flechas, 14,08% ref.<br>Caza: Gen 4, Ambos, Ruin, 2 flechas, 12,5% ref.<br>Caza: Gen 4, Ambos, Ruin, 3 flechas, 12,5% ref.<br>Caza: Gen 4, Zafiro, Ice Cave, 2 flechas, 12,5% ref.<br>Caza: Gen 4, Zafiro, Ice Cave, 3 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ambos, Cave, 2/3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Ambos, Ruin, 2/3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Ruby, Volcano, 2/3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Zafiro, Ice Cave, 2/3 flechas; seleccion y porcentaje variables por partida |
| 437 | Bronzong | Evolucion de Bronzor |
| 438 | Bonsly | Huevo: Gen 4, Ambos, Cualquier zona, 8% ref.<br>Huevo: RANDOM, Ambos, Cualquier zona, 2,67% ref. |
| 439 | Mime Jr. | Huevo: Gen 4, Ambos, Cualquier zona, 8% ref.<br>Huevo: RANDOM, Ambos, Cualquier zona, 2,67% ref. |
| 440 | Happiny | Huevo: Gen 4, Ambos, Cualquier zona, 8% ref.<br>Huevo: RANDOM, Ambos, Cualquier zona, 2,67% ref. |
| 441 | Chatot | Caza: Gen 4, Ambos, Plains, 3 flechas, 12,5% ref.<br>Caza: Gen 4, Ambos, Ocean, 2 flechas, 12,5% ref.<br>Caza: Gen 4, Ambos, Ocean, 3 flechas, 12,5% ref.<br>Caza: Gen 4, Ruby, Safari Zone, 3 flechas, 12,5% ref.<br>Caza: Gen 4, Zafiro, Wilderness, 3 flechas, 12,5% ref.<br>Caza: Gen 4, Ruby, City, 3 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ruby, City, 3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Ambos, Ocean, 2/3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Ambos, Plains, 3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Ruby, Safari Zone, 3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Zafiro, Wilderness, 3 flechas; seleccion y porcentaje variables por partida |
| 442 | Spiritomb | Caza: Gen 4, Ambos, Ruin, 2 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ambos, Ruin, 2 flechas; seleccion y porcentaje variables por partida |
| 443 | Gible | Caza: Gen 4, Ambos, Cave, 2 flechas, 14,08% ref.<br>Caza: Gen 4, Ambos, Cave, 3 flechas, 14,08% ref.<br>Caza: Gen 4, Ruby, Volcano, 2 flechas, 12,5% ref.<br>Caza: Gen 4, Ruby, Volcano, 3 flechas, 14,08% ref.<br>Caza: Gen 4, Zafiro, Ice Cave, 2 flechas, 12,5% ref.<br>Caza: Gen 4, Zafiro, Ice Cave, 3 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ambos, Cave, 2/3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Ruby, Volcano, 2/3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Zafiro, Ice Cave, 2/3 flechas; seleccion y porcentaje variables por partida |
| 444 | Gabite | Evolucion de Gible |
| 445 | Garchomp | Evolucion de Gabite |
| 446 | Munchlax | Huevo: Gen 4, Ambos, Cualquier zona, 8% ref.<br>Huevo: RANDOM, Ambos, Cualquier zona, 2,67% ref. |
| 447 | Riolu | Huevo: Gen 4, Ambos, Cualquier zona, 12% ref.<br>Huevo: RANDOM, Ambos, Cualquier zona, 4% ref. |
| 448 | Lucario | Evolucion de Riolu |
| 449 | Hippopotas | Caza: Gen 4, Ruby, Safari Zone, 2 flechas, 12,5% ref.<br>Caza: Gen 4, Ruby, Safari Zone, 3 flechas, 12,5% ref.<br>Caza: Gen 4, Ruby, Volcano, 2 flechas, 12,5% ref.<br>Caza: Gen 4, Ruby, Volcano, 3 flechas, 14,08% ref.<br>Caza: Gen 4, Zafiro, Wilderness, 2 flechas, 12,5% ref.<br>Caza: Gen 4, Zafiro, Wilderness, 3 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ruby, Safari Zone, 2/3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Ruby, Volcano, 2/3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Zafiro, Wilderness, 2/3 flechas; seleccion y porcentaje variables por partida |
| 450 | Hippowdon | Evolucion de Hippopotas |
| 451 | Skorupi | Caza: Gen 4, Ruby, Safari Zone, 2 flechas, 12,5% ref.<br>Caza: Gen 4, Ruby, Safari Zone, 3 flechas, 12,5% ref.<br>Caza: Gen 4, Zafiro, Wilderness, 2 flechas, 12,5% ref.<br>Caza: Gen 4, Zafiro, Wilderness, 3 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ruby, Safari Zone, 2/3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Zafiro, Wilderness, 2/3 flechas; seleccion y porcentaje variables por partida |
| 452 | Drapion | Evolucion de Skorupi |
| 453 | Croagunk | Caza: Gen 4, Ruby, Safari Zone, 2 flechas, 12,5% ref.<br>Caza: Gen 4, Ruby, Safari Zone, 3 flechas, 12,5% ref.<br>Caza: Gen 4, Zafiro, Lake, 2 flechas, 12,5% ref.<br>Caza: Gen 4, Zafiro, Lake, 3 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ruby, Safari Zone, 2/3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Zafiro, Lake, 2/3 flechas; seleccion y porcentaje variables por partida |
| 454 | Toxicroak | Evolucion de Croagunk |
| 455 | Carnivine | Caza: Gen 4, Ruby, Safari Zone, 2 flechas, 12,5% ref.<br>Caza: Gen 4, Ruby, Safari Zone, 3 flechas, 12,5% ref.<br>Caza: Gen 4, Zafiro, Lake, 2 flechas, 12,5% ref.<br>Caza: Gen 4, Zafiro, Lake, 3 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ruby, Safari Zone, 2/3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Zafiro, Lake, 2/3 flechas; seleccion y porcentaje variables por partida |
| 456 | Finneon | Caza: Gen 4, Ambos, Ocean, 2 flechas, 25% ref.<br>Caza: Gen 4, Ambos, Ocean, 3 flechas, 25% ref.<br>Caza: Gen 4, Zafiro, Lake, 2 flechas, 12,5% ref.<br>Caza: Gen 4, Zafiro, Lake, 3 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ambos, Ocean, 2/3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Zafiro, Lake, 2/3 flechas; seleccion y porcentaje variables por partida |
| 457 | Lumineon | Evolucion de Finneon |
| 458 | Mantyke | Huevo: Gen 4, Ambos, Cualquier zona, 12% ref.<br>Huevo: RANDOM, Ambos, Cualquier zona, 4% ref. |
| 459 | Snover | Caza: Gen 4, Ruby, Cave, 3 flechas, 14,08% ref.<br>Caza: Gen 4, Zafiro, Ice Cave, 2 flechas, 12,5% ref.<br>Caza: Gen 4, Zafiro, Ice Cave, 3 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ruby, Cave, 3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Zafiro, Ice Cave, 2/3 flechas; seleccion y porcentaje variables por partida |
| 460 | Abomasnow | Evolucion de Snover |
| 461 | Weavile | Evolucion de Sneasel |
| 462 | Magnezone | Evolucion de Magneton |
| 463 | Lickilicky | Evolucion de Lickitung |
| 464 | Rhyperior | Evolucion de Rhydon |
| 465 | Tangrowth | Evolucion de Tangela |
| 466 | Electivire | Evolucion de Electabuzz |
| 467 | Magmortar | Evolucion de Magmar |
| 468 | Togekiss | Evolucion de Togetic |
| 469 | Yanmega | Evolucion de Yanma |
| 470 | Leafeon | Evolucion de Eevee (Gen 4 o RANDOM, Forest de ambos tableros) |
| 471 | Glaceon | Evolucion de Eevee (Gen 4 o RANDOM, Ice Cave de Zafiro o Cave de Ruby) |
| 472 | Gliscor | Evolucion de Gligar |
| 473 | Mamoswine | Evolucion de Piloswine |
| 474 | Porygon-Z | Evolucion de Porygon2 |
| 475 | Gallade | Evolucion de Kirlia (Gen 4/RANDOM: si falta y la otra rama ya esta capturada; si ambas estan capturadas, Zafiro) |
| 476 | Probopass | Evolucion de Nosepass |
| 477 | Dusknoir | Evolucion de Dusclops |
| 478 | Froslass | Evolucion de Snorunt (Gen 4/RANDOM: si falta y la otra rama ya esta capturada; si ambas estan capturadas, Zafiro) |
| 479 | Rotom | Caza: Gen 4, Ambos, Ruin, 3 flechas, 12,5% ref.<br>Caza: Gen 4, Ruby, City, 3 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ruby, City, 3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Ambos, Ruin, 3 flechas; seleccion y porcentaje variables por partida |
| 522 | Blitzle | **Sin ruta natural detectada** |
| 523 | Zebstrika | Evolucion de Blitzle<br>**Cadena sin origen natural detectado** |
| 610 | Axew | **Sin ruta natural detectada** |
| 698 | Amaura | **Sin ruta natural detectada** |
| 722 | Rowlet | **Sin ruta natural detectada** |
| 840 | Applin | **Sin ruta natural detectada** |
| 909 | Fuecoco | **Sin ruta natural detectada** |

## Encuentros especiales

Los requisitos de Pokedex exigen CAPTURADO, no solo VISTO. Las capturas de partida incluyen evoluciones.
Los legendarios del selector nuevo se capturan una vez por partida; fallar un intento no consume su oportunidad. Rayquaza, los bonus originales y Manaphy conservan sus eventos propios.
En RANDOM se eligen dos grupos errantes y dos especiales compatibles con el tablero. Solo los elegidos pueden salir por este selector; Manaphy y los bonus son independientes.
Si las probabilidades de legendarios elegibles superan el 100%, el 100% se reparte por igual entre las especies elegibles. En otro caso se mantienen los porcentajes indicados.

| No. | Pokemon | Como se consigue |
| --- | --- | --- |
| 142 | Aerodactyl | Ademas de las rutas ordinarias indicadas debajo, puede obtenerse con la carta e-Reader de invitados especiales fuera de Gen 4. Tambien participa en el grupo de invitados heredado si ya tiene un flag en la Pokedex: grupo al 1% (2% con mejora), desde 100 especies registradas como capturadas en gBoardConfig y 5 capturas/evoluciones en partida. Se priorizan invitados pendientes; el porcentaje no es individual. forceSpecialMons puede forzar el grupo.<br>Otras rutas detectadas: Caza: Gen 1, Ambos, Ruin, 2 flechas, 20% ref.<br>Caza: Gen 1, Ambos, Ruin, 3 flechas, 14,29% ref.<br>Candidato a caza: RANDOM, Ambos, Ruin, 2/3 flechas; seleccion y porcentaje variables por partida |
| 144 | Articuno | Gen 1, Zafiro: cualquier zona, 5% compartido entre las aves disponibles. En Ice Cave, desde 10 capturas/evoluciones en partida: 20% para este Pokemon y 5% compartido entre las otras aves. |
| 145 | Zapdos | Gen 1, Zafiro: cualquier zona, 5% compartido entre las aves disponibles. En Plains, desde 10 capturas/evoluciones en partida: 20% para este Pokemon y 5% compartido entre las otras aves. |
| 146 | Moltres | Gen 1, Zafiro: cualquier zona, 5% compartido entre las aves disponibles. En Wilderness, desde 10 capturas/evoluciones en partida: 20% para este Pokemon y 5% compartido entre las otras aves. |
| 150 | Mewtwo | Gen 1, ambos tableros, cualquier zona: Articuno, Zapdos y Moltres capturados en la Pokedex y al menos 20 capturas/evoluciones en la partida. 25%. |
| 151 | Mew | Gen 1, ambos tableros, cualquier zona: tener capturados en la Pokedex los Pokemon nacionales 001-150 y llevar al menos 15 capturas/evoluciones en la partida. 25%. |
| 152 | Chikorita | Ademas de las rutas ordinarias indicadas debajo, puede obtenerse con la carta e-Reader de invitados especiales fuera de Gen 4. Tambien participa en el grupo de invitados heredado si ya tiene un flag en la Pokedex: grupo al 1% (2% con mejora), desde 100 especies registradas como capturadas en gBoardConfig y 5 capturas/evoluciones en partida. Se priorizan invitados pendientes; el porcentaje no es individual. forceSpecialMons puede forzar el grupo.<br>Otras rutas detectadas: Caza: Gen 2, Ambos, Forest, 2 flechas, 12,5% ref.<br>Caza: Gen 2, Ambos, Forest, 3 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ambos, Forest, 2/3 flechas; seleccion y porcentaje variables por partida |
| 155 | Cyndaquil | Ademas de las rutas ordinarias indicadas debajo, puede obtenerse con la carta e-Reader de invitados especiales fuera de Gen 4. Tambien participa en el grupo de invitados heredado si ya tiene un flag en la Pokedex: grupo al 1% (2% con mejora), desde 100 especies registradas como capturadas en gBoardConfig y 5 capturas/evoluciones en partida. Se priorizan invitados pendientes; el porcentaje no es individual. forceSpecialMons puede forzar el grupo.<br>Otras rutas detectadas: Caza: Gen 2, Ambos, Plains, 2 flechas, 12,5% ref.<br>Caza: Gen 2, Ruby, Volcano, 2 flechas, 20% ref.<br>Caza: Gen 2, Ruby, Volcano, 3 flechas, 19,61% ref.<br>Candidato a caza: RANDOM, Ambos, Plains, 2 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Ruby, Volcano, 2/3 flechas; seleccion y porcentaje variables por partida |
| 158 | Totodile | Ademas de las rutas ordinarias indicadas debajo, puede obtenerse con la carta e-Reader de invitados especiales fuera de Gen 4. Tambien participa en el grupo de invitados heredado si ya tiene un flag en la Pokedex: grupo al 1% (2% con mejora), desde 100 especies registradas como capturadas en gBoardConfig y 5 capturas/evoluciones en partida. Se priorizan invitados pendientes; el porcentaje no es individual. forceSpecialMons puede forzar el grupo.<br>Otras rutas detectadas: Caza: Gen 2, Ambos, Ocean, 2 flechas, 14,29% ref.<br>Caza: Gen 2, Ambos, Ocean, 3 flechas, 12,5% ref.<br>Caza: Gen 2, Zafiro, Lake, 2 flechas, 14,29% ref.<br>Caza: Gen 2, Zafiro, Lake, 3 flechas, 14,29% ref.<br>Candidato a caza: RANDOM, Ambos, Ocean, 2/3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Zafiro, Lake, 2/3 flechas; seleccion y porcentaje variables por partida |
| 172 | Pichu | Huevo especial heredado, ambos tableros, fuera de Gen 4: al menos 5 capturas/evoluciones y no ser el ultimo huevo. El codigo actual usa 2% sin mejora e-Reader y 1% con ella; forcePichuEgg puede forzarlo. Sus rutas ordinarias, si las hay, se muestran debajo.<br>Otras rutas detectadas: Caza: Gen 2, Zafiro, Lake, 2 flechas, 14,29% ref.<br>Caza: Gen 2, Ruby, City, 3 flechas, 12,5% ref.<br>Candidato a caza: RANDOM, Ruby, City, 3 flechas; seleccion y porcentaje variables por partida<br>Candidato a caza: RANDOM, Zafiro, Lake, 2 flechas; seleccion y porcentaje variables por partida |
| 243 | Raikou | Gen 2, Ruby: cualquier zona, 5% compartido entre las bestias disponibles. En Safari Zone, desde 10 capturas/evoluciones en partida: 20% para este Pokemon y 5% compartido entre las otras bestias. |
| 244 | Entei | Gen 2, Ruby: cualquier zona, 5% compartido entre las bestias disponibles. En Volcano, desde 10 capturas/evoluciones en partida: 20% para este Pokemon y 5% compartido entre las otras bestias. |
| 245 | Suicune | Gen 2, Ruby: cualquier zona, 5% compartido entre las bestias disponibles. En Ocean, desde 10 capturas/evoluciones en partida: 20% para este Pokemon y 5% compartido entre las otras bestias. |
| 249 | Lugia | Gen 2, Zafiro, cualquier zona: Suicune, Raikou y Entei capturados en la Pokedex y al menos 20 capturas/evoluciones en la partida. 25%. |
| 250 | Ho-Oh | Gen 2, Ruby, cualquier zona: Suicune, Raikou y Entei capturados en la Pokedex y al menos 20 capturas/evoluciones en la partida. 25%. |
| 251 | Celebi | Gen 2, ambos tableros, Forest: al menos 15 capturas/evoluciones en la partida. 25%. |
| 380 | Latias | Zafiro, fuera de Gen 4: aparece en la seleccion heredada de invitados, con al menos 100 especies capturadas registradas en gBoardConfig y 5 capturas/evoluciones en partida. El grupo se activa al 1% (2% con mejora e-Reader), luego prioriza invitados pendientes o sortea entre candidatos. No es un 1% individual garantizado; forceSpecialMons omite esos requisitos. |
| 381 | Latios | Ruby, fuera de Gen 4: aparece en la seleccion heredada de invitados, con al menos 100 especies capturadas registradas en gBoardConfig y 5 capturas/evoluciones en partida. El grupo se activa al 1% (2% con mejora e-Reader), luego prioriza invitados pendientes o sortea entre candidatos. No es un 1% individual garantizado; forceSpecialMons omite esos requisitos. |
| 382 | Kyogre | Bonus de Kyogre, Zafiro. La fase de captura se activa al superarlo cuando numCompletedBonusStages % 5 == 3 (segunda visita a Kyogre del ciclo). No usa una probabilidad de caza normal. |
| 383 | Groudon | Bonus de Groudon, Ruby. La fase de captura se activa al superarlo cuando numCompletedBonusStages % 5 == 3 (segunda visita a Groudon del ciclo). No usa una probabilidad de caza normal. |
| 384 | Rayquaza | Bonus de Rayquaza, accesible desde ambos tableros. La fase de captura se activa al superar el bonus cuando numCompletedBonusStages % 10 == 9 (segunda visita a Rayquaza del ciclo). No usa una probabilidad de caza normal. |
| 385 | Jirachi | **Pendiente de completar:** Existe el premio PRIZE_JIRACHI_CATCH_MODE del agujero central, que activa el modo Jirachi. Falta detallar en esta guia la disponibilidad y el peso del premio en la ruleta. |
| 386 | Deoxys | Gen 3, ambos tableros, Ruin: haber capturado a Rayquaza en esta partida. 20%. |
| 480 | Uxie | Gen 4, Zafiro, Lake: al menos 10 capturas/evoluciones. 20% compartido entre Uxie y Azelf; al capturar uno, el otro conserva el 20%. |
| 481 | Mesprit | Gen 4, ambos tableros: 5% en cualquier zona, aumentado al 20% en Lake. Sin minimo de capturas. |
| 482 | Azelf | Gen 4, Zafiro, Lake: al menos 10 capturas/evoluciones. 20% compartido entre Uxie y Azelf; al capturar uno, el otro conserva el 20%. |
| 483 | Dialga | Gen 4, Zafiro, cualquier zona: Uxie, Azelf y Mesprit capturados en la Pokedex y al menos 20 capturas/evoluciones en la partida. 25%. |
| 484 | Palkia | Gen 4, Ruby, cualquier zona: Uxie, Azelf y Mesprit capturados en la Pokedex y al menos 20 capturas/evoluciones en la partida. 25%. |
| 485 | Heatran | Gen 4, Ruby, Volcano: al menos 15 capturas/evoluciones en la partida. 25%. |
| 486 | Regigigas | Gen 4, ambos tableros, Ruin: Regirock, Regice y Registeel capturados en la Pokedex. 25%, sin minimo de capturas en partida. |
| 487 | Giratina | Gen 4, ambos tableros, cualquier zona: Dialga y Palkia capturados en la Pokedex y al menos 20 capturas/evoluciones en la partida. 25%. |
| 488 | Cresselia | Gen 4, ambos tableros, cualquier zona: 5%, sin minimo de capturas. |
| 489 | Phione | Gen 4, ambos tableros, Ocean: haber capturado a Manaphy en esta partida. 25%. |
| 490 | Manaphy | Gen 4 o RANDOM, ambos tableros: capturar cinco Pokemon de huevo en cualquier bioma. El siguiente huevo entregado en Ocean sera el huevo especial de Manaphy desde que aparece. Al iniciar ese intento se consume el contador; si se pierde, hay que capturar cinco huevos de nuevo. No entra en el sorteo ordinario. |
| 491 | Darkrai | Gen 4, ambos tableros, cualquier zona: haber capturado a Cresselia en esta partida y llevar al menos 15 capturas/evoluciones. 25%. |
| 492 | Shaymin | Gen 4, ambos tableros, Forest: al menos 15 capturas/evoluciones en la partida. 25%. |
| 493 | Arceus | Gen 4, ambos tableros, cualquier zona: Dialga, Palkia y Giratina capturados en la Pokedex y al menos 30 capturas/evoluciones en la partida. 25%. |

## Pendientes detectados

- 522 - Blitzle: sin origen natural en las fuentes revisadas.
- 523 - Zebstrika: sin origen natural en las fuentes revisadas.
- 610 - Axew: sin origen natural en las fuentes revisadas.
- 698 - Amaura: sin origen natural en las fuentes revisadas.
- 722 - Rowlet: sin origen natural en las fuentes revisadas.
- 840 - Applin: sin origen natural en las fuentes revisadas.
- 909 - Fuecoco: sin origen natural en las fuentes revisadas.

## Regenerar

```bash
python3 tools/scripts/generate_encounter_guide.py
```

Comprobar que la lista esta al dia, sin modificar archivos:

```bash
python3 tools/scripts/generate_encounter_guide.py --check
```

Fuentes: `data/mon_locations.inc`, `src/data/egg_locations.h`, `src/data/species.h`,
`data/graphics/mon_portraits.inc`, `src/main_board_catch_hatch_picker.c` y el JSON manual.
