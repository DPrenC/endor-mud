/*
DESCRIPCION  : puente en el camino hacia el newbie park
FICHERO      : /d/limbo/comun/habitacion/limbo/limbo/camino17.c
MODIFICACION : 27-07-98 [angor] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
#include <moving.h>

inherit ROOM;

//los PNJ no entran/salen del parque
int ir_no()
{
if (TP->QueryIsPlayer()) return TP->move(BOSQUE("entrada"),M_GO);
  return 1;
}


create() {
  ::create();
  SetIntShort("el puente en el camino hacia el parque de novatos");
  SetIntLong(
"Te hallas sobre un puente de madera bajo el que discurre apaciblemente un arroyo "
"de aguas cristalinas que avanza serpenteando entre rocas cubiertas de musgo y "
"liquenes. El puente permite al sendero que va hacia el parque de entrenamiento "
"para novatos cruzar el arroyo. Dada la humedad, junto al arroyo la vegetacion es "
"mas exuberante que en el resto del bosque y crecen todo tipo de plantas.\n");

AddDetail(({"isla","isla Limbo","Limbo","limbo"}),
"La isla Limbo es el lugar magico de Simauria donde habitan los dioses. Gracias "
"a ellos, es en este lugar donde las almas de los seres se encarnan y dan sus "
"primeros pasos para vivir en este mundo.\n");

 AddDetail(({"parque","entrenamiento","novatos","parque de entrenamientos"}),
"Este sendero conduce al parque de entrenamiento para novatos, una zona dispuesta "
"por los dioses para que los recien llegados a este mundo puedan practicar con "
"las armas y asi ganar algo de experiencia y nivel antes de emprender aventuras "
"en el resto de este mundo\n");

 AddDetail(({"puente","pilares"}),
"El puente esta construido con troncos de madera que se apoyan sobre un par de "
"pilares de piedra que descansan en el lecho del arroyo. Es una construccion algo "
"tosca pero practica que parece bastante solida.\n");

SetIntNoise("Oyes el murmullo del agua del arroyo discurrir entre las piedras de su cauce.\n");
SetIntSmell("Las flores inundan el bosque de una suave fragancia.\n");
SetLocate("isla Limbo");
SetIndoors(0);

AddExit("sudeste",LIMBO("camino15"));
AddExit("noroeste",SF(ir_no));

AddItem(HERBS("hierba_saciante"), REFRESH_REMOVE);
AddItem(HERBS("seta_curativa"), REFRESH_REMOVE);
AddItem(HERBS("hierba"), REFRESH_REMOVE);
}
