#include "path.h"
#include "rooms.h"
inherit ATB_CI("std_ciudad");

create()
{
  ::create();
  SetIntLong(W("�sta es la parte noroeste de la ciudad. En esta zona no se "
  	"puede decir que hayan muchas cosas interesantes, y si se dijera, "
  	"ser�a totalmente falso. El suelo es aburrido, el cielo es aburrido... "
  	"mejor ser�a que fueses hacia otra parte m�s entretenida.\n"));

  AddExit("sur", ATB_CI("ciudad06"));
  AddExit("sudeste", ATB_CI("ciudad14"));
}

