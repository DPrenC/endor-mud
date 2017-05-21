#include "./path.h"
inherit GBOSQUE;

create()
{
  ::create();

  AddExit("oeste","bosque11");
  AddExit("norte","bosque13");
  SetLocate("bosque djorn");
}
