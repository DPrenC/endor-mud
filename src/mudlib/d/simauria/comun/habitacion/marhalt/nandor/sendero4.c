#include "path.h"
#include <properties.h>

inherit SIM_ROOM;

create () {
  object portal;
  ::create();
Set(P_INT_SHORT,"un sendero");
SetIntLong(
"Los campos de cereales dominan el paisaje. Hacia el norte puedes ver una "
"pequenya casa.\n");

SetIndoors(0);
SetIntNoise("Oyes ruidos de animales.\n");
SetIntSmell("Olores campestres inundan tus sentidos.\n");
SetLocate("Nandor");

AddExit("norte","./sendero1");
AddExit("este","./sendero5");

portal=clone_object("/obj/monolito");
portal->SetRaza("draconiano");
portal->move(TO);

}
