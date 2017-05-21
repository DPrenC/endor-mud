/*
DESCRIPCION  : Gran Caverna, mivel superior
FICHERO      : /d/akallab/comun/rooms/akallab/kuntz/cueva/caverna18.c
MODIFICACION : 22-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit K_CUEVA("caverna");

create() {
  piso=2;
  ::create();

  AddExit("oeste",K_CUEVA("caverna19"));
  AddExit("nordeste",K_CUEVA("caverna17"));
  AddExit("sudeste",K_CUEVA("casa08"));
}
