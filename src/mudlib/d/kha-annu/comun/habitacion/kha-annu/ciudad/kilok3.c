#include "./path.h"

inherit KHA_ROOM;

create() {
   ::create();

   SetIntShort("la calle Kilok");
   SetIntLong(
"Te encuentras cerca de la posada del Dragon Rojo, situada en la Avenida "
"Grimly. Esta es la calle Kilok, que cruza la avenida en direccion sur y "
"continua al norte despues de doblar la esquina.\n");

AddDetail(({"esquina","la esquina"}),
"Esta hacia el este y continua la calle en direccion norte.\n");

   SetIntBright(80);
   SetIndoors(1);

  AddExit("sur",CIUDAD+"grimly11");
  AddExit("este",CIUDAD+"kilok4");

  SetLocate("Kha-annu");
}
