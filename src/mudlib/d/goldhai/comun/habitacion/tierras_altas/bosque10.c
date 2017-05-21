#include "./path.h"
inherit GBOSQUE;

create()
{
  ::create();

  AddFlor();

  AddExit("norte","bosque11");
  AddExit("sur","bosque9");
  SetLocate("bosque djorn");
}
