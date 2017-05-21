/*
DESCRIPCION  : vial de vida
FICHERO      : /d/akallab/comun/quest/bruja/vial.c
MODIFICACION : 20-10-01 [Maler] Creacion.
--------------------------------------------------------------------------------
*/

inherit THING;
#include "path.h"
#include <properties.h>

create() {
  ::create();
  AddId("vial");
  AddId("quest_vial_gardil");
  SetShort("un vial de vida");
  SetLong("Es un vial de vida, quiza lo necesites para algo.\n");
  Set(P_NOGIVE);
  Set(P_NOSELL);
  Set(P_NODROP);
  SetWeight(6500);
}
