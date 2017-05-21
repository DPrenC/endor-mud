#include "./path.h"

inherit KHA_ROOM;

create() {
   ::create();

   SetIntShort("la calle Antharax");
   SetIntLong(
"En este extremo de la calle, puedes visitar la tienda de armaduras cruzando "
"la puerta hacia el sur. La calle se termina hacia el este y varias farolas "
"iluminan el camino.\n");
  AddDetail(({"puerta"}),
  "Mas que una puerta, parece un arco construido en piedra.\n");
AddDetail(({"farolas","varias farolas"}),"Iluminan permanentemente la calle.\n");
   SetIntBright(80);
   SetIndoors(1);

  AddExit("sur",CIUDAD+"tiendas/tienda4");
  AddExit("este",CIUDAD+"antha12");
  AddExit("oeste",CIUDAD+"antha10");

  SetLocate("Kha-annu");
}
