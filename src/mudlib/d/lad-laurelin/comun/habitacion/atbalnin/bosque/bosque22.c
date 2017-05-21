#include "path.h"
inherit ATB_B("bosque_este");

create(){
  object portal;
  ::create();

  SetPathToCity("norte");

  portal=clone_object("obj/monolito");
  portal->SetRaza("medio-elfo");
  portal->move(TO);

  AddItem(PNJ("atbalnin/bosque/ent"), REFRESH_REMOVE, 1+random(2));
  AddExit("sur", ATB_B("bosque15"));
  AddExit("oeste", ATB_B("bosque21"));
}
