/*
DESCRIPCION  : palanca para abrir la caja del cuchillo de Malmabeth
FICHERO      : /d/simauria/comun/quest/cuchillo/palanca.c
MODIFICACION : 14-6-00 [Maler] Creacion.
--------------------------------------------------------------------------------
*/

inherit THING;
#include "path.h"
#include <properties.h>

create() {
  ::create();
  AddId("palanca");
  AddId("quest_palanca_berat");
  SetShort("una palanca");
  SetLong(W("Es una palanca de acero de lo más vulgar, de esas que se usan en "
  "los almacenes para abrir las cajas.\n"));
  SetWeight(800);
  SetValue(30);
  Set(P_CANT_STEAL,1);
  Set(P_NOGIVE, 1);
  Set(P_NODROP, 1);
  Set(P_NOSELL, 1);
  Set(P_NOBUY, 1);
}
