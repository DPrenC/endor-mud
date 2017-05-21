/*
DESCRIPCION  : casa en una cueva
FICHERO      : /d/akallab/comun/rooms/akallab/kuntz/cueva/casa04.c
MODIFICACION : 22-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit K_CUEVA("casa");

create() {
  gente=1;
  ::create();
  AddExit("este",K_CUEVA("caverna13"));
  AddItem(BEBIDA("tinaja_agua"),REFRESH_ALWAYS);
}
