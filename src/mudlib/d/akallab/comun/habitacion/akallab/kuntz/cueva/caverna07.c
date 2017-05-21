/*
DESCRIPCION  : Gran Caverna, mivel medio
FICHERO      : /d/akallab/comun/rooms/akallab/kuntz/cueva/caverna07.c
MODIFICACION : 22-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit K_CUEVA("caverna");

create() {
  piso=1;
  ::create();
  SetIntLong(QueryIntLong()+"Una escalera permite bajar al nivel inferior.\n");

  AddExit("oeste",K_CUEVA("caverna06"));
  AddExit("sudeste",K_CUEVA("caverna00"));
  AddExit("abajo",K_CUEVA("caverna15"));
  AddExit("nordeste",K_CUEVA("casa00"));
}
