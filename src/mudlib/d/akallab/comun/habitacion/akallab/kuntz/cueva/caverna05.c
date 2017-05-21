/*
DESCRIPCION  : Gran Caverna, mivel medio
FICHERO      : /d/akallab/comun/rooms/akallab/kuntz/cueva/caverna05.c
MODIFICACION : 22-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit K_CUEVA("caverna");

create() {
  piso=1;
  ::create();

  SetIntLong(QueryIntLong()+"Una escalera permite subir al nivel superior.\n");

  AddExit("oeste",K_CUEVA("casa01"));
  AddExit("nordeste",K_CUEVA("caverna06"));
  AddExit("sur",K_CUEVA("caverna04"));
  AddExit("arriba",K_CUEVA("caverna21"));
}
