/*
DESCRIPCION  : cementerio de Zarkam
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/cementerio/tumba06.c
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
    "Al sur de aqui se halla la muralla exterior de la ciudad.\n");

  AddDetail(({"muralla"}),
     "Es un inmenso muro de piedra que protege la ciudad rodeandola por completo. "
     "Dirias que como minimo tiene unos cinco metros de altura en las partes mas bajas "
     "y esta protegida con gruesas almenas. Sobre ella hay una pasarela por la que "
     "cada cierto tiempo ves pasar soldados fuertemente armados.\n");

  AddExit("norte",Z_CEMENTERIO("tumba07"));
  AddExit("oeste",Z_CEMENTERIO("tumba09"));
  AddExit("este",Z_CEMENTERIO("tumba03"));
  AddExit("abajo",Z_CEMENTERIO("fosa06"));
}
