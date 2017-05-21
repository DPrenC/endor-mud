/*
DESCRIPCION  : casa en una cueva
FICHERO      : /d/akallab/comun/rooms/akallab/kuntz/cueva/casa05.c
MODIFICACION : 22-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit K_CUEVA("casa");

create() {
  gente=1;
  ::create();
  AddExit("oeste",K_CUEVA("caverna08"));
}
