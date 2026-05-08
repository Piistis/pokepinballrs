# Guia para anadir una zona nueva

Esta guia documenta como anadir una zona nueva al modo Travel / ruleta de
areas sin romper las zonas originales. El caso usado como ejemplo es
`AREA_TEST`, con el retrato `test_area.png` y encuentros pensados para probar
Pokemon nuevos rapidamente.

## Estado actual

- El juego original tiene 14 areas (`AREA_COUNT = 14`).
- Ruby y Sapphire tienen cada uno una tabla de areas para la ruleta.
- Las zonas Ruin son especiales: normalmente dependen de e-Reader y no deben
  mezclarse con la logica normal de areas.
- Los retratos originales de zona se mantienen desde `baserom.gba`.
- Las zonas nuevas se anaden al final, como graficos y paletas propios.

Punto importante: no reemplaces los retratos originales por PNGs extraidos si se
ven como ruido. Esos PNGs no son una fuente limpia. Lo seguro es dejar el bloque
original desde `baserom.gba` y concatenar solamente las zonas nuevas.

## Checklist rapido

Para anadir una zona nueva hay que tocar, como minimo:

1. `include/constants/areas.h`
2. `data/rom_1.s`
3. `data/mon_locations.inc`
4. `graphics/area_portraits/area_portraits_gfx.json`
5. `graphics/area_portraits/nueva_zona.png`
6. Compilar y probar en ROM

Si tambien quieres aumentar la cantidad de slots de la ruleta, toca ademas:

1. `src/travel_mode.c`
2. `src/launcher_and_cutscenes.c`

## 1. Preparar la imagen de zona

Carpeta:

```text
graphics/area_portraits
```

La imagen debe ser:

- PNG indexado.
- Tamano exacto `48x32`.
- Maximo 16 colores.
- Sin alpha/transparencia rara.
- Fondo como color real.
- Nombre en minusculas y snake_case.

Ejemplo:

```text
graphics/area_portraits/test_area.png
```

Si la PNG esta bien indexada, `make` puede generar automaticamente:

```text
graphics/area_portraits/test_area.4bpp
graphics/area_portraits/test_area.gbapal
```

No hace falta subir esos dos archivos generados si estan ignorados por Git.

## 2. Registrar la imagen en el JSON

Archivo:

```json
graphics/area_portraits/area_portraits_gfx.json
```

Anade la imagen nueva en `files`:

```json
{
  "gfx_filename": "test_area"
}
```

El nombre no lleva extension. Si el archivo es:

```text
test_area.png
```

entonces el `gfx_filename` es:

```text
test_area
```

## 3. Crear la constante del area

Archivo:

```c
include/constants/areas.h
```

Las areas nuevas deben ir al final, sin cambiar los ids de las originales.

Ejemplo:

```c
#define AREA_RUIN_RUBY         12
#define AREA_RUIN_SAPPHIRE     13
#define AREA_TEST              14
#define AREA_COUNT              15
```

Si anades otra area despues:

```c
#define AREA_TEST              14
#define AREA_NEW_FOREST        15
#define AREA_COUNT              16
```

Reglas:

- No cambies los numeros de las areas existentes.
- `AREA_COUNT` debe ser el numero total de areas reales.
- Cada nueva area necesita entradas de encuentros y un indice de retrato.

## 4. Anadir el indice de retrato

Archivo:

```asm
data/rom_1.s
```

Buscar:

```asm
gAreaPortraitIndexes::
```

Ejemplo:

```asm
gAreaPortraitIndexes:: @ 0x08137928
	.2byte 0, 1, 2, 3, 4
	.2byte 5, 6, 7, 8, 9
	.2byte 10, 11, 12, 12
	.2byte 13
```

Interpretacion:

- Las areas originales usan retratos `0` a `12`.
- Ruby Ruin y Sapphire Ruin comparten el retrato `12`.
- `AREA_TEST` usa el retrato `13`.

La cantidad de valores de `gAreaPortraitIndexes` debe coincidir con
`AREA_COUNT`.

## 5. Anadir la paleta de la zona nueva

Archivo:

```asm
data/rom_1.s
```

Buscar:

```asm
gPortraitGenericPalettes::
```

La forma segura es mantener las paletas originales desde `baserom.gba` y meter
la nueva despues:

```asm
gPortraitGenericPalettes:: @ 0x081C00E4
	.incbin "baserom.gba", 0x1C00E4, 0x1A0
	.incbin "graphics/area_portraits/test_area.gbapal"
	.incbin "baserom.gba", 0x1C02A4, 0x40
```

