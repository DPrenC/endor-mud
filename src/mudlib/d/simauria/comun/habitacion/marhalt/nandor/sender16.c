/*sendero15.c : Aldea de Nandor
Creado por : Bomber
Fecha : 30-11-01
*/
#include "./path.h"

inherit SIM_ROOM;

create() {

::create();
SetLocate("Aldea de Nandor");
SetIntShort("un sendero entre el bosque");
SetIntLong(".\n");
SetIndoors(0);
AddExit("oeste","./sender15");
AddExit("este","./sender17");

}

