/*
DESCRIPCION  : Gran Caverna, mivel inferior
FICHERO      : /d/akallab/comun/rooms/akallab/kuntz/cueva/caverna12.c
MODIFICACION : 22-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit K_CUEVA("caverna");

create() {
  piso=0;

  ::create();
  SetIntLong(QueryIntLong()+"En la cueva que queda al oeste hay un comedor troll.\n");

  AddExit("este",K_CUEVA("suelo02"));
  AddExit("oeste",K_TIENDA("comedero1"));
  AddExit("sudeste",K_CUEVA("caverna11"));
  AddExit("norte",K_CUEVA("caverna13"));
}
