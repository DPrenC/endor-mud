/*
DESCRIPCION  : cementerio de Zarkam
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/cementerio/tumba10.c
MODIFICACION : 19-03-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit Z_CEMENTERIO("cementerio");

create() {
  lugar="Zarkam";
  abierta=0;
  amedida=0;

  ::create();
  AddExit("norte",Z_CEMENTERIO("tumba11"));
  AddExit("este",Z_CEMENTERIO("tumba07"));
  AddExit("sur",Z_CEMENTERIO("tumba09"));
}
