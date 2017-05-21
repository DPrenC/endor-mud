#include "./path.h"
inherit GBOSQUE;

create()
{
  ::create();

  AddExit("norte","bosque1");
  AddExit("este","bosque33");
  SetLocate("bosque djorn");
}
