/***********************************************************/
//	"mina_1-04"
//	Mina abandonada
//	10-12-01 : Creación -> Kodex
//	10-12-01 : Modificación -> Kodex
//
//
#include "./path.h"
#include <rooms.h>
inherit STD_AZMODAN("mina");


create()
{
::create();
SetIntShort("la primera planta de la mina");
SetIntLong(W("Estás en un pequeño pasillo que comunica"
" la entrada de la mina con una zona de excavación. Hace "
"mucho tiempo por este pasillo corrían los carros llenos de "
"mithril, hoy la mina sirve de guarida a criaturas "
"siniestras... orcos!.\n"));
AddExit("oeste",MINA_AZMODAN("mina_1-03"));
AddExit("norte",MINA_AZMODAN("mina_1-07"));
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