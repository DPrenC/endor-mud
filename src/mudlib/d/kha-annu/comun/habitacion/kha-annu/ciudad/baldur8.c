#include "./path.h"
inherit KHA_ROOM;
create() {
   ::create();

   SetIntShort("la calle de Baldur");
   SetIntLong(
"Has llegado a la entrada de la Sagrada Capilla en la ciudadela. Hacia "
"el norte ves el portal que conduce al interior. Este portal esta adornado "
"con tapices que representan a todos y cada uno de los dioses de los enanos, "
"que otorgan una infima parte de sus poderes a los enanos que pertenecen a "
"esta santa capilla.\n");
   SetIntBright(80);
   SetIndoors(1);
   AddDetail(({"portal","tapiz","tapices"}),
"Ves siete tapices adornando el hermoso portal de piedra de la entrada del "
"gremio. Los tapices representan a los cinco dioses adorados por los enanos.\n"
"Son los dioses de la Tierra, el Agua, el Fuego, los Vientos y la Destruccion.\n");
   AddDetail(({"gremio","gremios"}),
"Hacia el oeste esta la entrada al gremio de los guerreros y un poco mas hacia "
"el norte ves un portal que conduce al de clerigos.\n");
   AddDetail(
({"lamparas","farola","antorcha","antorchas","farolas","luz"}),
"Son dos especie de antorchas, pero que no despiden gas ni llama alguna.\n");
   AddExit("norte",CIUDAD+"iglesia");
   AddExit("este",CIUDAD+"baldur9");
   AddExit("oeste",CIUDAD+"baldur7");
   SetLocate("Kha-annu");
}