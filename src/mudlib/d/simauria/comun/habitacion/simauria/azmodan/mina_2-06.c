/***********************************************************/
//	"mina_2-06"
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
SetIntLong(W("Te encuentras en un largo y oscuro corredor. Hay a tu alrededor"
" algunos utensilios de minería y trozos de roca arrancados de las paredes"
", hacia el norte aumenta ligeramente la luz y al fondo "
"ves una sala algo más grande.\n"));
AddDetail(({"utensilios","utensilios de minería","utensilios de mineria"}),
"Ves los restos de un pico oxidado tirados en el suelo y algunos restos de cosas parecidas.\n");
AddExit("norte",MINA_AZMODAN("mina_2-10"));
AddExit("sur",MINA_AZMODAN("mina_2-02"));
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
