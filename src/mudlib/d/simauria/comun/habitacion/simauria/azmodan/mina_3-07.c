/***********************************************************/
//	"mina_3-07"
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
SetIntLong(W("Te encuentras en un gran cruce de caminos, aquí no"
" hay señales de excavación, solo hay alguna roca caída pero puede "
"haber sido por el paso de los años, o deberse a algún desprendimiento "
"casual. Aumenta ligeramente el nivel de luz hacia el norte, en los "
"demás caminos la oscuridad es constante.\n"));
AddExit("norte",MINA_AZMODAN("mina_3-11"));
AddExit("sur",MINA_AZMODAN("mina_3-04"));
AddExit("este",MINA_AZMODAN("mina_3-08"));
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
