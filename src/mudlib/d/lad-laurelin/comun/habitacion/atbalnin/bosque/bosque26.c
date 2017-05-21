#include "path.h"
inherit ATB_B("bosque_norte");

create(){
  ::create();
  SetPathToCity("este");

  AddExit("norte", ATB_B("bosque29"));
  AddExit("este", ATB_B("bosque27"));
  AddExit("oeste", ATB_B("bosque25"));
}
