/*
DESCRIPCION  : Camino que conduce a la torre de Wizards
FICHERO      : /d/limbo/comun/habitacion/limbo/limbo/camino05.c
MODIFICACION : 13-01-97 [Angor@Simauria] Creacion.
               30-08-98 [Angor@Simauria] Retoques varios
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit ROOM;

create() {
  ::create();
  SetIntShort("el camino hacia la torre de Wizards");
  SetIntLong(
"El camino adoquinado de piedra blanca continua su lento descenso hacia el este "
"de la isla, donde se haya sobre una peña la torre de los Wizards. A medida que "
"avanzas hacia el este, el bosque se hace más denso. Junto a un viejo tronco que "
"hay al lado del camino, crecen un conjunto de pequeñas setas de color pardo.\n");

   AddDetail(({"tronco","viejo tronco","setas junto al tronco"}),
  "Un pequeño grupo de setas crecen apiñadas al pie de un viejo tronco que hay "
  "junto al camino. El hecho de que el tronco este medio podrido por la humedad ha "
  "favorecido sin duda el crecimiento de estos hongos. El aspecto de las setas no "
  "parece peligroso, pero no sabes si realmente son comestibles.\n");

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

SetIntNoise("Solo el dulce trinar de los pajaros altera el silencio.\n");
SetIntSmell("Las flores inundan el bosque de una suave fragancia.\n");
SetLocate("isla Limbo");
SetIndoors(0);

AddExit("oeste",LIMBO("camino04"));
AddExit("este",LIMBO("camino06"));
AddItem(HERBS("seta_narcotica"), REFRESH_REMOVE);
}
