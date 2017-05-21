/*
DESCRIPCION  : Gran Caverna, mivel inferior
FICHERO      : /d/akallab/comun/rooms/akallab/kuntz/cueva/caverna11.c
MODIFICACION : 22-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit K_CUEVA("caverna");

create() {
  piso=0;
  ::create();
  SetIntLong(QueryIntLong()+
  "Una escalera permite subir al nivel superior. Oyes ruido de ninyos al suroeste.\n");

  AddExit("norte",K_CUEVA("suelo02"));
  AddExit("este",K_CUEVA("caverna10"));
  AddExit("suroeste",K_CUEVA("guarderia"));
  AddExit("arriba",K_CUEVA("caverna03"));
  AddExit("noroeste",K_CUEVA("caverna12"));
}
