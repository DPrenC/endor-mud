#include "./path.h"

inherit KHA_ROOM;

create() {
   ::create();

   SetIntShort("un callejón");
   SetIntLong(
"Te has parado en el cruce entre la Avenida Grimly, que esta hacia el norte "
"y la calle Baldur, que se encuentra hacia el sur. No ves nada especial "
"alrededor excepto una gran estatua. La luz de este lugar viene del norte "
"y tambien desde el sur.\n");
   SetIntBright(60);
   SetIndoors(1);

   AddExit("norte",CIUDAD+"grimly6");
   AddExit("sur",CIUDAD+"baldur6");
}
