/*senda7.c : Bosquecillo de nandor. Enlace con minialdea
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
AddExit("oeste","senda6");
AddExit("este","senda8");
}



