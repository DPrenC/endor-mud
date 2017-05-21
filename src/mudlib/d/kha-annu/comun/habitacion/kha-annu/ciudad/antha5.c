#include "./path.h"

inherit KHA_ROOM;

create() {
   ::create();

   SetIntShort("la calle Antharax");
   SetIntLong(
"En esta parte de la calle, puedes cruzar hacia la Avenida del Castillo por "
"el callejon que esta hacia el este. Las farolas iluminan la calle.\n");

  AddDetail(({"farola","farolas"}),
  "Simplemente iluminan la calle.\n");

   SetIntBright(80);
   SetIndoors(1);

  AddExit("este",CIUDAD+"antha6");
  AddExit("oeste",CIUDAD+"antha4");

  SetLocate("Kha-annu");
}
