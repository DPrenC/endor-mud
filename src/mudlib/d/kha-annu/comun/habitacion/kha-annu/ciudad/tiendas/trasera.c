#include "./path.h"

inherit KHA_ROOM;

create() {
   ::create();

   SetIntShort("la parte trasera de la tienda de Zanul");
   SetIntLong(
"Te encuentras en la parte trasera de la tienda de Zanul. Es unoscuro callejon "
"en el que Zanul arroja los desperdicios para que sean recogidos por el "
"servicio de limpieza.\n");

   SetIntBright(50);
   SetIndoors(1);
  AddItem(MONS+"raton",REFRESH_DESTRUCT,1);
  AddExit("sur",CIUDAD+"avcastle2");
  AddExit("oeste",CIUDAD+"tiendas/tienda1");
/*
  AddDoor("zanul","oeste",CIUDAD+"tiendas/tienda1","puerta trasera",
          "Es la puerta trasera de la tienda de armas de Zanul.\n"
          );
*/

  SetLocate("Kha-annu");
}