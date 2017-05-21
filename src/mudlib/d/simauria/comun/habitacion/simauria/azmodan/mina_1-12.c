/***********************************************************/
//	"mina_1-12"
//	Mina abandonada
//	11-12-01 : Creación -> Kodex
//	11-12-01 : Modificación -> Kodex
//
//
#include "./path.h"
#include <rooms.h>
inherit STD_AZMODAN("mina");


create() {
::create();
SetIntShort("la primera planta de la mina");
SetIntLong(W("Estás en un cruce de conductos el nivel de iluminación"
" aumenta al llegar desde tantos puntos diferentes, aquí puedes ver "
"con claridad las excavadas paredes de roca y algunas lámparas viejas "
"destrozadas por el paso del tiempo.\n"));
AddDetail(({"lampara","lámpara","lámparas","lamparas"}),"Es lo que utilizaban los mineros enanos para ver mejor, ahora solo hay una tenue luz que proviene de alguna antorcha.\n");
AddExit("suroeste",MINA_AZMODAN("mina_1-08"));
AddExit("este",MINA_AZMODAN("mina_1-13"));
AddExit("noroeste",MINA_AZMODAN("mina_1-17"));
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
