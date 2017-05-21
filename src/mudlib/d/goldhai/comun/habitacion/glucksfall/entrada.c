#include "path.h"
inherit GROOM;

create()
{
  ::create();
  SetIntShort("la entrada norte de Glucksfall");
  SetLongWrap(
    "Esta es la entrada norte de la ciudad de Glucksfall un lugar bastante "
    "concurrido y donde no es muy recomendable permanecer mucho tiempo parado. "
    "Hacia el Oeste tienes la puerta norte y si vas hacia el Este llegarás a "
    "la avenida principal de la ciudad, llamada Djorn. Al Norte puedes entrar "
    "en una de las numerosas torres que bordean Glucksfall."
    );
  SetIndoors(0);
 AddDetail(({"puerta","entrada"}),
"Ves una enorme puerta de madera de dos palmos de ancho.\n");

  AddExit("oeste","puerta_norte");
  AddExit("este","calle3");
  AddExit("norte","torre3");

 AddItem(PNJ("glucksfall/kas"),REFRESH_DESTRUCT);

  SetLocate("Glucksfall");
}
