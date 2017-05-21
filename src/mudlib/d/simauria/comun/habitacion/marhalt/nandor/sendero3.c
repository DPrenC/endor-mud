#include <mud.h>
#include <properties.h>
#include "./path.h"

inherit SIM_ROOM;
create () {
  ::create();
Set(P_INT_SHORT,"un sendero");
SetIntLong(
"Te encuentras en el sendero que une la parte posterior de la cuadra "
"con el camino que conduce hasta el molino. Hacia el este puedes "
"franquear la puerta trasera de la cuadra y hacia el oeste puedes "
"dirigirte hacia el molino.\n");

SetIndoors(0);
SetIntNoise("Oyes el rumor del agua y el escandalo que provocan los animales.");
SetIntSmell("Sientes un olor fresco procedente del oeste y uno fuerte y desagradable "
"del este.\n");
SetLocate("Nandor");

AddDetail(({"molino"}),
"Es un tipico molino de agua que la encauza hacia la zona de riego.\n");
AddExit("este","./granja/cuadra");
AddExit("oeste","./granja/molino");
}

