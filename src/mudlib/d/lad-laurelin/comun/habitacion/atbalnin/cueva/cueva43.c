#include "path.h"
#include <door.h>
#include <properties.h>
inherit ATB_C("aleat_cueva");

create(){
  object ob;
  ::create();
  AddExit("este", ATB_C("cueva44"));
  AddExit("oeste", ATB_C("cueva42"));
}
