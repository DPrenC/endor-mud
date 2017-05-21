#include "path.h"
inherit ATB_B("bosque_este");

create(){
  ::create();
  SetPathToCity("norte");

  AddItem(PNJ("atbalnin/bosque/ent"), REFRESH_REMOVE, 1+random(4));
  AddExit("norte", ATB_B("bosque23"));
  AddExit("oeste", ATB_B("bosque15"));
}
