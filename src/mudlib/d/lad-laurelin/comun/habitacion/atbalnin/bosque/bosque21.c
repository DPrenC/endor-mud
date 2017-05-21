#include "path.h"
inherit ATB_B("bosque_este");

create(){
  ::create();
  SetPathToCity("norte");

  AddExit("sur", ATB_B("bosque14"));
  AddExit("este", ATB_B("bosque22"));
  AddExit("oeste", ATB_B("bosque20"));
}
