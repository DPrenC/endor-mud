#include <mud.h>
#include <properties.h>
#include "path.h"

inherit SIM_ROOM;
create () {
  ::create();
Set(P_INT_SHORT,"un sendero");
SetIntLong(
"Una inmensa llanura dorada rodea el sendero por el que caminas en ambos "
"lados. El camino continua en direccion noroeste-sudeste.\n");

SetIndoors(0);
SetLocate("Nandor");

AddExit("sudeste","./sendero7");
AddExit("noroeste","./sendero5");
}
