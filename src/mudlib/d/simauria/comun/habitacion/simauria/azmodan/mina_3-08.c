/***********************************************************/
//	"mina_3-08"
//	Mina abandonada
//	15-12-01 : Creaci�n -> Kodex
//	15-12-01 : Modificaci�n -> Kodex
//
//
#include "./path.h"
#include <rooms.h>
inherit STD_AZMODAN("mina");


create() {
::create();
SetIntShort("la tercera planta de la mina");
SetIntLong(W("Est�s en un angosto conducto que une dos zonas de "
"la mina, en este tercer nivel ves como hay mucha m�s actividad "
"minera que en los dos anteriores, y se usan conductos como este "
"para comunicar principales zonas de extracci�n de mineral.\n"));
AddExit("nordeste",MINA_AZMODAN("mina_3-12"));
AddExit("oeste",MINA_AZMODAN("mina_3-07"));
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
