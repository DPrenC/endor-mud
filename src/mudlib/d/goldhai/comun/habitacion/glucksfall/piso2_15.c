#include "path.h"
inherit MURALLA;

create()
{
  ::create();

  SetIntShort("la torre Sudeste");
  SetLongWrap(
    "Estás en la planta segunda de la torre Sudeste de la ciudad. "
    "Hacia el Norte y el Sur transcurre un pasillo por el interior de "
    "la muralla. Si no quieres no tienes otra opción que bajar a la "
    "planta primera."
    );

 AddDetail(({"escalinata","escalera","escaleras"}),
"Ves una escalera construida de piedra que asciende en forma de caracol junto\n\
a las paredes de la torre.\n");

  AddExit("norte","piso2_14");
  AddExit("sur","piso2_16");
  AddExit("abajo","piso1_15");

}
