#include "path.h"
#include <nightday.h>
#include <moving.h>
#include <properties.h>


inherit DOM_STD+"restaurante";

create()
{
  ::create();

  SetIntLong(W("Estás en una gran cabaña que hace la función de "
  	"restaurante. La luz entra por las grandes aperturas que hay en "
  	"la pared en forma de ventanas. Cerca de tí ves un menú "
	"que puedes leer.\n"));
  SetIntShort("un restaurante");
  SetLocate("la ciudad de Atbalnin");

  SetIntNoise("Oyes las conversaciones de los comensales.\n");
  SetIntSmell("Huele a comida.\n");

  AddDrink(({"vino de flores", "vino"}), "un", 0, 5, 8);
  AddDrink(({"cerveza negra", "cerveza"}), "una", 5, 10, 10);
  AddDrink("aguamiel", "un", 10, 10, 10);
  AddDrink("zumo", "un", 5, 0, 10);

  AddFood(({"porcion de ciervo", "ciervo"}), "una", 0, 40);
  AddFood(({"jabalí relleno", "jabali relleno", "jabalí"}), "un", 10, 60);
  AddFood(({"ave en salsa", "ave"}), "un", 0, 25);

  AddSpecial(({"sopa casera", "sopa"}), "una", 0, 0, 15, 15);

  AddExit("salir", ATB_CI("ciudad16"));
}

int allow_enter(int method, mixed extra)
{
  int state;
  if (TP==PO)
  {
    if (method!=M_GO) return ::allow_enter(method, extra);

    state=NIGHTDAY->QueryState();
    if ((state>=ND_PREDAWN && state<=ND_PRENOON) && TP->Query(P_LSTATE)!=LSTATE_GHOST)
    {
      write("El restaurante está cerrado por las mañanas.\n");
      return ME_NO_ENTER;
    }
  }
  return ::allow_enter(method, extra);
}

