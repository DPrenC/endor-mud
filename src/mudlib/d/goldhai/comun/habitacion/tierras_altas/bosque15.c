#include "./path.h"
inherit GBOSQUE;

create()
{
  ::create();

  AddFlor();

  AddExit("oeste","bosque14");
  AddExit("sur","bosque16");
  SetLocate("bosque djorn");
}
