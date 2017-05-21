/***********************************************************/
//	"valley_07"
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
SetIntLong(W("Est�s en la zona centro del valle. La hierba es baja"
" y puedes ver claramente todo a tu alrededor. Al norte ves una peque�a "
"cascada natural, hacia las dem�s direcciones ves como se extiende el "
"valle con su verdosa vegetaci�n.\n"));
SetIndoors(0);
SetIntNoise("Oyes los p�jaros cantar.\n");
SetIntSmell("Huele a aire puro.\n");
AddDetail(({"vegetaci�n","vegetacion"}),"La vegetaci�n de los alrededores tiene un verdor caracter�stico.\n");
AddExit("oeste",VALLE_AZMODAN("valley_06"));
AddExit("este",VALLE_AZMODAN("valley_08"));
AddExit("norte",VALLE_AZMODAN("valley_11"));
AddExit("sur",VALLE_AZMODAN("valley_03"));
SetLocate("Valle");
if (random(100) < 60)
	AddItem(NPC_AZMODAN("goblin"),REFRESH_DESTRUCT,1);
if (random(100) < 15)
	AddItem(NPC_AZMODAN("goblin"),REFRESH_DESTRUCT,1);
}