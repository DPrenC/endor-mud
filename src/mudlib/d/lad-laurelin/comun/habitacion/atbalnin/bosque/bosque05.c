#include "path.h"
inherit ATB_B("bosque_sur");

create(){
  ::create();
  SetPathToCity("norte");

  AddExit("norte", ATB_B("bosque10"));
  AddExit("sur", ATB_B("bosque02"));
  AddExit("este", ATB_B("bosque06"));
  AddExit("oeste", ATB_B("bosque04"));
}
