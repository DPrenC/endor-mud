#include "./path.h"
inherit GBOSQUE;

create()
{
  ::create();

  AddExit("sur","bosque1");
  AddExit("norte","bosque40");
  SetLocate("bosque djorn");
}
