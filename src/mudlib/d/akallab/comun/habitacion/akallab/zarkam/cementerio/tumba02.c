/*
DESCRIPCION  : cementerio de Zarkam
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/cementerio/tumba00.c
MODIFICACION : 19-03-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
#include <moving.h>


inherit Z_CEMENTERIO("cementerio");

int ir_n(){
  if (TP->QueryIsPlayer()){
     write("La puerta de la verja chirria lastimeramente cuando la abres al salir.\n");
     return TP->move(Z_CIUDAD("calle_37"),M_GO);
     }
  return 1;
}

create() {
  lugar="Zarkam";
  abierta=0;
  amedida=0;

  ::create();
  SetIntLong(QueryIntLong()+
    "Una oxidada verja de hierro te permite salir del cementerio a una ancha calle. "
    "Al este de aqui se alza el sombrio edificio del 'Gremio de Conjuradores'.\n");

  AddDetail(({"gremio","Gremio","gremio de conjuradores","edificio"}),
     "Es el sombrio y austero edificio de tres plantas que se encuentra al este.\n");

  AddDetail(({"verja","puerta"}),
    "Es una puerta hecha con delgadas barras de metal. Esta bastante oxidada y sus "
    "goznes chirrian lastimeramente cada vez que se abre para salir o entrar al "
    "cementerio.\n");

  AddExit("sur",Z_CEMENTERIO("tumba01"));
  AddExit("oeste",Z_CEMENTERIO("tumba05"));
  AddExit("norte",SF(ir_n));
}
