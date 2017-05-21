/***********************************************************/
//	"mina_3-24"
//	Mina abandonada
//	15-12-01 : Creaci�n -> Kodex
//	15-12-01 : Modificaci�n -> Kodex
//
//
#include "./path.h"
#include <rooms.h>
inherit STD_AZMODAN("mina");


create() {
::create();
SetIntShort("la tercera planta de la mina");
SetIntLong(W("Te encuentras en una sala que sirve de entrada a las"
" habitaciones de los l�deres que puedes ver si miras hacia delante"
". La habitaci�n del centro parece la m�s grandiosa desde fuera, "
"a los lados observas otras habitaciones menos espectaculares, pero "
"que tambi�n desentonan con el ambiente de la mina.\n"));
AddExit("noroeste",MINA_AZMODAN("mina_3-26"));
AddExit("norte",MINA_AZMODAN("mina_3-27"));
AddExit("nordeste",MINA_AZMODAN("mina_3-28"));
AddExit("suroeste",MINA_AZMODAN("mina_3-20"));
AddExit("sudeste",MINA_AZMODAN("mina_3-21"));
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
