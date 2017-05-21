/***********************************************************/
//	"mina_3-09"
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
SetIntLong(W("Estás en un pasillo de la mina que justo gira a esta altura"
", hacia el sur puedes ver unas rudimentarias escaleras que suben a un piso "
"superior. Hacia el este sales a un gran corredor de la mina. Ves como las "
"ratas pueblan el suelo, debe haber algun cuerpo en descomposición por aquí.\n"));
AddDetail(({"ratas"}),
"Una hilera de ratas viaja de un agujero del suelo hacia uno situado en la pared.\n");
AddExit("sur",MINA_AZMODAN("mina_3-05"));
AddExit("este",MINA_AZMODAN("mina_3-10"));
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
