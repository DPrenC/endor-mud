#include "path.h"
inherit ATB_B("bosque_sur");

create(){
  ::create();
  SetPathToCity("norte");

  AddExit("norte", ATB_B("bosque11"));
  AddExit("este", ATB_B("bosque07"));
  AddExit("oeste", ATB_B("bosque05"));
}
