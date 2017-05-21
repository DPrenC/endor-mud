#include "./path.h"

inherit KHA_ROOM;

create() {
   ::create();

   SetIntShort("la calle Antharax");
   SetIntLong(
"Te encuentras en la calle comercial de la ciudad. Al oeste queda la tienda "
"de armas, y puedes encontrar diferentes tiendas en direccion este.\n");

  AddDetail(({"farolas","farola","antorchas","antorcha"}),
  "Grandes y de color negro, estan puestas por toda la calle.\n");

   SetIntBright(80);
   SetIndoors(1);

  AddExit("este",CIUDAD+"antha3");
  AddExit("oeste",CIUDAD+"antha1");

  SetLocate("Kha-annu");
}
