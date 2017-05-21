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
  AddExit("este", TBOSQUE("bosque017"));
  AddExit("sur", TBOSQUE("bosque032"));
  AddExit("oeste", TBOSQUE("bosque015"));
  AddExit("sudeste", TBOSQUE("bosque033"));
  AddExit("suroeste", TBOSQUE("bosque031"));
  ::salidas_cmd();
}
