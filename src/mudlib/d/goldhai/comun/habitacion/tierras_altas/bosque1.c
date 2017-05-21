#include "./path.h"
inherit GBOSQUE;

create()
{
  ::create();

  AddExit("oeste","bosque2");
  AddExit("sur","bosque34");
  AddExit("norte","bosque41");
  SetLocate("bosque djorn");
}
