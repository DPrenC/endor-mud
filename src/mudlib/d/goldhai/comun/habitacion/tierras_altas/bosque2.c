#include "./path.h"
inherit GBOSQUE;

create()
{
  ::create();

  AddExit("oeste","bosque6");
  AddExit("este","bosque1");
  SetLocate("bosque djorn");
}
