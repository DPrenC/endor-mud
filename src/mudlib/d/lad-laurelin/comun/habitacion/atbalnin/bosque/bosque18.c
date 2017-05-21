#include "path.h"
inherit ATB_B("bosque_norte");

create(){
  ::create();
  SetPathToCity("norte");

  AddExit("norte", ATB_B("bosque27"));
  AddExit("sur", ATB_B("bosque09"));
  AddExit("este", ATB_B("bosque19"));
}
