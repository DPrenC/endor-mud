/***********************************************************/
//	"mina_2-04"
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
SetIntLong(W("En esta zona del segundo nivel de la mina hay unas cadenas"
" metálicas en las paredes, y unos cráneos tirados por el suelo. Los "
"cráneos están rotos y hacen juego con el ambiente tétrico de este oscuro y "
"estrecho pasillo.\n"));
AddDetail(({"cadenas"}),"Cadenas rotas, nada más.\n");
AddDetail(({"cráneos","craneos"}),"Esto hace mucho tiempo eran cráneos.\n");
AddExit("oeste",MINA_AZMODAN("mina_2-03"));
AddExit("norte",MINA_AZMODAN("mina_2-07"));
if (random(100) < 50)
	{
		switch(random(3))
		{
		case 0 .. 1: AddItem(NPC_AZMODAN("uruk"),REFRESH_DESTRUCT,1);break;
		case 2: AddItem(NPC_AZMODAN("orco"),REFRESH_DESTRUCT,1); break;
		default: break;
		}
	}

}
