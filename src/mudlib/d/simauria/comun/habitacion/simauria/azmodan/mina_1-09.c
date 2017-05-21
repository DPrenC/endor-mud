/***********************************************************/
//	"mina_1-09"
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
SetIntLong(W("Aqu� no ves nada m�s que piedras por el "
"suelo y algunos picos rotos y desgastados. Los mineros "
"se fueron hace mucho tiempo y no dejaron nada de valor,"
" a�n no comprendes por que los orcos ambicionan esta mina.\n"));
AddExit("sur",MINA_AZMODAN("mina_1-05"));
AddExit("este",MINA_AZMODAN("mina_1-10"));
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
