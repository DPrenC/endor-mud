#include "./path.h"

inherit KHA_ROOM;

create() {
   ::create();

   SetIntShort("la avenida del castillo");
   SetIntLong(
"En esta esquina de la calle, puedes acceder al ayuntamiento y a las tiendas si "
"te diriges hacia el oeste. La Avenida del Castillo queda en esa misma direccion, "
"y esta calle continua hacia el sur despues de doblar la esquina.\n");

   SetIntBright(80);
   SetIndoors(1);

   AddExit("norte",CIUDAD+"kilok10");
   AddExit("oeste",CIUDAD+"avcastle11");
   SetLocate("Kha-annu");
}
