/***********************************************************/
//	"valley_05"
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
SetIntLong(W("Est�s al oeste del valle de Azmodan. M�s al oeste fluye un gran "
"r�o lleno de peces dando saltos, la vegetaci�n cerca del r�o es a�n "
"m�s rica aunque no demasiado, el valle se extiende en casi todas las "
"direcciones.\n"));
SetIndoors(0);
SetIntNoise("Oyes el sonido del agua.\n");
SetIntSmell("Huele a aire puro.\n");
AddDetail(({"r�o","r�o"}),"Es un gran r�o, parece bastante profundo, no puedes llegar hasta �l.\n");
AddDetail(({"vegetaci�n","vegetacion"}),"Cerca del r�o aumenta el nivel de vegetaci�n.\n");
AddDetail(({"peces"}),"Los peces del r�o dan saltos alegremente.\n");
AddExit("este",VALLE_AZMODAN("valley_06"));
AddExit("norte",VALLE_AZMODAN("valley_09"));
AddExit("sur",VALLE_AZMODAN("valley_01"));
SetLocate("Valle");
if (random(100) < 60)
	AddItem(NPC_AZMODAN("goblin"),REFRESH_DESTRUCT,1);
if (random(100) < 15)
	AddItem(NPC_AZMODAN("goblin"),REFRESH_DESTRUCT,1);
}