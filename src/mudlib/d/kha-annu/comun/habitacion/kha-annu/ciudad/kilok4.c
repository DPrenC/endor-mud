#include "./path.h"

inherit KHA_ROOM;

create() {
   ::create();

   SetIntShort("la calle Kilok");
   SetIntLong(
"Estas en otra de las muchas esquinas y recodos de la calle Kilok. Hacia el norte "
"puedes encontrar una pequeña tienda. Si doblas la esquina hacia el oeste, "
"cruzaras la Avenida Grimly.\n");

   SetIntBright(80);
   SetIndoors(1);

  AddExit("norte",CIUDAD+"kilok5");
  AddExit("oeste",CIUDAD+"kilok3");

  SetLocate("Kha-annu");
}
