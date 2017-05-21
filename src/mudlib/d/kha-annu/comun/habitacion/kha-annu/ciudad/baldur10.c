#include "./path.h"
inherit KHA_ROOM;
create() {
   ::create();

   SetIntShort("la calle de Baldur");
   SetIntLong(
"Te encuentras en la calle Baldur, justo dentro de una caverna excavada en "
"la roca pura. Las farolas negras que ves por toda la calle, iluminan la cueva, "
"y la hacen algo menos tetrica de lo que parece. Hacia el norte, una bifurcacion "
"lleva a la calle Grimly.\n");
   SetIntBright(60);
   SetIndoors(1);
   AddDetail( ({"caverna","cueva","excavacion"}),
"Toda la parte este de la ciudad esta excavada a mano en la pared de la "
"montanya.\n");
   AddDetail(({"gremio","gremios"}),
"Un poco hacia el oeste se encuentra la entrada al gremio de clerigos, y por "
"esta misma calle en la misma direccion esta tambien el de guerreros.\n");
   AddDetail(
({"lamparas","farola","antorcha","antorchas","farolas","luz"}),
"Son dos especie de antorchas, pero que no despiden gas ni llama alguna.\n");
   AddExit("norte",CIUDAD+"callejon5");
   AddExit("este",CIUDAD+"baldur11");
   AddExit("oeste",CIUDAD+"baldur9");
   SetLocate("Kha-annu");
}