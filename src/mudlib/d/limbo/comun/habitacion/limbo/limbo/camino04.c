/*
DESCRIPCION  : Camino que conduce a la torre de Wizards
FICHERO      : /d/limbo/comun/habitacion/limbo/limbo/camino04.c
MODIFICACION : 11-01-97 {Angor@Simauria] Creacion.
               30-08-98 [Angor@Simauria] Retoques varios
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit ROOM;

create() {
  ::create();
  SetIntShort("el camino hacia la torre de Wizards");
  SetIntLong(
"Hacia el oeste, se abre un claro en el bosque por que transcurre el camino que "
"conduce a la torre de los Wizards. En el medio de este claro se encuentra "
"situada una fuente y un poste con varios letreros indicadores. Un camino cruza "
"de norte a sur este claro del bosque, atravesando la via principal.\n");

   AddDetail(({"isla","isla Limbo","Limbo","limbo"}),
  "La isla Limbo es el lugar mágico de Simauria donde habitan los dioses. "
  "Gracias a ellos, es en este lugar donde las almas de los seres se "
  "encarnan y dan sus primeros pasos para vivir en este mundo.\n");

 AddDetail(({"torre de wizards","torre de Wizards","torre","Torre"}),
  "La torre de los Wizards es un edificio construido sobre una roca al "
  "este de la isla Limbo. En ella trabajan y se reunen los wizards, seres "
  "que ayudan a los dioses a crear este mundo, y ademas se encuentran una "
  "serie de servicios para resolver problemas, tales como la Justicia, que "
  "surjan con o entre los jugadores de Simauria.\n");

  AddDetail(({"fuente","letreros","indicadores","poste"}),
  "Se encuentra en medio del claro, tal vez deberias acercarte más para ver "
  "con más detalle.\n");

SetIntNoise("Solo el dulce trinar de los pajaros altera el silencio.\n");
SetIntSmell("Las flores inundan el bosque de una suave fragancia.\n");
SetLocate("isla Limbo");
SetIndoors(0);

AddExit("oeste",LIMBO("camino03"));
AddExit("este",LIMBO("camino05"));
AddExit("noroeste",LIMBO("camino07"));
AddExit("suroeste",LIMBO("camino08"));
}
