#include "./path.h"

inherit KHA_ROOM;

create() {
   ::create();

   SetIntShort("la calle Keniah");
   SetIntLong(
"Estas en la calle Keniah, que desemboca al sur hacia la Avenida Grimly y sigue "
"hacia el norte bordeando el castillo.\n");

   SetIntBright(80);
   SetIndoors(1);

  AddExit("norte",CIUDAD+"keniah2");
  AddExit("sur",CIUDAD+"grimly9");

  SetLocate("Kha-annu");
}
