#include "./path.h"
inherit GBOSQUE;

create()
{
  ::create();

  AddExit("oeste","bosque3");
  AddExit("este","bosque31");
  SetLocate("bosque djorn");
}
