#include "./path.h"

inherit KHA_ROOM;

create() {
   ::create();

   SetIntShort("un callejón");
   SetIntLong(
"Estas en un callejon oscuro y vacio. No hay nada interesante aqui.\n");

   SetIntBright(20);
   SetIndoors(1);

   AddExit("este",CIUDAD+"hunkas4");
   AddExit("oeste",CIUDAD+"rurik4");
}
