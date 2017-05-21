/***********************************************************/
//	"mina_2-21"
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
SetIntLong(W("A tu alrededor no ves más que las sucias paredes del segundo"
" nivel de la mina. Suponías encontrar algún indicio de mineral o algo, "
"pero no es así. Los que construyeron esta mina la vaciaron del todo y no "
"dejaron nada para los visitantes. La presencia de los orcos le da algo más "
"de \"alegría\" a la fiesta.\n"));
AddExit("sur",MINA_AZMODAN("mina_2-17"));
AddExit("este",MINA_AZMODAN("mina_2-22"));
AddExit("noroeste",MINA_AZMODAN("mina_2-24"));
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
