#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("este");
  SetPathToTrolls("nordeste");
  SetPathToGigants("suroeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque049"));
  AddExit("oeste", TBOSQUE("bosque047"));
  AddExit("sur", TBOSQUE("bosque064"));
  AddExit("sudeste", TBOSQUE("bosque065"));
  AddExit("suroeste", TBOSQUE("bosque063"));
  AddExit("norte", TBOSQUE("bosque032"));
  AddExit("nordeste", TBOSQUE("bosque033"));
  AddExit("noroeste", TBOSQUE("bosque031"));
  ::salidas_cmd();
}
