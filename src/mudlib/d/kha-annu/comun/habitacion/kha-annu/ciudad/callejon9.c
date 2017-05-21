#include "./path.h"

inherit KHA_ROOM;

create() {
   ::create();

   SetIntShort("un callejón");
   SetIntLong(
"Este es el cruce entre la calle Antharax, que se encuentra al norte, y la "
"Avenida del Castillo, que esta hacia el sur. No hay nada en especial aqui.\n");

   SetIntBright(70);
   SetIndoors(1);

  AddExit("norte",CIUDAD+"antha6");
   AddExit("sur",CIUDAD+"avcastle6");
}
