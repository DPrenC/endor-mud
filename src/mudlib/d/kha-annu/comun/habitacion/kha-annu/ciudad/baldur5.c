#include "./path.h"
inherit KHA_ROOM;
create() {
   ::create();

   SetIntShort("la calle de Baldur");
   SetIntLong(
"Caminas por la calle Baldur. Te encuentras en una zona muerta de la calle, "
"apenas si ves gente aqui. Los gremios estan situados a ambos lados de donde "
"te encuentras. Hacia el oeste puedes vislumbrar la silueta de la estatua "
"de una mujer.\n"
);
   SetIntBright(80);
   SetIndoors(1);
   AddDetail(({"gremio","gremios"}),
"Hacia el oeste esta la entrada al gremio de los guerreros y algo mas hacia "
"ves una capilla.\n");
   AddDetail(
({"lamparas","farola","antorcha","antorchas","farolas","luz"}),
"Son dos especie de antorchas, pero que no despiden gas ni llama alguna.\n");
   AddExit("este",CIUDAD+"baldur6");
   AddExit("oeste",CIUDAD+"baldur4");
   SetLocate("Kha-annu");
}