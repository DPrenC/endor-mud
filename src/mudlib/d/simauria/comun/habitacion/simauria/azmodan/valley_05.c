/***********************************************************/
//	"valley_05"
//	Valle
//	11-12-01 : Creación -> Kodex
//	11-12-01 : Modificación -> Kodex
//
//
#include "./path.h"
inherit SIM_ROOM;


create() {
::create();
SetIntShort("el oeste del valle");
SetIntLong(W("Estás al oeste del valle de Azmodan. Más al oeste fluye un gran "
"río lleno de peces dando saltos, la vegetación cerca del río es aún "
"más rica aunque no demasiado, el valle se extiende en casi todas las "
"direcciones.\n"));
SetIndoors(0);
SetIntNoise("Oyes el sonido del agua.\n");
SetIntSmell("Huele a aire puro.\n");
AddDetail(({"río","río"}),"Es un gran río, parece bastante profundo, no puedes llegar hasta él.\n");
AddDetail(({"vegetación","vegetacion"}),"Cerca del río aumenta el nivel de vegetación.\n");
AddDetail(({"peces"}),"Los peces del río dan saltos alegremente.\n");
AddExit("este",VALLE_AZMODAN("valley_06"));
AddExit("norte",VALLE_AZMODAN("valley_09"));
AddExit("sur",VALLE_AZMODAN("valley_01"));
SetLocate("Valle");
if (random(100) < 60)
	AddItem(NPC_AZMODAN("goblin"),REFRESH_DESTRUCT,1);
if (random(100) < 15)
	AddItem(NPC_AZMODAN("goblin"),REFRESH_DESTRUCT,1);
}