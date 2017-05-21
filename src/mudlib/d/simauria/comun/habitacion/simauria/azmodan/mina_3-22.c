/***********************************************************/
//	"mina_3-22"
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
SetIntLong(W("Te encuentras en un pasillo que va de este a oeste, "
"hay señales de que alguien ha estado trabajando esta zona de la mina "
"recientemente. Hacia el este aumenta considerablemente el nivel de luz y "
"también el calor. El frío de esta mina es algo que ya tienes asumido "
"y controlado.\n"));
AddExit("este",MINA_AZMODAN("mina_3-23"));
AddExit("oeste",MINA_AZMODAN("mina_3-21"));
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
