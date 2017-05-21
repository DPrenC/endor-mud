/***********************************************************/
//	"mina_1-15"
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
SetIntLong(W("Estás al lado de una gran pila de desperdicios, ves"
" algunas ratas moviendose en la pila. Esta gran sala ha sido "
"utilizada para almacenar basuras, pero al norte puedes ver el "
"lugar donde los orcos se reúnen para comer.\n"));
AddExit("norte",MINA_AZMODAN("mina_1-20"));
AddExit("oeste",MINA_AZMODAN("mina_1-14"));
AddExit("este",MINA_AZMODAN("mina_1-16"));
		switch(random(3))
		{
		case 0 .. 1: AddItem(NPC_AZMODAN("orco"),REFRESH_DESTRUCT,1);break;
		case 2: AddItem(NPC_AZMODAN("goblin"),REFRESH_DESTRUCT,1); AddItem(NPC_AZMODAN("goblin"),REFRESH_DESTRUCT,1); break;
		default: break;
		}
}
