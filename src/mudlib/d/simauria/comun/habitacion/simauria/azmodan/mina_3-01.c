/***********************************************************/
//	"mina_3-01"
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
SetIntShort("la tercera planta de la mina");
SetIntLong(W("Ves indicios de que los orcos han estado excavando"
" aqu� recientemente, ves trozos de roca esparcidos por el suelo "
"y carros de mineral llenos de rocas sin valor.\n"));
AddDetail(({"carro","carros"}),
"Son carros viejos, no se utilizaban desde hacia cientos de a�os, pero "
"los orcos est�n buscando algo ahora.\n");
AddExit("norte",MINA_AZMODAN("mina_3-03"));
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
