/*
DESCRIPCION  : Bosque al nordeste de Zarkam.
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/bosque/bosque_22.c
MODIFICACION : 13-04-98 [Elric@Simauria] Creacion
               10-10-98 [Angor@Simauria] Rehecha
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

create() {
  ::create();
  SetIntShort("el camino interior");
  SetIntLong(
     "En esta zona del camino la tierra ha dejado de ser mera tierra para pasar a ser "
     "barro, debe haber alguna corriente de agua cerca. Apilados a los lados ves "
     "varios tablones bastante anchos y de aspecto resistente. A medida que se avanza "
     "hacia el este, el terreno esta mas humedo. El camino avanza desde el oeste hacia "
     "el noroeste.\n");

  AddDetail(({"tierra","barro","camino"}),
     "Todo el suelo esta lleno de barro, con solo dar dos pasos, ya te estancas "
     "hasta los tobillos.\n");

  AddDetail(({"tablones","tablas","maderos"}),
     "Contemplas atentamente los tablones. Tienen una de sus caras cubierta de barro "
     "del camino. Deduces que han sido utilizados para que animales de tiro y carros "
     "avanzaran por el camino sin hundirse en el barro.\n");

  SetIntNoise("Oyes rumor de agua.\n");
  SetIntSmell("El aire es humedo aqui.\n");
  SetLocate("bosque de Zarkam");
  SetIndoors(0);

  AddExit("sur",Z_BOSQUE("bosque_13"));
  AddExit("este",Z_BOSQUE("bosque_23"));
  AddExit("oeste",Z_BOSQUE("bosque_21"));
  AddExit("noroeste",Z_BOSQUE("bosque_31"));

  AddItem(PNJ("animal/liebre"),REFRESH_DESTRUCT);
}
