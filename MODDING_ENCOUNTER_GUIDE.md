# Generador de la lista de encuentros

## Archivos

- `docs/ENCUENTROS.md`: lista legible, ordenada por numero nacional, separada
  en encuentros normales y especiales.
- `docs/encounters_generated.csv`: los mismos datos con una fila por ruta,
  separador `;`, listo para filtrar por Pokemon, generacion, tablero o zona.
- `docs/encounters_special.json`: archivo MANUAL. Contiene requisitos de eventos
  especiales y excepciones a las evoluciones lineales.
- `tools/scripts/generate_encounter_guide.py`: generador, solo biblioteca
  estandar de Python 3.10 o superior. No requiere ROM, compilador ARM ni internet.

El antiguo `docs/encounter_rates_by_board_area.csv` no se modifica.

## Uso

```bash
python3 tools/scripts/generate_encounter_guide.py
```

Tambien se puede usar `make encounters` en Codespaces. No hace falta compilar el
juego para actualizar la lista. El build normal de la ROM no cambia.

Antes de subir cambios:

```bash
python3 tools/scripts/generate_encounter_guide.py
python3 tools/scripts/test_encounter_guide.py
python3 tools/scripts/test_evolution_reachability.py
python3 tools/scripts/generate_encounter_guide.py --check
```

`--check` no escribe archivos y devuelve un error si falta regenerar. Se deben
incluir ambos archivos generados en el mismo commit que cambia las tablas.

La auditoria de rutas compila en el equipo las funciones C reales de caza,
huevo, seleccion de evolucion y registro de captura (requiere GCC/Clang o MSVC).
Comprueba las especies normales de la beta por generacion y tablero, usando
solo las zonas de la ruleta de ese tablero, sin transferir el equipo a otro.
Parte de una Pokedex vacia por contexto y explora las ramas al ir registrandolas.
La union debe cubrir todas las especies normales; no obliga a que los exclusivos
aparezcan en ambos tableros. Para Gen 4 se exige ademas cobertura en cada tablero.
Los eventos legendarios se comprueban por separado con
`test_legendary_encounters.py` y `test_manaphy_egg.py`; esta auditoria no sustituye
la comprobacion de la ROM en emulador.

Regresiones cubiertas: Clamperl en Ocean/Ruby/Gen 3 con tres flechas para Huntail;
Poliwag en Ocean/Ruby/Gen 1 con tres flechas para Poliwrath. Gorebyss sigue
requiriendo Sapphire. Tentacool conserva su encuentro de dos flechas en Ocean
de Ruby. Las pruebas retiran los dos encuentros nuevos solo en memoria y
verifican que ambos bloqueos vuelven a detectarse.

## Automatizacion de GitHub

El workflow **Lista de encuentros** se ejecuta al subir cambios relevantes,
en pull requests y manualmente desde Actions. Genera la lista, ejecuta pruebas
y publica el artefacto `lista-encuentros` con el Markdown y el CSV actualizados.
Despues comprueba que esos resultados coinciden con los versionados en el repo.

Si estan desactualizados, la comprobacion falla para recordar que hay que
regenerarlos y subirlos. No hace commits automaticos ni tiene permisos de
escritura en el repositorio. Si falla la validacion de las reglas, no publica
como actualizada una lista antigua. Los workflows deben estar habilitados en
GitHub para que esta parte se ejecute.

## Mantenimiento de especiales

Anadir una entrada a `specials`, usando la constante real de especie:

```json
{
  "species": "SPECIES_MEW",
  "description": "Gen 1, ambos tableros: Pokedex nacional 001-150 capturada y al menos 15 capturas/evoluciones en partida. 25%."
}
```

Si ya existe, editar su descripcion en lugar de duplicarla. `pending: true`
marca detalles pendientes de catalogar en una ruta conocida. Las rutas normales
detectadas para un Pokemon especial se conservan debajo de su descripcion.

Las evoluciones lineales se leen de `src/data/species.h`. Las ramas que dependen
del tablero, bioma o Pokedex se mantienen en `evolution_overrides`; cada entrada
indica `target` y `condition`. El generador verifica que todos los padres con
ramas en el selector esten cubiertos y que todas las especies existan.

`reviewed_functions` y `reviewed_blocks` guardan huellas SHA256 de las reglas
revisadas. Si cambia el selector o una probabilidad especial, la generacion se
detiene y muestra la nueva huella. Primero revisar el codigo y actualizar las
descripciones/modelo de porcentajes que corresponda; SOLO despues actualizar
la huella en el JSON. No actualizar huellas automaticamente para silenciar el aviso.
Los cambios en filas de encuentros, datos base y nuevos retratos se extraen
automaticamente sin alterar los textos manuales.

## Significado de las cifras

Los porcentajes normales son de referencia DENTRO de la tabla normal, no una
probabilidad absoluta para cualquier estado de partida. Se calculan con todos
los candidatos y sus evoluciones sin registrar, al menos una captura/evolucion,
sin excluir el ultimo encuentro y sin mejoras e-Reader. Una especie rara tiene
el peso que aplica el codigo, no necesariamente el mismo peso que una comun.

La Pokedex, el ultimo Pokemon, la primera captura, las mejoras y los encuentros
especiales modifican las probabilidades reales. En RANDOM se listan candidatos
a entrar en la tabla de la partida; no se inventa un porcentaje fijo para ellos.
Los huevos RANDOM si tienen una tabla combinada que permite calcular una cifra
de referencia, conservando las repeticiones de las tablas fuente.

## Limites del inventario

- Es un inventario del codigo actual, no una garantia de que cada sprite/grito
  ya este conectado ni una simulacion completa del juego.
- Los nombres/numeros se obtienen de especies y retratos; los IDs internos no
  se confunden con los numeros de la Pokedex Nacional.
- Se conservan los comportamientos heredados, incluso mezclas de generaciones
  en los huevos de Gen 1/3. Documentar no modifica el juego.
- Las especies sin origen natural en las tablas/eventos revisados se marcan.
  Las evoluciones de una especie sin origen tambien se marcan. DEBUG no cuenta.
- Los detalles aun pendientes de los eventos heredados aparecen expresamente
  como pendientes, no como requisitos inventados.
