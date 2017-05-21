/***********************************************************/
//	"mina_2-10"
//	Mina abandonada
//	14-12-01 : Creación -> Kodex
//	14-12-01 : Modificación -> Kodex
//
//
#include "./path.h"
#include <rooms.h>
inherit STD_AZMODAN("mina");


create() {
::create();
SetIntShort("la segunda planta de la mina");
SetIntLong(W("Estás en un pasillo que recorre el segundo nivel"
" de la mina de norte a sur. No hay rocas por el medio, por lo "
"que adivinas que debe ser un pasillo bastante utilizado por los "
"orcos para moviemiento de sus tropas y patrullas. Al norte ves "
"una gran sala que parece una armería, hacia el sur continua el pasillo "
"y tu vista no alcanza a ver donde termina.\n"));
AddExit("sur",MINA_AZMODAN("mina_2-06"));
AddExit("norte",MINA_AZMODAN("mina_2-14"));
AddExit("oeste",MINA_AZMODAN("mina_2-09"));
if (random(100) < 50)
	{
		switch(random(3))
		{
		case 0 .. 1: AddItem(NPC_AZMODAN("uruk"),REFRESH_DESTRUCT,1); break;
		case 2: AddItem(NPC_AZMODAN("orco"),REFRESH_DESTRUCT,1); break;
		default: break;
		}
	}

}
