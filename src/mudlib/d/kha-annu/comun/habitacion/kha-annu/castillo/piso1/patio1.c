// Coded by Yandros to AURORA MUD.

#include "path.h"
inherit KHA_ROOM;

create() {
   ::create();
SetIntShort("la entrada al patio");
SetIntLong(
"Estas en el patio del castillo Kha-annu. Unas grandes columnas se alzan ante "
"ante ti y uniendolas unos arcos a modo decorativo. Hacia el norte ves el "
"portico hacia el jardin.\n");

SetIndoors(0);
SetIntBright(70);

AddExit("norte", PISO1+"garden");
AddExit("sur", PISO1+"patio2");
AddExit("este", PISO1+"patio6");
AddExit("oeste", PISO1+"patio3");

AddDetail(({"jardin","jardines"}), "Un precioso jardin queda al norte.\n");
AddDetail(({"arco","arcos"}), "Los arcos solo unen las columnas del patio.\n");
AddDetail(({"columna","columnas"}),
"Unas inmensas columnas se alzan por toda la superficie del patio.\n\
Tienen escritos viejos grabados que no puedes descifrar.\n");
}
