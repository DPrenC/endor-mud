/***********************************************************/
//	"mina_2-08"
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
SetIntShort("la segunda planta de la mina");
SetIntLong(W("Estás en un conducto algo más oscuro, ves rastros "
"de actividad alguien estuvo aquí recientemente extrayendo mineral, o "
"al menos eso es lo que parece. Es posible que no fuera mineral lo que "
"estaba buscando exactamente. El conducto se estrecha en dirección nordeste.\n"));
AddExit("nordeste",MINA_AZMODAN("mina_2-12"));
AddExit("oeste",MINA_AZMODAN("mina_2-07"));
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
