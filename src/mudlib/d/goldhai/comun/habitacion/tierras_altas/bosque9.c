#include "./path.h"
inherit GBOSQUE;

create()
{
  ::create();

  AddExit("norte","bosque10");
  AddExit("sur","bosque8");
  AddExit("este","bosque35");
  SetLocate("bosque djorn");
}
