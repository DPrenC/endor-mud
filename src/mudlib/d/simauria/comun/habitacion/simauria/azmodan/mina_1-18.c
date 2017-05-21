/***********************************************************/
//	"mina_1-18"
//	Mina abandonada
//	11-12-01 : Creaci�n -> Kodex
//	11-12-01 : Modificaci�n -> Kodex
//
//
#include "./path.h"
#include <rooms.h>
inherit STD_AZMODAN("mina");


create() {
::create();
SetIntShort("la primera planta de la mina");
SetIntLong(W("Est�s en un corredor excavado en la roca, es un tunel"
" bien construido y con apenas luz. Las rocas resplandecen en algunos "
"puntos a�n con la poca luz que llega. Al norte ves una sala que hace "
"esquina y hay algo que resplandece m�s all�.\n"));
AddExit("sur",MINA_AZMODAN("mina_1-13"));
AddExit("norte",MINA_AZMODAN("mina_1-23"));
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
