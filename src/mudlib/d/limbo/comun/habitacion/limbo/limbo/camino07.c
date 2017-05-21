/*
DESCRIPCION  : Camino del norte.
FICHERO      : /d/limbo/comun/habitacion/limbo/limbo/camino07.c
MODIFICACION : 12-01-97 [angor] Creacion.
*/

#include "./path.h"
inherit ROOM;

create() {
  ::create();
  SetIntShort("el camino del Norte.");
  SetIntLong(
"Hacia el sur, se abre un claro en el bosque por el que transcurre el camino "
"del Norte en el que estás. En el medio de este claro se encuentra situada "
"una fuente y un poste con varios letreros indicadores. Un camino adoquinado "
"con piedras blancas cruza de este a oeste el claro del bosque. El clima es "
"agradable y primaveral.\n");

   AddDetail(({"isla","isla Limbo","Limbo","limbo"}),
  "La isla Limbo es el lugar mágico de Simauria donde habitan los dioses. "
  "Gracias a ellos, es en este lugar donde las almas de los seres se "
  "encarnan y dan sus primeros pasos para vivir en este mundo.\n");

 AddDetail(({"camino del norte","camino","camino del Norte"}),
  "El camino del Norte conduce desde el claro del bosque, que se encuentra "
  "en el centro de la isla, hacia la zona norte de la misma y en particular "
  "a la zona de entrenamiento para principiantes que se encuentra allí.\n");

  AddDetail(({"fuente","letreros","indicadores","poste"}),
  "Se encuentra en medio del claro, tal vez deberias acercarte más para ver "
  "con más detalle.\n");

SetIntNoise("Solo el dulce trinar de los pajaros altera el silencio.\n");
SetIntSmell("Las flores inundan el bosque de una suave fragancia.\n");
SetLocate("isla Limbo");
SetIndoors(0);

AddExit("norte",LIMBO("camino09"));
AddExit("sur",LIMBO("camino03"));
AddExit("suroeste",LIMBO("camino02"));
AddExit("sudeste",LIMBO("camino04"));
}