Por que esos numeros:

- `0x1A0` son 13 paletas originales de `0x20` bytes cada una.
- `test_area.gbapal` es la paleta nueva.
- `0x40` conserva dos paletas originales sobrantes para no mover
  `gPortraitAnimPalettes`.

Si anades mas zonas nuevas, se insertan despues de `test_area.gbapal`:

```asm
	.incbin "baserom.gba", 0x1C00E4, 0x1A0
	.incbin "graphics/area_portraits/test_area.gbapal"
	.incbin "graphics/area_portraits/new_area.gbapal"
	.incbin "baserom.gba", 0x1C02C4, 0x20
```

Ojo: si usas los dos huecos sobrantes originales, el offset y el tamano del
ultimo `.incbin` deben ajustarse. Cuando haya dudas, es mejor revisar el mapa de
memoria antes de compilar.

## 6. Anadir los graficos de la zona nueva

Archivo:

```asm
data/rom_1.s
```

Buscar:

```asm
gPortraitGenericGraphics::
```

La forma segura:

```asm
gPortraitGenericGraphics:: @ 0x0848D68C
	.incbin "baserom.gba", 0x48D68C, 0x2700
	.incbin "graphics/area_portraits/test_area.4bpp"
```

Por que `0x2700`:

- Cada retrato ocupa `0x300` bytes.
- Hay 13 retratos originales.
- `13 * 0x300 = 0x2700`.

Si anades otra zona:

```asm
	.incbin "baserom.gba", 0x48D68C, 0x2700
	.incbin "graphics/area_portraits/test_area.4bpp"
	.incbin "graphics/area_portraits/new_area.4bpp"
```

## 7. Anadir encuentros salvajes

Archivo:

```asm
data/mon_locations.inc
```

Cada area necesita dos bloques:

- Two arrows.
- Three arrows.

Cada bloque tiene exactamente 8 entradas.

Ejemplo para una zona de pruebas con solo Blitzle:

```asm
	@ Test Area | Ruby | Two arrows
	.2byte SPECIES_TEST_EXTRA
	.2byte SPECIES_TEST_EXTRA
	.2byte SPECIES_TEST_EXTRA
	.2byte SPECIES_TEST_EXTRA
	.2byte SPECIES_TEST_EXTRA
	.2byte SPECIES_TEST_EXTRA
	.2byte SPECIES_TEST_EXTRA
	.2byte SPECIES_TEST_EXTRA

	@ Test Area | Ruby | Three arrows
	.2byte SPECIES_TEST_EXTRA
	.2byte SPECIES_TEST_EXTRA
	.2byte SPECIES_TEST_EXTRA
	.2byte SPECIES_TEST_EXTRA
	.2byte SPECIES_TEST_EXTRA
	.2byte SPECIES_TEST_EXTRA
	.2byte SPECIES_TEST_EXTRA
	.2byte SPECIES_TEST_EXTRA
```

Regla de oro:

```text
AREA_COUNT * 2 * 8 = total de entradas .2byte SPECIES_
```

Ejemplo con `AREA_COUNT = 15`:

```text
15 * 2 * 8 = 240
```

Si el numero no cuadra, el juego puede leer especies de otra zona o basura.

## 8. Meter la zona en la ruleta

Archivo:

```asm
data/rom_1.s
```

Buscar:

```asm
gAreaRouletteTable::
```

Con la ampliacion actual, cada tablero tiene:

- 7 slots normales.
- 1 slot especial para Ruins.

Ejemplo Ruby:

```asm
gAreaRouletteTable:: @ 0x08055A68
	.2byte AREA_FOREST_RUBY
	.2byte AREA_VOLCANO
	.2byte AREA_PLAINS_RUBY
	.2byte AREA_OCEAN_RUBY
	.2byte AREA_SAFARI_ZONE
	.2byte AREA_CAVE_RUBY
	.2byte AREA_TEST
	.2byte AREA_RUIN_RUBY
```

Ejemplo Sapphire:

```asm
	.2byte AREA_FOREST_SAPPHIRE
	.2byte AREA_LAKE
	.2byte AREA_PLAINS_SAPPHIRE
	.2byte AREA_WILDERNESS
	.2byte AREA_OCEAN_SAPPHIRE
	.2byte AREA_CAVE_SAPPHIRE
	.2byte AREA_TEST
	.2byte AREA_RUIN_SAPPHIRE
```

