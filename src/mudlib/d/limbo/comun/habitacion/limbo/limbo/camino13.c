/*
DESCRIPCION  : Camino del Sur
FICHERO      : /d/limbo/comun/habitacion/limbo/limbo/camino13.c
MODIFICACION : 14-09-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit ROOM;

create() {
  ::create();
  SetIntShort("el camino del Sur");
  SetIntLong(
"Notas que te estás acercando al limite del bosque ya que comienzan a aparecer "
"claros entre los árboles del mismo. El camino del Sur continua lento descenso a "
"medida que avanza a medida hacia el suroeste. Observas un cruce en el camino al "
"nordeste de aquí.\n");

AddDetail(({"isla","isla Limbo","Limbo","limbo"}),
 "La isla Limbo es el lugar mágico de Simauria donde habitan los dioses. Gracias "
 "a ellos, es en este lugar donde las almas de los seres se encarnan y dan sus "
 "primeros pasos para vivir en este mundo.\n");

AddDetail(({"camino del sur","camino","camino del Sur"}),
 "El camino del Sur conduce desde el claro del bosque, que se encuentra en el "
 "centro de la isla, hacia la zona sur de la misma en la que existe un pequenyo "
 "pueblo de pescadores.\n");

SetIntNoise("Solo el dulce trinar de los pajaros altera el silencio.\n");
SetIntSmell("Las flores inundan el bosque de una suave fragancia.\n");
SetLocate("isla Limbo");
SetIndoors(0);

AddExit("este",LIMBO("camino12"));
AddExit("oeste",LIMBO("camino14"));
AddItem(HERBS("hierba_saciante"));
}
