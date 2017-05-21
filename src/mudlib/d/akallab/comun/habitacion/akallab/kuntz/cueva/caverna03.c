/*
DESCRIPCION  : Gran Caverna, mivel medio
FICHERO      : /d/akallab/comun/rooms/akallab/kuntz/cueva/caverna03.c
MODIFICACION : 22-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit K_CUEVA("caverna");

create() {
  piso=1;
  ::create();
  SetIntLong(QueryIntLong()+"Una escalera permite bajar al nivel inferior.\n");

  AddExit("este",K_CUEVA("caverna02"));
  AddExit("suroeste",K_CUEVA("galeria04"));
  AddExit("abajo",K_CUEVA("caverna11"));
  AddExit("noroeste",K_CUEVA("caverna04"));
}
