/***********************************************************/
//	"mina_1-13"
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
SetIntLong(W("En este lugar ves un yacimiento poco explotado,"
" pero al fijarte mejor te das cuenta que no hay nada que explotar. "
"Si esta mina albergó minerales alguna vez eso fue hace mucho, mucho "
"tiempo. Algunas rocas te molestan para avanzar pero no suponen "
"un impedimento.\n"));
AddExit("oeste",MINA_AZMODAN("mina_1-12"));
AddExit("norte",MINA_AZMODAN("mina_1-18"));
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
