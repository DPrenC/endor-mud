#include "path.h"
#include <door.h>
#include <properties.h>
inherit ATB_C("aleat_cueva");

create(){
  object ob;
  ::create();
  AddExit("oeste", ATB_C("cueva32"));
  AddExit("nordeste", ATB_C("cueva34"));
}
