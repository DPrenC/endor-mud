/***********************************************************/
//	"mina_2-11"
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
SetIntLong(W("Estás en medio de un pequeño corredor tus únicas "
"salidas son norte y sur avanzando por el mismo pasillo, no sabes "
"cual de las dos será más segura ya que en esta mina nada te da "
"sensación de seguridad. Te preguntas por qué los orcos habrán "
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
