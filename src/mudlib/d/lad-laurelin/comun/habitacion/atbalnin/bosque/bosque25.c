#include "path.h"
inherit ATB_B("bosque_norte");

create(){
  ::create();
  SetPathToCity("este");

  AddExit("sur", ATB_B("bosque17"));
  AddExit("este", ATB_B("bosque26"));
}
