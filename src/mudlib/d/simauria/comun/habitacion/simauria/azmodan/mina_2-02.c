/***********************************************************/
//	"mina_2-02"
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
SetIntLong(W("Est�s en un pasillo que da a otros dos, hay algo"
" m�s de luz debido a la confluencia de pasillos. Unas vigas de "
"madera est�n puestas a los lados supuestamente para sujetar el techo"
", pero sinceramente no crees que sirvan de mucho.\n"));
AddDetail(({"vigas","vigas de madera"}),"Son demasiado viejas como para ser seguras.\n");
AddExit("norte",MINA_AZMODAN("mina_2-06"));
AddExit("este",MINA_AZMODAN("mina_2-03"));
AddExit("noroeste",MINA_AZMODAN("mina_2-05"));
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
