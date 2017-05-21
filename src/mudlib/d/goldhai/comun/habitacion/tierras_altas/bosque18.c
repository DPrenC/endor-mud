#include "./path.h"
inherit GBOSQUE;

create()
{
  ::create();

  AddExit("oeste","bosque17");
  AddExit("norte","bosque19");
  AddExit("sur","bosque20");
  SetLocate("bosque djorn");
}
