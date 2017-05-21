#include "./path.h"
inherit GBOSQUE;

create()
{
  ::create();

  AddExit("norte","bosque8");
  AddExit("sur","bosque6");
  SetLocate("bosque djorn");
}
