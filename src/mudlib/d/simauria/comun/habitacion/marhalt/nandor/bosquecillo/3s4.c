/*3s4.c : Bosquecillo de nandor. Enlace con minialdea
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
AddExit("oeste","3s3");
AddExit("norte","2s4");
AddExit("sur","4s4");
AddExit("nordeste","2s5");
}







