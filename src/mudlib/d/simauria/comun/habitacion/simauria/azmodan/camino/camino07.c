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
AddExit("noroeste",CAMINO_AZMODAN("camino06"));
AddExit("suroeste",CAMINO_AZMODAN("camino08"));
}