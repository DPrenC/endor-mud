#include "./path.h"
inherit KHA_ROOM;
create() {
   ::create();

   SetIntShort("la calle de Baldur");
   SetIntLong(
"Sigues caminando por la calle Baldur. Esta es una zona muerta de la ciudad.\n"
"Hacia el oeste logras divisar un desvio hacia el norte que comunica esta "
"calle con la Avenida Grimly, que corre pararela. Un poco mas hacia el este "
"puedes ver la entrada a una capilla.\n");
   SetIntBright(80);
   SetIndoors(1);
   AddDetail(({"gremio","gremios"}),
"Hacia el oeste esta la entrada al gremio de los guerreros y un poco mas hacia "
"el oeste ves una capilla.\n");
   AddDetail(
({"lamparas","farola","antorcha","antorchas","farolas","luz"}),
"Son dos especie de antorchas, pero que no despiden gas ni llama alguna.\n");
   AddExit("este",CIUDAD+"baldur8");
   AddExit("oeste",CIUDAD+"baldur6");
   SetLocate("Kha-annu");
}