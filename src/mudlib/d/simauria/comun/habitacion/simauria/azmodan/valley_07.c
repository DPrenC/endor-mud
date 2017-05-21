/***********************************************************/
//	"valley_07"
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
SetIntLong(W("Estás en la zona centro del valle. La hierba es baja"
" y puedes ver claramente todo a tu alrededor. Al norte ves una pequeña "
"cascada natural, hacia las demás direcciones ves como se extiende el "
"valle con su verdosa vegetación.\n"));
SetIndoors(0);
SetIntNoise("Oyes los pájaros cantar.\n");
SetIntSmell("Huele a aire puro.\n");
AddDetail(({"vegetación","vegetacion"}),"La vegetación de los alrededores tiene un verdor característico.\n");
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