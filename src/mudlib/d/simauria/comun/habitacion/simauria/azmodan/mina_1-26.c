/***********************************************************/
//	"mina_1-26"
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
SetIntLong(W("Estás en una habitación sin salida, los mineros se debieron"
" quedar en este punto excavando la mina. Quizá en esta pared se pueda encontrar "
"mineral ... o quizá los mineros estaban cansados de no encontrar nada de valor y "
"no continuaron por aquí, no serás tu el que lo averigüe. Ves"
" una roca con una inscripción.\n"));
AddDetail(({"roca"}),
W("En la inscripción no dice nada que comprendas parece un galimatías, "
"incluso es probable que sean dibujos.\n"));
AddExit("sudeste",MINA_AZMODAN("mina_1-24"));
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