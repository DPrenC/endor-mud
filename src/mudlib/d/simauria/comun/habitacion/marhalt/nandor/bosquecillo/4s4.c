/*4s4.c : Bosquecillo de nandor. Enlace con minialdea
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
AddExit("oeste","4s3");
AddExit("norte","3s4");
}

