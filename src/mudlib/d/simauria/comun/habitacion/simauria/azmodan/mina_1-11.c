/***********************************************************/
//	"mina_1-11"
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
SetIntLong(W("Estás dentro de un pasillo muy estrecho, sientes "
"que necesitas estirar los brazos y las piernas, este lugar no "
"te da mucha libertad de movimiento. Las paredes rocosas tienen "
"algunos salientes que pueden ser peligrosos si chocas contra ellos.\n"));
AddExit("sur",MINA_AZMODAN("mina_1-07"));
AddExit("norte",MINA_AZMODAN("mina_1-16"));
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
