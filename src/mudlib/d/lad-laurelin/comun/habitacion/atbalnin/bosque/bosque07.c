#include "path.h"
inherit ATB_B("bosque_sur");

create(){
  ::create();
  SetPathToCity("norte");

  AddExit("norte", ATB_B("bosque12"));
  AddExit("este", ATB_B("bosque08"));
  AddExit("oeste", ATB_B("bosque06"));
}
