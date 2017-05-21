#include <mud.h>
#include <properties.h>
#include "./path.h"

inherit SIM_ROOM;


create () {
  ::create();
Set(P_INT_SHORT,"un granero");
SetIntLong(
"Te encuentras en un espacioso granero lleno de montones de paja.\n"
"Las gallinas pueblan el lugar con su tipico cacareo. Un gallo se "
"encuentra encima de la escalera, parece que te vigila. Sacos de "
"grano, roídos por las ratas, se amontonan por todos los rincones.\n");

SetIndoors(1);
SetIntBright(30);

SetIntNoise("Lo unico que se oye es a las gallinas.\n");
SetIntSmell("Huele a grano seco.\n");
SetLocate("nandor");

AddDetail(({"paja"}),
"Solo es un monton de paja. A lo mejor encuentras un alfiler.\n");
AddDetail(({"gallo"}),
"En un precioso especimen masculino del orden de las gallinaceas.\n");
AddDetail(({"gallina","gallinas"}),
"Las tipicas aves ponedoras de huevos de una granja.\n");
AddExit("este","huerto");
AddExit("sur","../sendero2");
}

