#include "./path.h"

inherit KHA_ROOM;

create() {
   ::create();

   SetIntShort("la calle Keniah");
   SetIntLong(
"Has seguido esta calle y has llegado a un tramo en el que se puede ver "
"como se extiende durante un tramo bastante largo hacia el norte, mientras "
"que al sur solo ves como dobla una esquina.\n");

   AddDetail(({"farolas","farola"}),
"Son de color negro y alumbran el lugar.\n");
   AddDetail(({"plakita"}),
"Aportacion de Tannis a la ciudad de Kha-annu.\n");

   SetIntBright(80);
   SetIndoors(1);

  AddExit("norte",CIUDAD+"keniah6");
  AddExit("sur",CIUDAD+"keniah4");

  SetLocate("Kha-annu");
}
