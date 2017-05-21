#include "path.h"
inherit ATB_B("bosque_norte");

create(){
  ::create();
  SetPathToCity("este");

  AddExit("norte", ATB_B("bosque31"));
  AddExit("sur", ATB_B("bosque26"));
  AddExit("este", ATB_B("bosque30"));
}
