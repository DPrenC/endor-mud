/***********************************************************/
//	"mina_2-13"
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
SetIntLong(W("En este lado del pasillo ves unas piedras amontonadas "
"debido a un peque�o derrumbamiento, no te impiden moverte a trav�s "
"del conducto pero son bastante molestas. Las paredes est�n fr�as y "
"llevas tiempo sin ver el sol, no ser�a mala idea largarse de aqu�.\n"));
AddDetail(({"piedras"}),"Es un mont�n de piedras unas encima de otras.\n");
AddExit("norte",MINA_AZMODAN("mina_2-18"));
AddExit("oeste",MINA_AZMODAN("mina_2-12"));
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
