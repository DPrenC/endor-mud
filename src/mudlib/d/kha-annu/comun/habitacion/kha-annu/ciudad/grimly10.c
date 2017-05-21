#include "./path.h"

inherit KHA_ROOM;

create() {
   ::create();

   SetIntShort("la avenida Grimly.");
   SetIntLong(
"Al oeste de la Avenida puedes encontrar la Taberna del Pequenyo Dragon "
"Azul dando un tranquilo paseo por toda la calle. Varias farolas ilumian el "
"camino y un callejon se oscurece hacia el sur.\n");

   SetIntBright(80);
   SetIndoors(1);

   AddExit("sur",CIUDAD+"callejon5");
   AddExit("este",CIUDAD+"grimly11");
   AddExit("oeste",CIUDAD+"grimly9");

   SetLocate("Kha-annu");
}
