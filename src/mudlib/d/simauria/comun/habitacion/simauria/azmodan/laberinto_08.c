/***********************************************************/
//	"laberinto_08"
//
//	La salida no se encuentra en esta habitación
//	Kodex: Creación y ultima modificación 17-02-02
//



#include "./path.h"
inherit STD_AZMODAN("laberinto");

create() {
::create();
AddExit("norte",LABERINTO_AZMODAN(5));
AddExit("sur",LABERINTO_AZMODAN(2));
AddExit("este",LABERINTO_AZMODAN(6));
AddExit("oeste",LABERINTO_AZMODAN(7));
}