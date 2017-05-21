/***********************************************************/
//	"mina_2-15"
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
SetIntLong(W("Estás al sudeste de una gran armería, la habitación está "
"adornada con columnas de piedra. Aquí es donde los orcos guardan sus "
"armas y las armas de sus víctimas para usarlas en combate, se te pasa "
"por la cabeza... que tus armas podrían estar aquí!. Hacia el este tienes "
"un pasillo que sale de la armería.\n"));
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
