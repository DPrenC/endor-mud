#include "path.h"
inherit MURALLA;

create()
{
  ::create();

  SetIntShort("la torre Oeste");
  SetLongWrap(
    "Estás en la planta primera de la torre Oeste de la ciudad. "
    "Hacia el Norte y el Sur transcurre un pasillo por el interior de "
    "la muralla y si lo prefieres puedes subir o bajar por la escalera."
    );

 AddDetail(({"escalinata","escalera","escaleras"}),
"Ves una escalera construida de piedra que asciende en forma de caracol junto\n\
a las paredes de la torre.\n");

  AddExit("norte","piso1_29");
  AddExit("abajo","torre6");
  AddExit("sur","piso1_27");
  AddExit("arriba","piso2_28");

}
