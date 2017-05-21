/*
DESCRIPCION  : puente en el camino hacia la playa de Levante
FICHERO      : /d/limbo/comun/habitacion/limbo/limbo/camino18.c
MODIFICACION : 23-07-98 [angor] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit ROOM;

create() {
  ::create();
  SetIntShort("el puente en el camino hacia la playa");
  SetIntLong(
"Te hallas sobre un puente de madera bajo el que discurre apaciblemente un arroyo "
"de aguas cristalinas que avanza serpenteando entre rocas cubiertas de musgo y "
"líquenes. El puente permite al sendero que va hacia la playa de Levante cruzar "
"este arroyo. Debido a la humedad, junto al arroyo la vegetación es más "
"exuberante que en el resto del bosque y crecen todo tipo de plantas.\n");

AddDetail(({"isla","isla Limbo","Limbo","limbo"}),
"La isla Limbo es el lugar mágico de Simauria donde habitan los dioses. Gracias "
"a ellos, es en este lugar donde las almas de los seres se encarnan y dan sus "
"primeros pasos para vivir en este mundo.\n");

 AddDetail(({"playa","sendero","camino","playa de Levante"}),
"Este sendero conduce a la la playa de Levante que se halla en el nordeste de la "
"isla Limbo desde el camino del Norte.\n");

 AddDetail(({"puente","pilares"}),
"El puente esta construido con troncos de madera que se apoyan sobre un par de "
"pilares de piedra que descansan en el lecho del arroyo. Es una construcción "
"algo tosca pero practica que parece bastante solida.\n");

SetIntNoise("Oyes el murmullo del agua del arroyo discurrir entre las piedras de su cauce.\n");
SetIntSmell("Las flores inundan el bosque de una suave fragancia.\n");
SetLocate("isla Limbo");
SetIndoors(0);

AddExit("sur",LIMBO("camino16"));
AddExit("nordeste",LIMBO("camino19"));

AddItem(HERBS("hierba"), REFRESH_REMOVE);
AddItem(HERBS("hierba_magica"), REFRESH_REMOVE);
AddItem(HERBS("hierba_narcotica"), REFRESH_REMOVE);
}
