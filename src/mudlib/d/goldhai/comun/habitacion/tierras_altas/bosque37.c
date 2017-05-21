#include "./path.h"
inherit GBOSQUE;

create()
{
  ::create();

  AddExit("este","bosque38");
  AddExit("oeste","bosque36");
  AddExit("sur","bosque39");
  SetLocate("bosque djorn");
}
