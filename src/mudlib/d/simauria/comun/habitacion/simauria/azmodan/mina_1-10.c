/***********************************************************/
//	"mina_1-10"
//	Mina abandonada
//	11-12-01 : Creación -> Kodex
//	11-12-01 : Modificación -> Kodex
//
//
#include "./path.h"
#include <rooms.h>
inherit STD_AZMODAN("mina");


create() {
::create();
SetIntShort("la primera planta de la mina");
SetIntLong(W("Te encuentras en mitad del conducto principal"
" que recorre la mina de norte a sur. Hacia el sur se encuentra "
"la salida de la mina, y hacia el norte llegas a un conducto "
"secundario que recorre la mina de este a oeste.\n"));
AddExit("sur",MINA_AZMODAN("mina_1-06"));
AddExit("norte",MINA_AZMODAN("mina_1-14"));
AddExit("oeste",MINA_AZMODAN("mina_1-09"));
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
