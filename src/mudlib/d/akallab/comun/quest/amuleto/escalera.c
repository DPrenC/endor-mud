/*
DESCRIPCION  : escalera para el quest del amuleto perdido
FICHERO      : /d/akallab/comun/quest/amuleto/escalera.c
MODIFICACION : 26-10-99 [Angor@Simauria] Creacion.
--------------------------------------------------------------------------------
*/

inherit THING;
#include "path.h"
#include AK_MACRO
#include <properties.h>

create() {
  ::create();
  AddId("escalera");
  AddId("escalera de madera");
  AddId("amu_quest_00");
  AddAdjective("vieja");
  AddAdjective("de madera");
  SetShort("una vieja escalera de madera");
  SetLong("Es una vieja y alargada escalera de madera que sin duda conocio "
  "mejores tiempos. Algunos de los peldanyos de madera no estan en muy buen "
  "estado.\n");
  SetWeight(5000);
  SetValue(0);
}
