#include "path.h"
#include <door.h>
#include <properties.h>
inherit ATB_C("aleat_cueva");

create(){
  object ob;
  ::create();
  AddExit("este", ATB_C("cueva27"));
  AddExit("suroeste", ATB_C("cueva25"));
}
