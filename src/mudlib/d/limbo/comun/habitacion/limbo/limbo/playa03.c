/*
DESCRIPCION  : playa de Levante
FICHERO      : /d/limbo/comun/habitacion/limbo/limbo/playa03.c
MODIFICACION : 27-07-98 [angor] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit LIMBO("playa");

create() {
  ::create();
  SetIntShort("la playa de Levante");
  SetIntLong(
"Te encuentras cerca del extremo sur de la playa de Levante. Al oeste de aqu� "
"observas como las dunas de arena arrastradas por el viento se amontonan formando "
"una especie de muro de arena. Las olas del mar siguen chocando ritmicamente con "
"la orilla y se oyen gaviotas en el cielo. Al norte de aqu� se encuentra en la "
"playa la desembocadura del arroyo que atraviesa el bosque.\n");

AddDetail(({"isla","isla Limbo","Limbo","limbo"}),
"La isla Limbo es el lugar m�gico de Simauria donde habitan los dioses. Gracias "
"a ellos, es en este lugar donde las almas de los seres se encarnan y dan sus "
"primeros pasos para vivir en este mundo.\n");

 AddDetail(({"playa","playa de Levante"}), QueryIntLong());

 AddDetail(({"duna","dunas"}),
"Son grandes montones de arena arrastrados por el viento desde la playa hasta el "
"l�mite del bosque, donde la vegetaci�n contiene su avance.\n");

SetIntNoise("Oyes las olas al llegar a la orilla y a las gaviotas.\n");
SetIntSmell("Huele a mar.\n");
SetLocate("isla Limbo");
SetIndoors(0);

AddExit("norte",LIMBO("playa01"));
AddExit("sudeste",LIMBO("playa05"));
}
