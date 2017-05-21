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
  AddExit("este", TBOSQUE("bosque018"));
  AddExit("sur", TBOSQUE("bosque033"));
  AddExit("oeste", TBOSQUE("bosque016"));
  AddExit("sudeste", TBOSQUE("bosque034"));
  AddExit("suroeste", TBOSQUE("bosque032"));
  ::salidas_cmd();
}
