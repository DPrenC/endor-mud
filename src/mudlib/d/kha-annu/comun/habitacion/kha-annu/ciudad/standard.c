#include "./path.h"

inherit KHA_ROOM;

create() {
   ::create();

   SetIntShort("Nombre de la Calle");
   SetIntLong(
"Descripcion de la Calle.\n");

   SetIntBright(80);
   SetIndoors(1);

   AddExit("",CIUDAD+"");
   SetLocate("Kha-annu");
}
