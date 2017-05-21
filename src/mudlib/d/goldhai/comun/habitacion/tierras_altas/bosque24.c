#include "./path.h"
inherit GBOSQUE;

create()
{
  ::create();

  AddExit("norte","bosque23");
  AddExit("sur","bosque25");
  SetLocate("bosque djorn");
}
