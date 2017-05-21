/*
DESCRIPCION  : Camino del Sur
FICHERO      : /d/limbo/comun/habitacion/limbo/limbo/camino08.c
MODIFICACION : 12-01-97 [angor] Creacion.
*/

#include "./path.h"
inherit ROOM;

create() {
  ::create();
  SetIntShort("el camino del Sur.");
  SetIntLong(
"Hacia el norte, se abre un claro en el bosque por el que transcurre el camino "
"del Sur en el que estás. En el medio de este claro se encuentra situada "
"una fuente y un poste con varios letreros indicadores. Un camino adoquinado "
"con piedras blancas cruza de este a oeste el claro del bosque.\n");

   AddDetail(({"isla","isla Limbo","Limbo","limbo"}),
  "La isla Limbo es el lugar mágico de Simauria donde habitan los dioses. "
  "Gracias a ellos, es en este lugar donde las almas de los seres se "
  "encarnan y dan sus primeros pasos para vivir en este mundo.\n");

 AddDetail(({"camino del sur","camino","camino del Sur"}),
  "El camino del Sur conduce desde el claro del bosque, que se encuentra "
  "en en el centro de la isla, hacia la zona sur de la misma en la que "
  "existe un pequeño pueblo de pescadores.\n");

  AddDetail(({"fuente","letreros","indicadores","poste"}),
  "Se encuentra en medio del claro, tal vez deberías acercarte más para ver "
  "con más detalle.\n");

 SetIntNoise("Solo el dulce trinar de los pajaros altera el silencio.\n");
 SetIntSmell("Las flores inundan el bosque de una suave fragancia.\n");
 SetLocate("isla Limbo");

AddExit("sur",LIMBO("camino10"));
AddExit("norte",LIMBO("camino03"));
AddExit("noroeste",LIMBO("camino02"));
AddExit("nordeste",LIMBO("camino04"));

SetIndoors(0);

}

