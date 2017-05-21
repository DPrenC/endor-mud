#include "./path.h"
inherit GBOSQUE;

create()
{
  ::create();

  AddExit("norte","bosque4");
  AddExit("este","bosque32");
  SetLocate("bosque djorn");
}
