#include "path.h"
inherit ROOM;
create()
{
  ::create();
  SetIntShort("el cementerio");
  SetIntLong(
    );
  SetIndoors(0);
  SetIntSmell(
    "Un olor a podrido se extiende por el ambiente poco a poco.\n"
    );
  SetIntNoise(
    "Ruidos como de arañazos se escuchan a lo lejos.\n"
    );
  AddExit("sur","camino8.c");
  SetLocate("cementerio2");
}
