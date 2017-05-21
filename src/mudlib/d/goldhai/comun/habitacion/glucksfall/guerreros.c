#include "path.h"
inherit ROOM;
create()
{
  ::create();
  SetIntShort("una habitación en obras");
  SetIntLong(
    "La Habitacion Esta en Obras. "
    "De Momento Solo Esta la Conectividad. "
    "Disculpa las Molestias. :) "
    );
  SetIndoors(1);
  SetIntBright(50);
  AddExit("oeste","calle4");
  SetLocate("Glucksfall");
}
