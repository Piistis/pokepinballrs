# Compatibilidad de partidas guardadas

## Reglas al insertar Pokemon

- Los IDs de `include/constants/species.h` son persistentes. Anadir al final,
  antes de `SPECIES_NONE`; nunca renumerar, reciclar ni ordenar por numero nacional.
- Mantener `NUM_SAVE_SPECIES = 205` y el layout original de `SaveData`.
- Registrar nuevos IDs publicados en `docs/save_schema_v1.json`, sin eliminar
  ni cambiar los existentes. El orden visible de la Pokedex va en su propia tabla.
- `make` ejecuta `check-save-schema`: bloquea cambios a IDs existentes y a las
  estructuras persistidas. No actualizar sus hashes para silenciar un fallo:
  un cambio de layout requiere otro formato, lector antiguo y pruebas de migracion.
- No escribir SRAM directamente desde nuevas funciones. Usar las APIs de
  `save.c` / `save_storage.c`. Revisar tambien el limite de especies de otras tablas.

## Formato versionado (version 1)

SRAM de 32 KiB. Todos los offsets son relativos a `0x0E000000`.

| Bloque | Copia A | Copia B | Espacio por copia |
| --- | --- | --- | --- |
| SaveData original (sin cambios) | 0x0004 | 0x02A4 | 0x274 bytes de datos |
| Flags extra de Pokedex | 0x2000 | 0x3000 | 0x1000 bytes |
| Partida suspendida | 0x4000 | 0x6000 | 0x2000 bytes |

Cada bloque nuevo tiene cabecera de 16 bytes: magic, version, longitud,
secuencia y CRC32 de cabecera/datos. Se escribe primero la copia no seleccionada,
se verifica y se confirma su magic al final; despues se actualiza la otra.
Al cargar se elige la copia valida mas reciente. Una escritura interrumpida
conserva una copia completa anterior o nueva, si habia alguna valida.
No es una transaccion conjunta entre SaveData, Pokedex extra y partida suspendida.

La Pokedex guarda su longitud; al crecer se conservan los flags anteriores y
se inicializan los nuevos como no vistos. Capacidad reservada: 2048 flags extra
(2253 especies totales). Superarla requiere otro esquema, no solo otra constante.

La partida suspendida conserva el layout de PinballGame (0x1424 bytes) y anade
8 bytes de metadatos: cantidad de especies, ID de musica, indices de bola/camara
y generacion seleccionada. Los tres punteros del bloque antiguo se ignoran y
reconstruyen con las direcciones de la build actual. El antiguo SPECIES_NONE se
traduce al actual; tambien se limpian las selecciones forzadas del debug.
Borrar/consumir una partida crea un registro vacio con CRC y secuencia nuevos,
para no recuperar accidentalmente una copia anterior al continuar.

## Migracion de builds anteriores

- Se mantienen intactos los bloques antiguos durante la migracion de Pokedex:
  0x1A00 / 0x1B00. En saves de 500 especies se solapaban; se usa el respaldo
  cuando la copia principal no pasa su checksum.
- Se aceptan los prefijos estables desde 388 especies y el prototipo de una/dos
  especies extra (Blitzle/Zebstrika), con traduccion de sus IDs antiguos.
- Hay dos formatos indistinguibles de 387 especies: el ID 205 fue Blitzle y
  despues Deoxys. Si tiene progreso, por defecto se bloquean escrituras.
  Solo con la build de origen identificada se configura `LEGACY_387_LAYOUT`
  en `include/save_storage.h`: 1 para Blitzle, 2 para Deoxys.
- Las partidas suspendidas antiguas sin cabecera solo se intentan recuperar
  cuando la Pokedex identifica un prefijo estable de 388 o mas especies.
  No tienen CRC; se comprueban campos basicos. La musica se reconstruye con la
  pista del tablero, porque el puntero antiguo no identifica una cancion estable.
- Una version futura/desconocida, datos irrecuperables o un guardado ambiguo
  activa `gMain.sramError`: no se sobrescribe SRAM. El juego no tiene aun un
  aviso especifico de migracion; no continuar jugando esperando nuevos guardados
  en ese caso. Conservar el archivo para diagnosticarlo.
- Si ambas copias de SaveData fallan y SRAM no esta vacia, no se reinicializa el
  archivo automaticamente. Esto protege datos recuperables de borrados accidentales.

No se promete compatibilidad con cualquier build historica ni volver a ROMs
antiguas: estas no conocen el formato nuevo. Tampoco con savestates del emulador,
que contienen RAM y direcciones de codigo. Actualizar usando el guardado normal
`.sav`, cerrar el emulador y conservar una copia previa. Las tablas RANDOM fuera
de PinballGame no se serializan; esta migracion no cambia esa limitacion previa.

## Pruebas

```sh
python3 tools/scripts/test_save_compatibility.py --schema-only
python3 tools/scripts/test_save_compatibility.py
```

La segunda compila el codigo real de save.c/save_storage.c contra SRAM simulada
de 32 KiB y un fixture con los offsets ARM. Requiere MSVC x86 en Windows o un
compilador C con soporte de 32 bits (`gcc-multilib` en Linux).
Prueba 500 y 520 especies, recuperacion de respaldo, todas las interrupciones
de escritura del bloque Dex, interrupciones de snapshot, limites, versiones
futuras, punteros reconstruidos, contadores, sentinel y borrado.

Para la muestra legacy de 500 especies y sin partida suspendida aportada durante
esta tarea, se puede anadir `--save ../pokepinballrs.sav`. Solo se lee; se comprueba
su hash al terminar. Ese archivo personal NO se incluye en Git.

Estas pruebas de host no sustituyen compilar con agbcc y probar en emulador:
guardar/continuar en ambos tableros, conservar puntos, vidas, contador, generacion,
equipo y Pokedex, y repetir tras actualizar a una build con especies nuevas.
