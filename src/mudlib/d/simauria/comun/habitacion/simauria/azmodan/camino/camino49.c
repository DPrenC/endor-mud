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
AddExit("oeste",CAMINO_AZMODAN("camino48"));
AddExit("este",CAMINO_AZMODAN("camino50"));
}