/***********************************************************/
//	"mina_1-06"
//	Mina abandonada
//	10-12-01 : Creación -> Kodex
//	10-12-01 : Modificación -> Kodex
//
//
#include "./path.h"
#include <rooms.h>
inherit STD_AZMODAN("mina");


create() {
::create();
SetIntShort("la primera planta de la mina");
SetIntLong(W("La luz aumenta en este conducto, unas antorchas"
" encendidas a los lados te hacen pensar que la presencia de "
"orcos aquí no es mera casualidad. Este pasillo recorre la "
"mina de norte a sur y se va ensanchando poco a poco.\n"));
AddExit("sur",MINA_AZMODAN("mina_1-02"));
AddExit("norte",MINA_AZMODAN("mina_1-10"));
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
