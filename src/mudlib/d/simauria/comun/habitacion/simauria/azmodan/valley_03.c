/***********************************************************/
//	"valley_03"
//	Valle
//	11-12-01 : Creación -> Kodex
//	11-12-01 : Modificación -> Kodex
//
//
#include "./path.h"
inherit SIM_ROOM;


create() {
::create();
SetPreIntShort("en el");
SetIntShort("sur del valle");
SetIntLong(W("Esta zona del valle tiene menos vegetación, "
"aunque tiene unas bonitas flores que adornan el suelo. Es "
"un lugar tranquilo y apacible, un buen sitio para echarse a dormir.\n"));
SetIndoors(0);
SetIntNoise("Oyes pajarillos cantar.\n");
SetIntSmell("Huele a aire puro.\n");
AddDetail(({"flores"}),"Ves flores de todos los colores avanzando en hilera hacia el este.\n");
AddDetail(({"vegetación","vegetacion"}),"La vegetación es rica en este lugar.\n");
AddExit("oeste",VALLE_AZMODAN("valley_02"));
AddExit("norte",VALLE_AZMODAN("valley_07"));
AddExit("este",VALLE_AZMODAN("valley_04"));
SetLocate("Valle");
if (random(100) < 60)
	AddItem(NPC_AZMODAN("goblin"),REFRESH_DESTRUCT,1);
if (random(100) < 15)
	AddItem(NPC_AZMODAN("goblin"),REFRESH_DESTRUCT,1);
}