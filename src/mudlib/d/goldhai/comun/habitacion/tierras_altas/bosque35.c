#include "./path.h"
inherit GBOSQUE;

create()
{
  ::create();

  AddFlor();

  AddExit("este","bosque36");
  AddExit("oeste","bosque9");
  SetLocate("bosque djorn");
}
