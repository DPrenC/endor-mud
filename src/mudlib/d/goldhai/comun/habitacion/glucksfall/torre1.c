#include "path.h"
inherit GROOM;

create()
{
  ::create();
  SetIntShort("la torre Noroeste");
  SetLongWrap(
    "Estás dentro de la torre noroeste de Glucksfall donde puedes ver "
    "una escalera de piedra que sube al primer piso. También tienes la "
    "opción de salir por la puerta situada en tu espalda."
    );
  SetIndoors(1);
  SetIntBright(50);
 AddDetail(({"puerta","entrada"}),
"Es una vieja puerta de madera abierta de par en par.\n");
 AddDetail(({"escalinata","escalera","escaleras"}),
"Ves una escalera construida de piedra que asciende en forma de caracol junto\n\
a las paredes de la torre.\n");

  AddExit("fuera","calle1");
  AddExit("arriba","piso1_31");
  SetLocate("Glucksfall");
}
