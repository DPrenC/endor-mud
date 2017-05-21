/***********************************************************/
//	"mina_1-02"
//	Mina abandonada
//	09-12-01 : Creaci�n -> Kodex
//	09-12-01 : Modificaci�n -> Kodex
//
//
#include "./path.h"
#include <rooms.h>
inherit STD_AZMODAN("mina");


create() {
::create();
SetIntShort("la primera planta de la mina");
SetIntLong(W("Observas una zona donde ves pruebas de que alguien"
" est� trabajando en esta mina. Fragmentos de roca llenan el suelo "
"y algunos utensilios de miner�a est�n apoyados en la pared. Justo "
"aqu� ves una bifurcaci�n y un camino al este que lleva a la salida.\n"));
AddExit("noroeste",MINA_AZMODAN("mina_1-05"));
AddExit("norte",MINA_AZMODAN("mina_1-06"));
AddExit("este",MINA_AZMODAN("mina_1-03"));
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
