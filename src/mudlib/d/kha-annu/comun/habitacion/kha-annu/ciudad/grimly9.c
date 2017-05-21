#include "./path.h"

inherit KHA_ROOM;

create() {
   ::create();

   SetIntShort("la avenida Grimly.");
   SetIntLong(
"El cruce con la calle Keniah te llevara al norte de la ciudad pasando por "
"la zona oriental del castillo de Kha-annu, la mayor construccion de la ciudad.\n");

   SetIntBright(80);
   SetIndoors(1);

   AddExit("norte",CIUDAD+"keniah1");
   AddExit("este",CIUDAD+"grimly10");
   AddExit("oeste",CIUDAD+"grimly8");

   SetLocate("Kha-annu");
}
