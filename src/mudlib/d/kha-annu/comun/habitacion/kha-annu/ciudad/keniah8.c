#include "./path.h"

inherit KHA_ROOM;

create() {
   ::create();

   SetIntShort("la calle Keniah");
   SetIntLong(
"Sigues por la calle Keniah, en una esquina que esta peor iluminada que el resto de "
"la travesia.\n");

   AddDetail( ({"farolas","farola"}),
"Son de color negro y alumbran el lugar.\n");
   SetIntBright(65);
   SetIndoors(1);

  AddExit("norte",CIUDAD+"keniah9");
  AddExit("este",CIUDAD+"keniah7");

  SetLocate("Kha-annu");
}
