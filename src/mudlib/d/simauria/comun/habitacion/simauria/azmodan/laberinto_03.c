/***********************************************************/
//	"laberinto_03"
//
//	La salida no se encuentra en esta habitaci�n
//	Kodex: Creaci�n y ultima modificaci�n 17-02-02
//



#include "./path.h"
inherit STD_AZMODAN("laberinto");

create() {
::create();
AddExit("norte",LABERINTO_AZMODAN(0));
AddExit("sur",LABERINTO_AZMODAN(6));
AddExit("este",LABERINTO_AZMODAN(4));
AddExit("oeste",LABERINTO_AZMODAN(5));
}