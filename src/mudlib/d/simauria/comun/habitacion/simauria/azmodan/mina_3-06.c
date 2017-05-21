/***********************************************************/
//	"mina_3-06"
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
SetIntLong(W("Est�s en un largo pasillo que recorre la mina de norte "
"a sur, en estos momentos ves todo el suelo levantado y las paredes muy "
"destrozadas. No hay que ser muy listo para advertir que los orcos est�n "
"extrayendo mineral, o quiz� est�n buscando otra cosa m�s importante.\n"));
AddItem("/obj/torch",REFRESH_REMOVE,1);
AddExit("norte",MINA_AZMODAN("mina_3-10"));
AddExit("sur",MINA_AZMODAN("mina_3-02"));
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
