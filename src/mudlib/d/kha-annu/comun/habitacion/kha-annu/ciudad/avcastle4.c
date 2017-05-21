#include "./path.h"

inherit KHA_ROOM;

create() {
   ::create();

   SetIntShort("la avenida del castillo");
   SetIntLong(
"Circulando por la avenida del castillo llegas hasta la entrada de una "
"tienda. Tiene una fachada lujosa propia de la calle. Las farolas adornan "
"la avenida que fluye de este a oeste.\n");

AddDetail( ({"farola","farolas"}),
"Son unas farolas de unos cuatro metros hechas de hierro puro, adornadas con "
"todo tipo de grabados y tallas tanto es su mastil como en el farol.\n"
"Su mision es la iluminacion de toda la ciudad\n");

   SetIntBright(80);
   SetIndoors(1);

   AddExit("norte",CIUDAD+"tiendas/tienda2");
   AddExit("este",CIUDAD+"avcastle5");
   AddExit("oeste",CIUDAD+"avcastle3");
   SetLocate("Kha-annu");
}
