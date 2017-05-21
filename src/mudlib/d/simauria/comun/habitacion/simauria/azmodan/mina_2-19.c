/***********************************************************/
//	"mina_2-19"
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
SetIntLong(W("Estás al noroeste de una gran armería. Ves unos maniquíes"
" utilizados para montar armaduras sobre ellos, hay algunas armaduras destrozadas "
"y otras en mejor estado. Las columnas de piedra que sujetan el techo te impiden"
" ver todo lo que hay con claridad.\n"));
AddItem(ARMADURA_AZMODAN("cota"),REFRESH_REMOVE,1);
AddItem(ARMADURA_AZMODAN("cuero"),REFRESH_REMOVE,1);
AddExit("este",MINA_AZMODAN("mina_2-20"));
AddExit("sur",MINA_AZMODAN("mina_2-14"));
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
