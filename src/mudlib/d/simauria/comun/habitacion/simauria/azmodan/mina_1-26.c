/***********************************************************/
//	"mina_1-26"
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
SetIntLong(W("Est�s en una habitaci�n sin salida, los mineros se debieron"
" quedar en este punto excavando la mina. Quiz� en esta pared se pueda encontrar "
"mineral ... o quiz� los mineros estaban cansados de no encontrar nada de valor y "
"no continuaron por aqu�, no ser�s tu el que lo averig�e. Ves"
" una roca con una inscripci�n.\n"));
AddDetail(({"roca"}),
W("En la inscripci�n no dice nada que comprendas parece un galimat�as, "
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