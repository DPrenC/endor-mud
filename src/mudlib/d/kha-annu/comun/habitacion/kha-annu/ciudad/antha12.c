#include "./path.h"

inherit KHA_ROOM;

create() {
   ::create();

   SetIntShort("la calle Antharax");
   SetIntLong(
"Esta es la parte mas oriental de la ciudad de Kha-annu. Antharax es una calle "
"llena de tiendas especiales para la lucha. Puedes encontrar incluso una tienda "
"especializada en hachas de combate al otro extremo de la calle. Si te dirigues "
"hacia el sur cruzaras el río Gaut-Kilok por la calle que lleva su mismo nombre.\n");

   SetIntBright(80);
   SetIndoors(1);

  AddExit("sur",CIUDAD+"kilok10");
  AddExit("oeste",CIUDAD+"antha11");

  SetLocate("Kha-annu");
}
