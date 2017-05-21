#include "./path.h"

inherit KHA_ROOM;

create() {
   ::create();

   SetIntShort("la calle Antharax");
   SetIntLong(
"Estas aproximadamente en mitad de la calle Antharax. Desde aqui puedes ver "
"otra tienda, aunque esta no parece de ninguna especialidad, sino mas bien "
"de utensilios en general.\n");

  AddDetail(({"tienda"}),
  "Desde aqui no parece muy grande, tal ves si entras podrias verla mejor.\n");
   SetIntBright(80);
   SetIndoors(1);

  AddExit("sur",CIUDAD+"tiendas/tienda3");
  AddExit("este",CIUDAD+"antha9");
  AddExit("oeste",CIUDAD+"antha7");

  SetLocate("Kha-annu");
}
