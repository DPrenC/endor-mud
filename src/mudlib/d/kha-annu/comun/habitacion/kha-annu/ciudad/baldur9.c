#include "./path.h"
inherit KHA_ROOM;
create() {
   ::create();

   SetIntShort("la calle de Baldur");
   SetIntLong(
"La calle cambia aqui, y te adentras en una especie de cavernas escavadas a "
"mano. Ahora te encuentras en la parte este cavada en la montanya. El lugar "
"esta iluminado por las mismas farolas negras en toda la calle, ya que de "
"no ser asi este seria un sitio bastante tetrico.\n");
   SetIntBright(60);
   SetIndoors(1);
   AddDetail( ({"caverna","cueva","excavacion"}),
"Toda la parte este de la ciudad esta excavada a mano en la pared de la "
"montanya.\n");
   AddDetail(({"gremio","gremios"}),
"Hacia el oeste esta la entrada al gremio de los guerreros y un poco mas hacia "
"el oeste ves un portal que conduce al de clerigos.\n");
   AddDetail(
({"lamparas","farola","antorcha","antorchas","farolas","luz"}),
"Son dos especie de antorchas, pero que no despiden gas ni llama alguna.\n");
   AddExit("este",CIUDAD+"baldur10");
   AddExit("oeste",CIUDAD+"baldur8");
   SetLocate("Kha-annu");
}