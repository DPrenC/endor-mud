/***********************************************************/
//	"mina_1-19"
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
SetIntLong(W("Estás en un recodo de la mina, al este ves algo parecido"
" a un comedor y al sur una sala que los enanos dedicaron a guardar los "
"minerales que extraían. A tu alrededor rocas, rocas y más rocas.\n"));
AddExit("este",MINA_AZMODAN("mina_1-20"));
AddExit("sur",MINA_AZMODAN("mina_1-14"));
		switch(random(3))
		{
		case 0 .. 1: AddItem(NPC_AZMODAN("orco"),REFRESH_DESTRUCT,1);break;
		case 2: AddItem(NPC_AZMODAN("goblin"),REFRESH_DESTRUCT,1); AddItem(NPC_AZMODAN("goblin"),REFRESH_DESTRUCT,1); break;
		default: break;
		}

}
