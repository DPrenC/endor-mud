#include "./path.h"

inherit KHA_ROOM;

create() {
   ::create();

   SetIntShort("la calle Keniah");
   SetIntLong(
"No es que sea una de las calles mas llamativas de la ciudad a no ser por "
"las farolas puestas a cada lado.\n");
   AddDetail( ({"farolas","farola"}),
"Son de color negro y alumbran el lugar.\n");

   SetIntBright(80);
   SetIndoors(1);

  AddExit("norte",CIUDAD+"keniah7");
  AddExit("sur",CIUDAD+"keniah5");

  SetLocate("Kha-annu");
}
