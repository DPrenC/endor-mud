/***********************************************************/
//	"mina_1-21"
//	Mina abandonada
//	11-12-01 : Creaci�n -> Kodex
//	11-12-01 : Modificaci�n -> Kodex
//
//
#include "./path.h"
#include <rooms.h>
inherit STD_AZMODAN("mina");


create() {
::create();
SetIntShort("la primera planta de la mina");
SetIntLong(W("Est�s en una bifurcaci�n de tres caminos, te preguntas "
"por qu� ten�an que darle tantas vueltas a los mineros. El camino m�s "
"oscuro es del noroeste, pero los otros tampoco tienen muy buena pinta. Unas "
"piedrecillas caen por la pared de roca, te viene a la cabeza la belleza del "
"valle y te preguntas por qu� est�s metido en esta oscura caverna...\n"));
AddExit("este",MINA_AZMODAN("mina_1-22"));
AddExit("noroeste",MINA_AZMODAN("mina_1-24"));
AddExit("sur",MINA_AZMODAN("mina_1-17"));
if (random(100) < 50)
	{
		switch(random(3))
		{
		case 0 .. 1: AddItem(NPC_AZMODAN("orco"),REFRESH_DESTRUCT,1);break;
		case 2: AddItem(NPC_AZMODAN("goblin"),REFRESH_DESTRUCT,1); AddItem(NPC_AZMODAN("goblin"),REFRESH_DESTRUCT,1); break;
		default: break;
		}
	}

}