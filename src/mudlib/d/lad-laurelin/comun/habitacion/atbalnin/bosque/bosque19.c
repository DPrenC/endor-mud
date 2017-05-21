#include "path.h"
inherit ATB_B("bosque_norte");

create(){
  ::create();
  SetPathToCity("oeste");

  AddExit("sur", ATB_B("bosque10"));
  AddExit("oeste", ATB_B("bosque18"));
}
