#include "path.h"
inherit ATB_B("bosque_este");

create(){
  ::create();
  SetPathToCity("norte");

  AddExit("norte", ATB_B("bosque22"));
  AddExit("este", ATB_B("bosque16"));
  AddExit("oeste", ATB_B("bosque14"));
}
