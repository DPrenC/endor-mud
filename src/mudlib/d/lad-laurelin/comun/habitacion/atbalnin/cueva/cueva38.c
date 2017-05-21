#include "path.h"
#include <door.h>
#include <properties.h>
inherit ATB_C("aleat_cueva");

create(){
  object ob;
  ::create();
  AddExit("este", ATB_C("cueva39"));
  AddExit("noroeste", ATB_C("cueva23"));
}
