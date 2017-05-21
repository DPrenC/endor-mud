/*
DESCRIPCION  : Gran Caverna, mivel inferior
FICHERO      : /d/akallab/comun/rooms/akallab/kuntz/cueva/caverna14.c
MODIFICACION : 22-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit K_CUEVA("caverna");

create() {
  piso=0;
  ::create();
 SetIntLong(QueryIntLong()+"En la cueva que queda al noroeste vive un alfarero.\n");

  AddExit("este",K_CUEVA("caverna15"));
  AddExit("suroeste",K_CUEVA("caverna13"));
  AddExit("noroeste",K_TIENDA("alfareria"));
  AddExit("sur",K_CUEVA("suelo00"));
}
