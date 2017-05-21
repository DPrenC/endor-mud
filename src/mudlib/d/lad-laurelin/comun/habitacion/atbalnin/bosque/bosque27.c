#include "path.h"
inherit ATB_B("bosque_norte");

create(){
  ::create();
  SetPathToCity("este");

  AddExit("norte", ATB_B("bosque30"));
  AddExit("sur", ATB_B("bosque18"));
  AddExit("este", ATB_B("bosque28"));
  AddExit("oeste", ATB_B("bosque26"));
}
