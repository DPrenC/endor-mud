#include "path.h"
inherit ATB_B("bosque_sur");

create(){
  ::create();
  SetPathToCity("este");

  AddExit("este", ATB_B("bosque04"));
}
