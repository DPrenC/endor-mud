/***********************************************************/
//	"mina_1-05"
//	Mina abandonada
//	10-12-01 : Creaci�n -> Kodex
//	10-12-01 : Modificaci�n -> Kodex
//
//
#include "./path.h"
#include <rooms.h>
inherit STD_AZMODAN("mina");


create() {
::create();
SetIntShort("la primera planta de la mina");
SetIntLong(W("Es una zona donde el mineral ha sido "
"bien extra�do, no queda ni rastro de nada que pueda "
"tener alg�n valor, incluso la roca est� tan ara�ada que no "
"sirve absolutamente para nada.\n"));
AddExit("sudeste",MINA_AZMODAN("mina_1-02"));
AddExit("norte",MINA_AZMODAN("mina_1-09"));
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
