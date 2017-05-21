/***********************************************************/
//	"mina_2-14"
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
SetIntLong(W("Estás al suroeste de una gran armería, hay muchos tipos "
"de armas y armaduras. Los orcos ya establecidos aquí han tenido tiempo "
"de ordenar esto. En este lugar las rocas están pulidas para no suponer "
"peligro y ves firmes columnas de roca que sujetan el techo.\n"));
AddItem(ARMA_AZMODAN("cimit"),REFRESH_REMOVE,1);
AddItem(ARMA_AZMODAN("espada_corta"),REFRESH_REMOVE,1);
AddExit("norte",MINA_AZMODAN("mina_2-19"));
AddExit("sur",MINA_AZMODAN("mina_2-10"));
AddExit("este",MINA_AZMODAN("mina_2-15"));
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
