/*
DESCRIPCION  : cementerio de Zarkam
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/cementerio/tumba00.c
MODIFICACION : 19-03-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
#include <moving.h>


inherit Z_CEMENTERIO("cementerio");

int ir_e(){
  if (TP->QueryIsPlayer()){
     write("La puerta de la verja chirria lastimeramente cuando la abres al salir.\n");
     return TP->move(Z_CIUDAD("calle_36"),M_GO);
     }
  return 1;
}

create() {
  lugar="Zarkam";
  abierta=0;
  amedida=0;

  ::create();
  SetIntLong(QueryIntLong()+
    "Una oxidada verja de hierro te permite salir del cementerio a una callejuela "
    "avanza hacia el este junto a la muralla de la ciudad. Al sur de aqui se halla "
    "la muralla exterior de la ciudad.\n");

  AddDetail(({"muralla"}),
     "Es un inmenso muro de piedra que protege la ciudad rodeandola por completo. "
     "Dirias que como minimo tiene unos cinco metros de altura en las partes mas bajas "
     "y esta protegida con gruesas almenas. Sobre ella hay una pasarela por la que "
     "cada cierto tiempo ves pasar soldados fuertemente armados.\n");

  AddDetail(({"verja","puerta"}),
    "Es una puerta hecha con delgadas barras de metal. Esta bastante oxidada y sus "
    "goznes chirrian lastimeramente cada vez que se abre para salir o entrar al "
    "cementerio.\n");

  AddExit("norte",Z_CEMENTERIO("tumba01"));
  AddExit("oeste",Z_CEMENTERIO("tumba03"));
  AddExit("este",SF(ir_e));
}
