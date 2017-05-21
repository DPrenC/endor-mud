/***********************************************************/
//	"mina_3-12"
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
SetIntLong(W("Te encuentras en una sala de la mina, está ligeramente"
" más iluminada que el resto. Unos hilos de agua caen desde el techo "
"hasta el suelo deslizandose por la pared de la mina.\n"));
AddExit("suroeste",MINA_AZMODAN("mina_3-08"));
AddExit("noroeste",MINA_AZMODAN("mina_3-17"));
AddExit("este",MINA_AZMODAN("mina_3-13"));
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
