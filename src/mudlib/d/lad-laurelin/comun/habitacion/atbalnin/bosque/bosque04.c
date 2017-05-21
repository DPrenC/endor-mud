#include "path.h"
inherit ATB_B("bosque_sur");

create(){
  ::create();
  SetPathToCity("norte");

  AddExit("norte", ATB_B("bosque09"));
  AddExit("sur", ATB_B("bosque01"));
  AddExit("este", ATB_B("bosque05"));
  AddExit("oeste", ATB_B("bosque03"));
}
