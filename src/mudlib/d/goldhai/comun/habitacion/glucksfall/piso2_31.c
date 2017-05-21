#include "path.h"
inherit MURALLA;

create()
{
  ::create();

  SetIntShort("la torre Noroeste");
  SetLongWrap(
    "Estás en el piso segundo de la torre Noroeste. Ves una escalera de piedra "
    "que te permitirá bajar al primer piso aunque también puedes ir al Norte y "
    "caminar por el pasillo interior de la muralla."
    );

 AddDetail(({"escalinata","escalera","escaleras"}),
"Ves una escalera construida de piedra que asciende en forma de caracol junto\n\
a las paredes de la torre.\n");

  AddExit("norte","piso2_2");
  AddExit("abajo","piso1_31");
  SetLocate("Glucksfall");
}
