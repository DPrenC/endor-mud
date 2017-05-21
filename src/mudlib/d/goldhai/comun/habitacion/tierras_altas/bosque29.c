#include "./path.h"
inherit GBOSQUE;

create()
{
  ::create();

  AddExit("este","bosque28");
  AddExit("sur","bosque30");
  AddExit("norte","bosque33");
  SetLocate("bosque djorn");
}
