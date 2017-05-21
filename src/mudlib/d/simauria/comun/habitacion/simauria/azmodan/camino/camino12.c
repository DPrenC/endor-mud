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
AddExit("nordeste",CAMINO_AZMODAN("camino11"));
AddExit("sudeste",CAMINO_AZMODAN("camino13"));
}