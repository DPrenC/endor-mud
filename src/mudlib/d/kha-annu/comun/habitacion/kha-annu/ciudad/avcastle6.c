#include "./path.h"

inherit KHA_ROOM;

create() {
   ::create();

   SetIntShort("la avenida del castillo");
   SetIntLong(
"Continuas en la avenida del castillo, su nombre viene dado porque justo "
"aqui se encuentra al sur el jardin que llega hasta el castillo.\n"
"Al norte hay un pequeño callejon, al este y oeste continua la avenida.\n"
"Hay una placa 'dorada' justo al sur.\n");

   SetIntBright(80);
   SetIndoors(1);

   AddReadMsg(({"dorada","placa"}),
 "Lees en la placa dorada:\n" // [o] Esto define un cartel, nota o cualquier
 "Al oeste de aqui se encuentra el censo y el portal de los dioses.\n"
 "Al sur el gran castillo de Kha-annu.\n");

   AddExit("norte",CIUDAD+"callejon9");
   AddExit("sur",PISO1+"garden");
   AddExit("este",CIUDAD+"avcastle7");
   AddExit("oeste",CIUDAD+"avcastle5");
   SetLocate("Kha-annu");
}
