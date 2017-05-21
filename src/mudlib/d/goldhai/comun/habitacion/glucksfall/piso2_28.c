#include "path.h"
inherit MURALLA;

create()
{
  ::create();

  SetIntShort("la torre Oeste");
  SetLongWrap(
    "Estás en la planta segunda de la torre Oeste de la ciudad. "
    "Hacia el Norte y el Sur transcurre un pasillo por el interior de "
    "la muralla. Si no quieres no tienes otra opción que bajar a la "
    "planta primera."
    );

 AddDetail(({"escalinata","escalera","escaleras"}),
"Ves una escalera construida de piedra que asciende en forma de caracol junto\n\
a las paredes de la torre.\n");

  AddExit("abajo","piso1_28");
  AddExit("norte","piso2_29");
  AddExit("sur","piso2_27");

}
