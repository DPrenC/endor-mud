#include "path.h"
inherit GROOM;

create()
{
  ::create();
  SetIntShort("la entrada sur de Glucksfall");
  SetLongWrap(
    "Esta es la entrada sur de la ciudad de Glucksfall. Aquí no hay nada "
    "interesante así que será mejor que decidas que quieres hacer, si salir "
    "de la ciudad por el Oeste o bien permanecer en ella en sentido contrario."
    );
  SetIndoors(0);
 AddDetail(({"puerta","entrada"}),
"Ves una enorme puerta de madera de dos palmos de ancho.\n");

  AddExit("oeste","puerta_sur");
  AddExit("este","calle8");

  SetLocate("Glucksfall");
}
