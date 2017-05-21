/***********************************************************/
//	"mina_2-20"
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
SetIntLong(W("Estás al nordeste de una gran armería. En esta sala ves escudos"
" en las paredes, parecen bien anclados aunque quizá no estén todos anclados. "
"Ves restos de lámapras viejas en el suelo y marcas de una posible escaramuza "
"entre las columnas. Al nordeste se encuentra la salida de la armería.\n"));
AddItem(ARMA_AZMODAN("cimit2"),REFRESH_REMOVE,1);
AddItem(ARMADURA_AZMODAN("esc_mad"),REFRESH_REMOVE,1);
AddExit("oeste",MINA_AZMODAN("mina_2-19"));
AddExit("sur",MINA_AZMODAN("mina_2-15"));
AddExit("nordeste",MINA_AZMODAN("mina_2-24"));
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
