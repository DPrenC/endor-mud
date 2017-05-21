/*
DESCRIPCION  : pelo de kender
FICHERO      : /d/kenton/comun/quest/bruja/pelo.c
MODIFICACION : 14-6-00 [Maler] Creacion.
--------------------------------------------------------------------------------
*/

inherit THING;
#include "path.h"
#include <properties.h>

create() {
  ::create();
  AddId("pelo");
  AddId("quest_pelo_bruja");
  SetShort("un pelo");
  SetLong(W("Es un pelo de kender. Es castaño, como es normal en "
  "esta raza.\n"));
  Set(P_NOGIVE);
  Set(P_NOSELL);
  Set(P_NODROP);
  SetWeight(30);
}
