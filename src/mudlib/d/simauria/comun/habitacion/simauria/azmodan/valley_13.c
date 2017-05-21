/***********************************************************/
//	"valley_13"
//	Valle
//	11-12-01 : Creaci�n -> Kodex
//	11-12-01 : Modificaci�n -> Kodex
//
//
#include "./path.h"
inherit SIM_ROOM;


create() {
::create();
SetIntShort("el noroeste del valle");
SetIntLong(W("Desde aqu� ves como el r�o que fluye al oeste del valle"
" se aleja y desaparece en el horizonte, hacia el norte ves una pared "
"rocosa con plantas saliendo por todas partes, puedes observar el resto "
"del valle desde su zona m�s al noroeste y s�lo contemplas un bello paisaje "
"natural, que sirve de morada a algunas criaturas indeseables.\n"));
SetIndoors(0);
SetIntNoise("No se oye nada.\n");
SetIntSmell("Huele a aire puro.\n");
AddDetail(({"r�o","r�o"}),
"El gran r�o del oeste del valle es lo que alimenta sus plantas y todo su ecosistema.\n");
AddExit("este",VALLE_AZMODAN("valley_14"));
AddExit("sur",VALLE_AZMODAN("valley_09"));
SetLocate("Valle");
if (random(100) < 60)
	AddItem(NPC_AZMODAN("goblin"),REFRESH_DESTRUCT,1);
if (random(100) < 15)
	AddItem(NPC_AZMODAN("goblin"),REFRESH_DESTRUCT,1);
}