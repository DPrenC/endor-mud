#include "path.h"
inherit GROOM;

create()
{
  ::create();
  SetPreIntShort("dentro de");
  SetIntShort("la torre");
  SetLongWrap(
    "Te encuentras en una pequeña estancia dentro de una de las torres "
    "de la ciudad. Al Oeste puedes ver una habitación bastante grande con "
    "lo que parece ser una escalera. Tienes la entrada norte de Glucksfall "
    "si sales por el sur."
    );
  SetIndoors(1);
  SetIntBright(50);
 AddDetail(({"puerta","entrada"}),
"Es una vieja puerta de madera abierta de par en par.\n");

  AddExit("oeste","torre6");
  AddExit("fuera","entrada");
  SetLocate("Glucksfall");
}