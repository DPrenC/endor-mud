/*
DESCRIPCION  : Gran Caverna, mivel superior
FICHERO      : /d/akallab/comun/rooms/akallab/kuntz/cueva/caverna22.c
MODIFICACION : 22-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit K_CUEVA("caverna");

create() {
  piso=2;
  ::create();
  SetIntLong(QueryIntLong()+"Una galeria parte de aqui hacia el noroeste.\n");

  AddExit("este",K_CUEVA("caverna23"));
  AddExit("suroeste",K_CUEVA("caverna21"));
  AddExit("noroeste",K_CUEVA("galeria07"));
}
