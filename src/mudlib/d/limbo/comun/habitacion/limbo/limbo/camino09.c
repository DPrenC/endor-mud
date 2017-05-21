/*
DESCRIPCION  : Camino del norte.
FICHERO      : /d/limbo/comun/habitacion/limbo/limbo/camino09.c
MODIFICACION : 23-07-98 [angor] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit ROOM;

create() {
  ::create();
  SetIntShort("el camino del Norte");
  SetIntLong(
"El camino del Norte continua su avance tranquilo través del bosque, ascendiendo "
"ligeramente a medida que se acerca al norte de la isla Limbo. El bosque poco a "
"poco se vuelve más denso una vez dejado atrás el claro en el centro de la isla.\n");

AddDetail(({"isla","isla Limbo","Limbo","limbo"}),
"La isla Limbo es el lugar mágico de Simauria donde habitan los dioses. Gracias "
"a ellos, es en este lugar donde las almas de los seres se encarnan y dan sus "
"primeros pasos para vivir en este mundo.\n");

 SetIntNoise("Solo el dulce trinar de los pajaros altera el silencio.\n");
 SetIntSmell("Las flores inundan el bosque de una suave fragancia.\n");
 SetLocate("isla Limbo");
 SetIndoors(0);

 AddExit("norte",LIMBO("camino15"));
 AddExit("sur",LIMBO("camino07"));

 AddItem(HERBS("hierba"), REFRESH_REMOVE);
}
