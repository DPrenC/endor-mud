#include <mud.h>
#include <properties.h>
#include "./path.h"

inherit SIM_ROOM;
create () {
  ::create();
Set(P_INT_SHORT,"un sendero");
SetIntLong(
"Te encuentras en un sendero que cruza la zona agricola. Hacia el este "
"te dirigiras a la aldea de Nandor y sus aledanyos. Hacia el oeste te "
"internaras mas en los campos.\n");

SetIndoors(0);
SetIntNoise("Solo escuchas el rumor del viento.\n");
SetIntSmell("Olores campestres inundan tus sentidos.\n");
SetLocate("nandor");

AddExit("este","./sendero9");
AddExit("oeste","./sendero7");
}
