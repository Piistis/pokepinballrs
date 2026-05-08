# Guia para anadir una especie nueva

Esta rama ya tiene una primera especie extra funcionando: `SPECIES_TEST_EXTRA`,
usada como Blitzle. La idea de esta guia es dejar una receta repetible para
anadir mas Pokemon sin romper la ROM ni el guardado.

## Estado actual

- El juego original guarda flags de Pokedex para 205 especies.
- La rama mantiene ese tamano de guardado con `NUM_SAVE_SPECIES`.
- Las especies nuevas viven por encima de `NUM_SAVE_SPECIES` y usan flags extra
  en RAM para pruebas.
- Blitzle usa el indice interno `SPECIES_TEST_EXTRA`, que actualmente vale `205`.
- `SPECIES_NONE` vale `206`, asi que `NUM_SPECIES` tambien es `206`.

El punto importante: no subas el tamano de `pokedexFlags` dentro de `SaveData`
si no quieres cambiar el layout del save y arriesgar corrupciones/crashes.

## Checklist rapido

Para anadir una especie nueva hay que tocar, como minimo:

1. `include/constants/species.h`
2. `src/data/species.h`
3. `data/pokedex_entries/dex.inc`
4. `data/mon_locations.inc`
5. Graficos de retrato en `graphics/mon_portraits`
6. Graficos de captura en `graphics/mon_catch_sprites`
7. Includes de graficos/paletas en `data/graphics`
8. Tablas de animacion de Pokedex en `data/rom_2.s`
9. Compilar y probar en ROM

## 1. Crear la constante de especie

Archivo:

```c
include/constants/species.h
```

Ejemplo actual:

```c
#define SPECIES_AERODACTYL      204
#define SPECIES_TEST_EXTRA      205
#define SPECIES_NONE            206

#define BONUS_SPECIES_START SPECIES_CHIKORITA
#define NUM_BONUS_SPECIES (SPECIES_TEST_EXTRA - SPECIES_CHIKORITA)
#define NUM_SPECIES SPECIES_NONE
#define NUM_SAVE_SPECIES 205
```

Para anadir otra especie despues de Blitzle, el patron seria:

```c
#define SPECIES_AERODACTYL      204
#define SPECIES_BLITZLE         205
#define SPECIES_NUEVO_MON       206
#define SPECIES_NONE            207

#define NUM_SPECIES SPECIES_NONE
#define NUM_SAVE_SPECIES 205
```

Notas:

- `NUM_SAVE_SPECIES` debe quedarse en `205`.
- `SPECIES_NONE` debe estar siempre justo despues de la ultima especie real.
- Conviene renombrar `SPECIES_TEST_EXTRA` a `SPECIES_BLITZLE` cuando el prototipo
  ya deje de ser temporal.

## 2. Anadir datos base de especie

Archivo:

```c
src/data/species.h
```

Cada especie necesita una entrada:

```c
[SPECIES_TEST_EXTRA] = {
    .speciesIdRS = 310,
    .nameJapanese = {0},
    .name = "BLITZLE   ",
    .catchIndex = 84,
    .eggIndex = 0,
    .specialEggFlag = 0,
    .evolutionMethod = 0,
    .evolutionTarget = SPECIES_NONE
},
```

Campos importantes:

- `.name`: nombre mostrado por el juego. Debe respetar el ancho usado por el
  resto de entradas; normalmente se rellena con espacios.
- `.speciesIdRS`: se usa para datos relacionados con especies de Ruby/Sapphire,
  como gritos. Si no existe la especie en Gen 3, hay que reutilizar un grito
  existente o ampliar tambien el sistema de cries.
- `.catchIndex`: indice del sprite de captura. Blitzle usa `84` porque queda
  despues de Aerodactyl en el grupo de sprites de captura.
- `.evolutionTarget`: si no evoluciona dentro de este mod, usa `SPECIES_NONE`.

## 3. Anadir entrada de Pokedex

Archivo:

```asm
data/pokedex_entries/dex.inc
```

Cada entrada debe tener:

- Coordenadas/formato inicial con `.2byte`
- `.dexName`
- `.dexCategory`
- Exactamente 6 lineas `.dexText`

Ejemplo:

