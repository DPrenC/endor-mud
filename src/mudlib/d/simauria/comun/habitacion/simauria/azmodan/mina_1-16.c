/***********************************************************/
//	"mina_1-16"
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
SetIntLong(W("Est�s en el final de un pasillo hacia el norte"
", ves unas salas m�s grandes hacia el oeste y una bifurcaci�n "
"al este. Si no fuera por que a�n crees en ti mismo se podr�a "
"decir que est�s muy perdido entre tantas rocas y caminos iguales"
". Las antorchas que iluminan la mina dan una luz tan tenue "
"que ni siquiera los orcos deben ver con claridad.\n"));
AddExit("oeste",MINA_AZMODAN("mina_1-15"));
AddExit("este",MINA_AZMODAN("mina_1-17"));
AddExit("sur",MINA_AZMODAN("mina_1-11"));
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
