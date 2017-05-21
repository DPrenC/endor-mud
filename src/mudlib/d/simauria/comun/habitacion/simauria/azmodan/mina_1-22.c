/***********************************************************/
//	"mina_1-22"
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
SetIntLong(W("Ves el esqueleto de un enano apoyado en la pared de la mina, "
"aún lleva su casco puesto pero imaginas que debió sufrir una muerte violenta "
"debido a sus costillas rotas. Esta mina es peligrosa y no quieres acabar como "
"el enano. Hay un pequeño charco de agua sucia en un lado del pasillo que "
"continua hacia el este y el oeste.\n"));
AddDetail(({"esqueleto"}),
W("Los huesos están muy descoloridos y a punto de convertirse en polvo. Definitivamente "
"no quieres acabar como él.\n"));
AddDetail(({"casco"}),
W("Es un casco con cuernos totalmente destrozado, crees que si lo tocaras "
"se desmoronaría junto con el esqueleto que lo porta.\n"));
AddDetail(({"charco","agua","agua sucia"}),
W("No es más que agua que se ha ensuciado con tierra, sangre y todas "
"las cosas desagradables que te puedas imaginar.\n"));
AddExit("este",MINA_AZMODAN("mina_1-23"));
AddExit("oeste",MINA_AZMODAN("mina_1-21"));
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