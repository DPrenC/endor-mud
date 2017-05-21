
#include "./path.h"

inherit SIM_ROOM;
create () {
  ::create();
SetLocate("Islote de Gorat");
SetIntShort("la playa del islote de Gorat");
SetIntLong(
"Est�s en el oeste de la playa del islote de Gorat, al fondo ves el "
"continente de Simauria, y las playas de Gorat, con su majestuoso faro "
"iluminando toda la bah�a. "
"Al noreste, este y sureste sigue el islote y en las dem�s direcciones "
"tienes agua.\n");
AddDetail("arena","Es arena de playa normal.\n");
//arena en el este
SetIndoors(0);
AddExit("este","estatua");
AddExit("nordeste","playan");
AddExit("sudeste","playas");
}