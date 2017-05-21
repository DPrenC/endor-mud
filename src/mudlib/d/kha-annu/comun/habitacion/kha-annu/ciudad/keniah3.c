#include "./path.h"

inherit KHA_ROOM;

create() {
   ::create();

   SetIntShort("la calle Keniah");
   SetIntLong(
"La calle es mas estrecha en esta esquina, que gira hacia la derecha.\n");

   SetIntBright(65);
   SetIndoors(1);

  AddExit("norte",CIUDAD+"keniah4");
  AddExit("oeste",CIUDAD+"keniah2");

  SetLocate("Kha-annu");
}
