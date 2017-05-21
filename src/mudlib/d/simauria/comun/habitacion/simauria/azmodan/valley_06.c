/***********************************************************/
//	"valley_06"
//	Valle
//	11-12-01 : Creaci�n -> Kodex
//	11-12-01 : Modificaci�n -> Kodex
//
//
#include "./path.h"
inherit SIM_ROOM;


create() {
::create();
SetIntShort("el centro del valle");
SetIntLong(W("Est�s en la zona centro del valle. La vegetaci�n es"
" menos densa en esta parte, debe ser porque las otras zonas est�n "
"m�s cerca del r�o. Esta zona ha sido m�s transitada que el resto del "
"valle. Ves los restos de una hoguera y una madriguera.\n"));
SetIndoors(0);
SetIntNoise("Oyes los p�jaros cantar.\n");
SetIntSmell("Huele a aire puro.\n");
AddDetail(({"madriguera"}),"Es la madriguera de un conejo.\n");
AddDetail(({"restos","hoguera"}),"Ves los restos calcinados de una hoguera alguien debi� acampar aqu� anoche.\n");
AddDetail(({"vegetaci�n","vegetacion"}),"La vegetaci�n de los alrededores tiene un verdor caracter�stico.\n");
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