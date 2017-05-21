/*
DESCRIPCION  : Gran Caverna, mivel medio
FICHERO      : /d/akallab/comun/rooms/akallab/kuntz/cueva/caverna04.c
MODIFICACION : 22-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit K_CUEVA("caverna");

create() {
  piso=1;
  ::create();

  AddExit("oeste",K_CUEVA("casa02"));
  AddExit("sudeste",K_CUEVA("caverna03"));
  AddExit("norte",K_CUEVA("caverna05"));
}
