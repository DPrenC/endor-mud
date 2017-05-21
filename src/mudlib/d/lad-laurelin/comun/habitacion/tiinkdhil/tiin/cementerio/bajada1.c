
#include <rooms.h>

#include <properties.h>
#include "path.h"

inherit ROOM;

create()
{
  ::create();
  SetIntShort("el cementerio");
  SetIntLong("\n"
    );
  SetIndoors(0);
  SetIntSmell(
    "Un olor a podrido se extiende por el ambiente poco a poco.\n"
    );
  SetIntNoise(
    "Ruidos como de arañazos se escuchan a lo lejos.\n"
    );
  AddExit("sur",ALUTIIN("cementerio/camino8"));
  SetLocate("cementerio2");
}
 