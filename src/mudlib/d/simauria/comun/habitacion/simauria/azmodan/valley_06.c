/***********************************************************/
//	"valley_06"
//	Valle
//	11-12-01 : Creación -> Kodex
//	11-12-01 : Modificación -> Kodex
//
//
#include "./path.h"
inherit SIM_ROOM;


create() {
::create();
SetIntShort("el centro del valle");
SetIntLong(W("Estás en la zona centro del valle. La vegetación es"
" menos densa en esta parte, debe ser porque las otras zonas están "
"más cerca del río. Esta zona ha sido más transitada que el resto del "
"valle. Ves los restos de una hoguera y una madriguera.\n"));
SetIndoors(0);
SetIntNoise("Oyes los pájaros cantar.\n");
SetIntSmell("Huele a aire puro.\n");
AddDetail(({"madriguera"}),"Es la madriguera de un conejo.\n");
AddDetail(({"restos","hoguera"}),"Ves los restos calcinados de una hoguera alguien debió acampar aquí anoche.\n");
AddDetail(({"vegetación","vegetacion"}),"La vegetación de los alrededores tiene un verdor característico.\n");
AddExit("oeste",VALLE_AZMODAN("valley_05"));
AddExit("este",VALLE_AZMODAN("valley_07"));
AddExit("norte",VALLE_AZMODAN("valley_10"));
AddExit("sur",VALLE_AZMODAN("valley_02"));
SetLocate("Valle");
if (random(100) < 60)
	AddItem(NPC_AZMODAN("goblin"),REFRESH_DESTRUCT,1);
if (random(100) < 15)
	AddItem(NPC_AZMODAN("goblin"),REFRESH_DESTRUCT,1);
}