```asm
dexEntry206::
    .2byte 2, 0, 6, 0xA, 0, 0, 8, 0xA, 2, 9, 8, 0
    .dexName "BLITZLE"
    .dexCategory "ELECTRIC"
    .dexText "BLITZLE stores electricity in the"
    .dexText "white stripes on its body."
    .dexText "When startled, it releases sparks"
    .dexText "that flash like lightning."
    .dexText ""
    .dexText ""
```

Avisos:

- Usa texto ASCII. Evita acentos, simbolos raros y caracteres copiados de
  editores modernos.
- No dejes entradas con menos de 6 `.dexText`; eso descoloca los datos de las
  especies siguientes.
- El numero de la etiqueta `dexEntry206` es el numero mostrado en Pokedex, no
  necesariamente el indice interno C.

## 4. Colocar la especie en encuentros

Archivo:

```asm
data/mon_locations.inc
```

Cada zona tiene listas de 8 entradas. Para Petalburg Forest en Ruby:

```asm
    @ Forest | Ruby | Two arrows
    .2byte SPECIES_TEST_EXTRA
    .2byte SPECIES_TEST_EXTRA
    .2byte SPECIES_SILCOON
    .2byte SPECIES_CASCOON
    .2byte SPECIES_DUSKULL
    .2byte SPECIES_KECLEON
    .2byte SPECIES_TEST_EXTRA
    .2byte SPECIES_NONE
```

Cuantas mas veces repitas una especie en la lista, mas probable sera que salga.

Detalle importante: algunas especies originales tienen bloqueos o reglas
especiales antes de llegar al encuentro. Si una especie no aparece aunque este
en la tabla, revisa `src/catch_hatch_picker.c`.

## 5. Preparar el retrato

Carpeta:

```text
graphics/mon_portraits
```

Anade el PNG:

```text
graphics/mon_portraits/blitzle_portrait.png
```

Luego registra el grafico en:

```json
graphics/mon_portraits/mon_portraits_gfx.json
```

Ejemplo:

```json
{
  "gfx_filename": "blitzle_portrait",
  "palette": "blitzle_portrait.gbapal"
}
```

Y anade los includes:

```asm
data/graphics/mon_portraits.inc
data/graphics/mon_portraits_pals.inc
```

Ejemplo:

```asm
.incbin "graphics/mon_portraits/blitzle_portrait.4bpp"
```

```asm
.incbin "graphics/mon_portraits/blitzle_portrait.gbapal"
```

El orden importa: la posicion del retrato debe coincidir con el indice de la
especie en la tabla.

## 6. Preparar el sprite de captura

Carpeta:

```text
graphics/mon_catch_sprites
```

Anade el PNG:

```text
graphics/mon_catch_sprites/catch_mon_85_blitzle.png
```

Luego registra el grafico en:

```json
graphics/mon_catch_sprites/catch_sprites_gfx.json
```

Ejemplo:

```json
{
  "gfx_filename": "catch_mon_85_blitzle",
  "palette": "catch_mon_85_blitzle.gbapal"
}
```

Y anade los includes:

```asm
data/graphics/mon_catch_sprites.inc
data/graphics/mon_catch_sprites_pals.inc
```

Ejemplo actual:

```asm
gMonCatchSpriteGroup16_Gfx::
    .incbin "graphics/mon_catch_sprites/catch_mon_81_chikorita.4bpp"
    .incbin "graphics/mon_catch_sprites/catch_mon_82_cyndaquil.4bpp"
    .incbin "graphics/mon_catch_sprites/catch_mon_83_totodile.4bpp"
    .incbin "graphics/mon_catch_sprites/catch_mon_84_aerodactyl.4bpp"
    .incbin "graphics/mon_catch_sprites/catch_mon_85_blitzle.4bpp"
```

## 7. Conectar la animacion de Pokedex

Archivo:

```asm
data/rom_2.s
```

Hay dos tablas importantes:

```asm
gDexAnimationIx
gPokedexCatchAnimIndices
```

Para que `Select` en la Pokedex muestre el sprite correcto, la especie nueva
necesita una entrada en esas tablas.

Blitzle usa una entrada nueva al final:

