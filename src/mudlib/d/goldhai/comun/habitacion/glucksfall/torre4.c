#include "path.h"
inherit GROOM;

create()
{
  ::create();
  SetIntShort("la torre Suroeste");
  SetLongWrap(
    "Estás dentro de la torre suroeste de Glucksfall donde puedes ver "
    "una escalera de piedra que sube al primer piso. También puedes "
    "salir por la puerta y llegar a la avenida Djorn."
    );
  SetIndoors(1);
  SetIntBright(50);
 AddDetail(({"puerta","entrada"}),
"Es una vieja puerta de madera abierta de par en par.\n");
 AddDetail(({"escalinata","escalera","escaleras"}),
"Ves una escalera construida de piedra que asciende en forma de caracol junto\n\
a las paredes de la torre.\n");

  AddExit("fuera","calle9");
  AddExit("arriba","piso1_19");
  SetLocate("Glucksfall");
}
