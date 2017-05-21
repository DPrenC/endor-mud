#include "path.h"
inherit ATB_B("bosque_sur");

create(){
  object portal;
  ::create();
  seteuid(getuid());
  SetPathToCity("norte");

  AddExit("norte", ATB_B("bosque18"));
  AddExit("sur", ATB_B("bosque04"));
  AddExit("este", ATB_B("bosque10"));

  portal=clone_object("/obj/monolito");
  portal->SetRaza("elfo");
  portal->move(TO);
}
