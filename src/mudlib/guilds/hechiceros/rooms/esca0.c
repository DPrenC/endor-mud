inherit ROOM;
#include "path.h"


create() {
::create();
SetLocate("gremio de hechiceros");
SetIntBright(50);
SetIntShort("unas escaleras");
SetIntLong(W("Estas en las escaleras que comunican los distintos pisos"
"de la torre del gremio estan realizadas en marmol esqueisitamente tallado"
" si miras hacia arriba puedes verte reflejado en el pulido techo.\n"));
SetIndoors(1);

AddExit("suroeste",H_HOME+"hechiceros");
AddExit("arriba","./esca1");
}


