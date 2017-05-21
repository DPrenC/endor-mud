/***********************************************************/
//	"mina_2-26"
//	Mina abandonada
//	14-12-01 : Creación -> Kodex
//	14-12-01 : Modificación -> Kodex
//
//
#include "./path.h"
#include <rooms.h>
inherit STD_AZMODAN("mina");


create() {
::create();
SetIntShort("la segundo nivel de la mina");
SetIntLong(W("Estás en una pequeña sala donde se ha improvisado una herrería"
". Excavado en la roca hay un alto horno que debe llevar fuera de funcionamiento "
"cientos de años. También hay un gran yunque adornando la habitación, está todo "
"resquebrajado y ya no sirve para nada. Encuentras un martillo de herrería "
"encadenado al yunque.\n"));
AddExit("sudeste",MINA_AZMODAN("mina_2-24"));
if (random(100) < 50)
	{
		switch(random(3))
		{
		case 0 .. 1: AddItem(NPC_AZMODAN("uruk"),REFRESH_DESTRUCT,1); break;
		case 2: AddItem(NPC_AZMODAN("orco"),REFRESH_DESTRUCT,1); break;
		default: break;
		}
	}

}
