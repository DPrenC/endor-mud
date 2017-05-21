#include "./path.h"

inherit KHA_ROOM;

create() {
   ::create();

   SetIntShort("un callejón");
   SetIntLong(
"Estas en un callejon entre la calle Antharax y la Avenida del Castillo. Ves "
"ligeros rayos de luz artificial que vienen del norte y del sur.\n");

   SetIntBright(40);
   SetIndoors(1);

  AddExit("norte",CIUDAD+"antha10");
   AddExit("sur",CIUDAD+"avcastle10");
}
