#include "path.h"
inherit MURALLA;

create()
{
  ::create();

  AddExit("este","piso1_19");
  AddExit("norte","piso1_21");

  AddItem("/guilds/conjuradores/pergamino/pergamino_hogaza",REFRESH_REMOVE,1);
}
