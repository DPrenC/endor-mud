#include "./path.h"
inherit GBOSQUE;

create()
{
  ::create();

  AddExit("oeste","bosque40");
  AddExit("norte","bosque37");
  SetLocate("bosque djorn");
}
