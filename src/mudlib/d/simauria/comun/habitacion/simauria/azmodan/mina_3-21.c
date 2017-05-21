/***********************************************************/
//	"mina_3-21"
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
SetIntLong(W("Desde aqu� puedes contemplar varios pasillos uno al sur que"
" est� bastante oscuro, otro al este que se ilumina un poco m�s y por �ltimo "
"el pasillo noroeste, en el que puedes ver como la apariencia de la mina cambia "
"de manera considerable. Es algo m�s habitable y menos rudimentario.\n"));
AddExit("noroeste",MINA_AZMODAN("mina_3-24"));
AddExit("este",MINA_AZMODAN("mina_3-22"));
AddExit("sur",MINA_AZMODAN("mina_3-17"));
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
