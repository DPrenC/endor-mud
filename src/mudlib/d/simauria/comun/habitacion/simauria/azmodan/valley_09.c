/***********************************************************/
//	"valley_09"
//	Valle
//	11-12-01 : Creaci�n -> Kodex
//	11-12-01 : Modificaci�n -> Kodex
//
//
#include "./path.h"
inherit SIM_ROOM;


create() {
::create();
SetIntShort("el oeste del valle");
SetIntLong(W("A pesar de estar cerca del r�o ya no lo oyes con "
"tanta claridad como en otras zonas del oeste del valle, apenas "
"hay matorrales en esta zona pero abunda la hierba baja. "
"El suelo bajo tus pies est� h�medo y es f�cil dejar huella, "
"ves unas pisadas a tu alrededor.\n"));
SetIndoors(0);
SetIntNoise("Oyes los p�jaros cantar.\n");
SetIntSmell("Huele a aire puro.\n");
AddDetail(({"pisadas"}),"Ves unas pisadas sospechosas, sigues su recorrido con la mirada y te das cuenta de que acaban en tus pies!!!.\n");
AddExit("este",VALLE_AZMODAN("valley_10"));
AddExit("norte",VALLE_AZMODAN("valley_13"));
AddExit("sur",VALLE_AZMODAN("valley_05"));
SetLocate("Valle");
if (random(100) < 60)
	AddItem(NPC_AZMODAN("goblin"),REFRESH_DESTRUCT,1);
if (random(100) < 15)
	AddItem(NPC_AZMODAN("goblin"),REFRESH_DESTRUCT,1);
}