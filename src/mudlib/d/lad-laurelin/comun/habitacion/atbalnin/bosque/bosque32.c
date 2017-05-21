#include "path.h"
inherit ATB_B("bosque_norte");

create(){
  ::create();
  SetPathToCity("este");

  AddExit("norte", ATB_CI("ciudad00"));
  AddExit("sur", ATB_B("bosque30"));
  AddExit("este", ATB_CI("ciudad01"));
  AddExit("oeste", ATB_B("bosque31"));
}
