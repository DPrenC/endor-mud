#include "path.h"
#include <door.h>
#include <properties.h>
inherit ATB_C("aleat_cueva");

create(){
  object ob;
  ::create();
  AddExit("sudeste", ATB_C("cueva36"));
  AddExit("oeste", ATB_C("cueva34"));
}
