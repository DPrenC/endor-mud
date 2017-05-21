/***********************************************************/
//	"mina_3-14"
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
SetIntLong(W("Estás al suroeste de una gran sala de celebraciones, "
"no está nada adornada solo hay calaveras huesos y palos de madera "
"fuertemente clavados. Solo se te vienen a la mente rituales oscuros "
"de magia negra. Tienes ganas de abandonar esta sala que continua al "
"norte y al este.\n"));
AddDetail(({"huesos","calaveras","palos"}),
"No sabes lo que significa pero se refieren a la magia negra y a las maldiciones.\n");
AddExit("norte",MINA_AZMODAN("mina_3-19"));
AddExit("este",MINA_AZMODAN("mina_3-15"));
AddExit("sur",MINA_AZMODAN("mina_3-10"));
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
