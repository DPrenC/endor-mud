/*
DESCRIPCION  : Gran Caverna, nivel superior
FICHERO      : /d/akallab/comun/rooms/akallab/kuntz/cueva/caverna17.c
MODIFICACION : 22-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit K_CUEVA("caverna");

create() {
  piso=2;
  ::create();
  SetIntLong(QueryIntLong()+
     "Una galeria parte de aqui hacia el este y una escalera permite bajar al nivel "
     "inferior.\n");

  AddExit("este",K_CUEVA("galeria08"));
  AddExit("norte",K_CUEVA("caverna16"));
  AddExit("suroeste",K_CUEVA("caverna18"));
  AddExit("abajo",K_CUEVA("caverna01"));
}
