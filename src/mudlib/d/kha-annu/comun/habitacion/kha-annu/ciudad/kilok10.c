#include "./path.h"

inherit KHA_ROOM;

create() {
   ::create();

   SetIntShort("la calle Kilok");
   SetIntLong(
"La calle Kilok, cruza el río de la ciudad hacia el sur. Las mayoria de las tiendas "
"quedan muy cerca de aqui, hacia el norte por la calle Antharax o al sur por la "
"Avenida del Castillo.\n");

   SetIntBright(80);
   SetIndoors(1);

  AddExit("norte",CIUDAD+"antha12");
  AddExit("sur",CIUDAD+"avcastle12");

  SetLocate("Kha-annu");
}
