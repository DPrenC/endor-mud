/***********************************************************/
//	"laberinto_00"
//
//	La salida no se encuentra en esta habitación
//	Kodex: Creación y ultima modificación 17-02-02
//



#include "./path.h"
inherit STD_AZMODAN("laberinto");

object troll;

create() {
::create();
AddExit("norte",LABERINTO_AZMODAN(6));
AddExit("sur",LABERINTO_AZMODAN(3));
AddExit("este",LABERINTO_AZMODAN(1));
AddExit("oeste",LABERINTO_AZMODAN(2));
if (!living(troll))
troll = AddItem(NPC_AZMODAN("cave_troll"),REFRESH_DESTRUCT,1);
}