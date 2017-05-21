#include "./path.h"
inherit KHA_ROOM;
create() {
   ::create();

   SetIntShort("la calle de Baldur");
   SetIntLong(
"Caminando por la calle Baldur llegas a un cruce. Hacia el norte una calle "
"comunica Baldur con la Avenida Grimly, nombre de un antiguo guerrero "
"enano que termino con las vidas de cientos de seres al servicio de la "
"oscuridad. Hacia el este continua la calle Baldur.\n" );
   SetIntBright(80);
   SetIndoors(1);
   AddDetail(({"gremio","gremios"}),
"Hacia el oeste esta la entrada al gremio de los guerreros y algo mas hacia "
"el este ves el de clerigos.\n");
   AddDetail(
({"lamparas","farola","antorcha","antorchas","farolas","luz"}),
"Son dos especie de antorchas, pero que no despiden gas ni llama alguna.\n");
   AddExit("norte",CIUDAD+"cruce1");
  AddExit("sur",PUERTASUR+"gorin2");
   AddExit("este",CIUDAD+"baldur7");
   AddExit("oeste",CIUDAD+"baldur5");
   SetLocate("Kha-annu");
}