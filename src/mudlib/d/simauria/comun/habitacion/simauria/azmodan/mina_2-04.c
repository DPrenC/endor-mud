/***********************************************************/
//	"mina_2-04"
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
SetIntLong(W("En esta zona del segundo nivel de la mina hay unas cadenas"
" met�licas en las paredes, y unos cr�neos tirados por el suelo. Los "
"cr�neos est�n rotos y hacen juego con el ambiente t�trico de este oscuro y "
"estrecho pasillo.\n"));
AddDetail(({"cadenas"}),"Cadenas rotas, nada m�s.\n");
AddDetail(({"cr�neos","craneos"}),"Esto hace mucho tiempo eran cr�neos.\n");
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
