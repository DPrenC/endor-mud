#include "path.h"
inherit MURALLA;

create()
{
  ::create();

  SetIntShort("la torre Suroeste");
  SetLongWrap(
    "Estás en la planta primera de la torre Suroeste de la ciudad. "
    "Hacia el Este y el Oeste transcurre un pasillo por el interior de "
    "la muralla."
    );

 AddDetail(({"escalinata","escalera","escaleras"}),
"Ves una escalera construida de piedra que asciende en forma de caracol junto\n\
a las paredes de la torre.\n");

  AddExit("este","piso1_18");
  AddExit("abajo","torre4");
  AddExit("oeste","piso1_20");
  AddExit("arriba","piso2_19");

}
