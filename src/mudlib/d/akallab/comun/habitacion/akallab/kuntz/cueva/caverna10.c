/*
DESCRIPCION  : Gran Caverna, mivel inferior
FICHERO      : /d/akallab/comun/rooms/akallab/kuntz/cueva/caverna10.c
MODIFICACION : 22-10-98 [Angor@Simauria] Creacion
*/

#include "path.h"
inherit K_CUEVA("caverna");

create() {
  piso=0;
  ::create();
 SetIntLong(QueryIntLong()+ "Una galeria parte de aqui hacia el sudeste.\n");

  AddExit("norte",K_CUEVA("suelo03"));
  AddExit("oeste",K_CUEVA("caverna11"));
  AddExit("nordeste",K_CUEVA("caverna09"));
  AddExit("sudeste",K_CUEVA("galeria06"));
}
