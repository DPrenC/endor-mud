#include "./path.h"
inherit GBOSQUE;

create()
{
  ::create();

  AddFlor();

  AddExit("norte","bosque29");
  AddExit("oeste","bosque31");
  SetLocate("bosque djorn");
}
