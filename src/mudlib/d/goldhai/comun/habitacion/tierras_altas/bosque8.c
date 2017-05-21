#include "./path.h"
inherit GBOSQUE;

create()
{
  ::create();

  AddExit("norte","bosque9");
  AddExit("sur","bosque7");
  SetLocate("bosque djorn");
}
