/*
DESCRIPCION  : cementerio de Zarkam
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/cementerio/tumba07.c
MODIFICACION : 19-03-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit Z_CEMENTERIO("cementerio");

create() {
  lugar="Zarkam";
  abierta=1;
  amedida=0;

  ::create();
  AddExit("oeste",Z_CEMENTERIO("tumba10"));
  AddExit("norte",Z_CEMENTERIO("tumba08"));
  AddExit("este",Z_CEMENTERIO("tumba04"));
  AddExit("sur",Z_CEMENTERIO("tumba06"));
  AddExit("abajo",Z_CEMENTERIO("fosa07"));
}
