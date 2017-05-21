/***********************************************************/
//	"mina_1-20"
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
SetIntLong(W("Ves una gran mesa de madera en el centro de la sala, aunque"
" excavado en la roca tiene todas las comodidades de un comedor. Ves una "
"gran mesa de madera, unos taburetes, armarios, etc. Incluso puedes ver los "
"restos de la ultima comida de los inquilinos de la mina.\n"));
AddDetail(({"restos"}),
W("Ves un montón de comida podrida... incluso piensas que parte de "
"esa comida puede empezar a moverse en cualquier momento.\n"));
AddDetail(({"mesa","mesa de madera"}),
W("Es una mesa alargada en la que pueden caber hasta "
"dieciseis comensales, veintidos si son goblins.\n"));
AddDetail(({"tabuerte","taburetes"}),
"Son taburetes de madera ideales para sentarse a la mesa.\n");
AddDetail(({"armarios"}),
W("Ves unos armarios con las puertas rotas y medio descolgadas "
"dentro solo tienen comida podrida... puaj!.\n"));
AddExit("oeste",MINA_AZMODAN("mina_1-19"));
AddExit("sur",MINA_AZMODAN("mina_1-15"));
AddExit("nordeste",MINA_AZMODAN("mina_1-24"));
		switch(random(3))
		{
		case 0 .. 1: AddItem(NPC_AZMODAN("orco"),REFRESH_DESTRUCT,1);break;
		case 2: AddItem(NPC_AZMODAN("goblin"),REFRESH_DESTRUCT,1); AddItem(NPC_AZMODAN("goblin"),REFRESH_DESTRUCT,1); break;
		default: break;
		}

}
