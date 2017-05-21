#include "./path.h"
inherit GBOSQUE;

create()
{
  ::create();

  AddExit("norte","bosque5");
  AddExit("sur","bosque3");
  SetLocate("bosque djorn");
}
