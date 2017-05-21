#include "./path.h"
inherit GBOSQUE;

create()
{
  ::create();

  AddExit("oeste","bosque13");
  AddExit("este","bosque15");
  SetLocate("bosque djorn");
}
