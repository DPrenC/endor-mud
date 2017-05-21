/***********************************************************/
//	"valley_08"
//	Valle
//	11-12-01 : Creaci�n -> Kodex
//	11-12-01 : Modificaci�n -> Kodex
//
//
#include "./path.h"
inherit SIM_ROOM;


create() {
::create();
SetIntShort("el este del valle");
SetIntLong(W("Contemplas la zona este del valle, la visi�n del"
" paisaje te produce una sensaci�n de bienestar muy agradable. "
"Todo tranquilo, peque�os animales correteando por el suelo, la "
"brisa moviendo las hojas de los matorrales, parece un lugar de ensue�o.\n"));
SetIndoors(0);
SetIntNoise("Oyes los p�jaros cantar.\n");
SetIntSmell("Huele a aire puro.\n");
AddDetail(({"matorrales"}),"Son la vegetaci�n que abunda por el valle.\n");
AddDetail(({"animales"}),"Una ardilla sale corriendo y se oculta de repente.\n");
AddExit("oeste",VALLE_AZMODAN("valley_07"));
AddExit("norte",VALLE_AZMODAN("valley_12"));
AddExit("sur",VALLE_AZMODAN("valley_04"));
SetLocate("Valle");
if (random(100) < 60)
	AddItem(NPC_AZMODAN("goblin"),REFRESH_DESTRUCT,1);
if (random(100) < 15)
	AddItem(NPC_AZMODAN("goblin"),REFRESH_DESTRUCT,1);
}