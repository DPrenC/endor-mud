#include "./path.h"

inherit KHA_ROOM;

create() {
   ::create();

   SetIntShort("la calle Antharax");
   SetIntLong(
"Caminando por esta calle en direccion oeste, puedes llegar a la mejor tienda "
"de armas de la ciudad. Al este queda la tienda de armas y puedes ver un "
"callejon justo en esa direccion.\n");

  AddDetail(({"farolas","farola"}),
  "Parece como si nunca te hubieses fijado en una. Iluminan la calle.\n");
  AddDetail(({"callejon"}),
  "Desde aqui no puedes ver mas que la entrada hacia el sur.\n");
   SetIntBright(80);
   SetIndoors(1);

  AddExit("este",CIUDAD+"antha10");
  AddExit("oeste",CIUDAD+"antha8");

  SetLocate("Kha-annu");
}
