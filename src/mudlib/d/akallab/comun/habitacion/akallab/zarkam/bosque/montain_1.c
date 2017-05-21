/*
DESCRIPCION  : Cordillera de Kova
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/bosque/montain_1.c
MODIFICACION : 13-04-98 [Elric@Simauria] Creacion
               10-10-98 [Angor@Simauria] Rehecha
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

create() {
  ::create();
  SetIntShort("la cordillera de Kova");
  SetIntLong(
     "Altas paredes rocosas se levantan ante ti, impidiendote el paso en cualquier "
     "direccion. La unica salida posible es hacia el este, a no ser que quieras "
     "lanzarte montanya abajo, algo realmente peligroso. Desde la posicion en la "
     "que te encuentras hasta la falda de la montanya hay un buen monton de metros "
     "de caida libre.\n");

  AddDetail(({"pared","paredes","paredes rocosas"}),
     "Te rodean inmensos muros de piedra infranqueables que te impiden avanzar en "
     "muchas direcciones.\n");

  SetIntNoise("Reina el silencio.\n");
  SetIntSmell("El aire es frio en estas alturas.\n");
  SetLocate("bosque de Zarkam");
  SetIndoors(0);

  AddExit("este",Z_BOSQUE("montain_2"));
}

