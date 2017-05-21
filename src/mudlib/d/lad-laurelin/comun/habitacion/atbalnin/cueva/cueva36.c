#include "path.h"
#include <door.h>
#include <properties.h>
inherit ATB_C("aleat_cueva");

create(){
  object ob;
  ::create();
  AddExit("noroeste", ATB_C("cueva35"));
  AddExit("este", ATB_C("cueva37"));
}
