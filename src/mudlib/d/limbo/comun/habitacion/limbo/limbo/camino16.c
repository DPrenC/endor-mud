/*
DESCRIPCION  : camino hacia la playa de Levante
FICHERO      : /d/limbo/comun/habitacion/limbo/limbo/camino16.c
MODIFICACION : 23-07-98 [angor] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit ROOM;

create() {
  ::create();
  SetIntShort("el camino hacia la playa de Levante");
  SetIntLong(
"Estás en un sendero de tierra que atraviesa la parte nordeste del bosque de la "
"isla Limbo. El sendero parte del camino del Norte, al suroeste de aquí, y "
"desciende entre el bosque hasta la playa de Levante que queda al nordeste de "
"la isla. Al norte de aquí, un arroyo cruza el sendero.\n");

AddDetail(({"isla","isla Limbo","Limbo","limbo"}),
"La isla Limbo es el lugar mágico de Simauria donde habitan los dioses. Gracias "
"a ellos, es en este lugar donde las almas de los seres se encarnan y dan sus "
"primeros pasos para vivir en este mundo.\n");

 AddDetail(({"camino del norte","camino del Norte"}),
"El camino del Norte conduce desde el claro del bosque, que se encuentra en el "
"centro de la isla, hacia la zona norte de la misma en la que existe una zona de "
"entrenamiento para los jugadores recien llegados a este mundo.\n");

 AddDetail(({"playa","sendero","camino","playa de Levante"}),
"Este sendero conduce a la la playa de Levante que se halla en el nordeste de la "
"isla Limbo desde el camino del Norte.\n");

 AddDetail(({"puente","arroyo"}),
"Al norte de aqui un arroyo de agua clara se cruza con el sendero. Se ha "
"construido un puente de madera para que el sendero pueda atravesar el arroyo.\n");

SetIntNoise("Solo el dulce trinar de los pájaros altera el silencio.\n");
SetIntSmell("Las flores inundan el bosque de una suave fragancia.\n");
SetLocate("isla Limbo");
SetIndoors(0);

AddExit("norte",LIMBO("camino18"));
AddExit("suroeste",LIMBO("camino15"));
AddItem(PNJ("conejo"), REFRESH_DESTRUCT, 1);
}
