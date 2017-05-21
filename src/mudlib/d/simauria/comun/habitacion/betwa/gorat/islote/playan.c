
#include "./path.h"

inherit SIM_ROOM;
create () {
  ::create();
SetLocate("Islote de Gorat");
SetIntShort("la playa del islote de Gorat");
SetIntLong(
"Estás en el norte de la playa del islote de Gorat, al fondo ves el "
"continente de Simauria, y las playas de Gorat, con su majestuoso faro "
"iluminando toda la bahía. "
"Al sur, suroeste y sureste sigue el islote y en las demás direcciones "
"tienes agua.\n");
AddDetail("arena","Es arena de playa normal.\n");
//arena en el este
SetIndoors(0);
AddExit("sur","estatua");
AddExit("suroeste","playao");
AddExit("sudeste","playae");
}