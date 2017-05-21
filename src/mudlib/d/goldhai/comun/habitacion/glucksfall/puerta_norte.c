#include "path.h"
inherit GROOM;

create()
{
  ::create();
  SetIntShort("las puertas de Glucksfall");
  SetLongWrap(
    "Est�s cruzando las puertas de la ciudad de Glucksfall. Hacia el "
    "Oeste solo encontrar�s bosque y hacia el Este podr�s entrar en "
    "la ciudad y disfrutar de sus comercios."
    );
  SetIndoors(0);
 AddDetail(({"puerta","entrada"}),
"Ves una enorme puerta de madera de dos palmos de ancho.\n");

  AddExit("este","entrada");
  AddExit("oeste",TALTAS("bosque21"));
  SetLocate("Glucksfall");
}