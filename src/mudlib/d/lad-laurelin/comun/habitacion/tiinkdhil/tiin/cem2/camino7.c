#include "path.h"
inherit ROOM;
create()
{
  ::create();
  SetIntShort("el cementerio");
  SetIntLong(
    "Estas en un camino que en otra epoca fue muy bonito. A ambos lados puedes ver grandes mausoleos que se conservan en buen estado pese a la estar abandonados. Unos bancos de madera se situan a cada lado del camino, que te lleva hacia mas mausoleos al sur y hacia la zona norte del cementerio el otro.\n"
    );
  SetIndoors(0);
  SetIntSmell(
    "El olor en esta zona es asqueroso, como si la putrefaccion se concentrara cerca de aqui.\n"
    );
  SetIntNoise(
    "El ruido en esta zona es mas bajo, como si guardara un respetuoso silencio.\n"
    );
  AddDetail(({"niebla"}),
    "Remolinos de niebla se mueven inexplicablemente de un lado a otro, impidiendo que veas mas alla de un par de metros, te sientes terriblemente solo y triste en este mar blanco.\n"
    );
  AddDetail(({"banco","bancos"}),
    "Bancos de madera, que al mirarlos con mas atencion descubres que esta podrida por el tiempo o por algun tipo de carcoma.\n"
    );
  AddDetail(({"mausoleos"}),
    "Unos mausoleos de aspecto rico se alzan a ambos lados del camino.\n"
    );
  AddExit("norte","camino8.c");
  AddExit("oeste","mausoleo4.c");
  AddExit("este","mausoleo6.c");
  AddExit("sur","camino6.c");
  SetLocate("cementerio2");
}
