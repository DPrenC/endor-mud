#include "path.h"
inherit MURALLA;

create()
{
  ::create();


  SetIntShort("la torre Suroeste");
  SetLongWrap(
    "Estás en la planta segunda de la torre Suroeste de la ciudad. "
    "Hacia el Este y el Oeste transcurre un pasillo por el interior de "
    "la muralla y si lo prefieres puedes bajar por la escalera."
    );

 AddDetail(({"escalinata","escalera","escaleras"}),
"Ves una escalera construida de piedra que asciende en forma de caracol junto\n\
a las paredes de la torre.\n");

  AddExit("este","piso2_18");
  AddExit("abajo","piso1_19");
  AddExit("oeste","piso2_20");

}
