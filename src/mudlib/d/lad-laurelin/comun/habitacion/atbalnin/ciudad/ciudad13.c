#include "path.h"
#include "rooms.h"
inherit ATB_CI("std_ciudad");

create()
{
  ::create();
  SetIntLong(W("Ésta es la parte noroeste de la ciudad. En esta zona no se "
  	"puede decir que hayan muchas cosas interesantes, y si se dijera, "
  	"sería totalmente falso. El suelo es aburrido, el cielo es aburrido... "
  	"mejor sería que fueses hacia otra parte más entretenida.\n"));

  AddExit("sur", ATB_CI("ciudad06"));
  AddExit("sudeste", ATB_CI("ciudad14"));
}

