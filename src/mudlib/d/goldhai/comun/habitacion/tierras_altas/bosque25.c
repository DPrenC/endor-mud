#include "./path.h"
inherit GBOSQUE;

create()
{
  ::create();

  AddFlor();

  AddExit("norte","bosque24");
  AddExit("sur","bosque26");
  SetLocate("bosque djorn");
}
