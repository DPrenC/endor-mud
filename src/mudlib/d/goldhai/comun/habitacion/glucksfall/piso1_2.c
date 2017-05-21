#include "path.h"
inherit MURALLA;

create()
{
  ::create();

  AddExit("oeste","piso1_1");
  AddExit("sur","piso1_31");
  AddExit("este","piso1_3");

}
