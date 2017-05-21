/***********************************************************/
//	"mina_2-17"
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
SetIntLong(W("Te encuentras en un cruce de corredores, aqu� los caminos se bifurcan"
" para conectar diversos puntos de la mina. En las paredes hay marcas de golpes con "
"picos, esta deb�a ser una de las principales zonas de extracci�n de mineral, aunque "
"en esta mina hace ya mucho tiempo que se dej� de buscar mineral, los orcos no han venido "
"para hacer de mineros... son guerreros!.\n"));
AddExit("sudeste",MINA_AZMODAN("mina_2-12"));
AddExit("norte",MINA_AZMODAN("mina_2-21"));
AddExit("oeste",MINA_AZMODAN("mina_2-16"));
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
