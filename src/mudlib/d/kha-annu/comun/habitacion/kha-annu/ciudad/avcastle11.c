#include "./path.h"

inherit KHA_ROOM;

create() {
   ::create();

   SetIntShort("la avenida del castillo");
   SetIntLong(
"Te encuentras en la ciudadela de Kha-annu. Esta es la avenida del Castillo, que va "
"de este a este. Al este ves un cruce con otra calle de la ciudad. El castillo se "
"encuentra hacia el oeste, y justo al norte ves una puerta con un cartel colgando "
"en la entrada.\n"
);

   SetIntBright(80);
   SetIndoors(1);
   AddDetail("cartel",
"Podrias leer el cartel que hay sobre la puerta.\n");

   AddReadMsg( ({"cartel"}),
"\nEl cartel dice:"
"\tTienda de Armaduras de Kha-annu.\n");
   AddExit("norte",CIUDAD+"tiendas/tienda4");
   AddExit("sur",CIUDAD+"kilok9");
   AddExit("este",CIUDAD+"avcastle12");
   AddExit("oeste",CIUDAD+"avcastle10");
   AddItem(MONS+"guardia",REFRESH_DESTRUCT,1);
   SetLocate("Kha-annu");
}
