#include "./path.h"
inherit GBOSQUE;

create()
{
  ::create();

  AddExit("norte","bosque15");
  AddExit("este","bosque17");
  SetLocate("bosque djorn");
}
