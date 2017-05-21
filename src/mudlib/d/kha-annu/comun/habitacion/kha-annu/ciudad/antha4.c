#include "./path.h"

inherit KHA_ROOM;

create() {
   ::create();

   SetIntShort("la calle Antharax");
   SetIntLong(
"Estas en la calle Antharax y justo al sur queda otra tienda de las muchas "
"que puedes encontrar en esta zona de la ciudad.\n");

   SetIntBright(80);
   SetIndoors(1);

  AddExit("sur",CIUDAD+"tiendas/tienda2");
  AddExit("este",CIUDAD+"antha5");
  AddExit("oeste",CIUDAD+"antha3");

  SetLocate("Kha-annu");
}
