/*
DESCRIPCION  : playa de Levante
FICHERO      : /d/limbo/comun/habitacion/limbo/limbo/playa05.c
MODIFICACION : 27-07-98 [angor] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit LIMBO("playa");

create() {
  ::create();
  SetIntShort("la playa de Levante");
  SetIntLong(
"Has llegado al extremo sur de la playa de Levante. Aquí la playa acaba en las "
"rocas al pie del acantilado que forma la meseta central de la isla. Las olas "
"te salpican al chocar contra las rocas. Desde aquí puedes ver al sudeste una "
"torre construida sobre unas peñas en medio del mar y unida a la isla por medio "
"de un puente: es la torre de los wizards.\n");

AddDetail(({"torre de wizards","torre de Wizards","torre","Torre"}),
 "La torre de los Wizards es un edificio construido sobre una roca al este de la "
 "isla Limbo. En ella trabajan y se reunen los wizards, los seres que ayudan a los "
 "dioses a crear este mundo, y además se encuentran una serie de servicios para "
 "resolver problemas, tales como la Justicia, que surjan con o entre los jugadores "
 "de Simauria.\n");

AddDetail(({"acantilado","meseta"}),
 "La zona central de la isla es una meseta elevada sobre el nivel del mar, que "
 "al llegar al mar forman altos y rocosos acantilados. Te hallas junto a uno "
 "de ellos.\n");

AddDetail(({"rocas","roca"}),
 "Las olas embisten incansablemente las rocas de la costa. Ten cuidado si piensas "
 "caminar sobre las rocas, pues estan muy resbaladizas y una caida podría resultar "
 "fatal.\n");

AddDetail(({"isla","isla Limbo","Limbo","limbo"}),
 "La isla Limbo es el lugar mágico de Simauria donde habitan los dioses. Gracias "
 "a ellos, es en este lugar donde las almas de los seres se encarnan y dan sus "
 "primeros pasos para vivir en este mundo.\n");

AddDetail(({"playa","playa de Levante"}), QueryIntLong());

SetIntNoise("Oyes las olas chocar contra las rocas.\n");
SetIntSmell("Huele a mar.\n");
SetLocate("isla Limbo");
SetIndoors(0);

AddExit("noroeste",LIMBO("playa03"));
}
