/*
DESCRIPCION  : cementerio de Zarkam
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/cementerio/fosa03.c
MODIFICACION : 26-03-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit Z_CEMENTERIO("fosa");

create() {
  abierta=0;
  agujero=1;
  saqueada=random(2);

  ::create();
  AddExit("oeste",Z_CEMENTERIO("fosa06"));
}
