#include "path.h"
inherit ATB_B("bosque_norte");

create(){
  ::create();
  SetPathToCity("este");

  AddExit("norte", ATB_B("bosque32"));
  AddExit("sur", ATB_B("bosque27"));
  AddExit("este", ATB_CI("ciudad02"));
  AddExit("oeste", ATB_B("bosque29"));
}
