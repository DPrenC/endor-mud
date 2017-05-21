/*2n5.c : Bosquecillo de nandor. Enlace con minialdea
Creado por : [Bomber]
Fecha : 1-12-01
*/
#include "./path.h"

inherit SIM_ROOM;

create() {
::create();
SetLocate("Aldea de Nandor");
SetIntShort("una zona apartada del bosque");
SetIntLong(".\n");
SetIndoors(0);
AddExit("este","2n4");
AddExit("sur","1n5");
AddExit("oeste","2n4");
AddExit("noroeste","3n4");
AddExit("sudeste","1n6");
}
