/***********************************************************/
//	"mina_1-08"
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
SetIntLong(W("Est�s en el interior de un gran conducto rocoso"
", oyes agua chocar contra las rocas, debe pasar un r�o subterr�neo "
"por aqu� o algo parecido. Las fr�as paredes provocan una sensaci�n "
"de inseguridad, no hay muchas salidas obvias en caso de tener que huir.\n"));
AddExit("nordeste",MINA_AZMODAN("mina_1-12"));
AddExit("oeste",MINA_AZMODAN("mina_1-07"));
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
