#include "./path.h"
inherit GBOSQUE;

create()
{
  ::create();

  AddFlor();

  AddExit("sur","bosque41");
  AddExit("este","bosque39");
  SetLocate("bosque djorn");
}
