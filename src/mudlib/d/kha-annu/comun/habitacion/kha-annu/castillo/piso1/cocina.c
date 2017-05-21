/* Coded by Yandros to AURORA MUD.
   Modificado por [i] Izet@Simauria, para implemental a Nightfall(tm).
   Ultima modificacion: 9 Oct, 1997.
 */
#include "path.h"
#include <rooms.h>
#include <properties.h>
inherit KHA_ROOM;

create() {
::create();

SetIntShort("la cocina");

SetIntLong(
"Esta es la cocina del castillo. Es una cocina muy grande y todo esta muy "
"ordenado. De las paredes cuelgan cucharones, cuchillos, tenedores y sartenes.\n\
Ves un par de estantes llenos con extranya comida, casi parecen brebajes. Al "
"fondo de la cocina hay un hogar y sobre el fuego una gran olla.\n");

SetIntBright(80);

AddExit("oeste", PISO1+"bajada");

AddDetail("olla","Solo es una gran olla con un extranyo asado cocinandose.\n");
AddDetail(({"estante","estantes"}),
"Unas grandes estanterias llenas de potes llenos de quien sabe que.\n");
AddDetail(({"fuego","hogar","chimenea"}),
"El fuego del hogar calienta una gran olla.\n");
AddDetail("cocina",
"La cocina esta muy limpia. Todas las cosas estan relucientes aqui.\n");
SetIntSmell("La comida que se hace aqui huele muy rara, es casi repugnante.\n");
SetIntNoise(
"Al ponerte a escuchar, solo oyes el gorgoteo del asado calentándose al fuego.\n");
AddItem(MONS+"cocinero",REFRESH_DESTRUCT,1);
}
