#include "path.h"
inherit MURALLA;

create()
{
  ::create();

  SetIntShort("la torre Nordeste");
  SetLongWrap(
    "Estás en la escalera de la torre Nordeste de la ciudad justo en el piso segundo."
    "Una escalera de piedra te permite bajar a la planta primera."
    );

 AddDetail(({"escalinata","escalera","escaleras"}),
"Ves una escalera construida de piedra que asciende en forma de caracol junto\n\
a las paredes de la torre.\n");

  AddExit("norte","piso2_5");
  AddExit("abajo","piso1_6");
  AddExit("este","piso2_7");

}
