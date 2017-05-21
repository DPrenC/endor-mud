#include "path.h"
inherit MURALLA;

create()
{
  ::create();

  SetIntShort("la torre Noroeste");
  SetLongWrap(
    "Estás en la escalera de la torre Noroeste de la ciudad. Si vas al Norte "
    "llegarás al pasillo interior de la muralla. Puedes continuar subiendo o "
    "bajando por la escalera."
    );

 AddDetail(({"escalinata","escalera","escaleras"}),
"Ves una escalera construida de piedra que asciende en forma de caracol junto\n\
a las paredes de la torre.\n");

  AddExit("norte","piso1_2");
  AddExit("abajo","torre1");
  AddExit("arriba","piso2_31");
  SetLocate("Glucksfall");
}
