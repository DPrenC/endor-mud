/***********************************************************/
//	"mina_2-18"
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
SetIntLong(W("Est�s en un angosto corredor, ves huesos en el suelo que han"
" sido ro�dos por ratas. Los orcos buscan algo en esta mina y no se trata "
"de oro... puedes suponer que buscan algo m�s importante por el despliegue de "
"fuerzas que han realizado. �Qui�n estar� detr�s de todo esto?\n"));
AddDetail(({"huesos"}),"Huesos de alg�n minero que trabaj� aqu� tiempo atr�s.\n");
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
