/***********************************************************/
//	"valley_10"
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
SetIntLong(W("Estás en la zona centro del valle escuchas el sonido "
"de agua proveniente del este, lejos al norte divisas una pared rocosa y "
"a tu alrededor ves plantas exóticas situadas alrededor de pequeños charcos "
"de agua, la belleza del lugar es increíble.\n"));
SetIndoors(0);
SetIntNoise("Oyes los pájaros cantar.\n");
SetIntSmell("Huele a aire puro.\n");
AddDetail(({"plantas"}),
W("Son plantas grandes con hojas anchas que se arquean a medida que suben, "
"nunca habías visto nada igual.\n"));
AddExit("oeste",VALLE_AZMODAN("valley_09"));
AddExit("este",VALLE_AZMODAN("valley_11"));
AddExit("norte",VALLE_AZMODAN("valley_14"));
AddExit("sur",VALLE_AZMODAN("valley_06"));
SetLocate("Valle");
if (random(100) < 60)
	AddItem(NPC_AZMODAN("goblin"),REFRESH_DESTRUCT,1);
if (random(100) < 15)
	AddItem(NPC_AZMODAN("goblin"),REFRESH_DESTRUCT,1);
}