/***********************************************************/
//	"mina_1-03"
//	Mina abandonada
//	10-12-01 : Creación -> Kodex
//	10-12-01 : Modificación -> Kodex
//
//
#include "./path.h"
#include <rooms.h>
inherit STD_AZMODAN("mina");


create()
{
::create();
SetIntShort("la primera planta de la mina");
SetIntLong(W("La mina se bifurca en dos direcciones este"
" y oeste dejando al sur la salida, ligeros hilos de agua "
"caen por las paredes de roca y producen un sonido inquietante. "
"Estás solo en el primer nivel y ya sientes nostalgia del exterior.\n"));
AddExit("oeste",MINA_AZMODAN("mina_1-02"));
AddExit("este",MINA_AZMODAN("mina_1-04"));
AddExit("sur",MINA_AZMODAN("mina_1-01"));
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