```asm
gDexAnimationIx:
    ...
    .2byte  84

gPokedexCatchAnimIndices:
    ...
    .2byte 0
```

Si al crecer estas tablas la ROM crashea, el plan conservador es no crecerlas y
meter un caso especial en `src/pokedex.c` para devolver los indices de la especie
nueva. De momento Blitzle funciona con tabla extendida.

## 8. No romper el guardado

Archivos relacionados:

```c
include/main.h
include/variables.h
src/save.c
src/pokedex.c
src/catch_hatch_picker.c
src/high_scores.c
src/pinball_game_main.c
```

Regla general:

- Los arrays persistentes del save deben usar `NUM_SAVE_SPECIES`.
- Los arrays temporales en RAM que representan la Pokedex completa pueden usar
  `NUM_SPECIES`.
- Las especies extra deben guardarse aparte o tratarse como flags temporales
  mientras no se disene una ampliacion real del save.

Esta rama usa:

```c
#define NUM_SAVE_SPECIES 205
```

Y `gExtraPokedexFlags` para los flags extra durante la partida.

## 9. Compilar en Codespaces

Despues de subir cambios:

```bash
git fetch origin
git reset --hard origin/species-count-audit
make clean
make -j"$(nproc)"
```

Si se cambia solo C/ASM y quieres una prueba rapida:

```bash
make NODEP=1 -j"$(nproc)"
```

Para cambios de graficos, usa `make clean` al menos la primera vez, porque los
PNG generan `.4bpp` y `.gbapal`.

## 10. Pruebas recomendadas en emulador

Prueba esto antes de dar una especie por buena:

1. La ROM arranca sin crash.
2. La pantalla de titulo y menus no tienen graficos corruptos.
3. La especie aparece en la zona elegida.
4. El retrato previo al encuentro es correcto.
5. El sprite durante la captura es correcto.
6. El grito no crashea y suena como esperas.
7. Al capturarla, la Pokedex la marca como capturada.
8. En la Pokedex se muestra el numero correcto.
9. En la Pokedex se muestran nombre, categoria, altura, peso y texto correctos.
10. Al pulsar `Select` en la Pokedex, sale el sprite de captura correcto.
11. Electrike/Aerodactyl y las especies cercanas siguen viendose bien.

## Orden seguro para nuevas especies

Para reducir errores, conviene hacerlo en fases:

1. Anadir constante y datos base, pero usar graficos/cry de una especie existente.
2. Compilar y comprobar que no crashea.
3. Anadir encuentro con mucha probabilidad.
4. Confirmar que aparece y se captura.
5. Anadir entrada de Pokedex.
6. Confirmar que numero/texto no se descuadran.
7. Anadir retrato propio.
8. Anadir sprite de captura propio.
9. Probar `Select` en Pokedex.
10. Solo entonces pasar a otra especie.

## Problemas conocidos y soluciones

### `unknown character U+...`

El archivo tiene un caracter no ASCII, normalmente una tilde, comilla tipografica
o simbolo copiado desde fuera.

Solucion: reemplazarlo por texto ASCII.

### `syntax error at end of input` en `dex.inc`

Alguna entrada de Pokedex tiene formato incompleto, normalmente menos lineas
`.dexText` de las esperadas.

Solucion: asegurarse de que cada entrada tiene exactamente 6 `.dexText`.

### Crash `Jumped to invalid address`

Suele pasar por datos desplazados, tablas fuera de rango, save layout cambiado o
lecturas fuera de los arrays originales.

Solucion:

- Volver al ultimo commit estable.
- Probar con una sola modificacion cada vez.
- Revisar si se ha cambiado `SaveData`.
- Revisar si `NUM_SPECIES`, `SPECIES_NONE` y las tablas de graficos coinciden.

### La especie aparece como `No.000`

La entrada de Pokedex esta desalineada o falta una entrada/linea anterior.

Solucion: revisar `data/pokedex_entries/dex.inc`, sobre todo las entradas justo
antes de la nueva.

### El encuentro no aparece

Puede haber reglas en `src/catch_hatch_picker.c` que filtran especies ya vistas,
evoluciones, secretos o especies sin evolucion.

Solucion: revisar los pesos y los filtros antes de culpar a
`data/mon_locations.inc`.

