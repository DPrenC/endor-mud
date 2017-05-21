/*
DESCRIPCION  : Camino del Sur
FICHERO      : /d/limbo/comun/habitacion/limbo/limbo/camino10.c
MODIFICACION : 30-01-98 [angor] Creacion.
               29-06-99 [angor] Wrapeado
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit ROOM;

public create() {
  ::create();
  SetIntShort("el camino del Sur.");
  SetIntLong(W("El camino del Sur continua avanzando a trav�s del bosque y "
    "desciende ligeramente a medida que se avanza hacia el sur de la "
    "isla Limbo. Aqu� el bosque muestra toda su vitalidad con �rboles j�venes "
    "que compiten entre s� al crecer.\n"));

   AddDetail(({"isla","isla Limbo","Limbo","limbo"}),
  "La isla Limbo es el lugar m�gico de Simauria donde habitan los dioses. "
  "Gracias a ellos, es en este lugar donde las almas de los seres se "
  "encarnan y dan sus primeros pasos para vivir en este mundo.\n");

 AddDetail(({"camino del sur","camino","camino del Sur"}),
  "El camino del Sur conduce desde el claro del bosque, que se encuentra "
  "en en el centro de la isla, hacia la zona sur de la misma en la que "
  "existe un peque�o pueblo de pescadores.\n");

  AddDetail(({"arboles","arboles jovenes","�rboles"}),
  "Los arboles de esta parte del bosque son j�venes y crecen r�pido.\n");

 SetIntNoise("Solo el dulce trinar de los pajaros altera el silencio.\n");
 SetIntSmell("Las flores inundan el bosque de una suave fragancia.\n");
 SetLocate("isla Limbo");
 SetIndoors(0);

 AddExit("norte",LIMBO("camino08"));
 AddExit("sur",LIMBO("camino12"));
 AddItem(PNJ("gorrion"), REFRESH_DESTRUCT, 1);
}

