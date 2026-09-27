# Build de pruebas de la beta

La configuracion por defecto expone las generaciones 1-4 y RANDOM, sin debug.

- `include/constants/debug.h`: `DEBUG_TOOLS_ENABLED FALSE` desactiva los menus
  SELECT / L+R, los atajos de autocompletar la Pokedex y su funcion de escritura.
  El sound test del titulo sigue desactivado. START conserva la pausa normal.
- `include/constants/content.h`: `POST_GEN4_SPECIES_ENABLED FALSE` oculta de la
  Pokedex a Blitzle, Zebstrika, Axew, Amaura, Rowlet, Applin y Fuecoco.
  La lista y los totales visibles abarcan 493 especies, hasta Arceus.
- Esas siete especies no tienen rutas naturales desde los encuentros normales,
  huevos, especiales ni RANDOM. Sus tablas, assets, IDs y flags de guardado
  permanecen reservados para reactivarlas mas adelante, sin renumerar nada.
- No se borran capturas anteriores ni se reinicia una partida suspendida al
  actualizar. Una partida antigua de debug puede conservar Pokemon obtenidos
  con trucos; para comprobar la disponibilidad natural, comenzar una partida nueva.
- Las generaciones 5-10 siguen visibles pero bloqueadas, como antes.

Para reactivar herramientas de desarrollo, cambiar el primer interruptor a TRUE.
Para volver a mostrar las siete especies, cambiar el segundo a TRUE; anadirlas
a encuentros cuando toque insertar sus generaciones. No modificar NUM_SPECIES
ni el registro de IDs persistentes para ocultar contenido.

## Compilar en Codespaces

```bash
cd /workspaces/pokepinballrs
git pull --rebase origin species-count-audit
make -j$(nproc)
```

## Comprobaciones antes de distribuir

```bash
python3 tools/scripts/test_beta_build.py
python3 tools/scripts/test_save_compatibility.py
python3 tools/scripts/test_gen4_encounters.py
python3 tools/scripts/test_legendary_encounters.py
python3 tools/scripts/test_manaphy_egg.py
```

Probar la ROM en emulador: titulo/Pokedex con L+R, partida con SELECT y L+R
(sin menu debug), pausa/continuar/guardar con START, fin de lista en Arceus,
capturas/huevos/evoluciones en ambos tableros y guardar/continuar tras reiniciar.
Usar tambien un .sav vacio para testear progreso real sin autocompletado previo.
Las pruebas de host no sustituyen compilar con agbcc ni jugar en emulador.
