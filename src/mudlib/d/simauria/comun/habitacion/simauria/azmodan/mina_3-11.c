/***********************************************************/
//	"mina_3-11"
//	Mina abandonada
//	15-12-01 : Creación -> Kodex
//	15-12-01 : Modificación -> Kodex
//
//
#include "./path.h"
#include <rooms.h>
inherit STD_AZMODAN("mina");


create() {
::create();
SetIntShort("la tercera planta de la mina");
SetIntLong(W("Estás en un largo corredor que no ha sido utilizado para picar,"
" los orcos lo han dejado intacto por alguna razón. Es posible que sea por una "
"inscripción que tiene en una de las paredes. El pasillo continua de norte a sur.\n"));
AddDetail(({"inscripción","inscripcion"}),
"Lees la inscripción y dice: \"Jamás lo encontrareis, marchaos de aquí por que los"
" míos vendrán a vengarme!\".\n");
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
