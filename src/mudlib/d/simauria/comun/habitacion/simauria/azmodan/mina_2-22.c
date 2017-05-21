/***********************************************************/
//	"mina_2-22"
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
SetIntLong(W("Se te humedecen los pies, hay agua sucia en este lugar"
". Debe haberse filtrado agujero en la roca. Observas detenidamente "
"la habitación pero no localizas ningún agujero por el que se haya "
"podido filtrar el agua. El hedor que desprende el agua es irrespirable.\n"));
AddExit("este",MINA_AZMODAN("mina_2-23"));
AddExit("oeste",MINA_AZMODAN("mina_2-21"));
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
