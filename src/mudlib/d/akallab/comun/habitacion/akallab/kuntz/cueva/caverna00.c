/*
DESCRIPCION  : Gran Caverna, mivel medio
FICHERO      : /d/akallab/comun/rooms/akallab/kuntz/cueva/caverna00.c
MODIFICACION : 22-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit K_CUEVA("caverna");

create() {
  piso=1;
  ::create();
  SetIntLong(QueryIntLong()+"Una galeria parte de aqui hacia el este.\n");

  AddExit("este",K_CUEVA("galeria00"));
  AddExit("sur",K_CUEVA("caverna01"));
  AddExit("noroeste",K_CUEVA("caverna07"));
}
