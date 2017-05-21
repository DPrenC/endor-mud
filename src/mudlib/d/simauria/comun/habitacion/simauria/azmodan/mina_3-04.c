/***********************************************************/
//	"mina_3-04"
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
SetIntLong(W("Este pasillo de la mina va hacia el norte y hacia el "
"oeste. Ves un cubo de metal oxidado colgado en la pared y oyes el "
"incómodo sonido de una gotera que cae clop, clop, clop, lentamente "
"sobre el cubo metálico. Es insoportable!.\n"));
AddDetail(({"cubo"}),
"Es molesto pero si está ahí seguro que es para algo, será mejor dejarlo donde está.\n");
AddExit("norte",MINA_AZMODAN("mina_3-07"));
AddExit("oeste",MINA_AZMODAN("mina_3-03"));
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
