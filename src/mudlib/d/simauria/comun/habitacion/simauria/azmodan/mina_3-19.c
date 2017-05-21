/***********************************************************/
//	"mina_3-19"
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
SetIntLong(W("Estás al noroeste de una gran sala de celebraciones, en esta"
" zona de la sala, hay muy poco espacio, miras las paredes y ves pinturas "
"echas por los shamanes parece una gran ave de fuego sobrevolando un volcan "
"en erupción. No está muy bien dibujado pero se ve lo que se quiere pintar. "
"Huesos, calaveras y palos adornan al suelo de la habitación.\n"));
AddDetail(({"huesos","calaveras","palos"}),"No sabes lo que significa pero se refieren a la magia negra y a las maldiciones.\n");
AddExit("este",MINA_AZMODAN("mina_3-20"));
AddExit("sur",MINA_AZMODAN("mina_3-14"));
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
