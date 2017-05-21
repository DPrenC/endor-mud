/***********************************************************/
//	"laberinto_04"
//
//	La salida no se encuentra en esta habitación
//	Solo una salida aquí
//	Kodex: Creación y ultima modificación 17-02-02
//



#include "./path.h"
inherit STD_AZMODAN("laberinto");

create() {
::create();
AddExit("norte",LABERINTO_AZMODAN(1));
AddExit("sur",LABERINTO_AZMODAN(7));
AddExit("oeste",LABERINTO_AZMODAN(3));
}