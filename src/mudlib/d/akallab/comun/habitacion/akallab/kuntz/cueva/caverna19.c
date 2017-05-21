/*
DESCRIPCION  : Gran Caverna, mivel superior
FICHERO      : /d/akallab/comun/rooms/akallab/kuntz/cueva/caverna19.c
MODIFICACION : 22-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit K_CUEVA("caverna");

create() {
  piso=2;
  ::create();
  SetIntLong(QueryIntLong()+
    "Unos postes con un varias calaveras clavadas identifican la cueva que queda al "
    "suroeste como la del jefe de la tribu.\n");

  AddDetail(({"postes"}),
     "Son dos altos palos de madera clavados en el suelo, uno a cada lado de la "
     "entrada de la cueva. Ensartados en ellos hay varias calaveras.\n");

  AddDetail(({"calaveras"}),
     "Ensartadas en los postes que hay junto a la entrada de la cueva del jefe hay "
     "varias calaveras. Dirias que la mayor parte son de orcos, aunque tambien hay "
     "alguna humana y de algun gran animal salvaje. Las calaveras estan firmemente "
     "enganchadas a los postes y dudas que se puedan arrancar de alli.\n");

  AddExit("este",K_CUEVA("caverna18"));
  //AddExit("suroeste",K_TIENDA("cueva_jefe"));
  AddExit("noroeste",K_CUEVA("caverna20"));
  AddItem(PNJ("k_cueva/guardia"),REFRESH_DESTRUCT,2);
}
