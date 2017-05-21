/***********************************************************/
//	"mina_2-16"
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
SetIntLong(W("Te encuentras en un pasillo que recorre la mina el segundo"
" nivel de este a oeste, debe ser uno de los conductos principales. Hacia "
"el sur ves otro conducto bastante largo, cuyo final no alcanzas a contemplar, "
"y hacia el este ves una bifurcación.\n"));
AddItem("/obj/torch",REFRESH_REMOVE,1);
AddExit("oeste",MINA_AZMODAN("mina_2-15"));
AddExit("sur",MINA_AZMODAN("mina_2-11"));
AddExit("este",MINA_AZMODAN("mina_2-17"));
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
