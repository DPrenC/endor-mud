#include "path.h"
inherit GROOM;

create()
{
  ::create();
  SetIntShort("la torre Nordeste");
  SetLongWrap(
    "Estás dentro de la torre nordeste de Glucksfall. Una enorme "
    "escalera de piedra asciende hasta el primer piso. Puedes ver "
    "la calle a través de la puerta que está abierta."
    );

  SetIndoors(1);
  SetIntBright(50);
 AddDetail(({"puerta","entrada"}),
"Es una vieja puerta de madera abierta de par en par.\n");
 AddDetail(({"escalinata","escalera","escaleras"}),
"Ves una escalera construida de piedra que asciende en forma de caracol junto\n\
a las paredes de la torre.\n");

  AddExit("fuera","calle1");
  AddExit("arriba","piso1_6");
  SetLocate("Glucksfall");
}
