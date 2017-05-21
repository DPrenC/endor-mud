/*
DESCRIPCION  : playa de Levante
FICHERO      : /d/limbo/comun/habitacion/limbo/limbo/playa02.c
MODIFICACION : 24-07-98 [angor] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit LIMBO("playa");

create() {
  ::create();
  SetIntShort("la playa de Levante");
  SetIntLong(
"Te encuentras en la zona central de la playa de Levante. Las dunas de arena "
"arrastradas por el viento se agolpan al oeste de aqui formando una especie de "
"muro de arena. Las olas del mar siguen chocando ritmicamente con la orilla. "
"Al suroeste de aquí, un sendero parte de la playa y se adentra en el bosque.\n");

AddDetail(({"isla","isla Limbo","Limbo","limbo"}),
"La isla Limbo es el lugar mágico de Simauria donde habitan los dioses. Gracias "
"a ellos, es en este lugar donde las almas de los seres se encarnan y dan sus "
"primeros pasos para vivir en este mundo.\n");

 AddDetail(({"sendero","camino"}),
"Al suroeste de aquí, un sendero parte de la playa y se adentra en el bosque.\n");

 AddDetail(({"playa","playa de Levante"}), QueryIntLong());

 AddDetail(({"duna","dunas"}),
"Son grandes montones de arena arrastrados por el viento desde la playa hasta el "
"límite del bosque, donde la vegetación contiene su avance.\n");

SetIntNoise("Oyes las olas al llegar a la orilla.\n");
SetIntSmell("Huele a mar.\n");
SetLocate("isla Limbo");
SetIndoors(0);

AddExit("nordeste",LIMBO("playa04"));
AddExit("suroeste",LIMBO("playa00"));
}
