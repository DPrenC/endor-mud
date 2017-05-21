/***********************************************************/
//	"mina_1-01"
//	Mina abandonada
//	09-12-01 : Creación -> Kodex
//	09-12-01 : Modificación -> Kodex
//
//
#include "./path.h"
#include <rooms.h>
inherit STD_AZMODAN("mina");


create() {
::create();
SetIntShort("la primera planta de la mina");
SetIntLong(W("Estás en el primer nivel de la mina,"
" ves una luz muy débil que viene de alguna antorcha "
"en la pared, el ambiente es húmedo y las paredes de "
"roca te dan inseguridad, trabajar en esta mina debe ser un "
"infierno. Hacia el norte sigue el pasillo de la mina y hacia "
"arriba tienes unas escaleras de roca para ir al nivel superior.\n"));
AddExit("arriba",MINA_AZMODAN("entrada_2"));
AddExit("norte",MINA_AZMODAN("mina_1-03"));
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
