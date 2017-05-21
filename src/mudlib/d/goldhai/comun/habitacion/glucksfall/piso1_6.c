#include "path.h"
inherit MURALLA;

create()
{
  ::create();

  SetIntShort("la torre Nordeste");
  SetLongWrap(
    "Estás en la escalera de la torre Nordeste de la ciudad. "
    "Puedes continuar subiendo o bajando por la escalera. El pasillo que "
    "transcurre por el interior de la muralla sigue en dirección Norte y "
    "Este."
    );

 AddDetail(({"escalinata","escalera","escaleras"}),
"Ves una escalera construida de piedra que asciende en forma de caracol junto\n\
a las paredes de la torre.\n");

  AddExit("norte","piso1_5");
  AddExit("abajo","torre2");
  AddExit("este","piso1_7");
  AddExit("arriba","piso2_6");

}
