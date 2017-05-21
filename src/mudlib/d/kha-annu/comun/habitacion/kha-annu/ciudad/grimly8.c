#include "./path.h"

inherit KHA_ROOM;

#define NGREMIO "clerigos"

create() {
   ::create();

   SetIntShort("la avenida Grimly.");
   SetIntLong(
"Al este de la Avenida Grimly se encuentra el gremio de los "+NGREMIO+", lugar "
"de estudio de aquellos enanos que prefiren pasar mas tiempo en el, que en la "
"taberna situada al oeste del paseo.\n");

   SetIntBright(80);
   SetIndoors(1);

   AddExit("sur",CIUDAD+"iglesia");
   AddExit("este",CIUDAD+"grimly9");
   AddExit("oeste",CIUDAD+"grimly7");

   SetLocate("Kha-annu");
}
