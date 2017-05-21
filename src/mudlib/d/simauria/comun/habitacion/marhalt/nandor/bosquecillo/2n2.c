/*2n2.c : Bosquecillo de nandor. Enlace con minialdea
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
AddExit("este","2n3");
AddExit("sur","1n2");
AddExit("nordeste","3n3");
AddExit("suroeste","1n1");
}
