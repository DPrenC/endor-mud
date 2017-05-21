/***********************************************************/
//	"mina_3-18"
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
SetIntLong(W("Es esta zona de la mina ves una corriente de agua que va"
" de lado a lado, puede que lleve consigo diminutas pepitas de metales "
"preciosos, pero no tienes tiempo ni ganas de averiguarlo. El pasillo va "
"de norte a sur. Hacia el norte ves que aumenta la luz.\n"));
AddExit("sur",MINA_AZMODAN("mina_3-13"));
AddExit("norte",MINA_AZMODAN("mina_3-23"));
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
