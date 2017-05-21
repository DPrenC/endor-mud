/*
DESCRIPCION  : Gran Caverna, mivel medio
FICHERO      : /d/akallab/comun/rooms/akallab/kuntz/cueva/caverna07.c
MODIFICACION : 22-10-98 [Angor@Simauria] Creacion
               10-03-99 update
--------------------------------------------------------------------------------
*/

#include "path.h"
#include AK_MACRO
inherit K_CUEVA("caverna");

create() {
  piso=1;
  ::create();
  SetIntLong(QueryIntLong()+
  "En la cueva que hay al este de aqui parece haber una armeria. "
    "Una escalera permite subir al nivel superior.\n");

  AddExit("este",K_TIENDA("armeria0"));
  AddExit("norte",K_CUEVA("caverna00"));
  AddExit("suroeste",K_CUEVA("caverna02"));
  AddExit("arriba",K_CUEVA("caverna17"));
}
