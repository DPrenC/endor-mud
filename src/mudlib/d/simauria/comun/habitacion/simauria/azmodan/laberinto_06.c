/***********************************************************/
//	"laberinto_06"
//
//	La salida no se encuentra en esta habitaci�n
//	Kodex: Creaci�n y ultima modificaci�n 17-02-02
//



#include "./path.h"
inherit STD_AZMODAN("laberinto");

create() {
::create();
AddExit("norte",LABERINTO_AZMODAN(3));
AddExit("sur",LABERINTO_AZMODAN(0));
AddExit("este",LABERINTO_AZMODAN(7));
AddExit("oeste",LABERINTO_AZMODAN(8));
}