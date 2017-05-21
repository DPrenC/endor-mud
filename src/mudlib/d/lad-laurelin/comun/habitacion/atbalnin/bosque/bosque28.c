#include "path.h"
inherit ATB_B("bosque_norte");

create(){
  ::create();
  SetPathToCity("este");

  AddExit("norte", ATB_CI("ciudad02"));
  AddExit("este", ATB_CI("ciudad03"));
  AddExit("oeste", ATB_B("bosque27"));
}
