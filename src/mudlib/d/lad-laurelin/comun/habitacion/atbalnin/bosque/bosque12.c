#include "path.h"
inherit ATB_B("bosque_sur");

create(){
  ::create();
  SetPathToCity("norte");

  AddExit("sur", ATB_B("bosque07"));
  AddExit("este", ATB_B("bosque13"));
  AddExit("oeste", ATB_B("bosque11"));
}
