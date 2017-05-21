/*
DESCRIPCION  : Gran Caverna, mivel superior
FICHERO      : /d/akallab/comun/rooms/akallab/kuntz/cueva/caverna23.c
MODIFICACION : 22-10-98 [Angor@Simauria] Creacion
*/

#include "path.h"
inherit K_CUEVA("caverna");

create() {
  piso=2;
  ::create();
  SetIntLong(QueryIntLong()+
    "Al nordeste queda una amplia y silenciosa cueva. En su interior observas lo que "
    "parece ser una gran roca.\n");

  AddDetail(({"roca"}), "Para verla mejor deberias entrar en la cueva.\n");

  AddExit("oeste",K_CUEVA("caverna22"));
  AddExit("sudeste",K_CUEVA("caverna16"));
  AddExit("nordeste",K_CUEVA("templo"));
}
