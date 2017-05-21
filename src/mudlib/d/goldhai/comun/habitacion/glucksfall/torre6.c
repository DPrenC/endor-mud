#include "path.h"
inherit GROOM;

create()
{
  ::create();
  SetPreIntShort("dentro de");
  SetIntShort("la torre");
  SetLongWrap(
    "Te encuentras en una enorme habitaci�n dentro de una de las torres "
    "que protegen a la ciudad. Puedes subir al primer piso por medio de "
    "la escalera de piedra situada delante de t�. Hay otra estancia algo "
    "m�s peque�a en el Este."
    );
  SetIndoors(1);
  SetIntBright(50);

 AddDetail(({"escalinata","escalera","escaleras"}),
"Ves una escalera construida de piedra que asciende en forma de caracol junto\n\
a las paredes de la torre.\n");

  AddExit("este","torre3");
  AddExit("arriba","piso1_28");

 AddItem(PNJ("glucksfall/elfo-oscuro"),REFRESH_DESTRUCT);

  SetLocate("Glucksfall");
}