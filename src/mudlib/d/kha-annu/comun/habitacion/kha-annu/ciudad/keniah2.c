#include "./path.h"

inherit KHA_ROOM;

create() {
   ::create();

    SetIntShort("la calle Keniah");
   SetIntLong(
"Sigues por la calle Keniah. Al sur puedes ver un cruce, mientras que la calle "
"gira hacia la izquierda.\n");

   SetIntBright(80);
   SetIndoors(1);

  AddExit("sur",CIUDAD+"keniah1");
  AddExit("este",CIUDAD+"keniah3");

  SetLocate("Kha-annu");
}
