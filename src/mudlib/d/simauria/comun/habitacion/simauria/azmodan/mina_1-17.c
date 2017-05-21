/***********************************************************/
//	"mina_1-17"
//	Mina abandonada
//	11-12-01 : Creaci�n -> Kodex
//	11-12-01 : Modificaci�n -> Kodex
//
//
#include "./path.h"
#include <rooms.h>
inherit STD_AZMODAN("mina");


create() {
::create();
SetIntShort("la primera planta de la mina");
SetIntLong(W("Est�s en un curce de corredores, los tres pasillos"
" que comunican aqu� est�n muy oscuros pero la ligera impresi�n "
"de que el camino del sur est� algo m�s iluminado. Sientes que "
"las rocas a tu alrededor se encogen para atraparte, ser minero debe "
"ser un trabajo muy duro, por suerte no has venido aqu� a extraer mineral "
"y los moradores no estar�an contentos si les quitases lo poco que queda en la mina.\n"));
AddExit("sudeste",MINA_AZMODAN("mina_1-12"));
AddExit("norte",MINA_AZMODAN("mina_1-21"));
AddExit("oeste",MINA_AZMODAN("mina_1-16"));
if (random(100) < 50)
	{
		switch(random(3))
		{
		case 0 .. 1: AddItem(NPC_AZMODAN("orco"),REFRESH_DESTRUCT,1);break;
		case 2: AddItem(NPC_AZMODAN("goblin"),REFRESH_DESTRUCT,1); AddItem(NPC_AZMODAN("goblin"),REFRESH_DESTRUCT,1); break;
		default: break;
		}
	}

}
