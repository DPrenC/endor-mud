#include "./path.h"

inherit KHA_ROOM;

create() {
   ::create();

   SetIntShort("la calle Antharax");
   SetIntLong(
"Esta calle fue construida a partir de las ancias de los enanos por la "
"aventura. Justo al sur puedes ver un gran arco que da entrada a la mejor "
"tiendas de armas de todo Kha-annu. La calle sigue hacia el este y al oeste "
"esta el cruce con la calle Rurik. Hay un letrero en la pared.\n");
  AddDetail( ({"letrero","pared"}),
"En el letrero que esta en la pared pone:\n"
"Cerrado por reformas. Disculpen las molestas.\n");
  AddDetail(({"tienda","tienda de armas"}),
  "Desde aqui no puedes ver gran cosa, aunque la estancia parece amplia.\n");
  AddDetail(({"cruce"}),
  "Lleva a la calle Rurik.\n");
  AddDetail(({"arco"}),
  "Esta construido en piedra y lleva a la tienda de armas.\n");
   SetIntBright(80);
   SetIndoors(1);

  /* La tienda esta cerrada hasta su total reparacion */
  AddExit("sur",CIUDAD+"tiendas/tienda1");
  /* Evidentemente se abrira cuando lo crea conveniente */
  AddExit("este",CIUDAD+"antha2");
  AddExit("oeste",CIUDAD+"rurik10");

  SetLocate("Kha-annu");
}
