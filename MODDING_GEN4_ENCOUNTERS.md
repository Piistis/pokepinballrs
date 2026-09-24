# Encuentros normales y huevos de cuarta generacion

## Distribucion

`data/mon_locations.inc`, tabla `gWildMonLocationsGen4`, contiene 16 zonas con
dos filas de ocho entradas (dos y tres flechas). No ampliar las filas sin
revisar el codigo consumidor. Los legendarios se sortean aparte segun
`MODDING_LEGENDARY_ENCOUNTERS.md` y no ocupan estas casillas.

Hay 30 especies de captura propias de cuarta generacion y 14 preevoluciones
anteriores necesarias para obtener todas sus evoluciones. Cada tablero permite
obtener todos los Pokemon no legendarios de cuarta generacion, combinando
capturas, huevos y evoluciones; no todos aparecen directamente en modo caza.

Resumen por bioma (las dos filas pueden ofrecer especies distintas):

| Bioma | Especies principales |
| --- | --- |
| Forest, ambos | Turtwig, Burmy, Combee, Cherubi, Buneary, Kricketot, Aipom, Tangela, Eevee |
| Plains, ambos | Starly, Bidoof, Shinx, Pachirisu, Glameow, Stunky, Lickitung, Yanma, Chatot, Eevee |
| Ocean, ambos | Piplup, Buizel, Shellos, Finneon, Bidoof, Chatot |
| Cave, ambos | Gible, Bronzor, Cranidos, Shieldon, Gligar, Nosepass, Magnemite, Rhyhorn, Sneasel |
| Safari Zone, Ruby | Hippopotas, Skorupi, Croagunk, Carnivine, Yanma, Tangela, Lickitung, Bidoof, Chatot |
| Volcano, Ruby | Chimchar, Cranidos, Rhyhorn, Hippopotas, Gligar, Stunky, Bronzor, Gible, Nosepass |
| Lake, Sapphire | Buizel, Bidoof, Piplup, Croagunk, Yanma, Shellos, Finneon, Carnivine |
| Wilderness, Sapphire | Chimchar, Hippopotas, Skorupi, Stunky, Glameow, Lickitung, Shinx, Pachirisu, Chatot |
| Ruin, ambos | Bronzor, Cranidos, Shieldon, Drifloon, Duskull, Misdreavus, Murkrow, Spiritomb, Rotom |
| City, Ruby | Glameow, Stunky, Pachirisu, Magnemite, Porygon, Eevee, Starly, Drifloon, Rotom, Chatot |
| Ice Cave, Sapphire | Snover, Sneasel, Piplup, Gible, Bronzor, Eevee, Magnemite, Porygon |

Snover tambien aparece en Cave Ruby con tres flechas. Chimchar aparece en Plains
Ruby con tres flechas y Turtwig en Plains Sapphire. Las casillas repetidas son
pesos, no plazas reservadas para Pokemon pendientes.

## Huevos

Los graficos de los huevos de cuarta generacion ya estaban registrados, pero
faltaba la tabla de encuentros. `src/data/egg_locations.h` ahora contiene
`gEggLocationsGen4` para ambos tableros:

- Propios de Gen 4: Budew, Bonsly, Chingling, Happiny, Mime Jr., Munchlax,
  Riolu y Mantyke.
- Preevoluciones anteriores: Elekid, Magby, Togepi, Swinub, Ralts y Snorunt.
- Manaphy permanece EXCLUSIVAMENTE en su evento de huevo especial. No incluirlo
  en la tabla ordinaria. Phione tampoco es un huevo ordinario.

Se mantienen 25 entradas ponderadas por tablero, mas una entrada final sin uso.
En RANDOM se recorren las 75 entradas de las tablas original, Gen 2 y Gen 4,
sin ampliar `PinballGame.speciesWeights[25]` ni desplazar el guardado. Se conserva
la ponderacion por Pokedex, las evoluciones pendientes y la exclusion del ultimo
huevo. Las repeticiones entre tablas tambien aportan peso.

El evento antiguo de Pichu y los invitados especiales antiguos de captura no
sustituyen encuentros en partidas de cuarta generacion. El debug explicito y
el huevo especial de Manaphy siguen teniendo prioridad.

## Evoluciones

Los enlaces lineales entre generaciones ya estaban en `src/data/species.h`.
Se han completado estas ramas del selector para Gen 4 y RANDOM:

- Burmy: Wormadam o Mothim.
- Kirlia: Gardevoir o Gallade.
- Snorunt: Glalie o Froslass.

Como otras ramas del mod, se prioriza la evolucion que falta por capturar en
la Pokedex. Si ambas estan capturadas, Ruby elige la primera y Sapphire la
segunda. No hay comprobacion de sexo en este sistema.

Eevee evoluciona a Leafeon en Forest de ambos tableros y a Glaceon en Ice Cave
Sapphire o Cave Ruby. En las demas zonas conserva las rutas anteriores.

## Graficos y limites

Se conectan 23 sprites normales nuevos, de Cranidos a Rotom, con indices de
captura 193 a 215. Sus PNG originales, paletas, manifiesto, grupos de graficos
y animaciones de Pokedex deben mantenerse sincronizados. Este bloque no
registra los PNG pendientes de los legendarios.

Los indices de captura ya superan 199: el antiguo umbral de animacion de huevo
200 dejaria de distinguirlos. `HATCH_DEX_ANIM_OFFSET` se comparte entre C y
ensamblador desde `include/constants/global.h`, con valor 512. Todas las
referencias de huevo de `gDexAnimationIx` usan esa constante mas su `eggIndex`.
No cambiar solo el umbral o solo una parte de la tabla.

`catchIndex` sigue siendo u8: los valores de captura deben mantenerse por debajo
de 256. El umbral de Pokedex NO amplia ese campo. Los grupos de captura contienen
cinco especies; los de huevo, seis. No reordenar indices antiguos al anadir PNG.
Los PNG de captura son indexados, 144x48 (tres frames), con indices 0 a 15.

## Validacion

```bash
python tools/scripts/test_gen4_encounters.py
python tools/scripts/test_legendary_encounters.py
python tools/scripts/test_manaphy_egg.py
make -j$(nproc)
```

Las pruebas de host verifican rutas de obtencion de todos los no legendarios de
Gen 4 en ambos tableros, dimensiones de tablas, paletas PNG, indices de graficos,
ausencia de legendarios en tablas normales, todos los indices de huevo de la
Pokedex, sorteos C de captura/huevo, pools iniciales no vacios y ramas de evolucion.

La compilacion ARM y la comprobacion en emulador siguen siendo necesarias:
probar capturas en ambos tableros, huevos normales, Manaphy, SELECT en la Pokedex
para Buizel/Rotom y un huevo antiguo, y guardar/reanudar una partida RANDOM.
