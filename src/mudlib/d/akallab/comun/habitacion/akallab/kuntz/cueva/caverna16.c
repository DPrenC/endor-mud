/*
DESCRIPCION  : Gran Caverna, nivel superior
FICHERO      : /d/akallab/comun/rooms/akallab/kuntz/cueva/caverna16.c
MODIFICACION : 22-10-98 [Angor@Simauria] Creacion
*/

#include "path.h"
inherit K_CUEVA("caverna");

create() {
  piso=2;
  ::create();
  SetIntLong(QueryIntLong()+
    "La entrada de la cueva que queda al oeste esta pintada con toda un serie de "
    "extranyos signos. No sabes lo que significan, pero son una senyal inequivoca "
    "de que aqui vive el chaman de la tribu.\n");

  AddDetail(({"signos","figuras"}),
     "Son una serie de pinturas murales sobre las paredes de la entrada de la cueva. "
     "Crees reconocer figuras que podrian ser troll cazando y luchando contra seres "
     "mostruosos. Ademas existen otras figuras mas bien geometricas que no tienes ni "
     "idea de que deben significar.\n");

  AddExit("este",K_TIENDA("cueva_chaman"));
  AddExit("sur",K_CUEVA("caverna17"));
  AddExit("noroeste",K_CUEVA("caverna23"));
}
