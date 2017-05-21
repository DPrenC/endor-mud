/***********************************************************/
//	"mina_3-15"
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
SetIntLong(W("Estás al sudeste de una gran sala de celebraciones, "
"ves unas lamparas clavadas a las paredes que desprende una luz rojiza "
"que envuelve la sala. Palos de madera, calaveras y huesos adornan el suelo "
"de la sala haciendo figuras o dibujos. Es una de las zonas más tétricas de la mina.\n"));
AddDetail(({"huesos","calaveras","palos"}),
"No sabes lo que significa pero se refieren a la magia negra y a las maldiciones.\n");
AddExit("norte",MINA_AZMODAN("mina_3-20"));
AddExit("este",MINA_AZMODAN("mina_3-16"));
AddExit("oeste",MINA_AZMODAN("mina_3-14"));
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
