/***********************************************************/
//	"valley_14"
//	Valle
//	11-12-01 : Creaci�n -> Kodex
//	11-12-01 : Modificaci�n -> Kodex
//
//
#include "./path.h"
inherit SIM_ROOM;


create() {
::create();
SetIntShort("el norte del valle");
SetIntLong(W("Puedes tocar la pared rocosa que se extiende ante "
"ti ves unas extra�as runas enanas grabadas en ella, la vegetaci�n "
"te abruma y te das cuenta de que hay algo aqu� que no es obra de la "
"naturaleza, un cartel apuntando hacia el este.\n"));
SetIndoors(0);
SetIntNoise("No se oye nada.\n");
SetIntSmell("Huele a aire puro.\n");
AddDetail(({"runas","runas enanas"}),
W("Parecen unas runas grabadas con algun tipo de punz�n, "
"comienzas a leerlas y dice: \"Grutas de Azmodan\".\n"));
AddDetail(({"cartel"}),
"El cartel apunta hacia el este y en grandes letras pone: Mina.\n");
AddExit("oeste",VALLE_AZMODAN("valley_13"));
AddExit("este",VALLE_AZMODAN("valley_15"));
AddExit("sur",VALLE_AZMODAN("valley_10"));
SetLocate("Valle");
if (random(100) < 60)
	AddItem(NPC_AZMODAN("goblin"),REFRESH_DESTRUCT,1);
if (random(100) < 15)
	AddItem(NPC_AZMODAN("goblin"),REFRESH_DESTRUCT,1);
}