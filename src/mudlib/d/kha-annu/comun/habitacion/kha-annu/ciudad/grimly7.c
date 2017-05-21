#include "./path.h"

inherit KHA_ROOM;

create() {
   ::create();

   SetIntShort("la avenida Grimly.");
   SetIntLong(
"La gran Avenida Grimly recorre la ciudad de este a oeste y por ella circulan "
"tranquilamente los habitantes de Kha-annu. Algunas farolas alumbran la zona.\n");

   AddDetail(({"farola","farolas"}),
"Grandes y de color negro alumbran continuamente la Avenida.\n");

   SetIntBright(80);
   SetIndoors(1);

   AddExit("este",CIUDAD+"grimly8");
   AddExit("oeste",CIUDAD+"grimly6");

   SetLocate("Kha-annu");
}
