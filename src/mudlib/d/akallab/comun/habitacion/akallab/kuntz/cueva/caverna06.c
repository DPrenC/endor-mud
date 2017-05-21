/*
DESCRIPCION  : Gran Caverna, mivel medio
FICHERO      : /d/akallab/comun/rooms/akallab/kuntz/cueva/caverna06.c
MODIFICACION : 22-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit K_CUEVA("caverna");

create() {
  piso=1;
  ::create();
  SetIntLong(QueryIntLong()+"En la cueva que queda al noroeste hay un comedor troll.\n");

  AddExit("este",K_CUEVA("caverna07"));
  AddExit("suroeste",K_CUEVA("caverna05"));
  AddExit("noroeste",K_TIENDA("comedero0"));
}
