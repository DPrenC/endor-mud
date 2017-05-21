/***********************************************************/
//	"mina_2-18"
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
SetIntLong(W("Estás en un angosto corredor, ves huesos en el suelo que han"
" sido roídos por ratas. Los orcos buscan algo en esta mina y no se trata "
"de oro... puedes suponer que buscan algo más importante por el despliegue de "
"fuerzas que han realizado. ¿Quién estará detrás de todo esto?\n"));
AddDetail(({"huesos"}),"Huesos de algún minero que trabajó aquí tiempo atrás.\n");
AddExit("sur",MINA_AZMODAN("mina_2-13"));
AddExit("norte",MINA_AZMODAN("mina_2-23"));
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
