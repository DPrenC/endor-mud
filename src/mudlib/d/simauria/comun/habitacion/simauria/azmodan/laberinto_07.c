/***********************************************************/
//	"laberinto_07"
//
//	La salida no se encuentra en esta habitación
//	Kodex: Creación y ultima modificación 17-02-02
//



#include "./path.h"
inherit STD_AZMODAN("laberinto");

create() {
::create();
AddExit("norte",LABERINTO_AZMODAN(4));
AddExit("sur",LABERINTO_AZMODAN(1));
AddExit("este",LABERINTO_AZMODAN(8));
AddExit("oeste",LABERINTO_AZMODAN(6));
}