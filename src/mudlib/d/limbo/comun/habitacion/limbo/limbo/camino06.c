/*
DESCRIPCION  : Camino que conduce a la torre de Wizards
FICHERO      : /d/limbo/comun/habitacion/limbo/limbo/camino06.c
MODIFICACION : 14-01-97 [angor] Creacion.
*/

#include "./path.h"
#include <sounds.h>

inherit ROOM;

create() {
  ::create();
  SetIntShort("el camino hacia la torre de Wizards.");
  SetIntLong(
"A medida que el camino comienza a acercarse al mar, comienza a oirse a lo "
"lejos el sonido de las olas. El bosque aquí es muy denso y apenas se puede "
"divisar el cielo.\n");

   AddDetail(({"isla","isla Limbo","Limbo","limbo"}),
  "La isla Limbo es el lugar mágico de Simauria donde habitan los dioses. "
  "Gracias a ellos, es en este lugar donde las almas de los seres se "
  "encarnan y dan sus primeros pasos para vivir en este mundo.\n");

 AddDetail(({"torre de wizards","torre de Wizards","torre","Torre"}),
  "La torre de los Wizards es un edificio construido sobre una roca al "
  "este de la isla Limbo. En ella trabajan y se reunen los wizards, seres "
  "que ayudan a los dioses a crear este mundo, y además se encuentran una "
  "serie de servicios para resolver problemas, tales como la Justicia, que "
  "surjan con o entre los jugadores de Simauria.\n");

 SetIntNoise("Se oye a lo lejos el ruido del oleaje.\n");
 SetIntSmell("Las flores inundan el bosque de una suave fragancia.\n");
 SetLocate("isla Limbo");
 SetIndoors(0);

 SetSoundEnvironment(SND_AMBIENTES("olas"), 10);AddExit("oeste",LIMBO("camino05"));
 AddExit("este",LIMBO("camino11"));
}
