/***********************************************************/
//	"mina_2-09"
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
SetIntLong(W("Te encuentras en la esquina de uno de los pasillos de la mina"
". Puedes ver unas ropas viejas tiradas en el suelo, no sabes a quien "
"pertenecieron pero piensas que en estos momentos no las echará de menos. "
"Unas ratas se mueven entre las rocas bajo tus pies buscando algo de comer"
", este sitio es muy siniestro.\n"));
AddDetail(({"ropa","ropas","ropas viejas"}),
"Están desgarradas y sucias no sirven para nada, hacen juego con el "
"resto de la siniestra decoración.\n");
AddDetail(({"ratas","rata"}),
"Al sentirse observadas se ocultan debajo de las rocas.\n");
AddExit("sur",MINA_AZMODAN("mina_2-05"));
AddExit("este",MINA_AZMODAN("mina_2-10"));
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
