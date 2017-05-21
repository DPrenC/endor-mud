/*
DESCRIPCION  : cementerio de Zarkam
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/cementerio/tumba04.c
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
  AddExit("oeste",Z_CEMENTERIO("tumba07"));
  AddExit("norte",Z_CEMENTERIO("tumba05"));
  AddExit("este",Z_CEMENTERIO("tumba01"));
  AddExit("sur",Z_CEMENTERIO("tumba03"));
}

