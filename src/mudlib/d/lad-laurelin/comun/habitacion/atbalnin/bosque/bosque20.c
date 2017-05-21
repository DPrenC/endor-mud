#include "path.h"
inherit ATB_B("bosque_este");

create(){
  ::create();
  SetPathToCity("norte");

  AddExit("sur", ATB_B("bosque13"));
  AddExit("este", ATB_B("bosque21"));
}
