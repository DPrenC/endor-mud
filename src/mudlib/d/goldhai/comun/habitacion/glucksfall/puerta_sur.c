#include "path.h"
inherit GROOM;

create()
{
  ::create();
  SetIntShort("las puertas de Glucksfall");
  SetLongWrap(
    "Estás cruzando las puertas de la ciudad de Glucksfall. Hacia el "
    "Oeste solo encontrarás bosque pero puedes entrar en la ciudad "
    "y ver lo que ella te ofrece."
    );
  SetIndoors(0);
 AddDetail(({"puerta","entrada"}),
"Ves una enorme puerta de madera de dos palmos de ancho.\n");

  AddExit("este","entrada_sur");
  AddExit("oeste",TALTAS("bosque26"));
  SetLocate("Glucksfall");
}