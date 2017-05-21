#include "./path.h"

inherit KHA_ROOM;

create() {
   ::create();

   SetIntShort("la avenida Grimly.");
   SetIntLong(
"Esta es la parte oeste de la Avenida Grimly, una zona tranquila en la que puedes "
"pasear y distraerte. Prueba de ello es la taberna situada al sur, bien conocida "
"por todos los habitantes de Kha-annu, bautizada con el nombre del 'pequeño "
"dragon azul'.\n");

   SetIntBright(80);
   SetIndoors(1);
   AddDetail("taberna",
   "Seguramente su aspecto sea mas llamativo en el interior.\n");

  AddExit("sur",TIENDAS+"taberna");
  AddExit("este",CIUDAD+"grimly2");
  AddExit("oeste",CIUDAD+"rurik1");
  SetLocate("Kha-annu");
}
