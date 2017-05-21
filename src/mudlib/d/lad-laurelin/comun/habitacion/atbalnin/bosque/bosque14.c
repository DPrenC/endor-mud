#include "path.h"
inherit ATB_B("bosque_este");

create(){
  ::create();
  SetPathToCity("norte");

  AddItem(PNJ("atbalnin/bosque/ent"), REFRESH_REMOVE, 1+random(3));
  AddExit("norte", ATB_B("bosque21"));
  AddExit("este", ATB_B("bosque15"));
  AddExit("oeste", ATB_B("bosque13"));
}
