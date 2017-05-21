/*
DESCRIPCION  : Gran Caverna, nivel superior
FICHERO      : /d/akallab/comun/rooms/akallab/kuntz/cueva/caverna20.c
MODIFICACION : 22-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit K_CUEVA("caverna");

create() {
  piso=2;
  ::create();

  AddExit("oeste",K_CUEVA("casa07"));
  AddExit("sudeste",K_CUEVA("caverna19"));
  AddExit("norte",K_CUEVA("caverna21"));
}
