#include "./path.h"
inherit GBOSQUE;

create()
{
  ::create();

  AddExit("este","bosque30");
  AddExit("oeste","bosque32");
  SetLocate("bosque djorn");
}
