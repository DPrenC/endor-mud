#include "path.h"
inherit ATB_B("bosque_este");

create(){
  ::create();
  SetPathToCity("norte");

  AddExit("sur", ATB_B("bosque16"));
  AddExit("este", ATB_B("bosque24"));
}
