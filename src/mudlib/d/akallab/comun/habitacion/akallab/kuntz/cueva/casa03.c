/*
DESCRIPCION  : casa en una cueva
FICHERO      : /d/akallab/comun/rooms/akallab/kuntz/cueva/casa00.c
MODIFICACION : 22-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit K_CUEVA("casa");

create() {
  gente=1;
  ::create();
  AddExit("noroeste",K_CUEVA("caverna02"));
  AddItem(BEBIDA("tinaja_agua"),REFRESH_ALWAYS);
}
