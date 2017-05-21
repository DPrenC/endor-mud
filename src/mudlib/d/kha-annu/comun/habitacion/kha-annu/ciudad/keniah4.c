#include "./path.h"

inherit KHA_ROOM;

create() {
   ::create();

   SetIntShort("la calle Keniah");
   SetIntLong(
"La calle sigue en direccion norte con algunas farolas que alumbran el lugar.\n");

  AddDetail( ({"farolas","farola"}),
"Son de color negro y alumbran el lugar.\n");
   SetIntBright(80);
   SetIndoors(1);

  AddExit("norte",CIUDAD+"keniah5");
  AddExit("sur",CIUDAD+"keniah3");

  SetLocate("Kha-annu");
}
