/*
DESCRIPCION  : Gran Caverna, nivel superior
FICHERO      : /d/akallab/comun/rooms/akallab/kuntz/cueva/caverna21.c
MODIFICACION : 22-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit K_CUEVA("caverna");

create() {
  piso=2;
  ::create();
  SetIntLong(QueryIntLong()+"Una escalera permite bajar al nivel inferior.\n");

  AddExit("oeste",K_CUEVA("casa06"));
  AddExit("nordeste",K_CUEVA("caverna22"));
  AddExit("sur",K_CUEVA("caverna20"));
  AddExit("abajo",K_CUEVA("caverna05"));
}
