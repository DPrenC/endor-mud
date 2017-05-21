/***********************************************************/
//	"mina_2-07"
//	Mina abandonada
//	14-12-01 : Creación -> Kodex
//	14-12-01 : Modificación -> Kodex
//
//
#include "./path.h"
#include <rooms.h>
inherit STD_AZMODAN("mina");


create() {
::create();
SetIntShort("la segunda planta de la mina");
SetIntLong(W("A esta zona de la mina llegan tres conductos, al mirar"
" a tu alrededor ves una pequeña lagartija escalando la ennegrecida pared rocosa."
" También ves unas gotas de agua que caen del techo, debe haber un depósito subterraneo "
"o algo parecido cerca de aquí. Seguramente los orcos que viven en la mina utilicen "
"de alguna manera el agua de esos depósitos.\n"));
AddDetail(({"lagartija"}),
"La lagartija se siente observada y se mete rápidamente en una grieta.\n");
AddExit("norte",MINA_AZMODAN("mina_2-11"));
AddExit("este",MINA_AZMODAN("mina_2-08"));
AddExit("sur",MINA_AZMODAN("mina_2-04"));
if (random(100) < 50)
	{
		switch(random(3))
		{
		case 0 .. 1: AddItem(NPC_AZMODAN("uruk"),REFRESH_DESTRUCT,1); break;
		case 2: AddItem(NPC_AZMODAN("orco"),REFRESH_DESTRUCT,1); break;
		default: break;
		}
	}

}
