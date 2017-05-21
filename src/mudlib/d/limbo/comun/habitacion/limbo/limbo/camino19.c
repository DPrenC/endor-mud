/*
DESCRIPCION  : camino hacia la playa de Levante
FICHERO      : /d/limbo/comun/habitacion/limbo/limbo/camino19.c
MODIFICACION : 23-07-98 [angor] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit ROOM;

create() {
  ::create();
  SetIntShort("el camino hacia la playa de Levante");
  SetIntLong(
"Estás en el límite del bosque. Aquí comienzas a observar como los arboles del "
"bosque comienzan a dar paso a dunas de arena que anuncian la cercania de la "
"playa de Levante que se halla al este de aquí. El sendero se adentra en el "
"bosque hacia el suroeste.\n");

AddDetail(({"isla","isla Limbo","Limbo","limbo"}),
"La isla Limbo es el lugar mágico de Simauria donde habitan los dioses. Gracias "
"a ellos, es en este lugar donde las almas de los seres se encarnan y dan sus "
"primeros pasos para vivir en este mundo.\n");

 AddDetail(({"sendero","camino"}),
"Este sendero conduce a la playa de Levante que se halla frente a ti.\n");

 AddDetail(({"playa","playa de Levante"}),
"Es una playa larga y ancha de arenas claras que queda al este de aquí.\n");

 AddDetail(({"duna","dunas"}),
"Son grandes montones de arena arrastrados por el viento hasta aquí donde la "
"vegetación los contiene.\n");

SetIntNoise("Oyes el murmullo de las olas al llegar a la orilla.\n");
SetIntSmell("Se mezclan los olores del bosque y el mar.\n");
SetLocate("isla Limbo");
SetIndoors(0);

AddExit("este",LIMBO("playa00"));
AddExit("suroeste",LIMBO("camino18"));
}
