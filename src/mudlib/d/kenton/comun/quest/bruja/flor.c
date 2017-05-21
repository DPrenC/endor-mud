/*
DESCRIPCION  : pelo de kender
FICHERO      : /d/kenton/comun/quest/bruja/flor.c
MODIFICACION : 14-6-00 [Maler] Creacion.
--------------------------------------------------------------------------------
*/

inherit THING;
#include "path.h"
#include <properties.h>

create() {
  ::create();
  AddId("flor");
  AddId("quest_flor_bruja");
  SetShort("una flor");
  SetLong(W("Es una flor de las que flotan en todas las charcas, es completamente blanca y muy común, y "
  "no es especialmente bonita.\n"));
  Set(P_NOGIVE);
  Set(P_NOSELL);
  Set(P_NODROP);
  SetWeight(50);
}
