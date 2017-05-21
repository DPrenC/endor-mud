/*
DESCRIPCION  : cubo de madera para el quest del amuleto perdido
FICHERO      : /d/akallab/comun/quest/amuleto/cubo.c
MODIFICACION : 26-10-99 [Angor@Simauria] Creacion.
--------------------------------------------------------------------------------
*/

inherit THING;
#include "path.h"
#include AK_MACRO
#include <properties.h>

create() {
  ::create();
  AddId("cubo");
  AddId("cubo de madera");
  AddId("amu_quest_03");
  AddAdjective("pequenyo");
  AddAdjective("de madera");
  SetShort("un pequenyo cubo de madera");
  SetLong("Es un pequenyo cubo de madera. No esta en muy buen estado, pero "
  "aun puede utilizarse.\n");
  SetWeight(1500);
  SetValue(0);
}