Si solo quieres que la zona salga en Ruby, no la pongas en la fila de Sapphire.

## 9. Ajustar el tamano de la ruleta

Archivo:

```c
include/constants/areas.h
```

Constantes actuales:

```c
#define AREA_ROULETTE_SLOT_COUNT       7
#define AREA_ROULETTE_RUIN_SLOT        7
#define AREA_ROULETTE_TOTAL_SLOT_COUNT 8
```

Significado:

- `AREA_ROULETTE_SLOT_COUNT`: slots normales.
- `AREA_ROULETTE_RUIN_SLOT`: indice del slot especial Ruin.
- `AREA_ROULETTE_TOTAL_SLOT_COUNT`: total de columnas por tablero.

Si quieres 8 slots normales mas Ruin:

```c
#define AREA_ROULETTE_SLOT_COUNT       8
#define AREA_ROULETTE_RUIN_SLOT        8
#define AREA_ROULETTE_TOTAL_SLOT_COUNT 9
```

Entonces `gAreaRouletteTable` debe tener 9 entradas por tablero.

## 10. Actualizar codigo que usa el tamano de la ruleta

Archivos:

```c
src/travel_mode.c
src/launcher_and_cutscenes.c
```

Los `extern` deben usar el total de slots:

```c
extern const s16 gAreaRouletteTable[][AREA_ROULETTE_TOTAL_SLOT_COUNT];
```

Y los calculos de ruleta deben usar constantes, no numeros magicos:

```c
% AREA_ROULETTE_SLOT_COUNT
AREA_ROULETTE_RUIN_SLOT
AREA_ROULETTE_TOTAL_SLOT_COUNT
```

Evita dejar valores antiguos como:

```c
% 6
% 7
areaRouletteSlotIndex == 6
areaVisitCount < 5
```

Si esos valores quedan en el flujo de ruleta, es facil que la zona nueva no
aparezca o que Ruins se active en mal momento.

## 11. Cuidado con la logica de Ruins

Archivo revisado:

```c
src/center_capture_hole.c
```

No uses una condicion generica como:

```c
area > AREA_WILDERNESS
```

Eso rompe las zonas nuevas, porque normalmente se anaden despues de las
originales.

Usa una comprobacion explicita:

```c
area == AREA_RUIN_RUBY || area == AREA_RUIN_SAPPHIRE
```

## 12. Checks antes de compilar

Comprueba:

- `AREA_COUNT` coincide con el total de areas.
- `gAreaPortraitIndexes` tiene una entrada por area.
- `data/mon_locations.inc` tiene `AREA_COUNT * 2 * 8` especies.
- `gAreaRouletteTable` tiene `AREA_ROULETTE_TOTAL_SLOT_COUNT` entradas por
  tablero.
- La PNG nueva es `48x32`, indexada y con maximo 16 colores.
- Los retratos originales siguen viniendo desde `baserom.gba`.

## 13. Comandos en tu PC / GitHub

Para subir solo la documentacion:

```bash
git status
git add MODDING_ADD_AREA.md
git commit -m "Document adding new areas"
git push
```

Para subir tambien una zona nueva real:

```bash
git status
git add include/constants/areas.h data/rom_1.s data/mon_locations.inc src/travel_mode.c src/launcher_and_cutscenes.c src/center_capture_hole.c graphics/area_portraits/area_portraits_gfx.json graphics/area_portraits/nueva_zona.png
git commit -m "Add new area"
git push
```

No subas carpetas temporales como:

```text
_tmp_area_probe/
```

## 14. Comandos en Codespaces

Despues de subir cambios desde tu PC:

```bash
git pull
make clean
make -j"$(nproc)"
```

Si compila, prueba la ROM en emulador.

## Resumen corto

Para una zona nueva normal:

1. Preparas `48x32` PNG indexada a 16 colores.
2. La pones en `graphics/area_portraits`.
3. La registras en `area_portraits_gfx.json`.
4. Creas una constante `AREA_*`.
5. Subes `AREA_COUNT`.
6. Anades un indice en `gAreaPortraitIndexes`.
7. Concatenas `.gbapal` y `.4bpp` despues de los originales.
8. Anades dos bloques de encuentros en `mon_locations.inc`.
9. La metes en `gAreaRouletteTable`.
10. Compilas y pruebas.

La idea segura es: originales desde `baserom.gba`, zonas nuevas como PNGs
limpias anadidas al final.
