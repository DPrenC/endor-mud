#include "./path.h"

inherit KHA_ROOM;

create() {
   ::create();

   SetIntShort("un callejón");
   SetIntLong(
"Un oscuro callejon que conecta la Avenida Grimly con la calle Baldur.\n");

   SetIntBright(20);
   SetIndoors(1);

   AddExit("norte",CIUDAD+"grimly10");
   AddExit("sur",CIUDAD+"baldur10");
}
