/***********************************************************/
//	"mina_1-07"
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
SetIntLong(W("Te encuentras en una bifurcaci�n, hay un"
" cartel se�alando al este y tiene algo escrito en una "
"lengua que no conoces, no sabes si all� te espera algo "
"bueno... o algo malo, est� bastante oscuro y ver tanta "
"roca por todas partes est� empezando a afectarte a la cabeza.\n"));
AddExit("sur",MINA_AZMODAN("mina_1-04"));
AddExit("este",MINA_AZMODAN("mina_1-08"));
AddExit("norte",MINA_AZMODAN("mina_1-11"));
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
