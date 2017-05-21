/***********************************************************/
//	"mina_2-11"
//	Mina abandonada
//	14-12-01 : Creaci�n -> Kodex
//	14-12-01 : Modificaci�n -> Kodex
//
//
#include "./path.h"
#include <rooms.h>
inherit STD_AZMODAN("mina");


create() {
::create();
SetIntShort("la segunda planta de la mina");
SetIntLong(W("Est�s en medio de un peque�o corredor tus �nicas "
"salidas son norte y sur avanzando por el mismo pasillo, no sabes "
"cual de las dos ser� m�s segura ya que en esta mina nada te da "
"sensaci�n de seguridad. Te preguntas por qu� los orcos habr�n "
"elegido esta mina abandonada para establecerse.\n"));
AddExit("sur",MINA_AZMODAN("mina_2-07"));
AddExit("norte",MINA_AZMODAN("mina_2-16"));
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
