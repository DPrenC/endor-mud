/*
DESCRIPCION  : cementerio de Zarkam
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/cementerio/fosa05.c
MODIFICACION : 26-03-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit Z_CEMENTERIO("fosa");

create() {
  abierta=1;
  agujero=0;
  saqueada=random(2);

  ::create();
  AddExit("arriba",Z_CEMENTERIO("tumba05"));
}
