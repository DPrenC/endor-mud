#include "./path.h"

inherit SHOP;
#define RUTA "/d/Kha-annu/comun/pnj/"

create() {
   ::create();

  SetIntShort("el herbolario");
   SetIntLong(
"El ambiente de esta tienda es bastante relajado. Puedes percibir varios aromas "
"mezclados en el aire que te invitan a probarlos. La luz es mas debil que en el "
"exterior. Hay varias estanterias repletas de plantas.\n");

  SetIntBright(60);
   SetIndoors(1);
  AddDetail(({"estanteria","varias estanterias"}),
"Las estanterias estan en la parte derecha de la tienda y contien algunas plantas.\n");
  AddDetail(({"plantas","algunas plantas"}),
"Las plantas son de diverso tipo, forma y tamanyo, pero no reconoces ninguna.\n");
  AddExit("este",CIUDAD+"kilok5");

  SetIntSmell("Puedes percibir un agradable olor, seguramente mezcla de varias plantas.\n");
  SetLocate("Kha-annu");
}