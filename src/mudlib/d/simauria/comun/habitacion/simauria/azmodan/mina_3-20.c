/***********************************************************/
//	"mina_3-20"
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
SetIntLong(W("Estás al nordeste de una gran sala de celebraciones, llega"
" una luz rojiza intensa procedente del sur. El suelo está adornado con "
"unos palos de madera que hacen de piernas de un animal, cuyo cuerpo está "
"constituido por huesos y sus ojos por calaveras. Los shamanes orcos utilizan "
"esta sala para realizar sus conjuros oscuros y sus maldiciones.\n"));
AddDetail(({"huesos","calaveras","palos"}),
"No sabes lo que significa pero se refieren a la magia negra y a las maldiciones.\n");
AddExit("nordeste",MINA_AZMODAN("mina_3-24"));
AddExit("oeste",MINA_AZMODAN("mina_3-19"));
AddExit("sur",MINA_AZMODAN("mina_3-15"));
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
