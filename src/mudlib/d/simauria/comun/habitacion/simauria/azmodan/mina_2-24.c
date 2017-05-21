/***********************************************************/
//	"mina_2-24"
//	Mina abandonada
//	14-12-01 : Creaci�n -> Kodex
//	14-12-01 : Modificaci�n -> Kodex
//
//
#include "./path.h"
#include <rooms.h>
inherit STD_AZMODAN("mina");


create() {
::create();
SetIntShort("la segunda planta de la mina");
SetIntLong(W("Est�s en un cruce de corredores, es bastante extra�o"
". Despu�s de echar un vistazo no puedes estar seguro de donde viniste "
"para llegar hasta aqu�. El que planific� esta mina no le dedic� mucho "
"tiempo a tratar este tipo de cruces. Notas calor procedente del noroeste.\n"));
AddItem("/obj/torch",REFRESH_REMOVE,1);
AddExit("noroeste",MINA_AZMODAN("mina_2-26"));
AddExit("suroeste",MINA_AZMODAN("mina_2-20"));
AddExit("sudeste",MINA_AZMODAN("mina_2-21"));
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
