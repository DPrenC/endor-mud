/*
DESCRIPCION  : cementerio de Zarkam
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/cementerio/tumba01.c
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
  SetIntLong(QueryIntLong()+
    "Al este de aqui queda el sombrio edificio del 'Gremio de Conjuradores'.\n");

  AddDetail(({"gremio","Gremio","gremio de conjuradores","edificio"}),
     "Es el sombrio y austero edificio de tres plantas que se encuentra al este.\n");

  AddExit("norte",Z_CEMENTERIO("tumba02"));
  AddExit("sur",Z_CEMENTERIO("tumba00"));
  AddExit("oeste",Z_CEMENTERIO("tumba04"));
  AddExit("abajo",Z_CEMENTERIO("fosa01"));

}
