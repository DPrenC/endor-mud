/***********************************************************/
//	Camino que une Rhoemas con las grutas de Azmodan
//	Basado en "camino"
//	Kodex [28-02-02]
//


#include <properties.h>

#include "./path.h"
inherit CAMINO_AZMODAN("camino");

create() {
::create();
AddExit("norte",RHOECAM("camino_89"));
AddExit("sur",CAMINO_AZMODAN("camino02"));
}