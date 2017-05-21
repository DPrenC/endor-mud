/***********************************************************/
//	"mina_3-11"
//	Mina abandonada
//	15-12-01 : Creaci�n -> Kodex
//	15-12-01 : Modificaci�n -> Kodex
//
//
#include "./path.h"
#include <rooms.h>
inherit STD_AZMODAN("mina");


create() {
::create();
SetIntShort("la tercera planta de la mina");
SetIntLong(W("Est�s en un largo corredor que no ha sido utilizado para picar,"
" los orcos lo han dejado intacto por alguna raz�n. Es posible que sea por una "
"inscripci�n que tiene en una de las paredes. El pasillo continua de norte a sur.\n"));
AddDetail(({"inscripci�n","inscripcion"}),
"Lees la inscripci�n y dice: \"Jam�s lo encontrareis, marchaos de aqu� por que los"
" m�os vendr�n a vengarme!\".\n");
AddExit("sur",MINA_AZMODAN("mina_3-07"));
AddExit("norte",MINA_AZMODAN("mina_3-16"));
if (random(100) < 50)
	{
		switch(random(2))
		{
		case 0: AddItem(NPC_AZMODAN("shaman"),REFRESH_DESTRUCT,1); break;
		case 1: AddItem(NPC_AZMODAN("uruk"),REFRESH_DESTRUCT,1); break;
		default: break;
		}
	}

}
