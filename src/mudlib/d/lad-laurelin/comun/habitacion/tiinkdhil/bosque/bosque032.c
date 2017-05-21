#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("sudeste");
  SetPathToTrolls("este");
  SetPathToGigants("suroeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque033"));
  AddExit("sur", TBOSQUE("bosque048"));
  AddExit("oeste", TBOSQUE("bosque031"));
  AddExit("norte", TBOSQUE("bosque016"));
  AddExit("sudeste", TBOSQUE("bosque049"));
  AddExit("suroeste", TBOSQUE("bosque047"));
  AddExit("noroeste", TBOSQUE("bosque015"));
  AddExit("nordeste", TBOSQUE("bosque017"));
  ::salidas_cmd();
}
