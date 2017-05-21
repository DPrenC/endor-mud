/***********************************************************/
//	"valley_16"
//	Valle
//	11-12-01 : Creación -> Kodex
//	11-12-01 : Modificación -> Kodex
//
//
#include "./path.h"
inherit SIM_ROOM;



create() {
::create();
SetIntShort("el noreste del valle");
SetIntLong(W("Estás en el noreste del valle de Azmodan, a tu alrededor la vegetación"
" casi no crece y no ves más que rocas, esta zona ha perdido el tono encantador "
"que tenía el resto del valle, debe ser porque es la zona más alejada de "
"los ríos, un mal presentimiento te recorre, puede que alguien esté observandote "
"desde algún lado.\n"));
SetIndoors(0);
SetIntNoise("No se oye nada.\n");
SetIntSmell("Huele a aire puro.\n");
AddExit("oeste",VALLE_AZMODAN("valley_15"));
AddExit("sur",VALLE_AZMODAN("valley_12"));
SetLocate("Valle");
if (random(100) < 60)
	AddItem(NPC_AZMODAN("goblin"),REFRESH_DESTRUCT,1);
if (random(100) < 15)
	AddItem(NPC_AZMODAN("goblin"),REFRESH_DESTRUCT,1);
}