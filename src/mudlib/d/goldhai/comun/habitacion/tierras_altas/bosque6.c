#include "./path.h"
inherit GBOSQUE;

create()
{
  ::create();

  AddExit("norte","bosque7");
  AddExit("sur","bosque5");
  AddExit("este","bosque2");
  SetLocate("bosque djorn");
}
