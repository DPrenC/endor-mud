#include "./path.h"
inherit GBOSQUE;

create()
{
  ::create();

  AddExit("norte","bosque21");
  AddExit("sur","bosque23");
  SetLocate("bosque djorn");
}
