#include "./path.h"
inherit GBOSQUE;

create()
{
  ::create();

  AddExit("oeste","bosque16");
  AddExit("este","bosque18");
  SetLocate("bosque djorn");
}
