/***********************************************************/
//	"mina_3-02"
//	Mina abandonada
//	15-12-01 : Creaci�n -> Kodex
//	15-12-01 : Modificaci�n -> Kodex
//
//
#include "./path.h"
#include <rooms.h>
inherit STD_AZMODAN("mina");


create() {
::create();
SetIntShort("el tercer nivel de la mina");
SetIntLong(W("Est�s en una bifurcaci�n, a�n as� los orcos tambi�n han trabajado"
" aqu� picando las paredes y el suelo, te cuesta bastante moverte por aqu�. Al "
"noroeste puedes ver unas escaleras que suben a un nivel superior de la mina.\n"));
AddDetail(({"paredes","suelo"}),
"Las paredes y el suelo est�n llenos de marcas de picos y bastante destru�das.\n");
AddExit("noroeste",MINA_AZMODAN("mina_3-05"));
AddExit("norte",MINA_AZMODAN("mina_3-06"));
AddExit("este",MINA_AZMODAN("mina_3-03"));
if (random(100) < 50)
	{
		switch(random(2))
		{
		case 0: AddItem(NPC_AZMODAN("shaman"),REFRESH_DESTRUCT,1); break;
		case 1: AddItem(NPC_AZMODAN("uruk"),REFRESH_DESTRUCT,1); break;
		default: break;
		}
	}

}
