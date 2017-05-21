/***********************************************************/
//	"mina_2-15"
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
SetIntLong(W("Est�s al sudeste de una gran armer�a, la habitaci�n est� "
"adornada con columnas de piedra. Aqu� es donde los orcos guardan sus "
"armas y las armas de sus v�ctimas para usarlas en combate, se te pasa "
"por la cabeza... que tus armas podr�an estar aqu�!. Hacia el este tienes "
"un pasillo que sale de la armer�a.\n"));
AddItem(ARMA_AZMODAN("erizal"),REFRESH_REMOVE,1);
AddItem(ARMA_AZMODAN("daga"),REFRESH_REMOVE,1);
AddExit("norte",MINA_AZMODAN("mina_2-20"));
AddExit("oeste",MINA_AZMODAN("mina_2-14"));
AddExit("este",MINA_AZMODAN("mina_2-16"));
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
