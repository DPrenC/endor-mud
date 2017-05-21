/*
DESCRIPCION  : Gran Caverna, mivel inferior
FICHERO      : /d/akallab/comun/rooms/akallab/kuntz/cueva/caverna09.c
MODIFICACION : 22-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit K_CUEVA("caverna");

create() {
  piso=1;
  ::create();
  SetIntLong(QueryIntLong()+"En la cueva que hay al este de aqui parece haber una armeria.\n");

  AddExit("oeste",K_CUEVA("suelo03"));
  AddExit("este",K_TIENDA("armeria1"));
  AddExit("norte",K_CUEVA("caverna08"));
  AddExit("suroeste",K_CUEVA("caverna10"));
}
