/*senda6.c : Bosquecillo de nandor. Enlace con minialdea
Creado por : [Bomber]
Fecha : 1-12-01
*/
#include "./path.h"

inherit SIM_ROOM;

create() {
::create();
SetLocate("Aldea de Nandor");
SetIntShort("un sendero entre el bosque");
SetIntLong(".\n");
SetIndoors(0);
AddExit("oeste","senda5");
AddExit("este","senda7");
AddExit("norte","1n6");
AddExit("sur","1s6");
}


