/***********************************************************/
//	"valley_01"
//	Valle
//	11-12-01 : Creaci�n -> Kodex
//	11-12-01 : Modificaci�n -> Kodex
//
//
#include "./path.h"
inherit SIM_ROOM;


create() {
::create();
SetIntShort("el suroeste del valle");
SetIntLong(W("Est�s en la entrada del gran valle de Azmodan, hay bastante vegetaci�n"
" por los alrededores. Es un lugar sin ruidos y con olor a fresco, solo los "
"pajarillos perturban la tranquilidad de este sitio. Al oeste ves un r�o que "
"te corta el paso.\n"));
SetIndoors(0);
SetIntNoise("Oyes pajarillos cantar.\n");
SetIntSmell("Huele a aire puro.\n");
AddDetail(({"vegetaci�n","vegetacion"}),"La vegetaci�n es rica en este lugar.\n");
AddExit("este",VALLE_AZMODAN("valley_02"));
AddExit("norte",VALLE_AZMODAN("valley_05"));
AddExit("oeste",CAMINO_AZMODAN("camino50"));
SetLocate("Valle");
}