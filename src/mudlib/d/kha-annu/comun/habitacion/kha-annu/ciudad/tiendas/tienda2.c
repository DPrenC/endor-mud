#include "./path.h"
inherit "/room/herreria";
create() {
   ::create();

   SetIntShort("una tienda");
   SetIntLong(
"Estas en la herreria de la ciudad. Hay varias herramientas de trabajo ordenadas "
"cerca de una mesa. Si lo deseas, puedes reparar tu equipo en esta tienda.\n");

   SetIntBright(70);
   SetIndoors(1);
  AddDetail(({"herramientas","herramientas de trabajo","varias herramientas",
  "varias herramientas de trabajo"}),
  "Son de diverso tipo y se usan para reparar armas y armaduras.\n");
  AddDetail(({"mesa","mesa de trabajo"}),
  "Es una gran mesa de piedra donde Yako trabaja.\n");

  AddExit("norte",CIUDAD+"antha4");
   AddExit("sur",CIUDAD+"avcastle4");

  SetLocate("Kha-annu");
  SetShopkeeper(MONS+"yako");
}