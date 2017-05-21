#include "./path.h"
inherit KHA_ROOM;

create() {
   ::create();

   SetIntShort("la avenida Grimly");
   SetIntLong(
"El cruce entre la Avenida Grimly y la calle Kilok no es una de las zonas mas "
"interesantes de Kha-annu, pero es un buen punto de partida hacia la posada "
"y la taberna de los dragones. Varias farolas negras iluminan el lugar.\n");
   SetIntBright(80);
   SetIndoors(1);
   AddDetail(({"farolas","farolas negras"}),
"Tienen su encanto, aunque solo tengan una utilidad... iluminar el lugar.\n");

   AddExit("sur",CIUDAD+"kilok1");
   AddExit("oeste",CIUDAD+"grimly11");

   SetLocate("Kha-annu");
}
