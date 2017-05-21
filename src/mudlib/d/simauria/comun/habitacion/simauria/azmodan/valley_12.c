/***********************************************************/
//	"valley_12"
//	Valle
//	11-12-01 : Creación -> Kodex
//	11-12-01 : Modificación -> Kodex
//
//
#include "./path.h"
inherit SIM_ROOM;


create() {
::create();
SetIntShort("el este del valle");
SetIntLong(W("Ves un camino hecho por alguien hace tiempo que va en dirección"
" oeste, si te fijas puedes ver algo parecido a una fuente natural. Además "
"del camino ves unas rocas a montonadas recubiertas de musgo y hierba baja "
"por el resto de esta zona del valle.\n"));
SetIndoors(0);
SetIntNoise("No se oye nada.\n");
SetIntSmell("Huele a aire puro.\n");
AddDetail(({"camino"}),
W("Es una zona donde la hierba ha sido tan pisoteada que ya no queda verde, sino un "
"camino de tierra de color oscuro.\n"));
AddExit("oeste",VALLE_AZMODAN("valley_11"));
AddExit("norte",VALLE_AZMODAN("valley_16"));
AddExit("sur",VALLE_AZMODAN("valley_08"));
SetLocate("Valle");
if (random(100) < 60)
	AddItem(NPC_AZMODAN("goblin"),REFRESH_DESTRUCT,1);
if (random(100) < 15)
	AddItem(NPC_AZMODAN("goblin"),REFRESH_DESTRUCT,1);
}