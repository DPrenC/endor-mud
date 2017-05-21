#include <mud.h>
#include <properties.h>
#include "./path.h"

inherit SIM_ROOM;
create () {
  ::create();
Set(P_INT_SHORT,"un sendero");
SetIntLong(
"Estas enfrente de una pequenya granja. La puerta principal esta hacia el "
"norte. Detras puedes ver un campo de maiz que se extiende hacia el este. "
"A unos metros de aqui, en direccion oeste, se encuentra la cuadra.\n");

SetIndoors(0);
SetIntNoise("Oyes ruidos de animales hacia el oeste.\n");
SetIntSmell("El olor del aire inunda tus sentidos.\n");
SetLocate("nandor");

AddDetail(({"granja","pequenya granja","casa"}),
"Es una casa de madera con una altura de dos pisos.\n");
AddDetail(({"cuadra"}),
"Un enorme edificio de madera donde se guardan los animales.\n");
AddDetail(({"maizal","campo de maiz"}),
"Una vasta llanura dorada que se extiende hacia el horizonte. Algo "
"te llama la atencion en el suelo...\n");
AddDetail(({"suelo", "algo", "algo en el suelo"}),
"Oh! Parecen pisadas!\n");
AddDetail(({"pisadas"}),
"Parecen dirigirse hacia el nordeste\n");
AddExit("norte","./granja/granja1");
AddExit("oeste","./granja/cuadra");
AddExit("noroeste","./sendero2");
AddExit("sur", "./sendero4");
AddExit("nordeste","./granja/maizal1");
HideExit("nordeste",1);
// AddItem("abrevadero",REFRESH_DESTRUCT,1);
}