/***********************************************************/
//	"valley_02"
//	Valle
//	11-12-01 : Creaci�n -> Kodex
//	11-12-01 : Modificaci�n -> Kodex
//
//
#include "./path.h"
inherit SIM_ROOM;


create() {
::create();
SetIntShort("el sur del valle");
SetIntLong(W("Ves vegetaci�n a tu alrededor, la hierba verde recubre "
"el suelo, es un lugar ideal para tumbarse a descansar sino fuera por "
"esas pisadas recientes en el suelo que te hacen estar alerta.\n"));
SetIndoors(0);
SetIntNoise("Oyes pajarillos cantar.\n");
SetIntSmell("Huele a aire puro.\n");
AddDetail(({"vegetaci�n","vegetacion"}),"La vegetaci�n es rica en este lugar.\n");
AddDetail(({"pisadas"}),"No son de un animal...\n");
AddExit("oeste",VALLE_AZMODAN("valley_01"));
AddExit("norte",VALLE_AZMODAN("valley_06"));
AddExit("este",VALLE_AZMODAN("valley_03"));
SetLocate("Valle");
if (random(100) < 60)
	AddItem(NPC_AZMODAN("goblin"),REFRESH_DESTRUCT,1);
if (random(100) < 15)
	AddItem(NPC_AZMODAN("goblin"),REFRESH_DESTRUCT,1);

}