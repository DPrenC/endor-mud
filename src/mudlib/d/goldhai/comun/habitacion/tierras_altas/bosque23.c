#include "./path.h"
inherit GBOSQUE;

create()
{
  ::create();

  AddExit("norte","bosque22");
  AddExit("sur","bosque24");
  SetLocate("bosque djorn");
}
