#include "./path.h"
inherit GBOSQUE;

create()
{
  ::create();

  AddExit("norte","bosque6");
  AddExit("sur","bosque4");
  SetLocate("bosque djorn");
}
