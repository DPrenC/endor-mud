#include <mud.h>
#include <properties.h>
#include "./path.h"

inherit SIM_ROOM;
create () {
  ::create();
Set(P_INT_SHORT,"un sendero");
SetIntLong(
"Campos de cereales te rodean. El sendero en el que te encuentras gira en "
"direccion noroeste y continua hacia el este.\n");

SetIndoors(0);
SetIntNoise("Los cuervos graznan a ambos lados del camino.\n");
SetIntSmell("Huele a tierra recien cultivada.\n");
SetLocate("Nandor");

AddExit("este","./sendero8");
AddExit("noroeste","./sendero6");
}
