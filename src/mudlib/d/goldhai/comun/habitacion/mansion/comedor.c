#include "./path.h"
#include <magia.h>

inherit GROOM;

create()
{
 ::create();
 SetIntShort("el comedor");
SetIntLong(
"El comedor de la mansion resulta muy acojedor. En su extremo sur puedes ver "
"la gran chimenea de piedra que calienta la estancia y a su alrededor varias "
"butacas y una piel de oso a modo de alfombra. En el centro de la estancia "
"una larga mesa con candelabros rodeada de sillas permite organizar cenas.\n");

AddDetail(({"mesa","mesas"}),
"Es una larga mesa de madera de roble.\n");

AddDetail(({"candelabros"}),
"Dos pesados candelabros de hierro forjado se encuentran sobre la mesa.\n");

AddDetail(({"chimenea"}),
"Acercate a ella si quieres calentarte un poco.\n");

AddDetail(({"butacas"}),
"¿Qué mejor lugar para una charla tras una copiosa cena?.\n");

AddDetail(({"piel","oso"}),
"Probablemente la piel de osos que ves junto a la chimenea sea un trofeo de "
"caza del dueño de la mansión.\n");

AddDetail(({"mesa","mesas"}),
"Es una larga mesa de madera de roble.\n");

 SetIndoors(1); // 1: A cubierto  0: A descubierto
 SetIntBright(50);
 SetIntNoise("No oyes nada especial.\n");
 SetIntSmell("No huele a nada especial.\n");

 SetTPort(TPORT_NO);

 AddExit("norte",MANSION("entrada"));
 AddExit("oeste",MANSION("biblioteca"));

 SetLocate("mansión de Hardester Rankomme");
}