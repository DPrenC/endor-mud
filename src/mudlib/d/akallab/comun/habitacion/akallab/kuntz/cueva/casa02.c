/*
DESCRIPCION  : casa en una cueva
FICHERO      : /d/akallab/comun/rooms/akallab/kuntz/cueva/casa02.c
MODIFICACION : 22-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit K_CUEVA("casa");

create() {
  gente=1;
  ::create();
  AddExit("este",K_CUEVA("caverna04"));
}
