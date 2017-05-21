/***********************************************************/
//	"mina_3-17"
//	Mina abandonada
//	15-12-01 : Creación -> Kodex
//	15-12-01 : Modificación -> Kodex
//
//
#include "./path.h"
#include <rooms.h>
inherit STD_AZMODAN("mina");


create() {
::create();
SetIntShort("la tercera planta de la mina");
SetIntLong(W("Aquí el camino que viene el oeste se bifurca hacia el"
" norte y el sudeste. Hay un estandarte clavado el en suelo, está hecho "
"de cuero y tiene un dibujo de un lobo, debe ser el estandarte de un "
"clan orco de los que habitan la mina.\n"));
AddDetail(({"estandarte"}),"es el estandarte del clan Jhanzur.\n");
AddExit("sudeste",MINA_AZMODAN("mina_3-12"));
AddExit("oeste",MINA_AZMODAN("mina_3-16"));
AddExit("norte",MINA_AZMODAN("mina_3-21"));
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
