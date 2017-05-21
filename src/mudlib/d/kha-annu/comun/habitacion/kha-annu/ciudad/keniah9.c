#include "./path.h"

inherit KHA_ROOM;

create() {
   ::create();

   SetIntShort("la calle Keniah");
   SetIntLong(
"Estas en la calle Keniah. Al norte queda la Avenida del Castillo, que da "
"nombre a esta ciudad. Hacia el sur puedes ver una esquina, peor iluminada.\n");

   AddDetail( ({"farolas","farola"}),
"Son de color negro y alumbran el lugar.\n");
   SetIntBright(80);
   SetIndoors(1);

  AddExit("norte",CIUDAD+"avcastle9");
  AddExit("sur",CIUDAD+"keniah8");

  SetLocate("Kha-annu");
}
