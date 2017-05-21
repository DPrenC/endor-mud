#include "path.h"
inherit ATB_B("bosque_sur");

create(){
  ::create();
  SetPathToCity("norte");

  AddExit("sur", ATB_B("bosque06"));
  AddExit("este", ATB_B("bosque12"));
  AddExit("oeste", ATB_B("bosque10"));
}
