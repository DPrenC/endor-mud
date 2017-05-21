/*
DESCRIPCION  : Gran Caverna, nivel inferior
FICHERO      : /d/akallab/comun/rooms/akallab/kuntz/cueva/caverna13.c
MODIFICACION : 22-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit K_CUEVA("caverna");

create() {
  piso=0;
  ::create();

  AddExit("oeste",K_CUEVA("casa04"));
  AddExit("nordeste",K_CUEVA("caverna14"));
  AddExit("sur",K_CUEVA("caverna12"));
  AddExit("este",K_CUEVA("suelo00"));
}
