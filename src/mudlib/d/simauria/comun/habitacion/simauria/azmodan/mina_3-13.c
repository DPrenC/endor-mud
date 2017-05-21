/***********************************************************/
//	"mina_3-13"
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
SetIntLong(W("Entre las paredes rocosas de este tercer nivel de la "
"mina ves un montoncito de huesos pequeños, huele a carne podrida y "
"hay algunas prendas de ropa viejas justo al lado. El suelo está "
"lleno de rocas desprendidas y tus pies sufren al moverte por aquí.\n"));
AddDetail(({"ropa","ropas"}),
"Es ropa vieja y destrozada.\n");
AddDetail(({"huesos"}),
"Parecen huesos de animales, seguramente restos de alguna comida.\n");
AddExit("norte",MINA_AZMODAN("mina_3-18"));
AddExit("oeste",MINA_AZMODAN("mina_3-12"));
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
