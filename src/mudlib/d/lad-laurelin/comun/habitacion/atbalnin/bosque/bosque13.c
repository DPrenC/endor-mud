#include "path.h"
inherit ATB_B("bosque_este");

create(){
  ::create();
  SetPathToCity("norte");

  AddExit("norte", ATB_B("bosque20"));
  AddExit("sur", ATB_B("bosque08"));
  AddExit("este", ATB_B("bosque14"));
  AddExit("oeste", ATB_B("bosque12"));
}
