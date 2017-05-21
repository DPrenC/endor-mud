/***********************************************************/
//	"mina_1-17"
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
SetIntLong(W("Estás en un curce de corredores, los tres pasillos"
" que comunican aquí están muy oscuros pero la ligera impresión "
"de que el camino del sur está algo más iluminado. Sientes que "
"las rocas a tu alrededor se encogen para atraparte, ser minero debe "
"ser un trabajo muy duro, por suerte no has venido aquí a extraer mineral "
"y los moradores no estarían contentos si les quitases lo poco que queda en la mina.\n"));
AddExit("sudeste",MINA_AZMODAN("mina_1-12"));
AddExit("norte",MINA_AZMODAN("mina_1-21"));
AddExit("oeste",MINA_AZMODAN("mina_1-16"));
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
