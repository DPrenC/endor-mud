#include "path.h"
inherit ATB_B("bosque_sur");

create(){
  ::create();
  SetPathToCity("norte");

  AddExit("norte", ATB_B("bosque04"));
  AddExit("sur", ATB_B("bosque00"));
  AddExit("este", ATB_B("bosque02"));
}
