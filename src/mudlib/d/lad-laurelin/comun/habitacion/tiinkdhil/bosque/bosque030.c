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
  AddExit("este", TBOSQUE("bosque031"));
  AddExit("sur", TBOSQUE("bosque046"));
  AddExit("oeste", TBOSQUE("bosque029"));
  AddExit("norte", TBOSQUE("bosque014"));
  AddExit("sudeste", TBOSQUE("bosque047"));
  AddExit("suroeste", TBOSQUE("bosque045"));
  AddExit("noroeste", TBOSQUE("bosque013"));
  AddExit("nordeste", TBOSQUE("bosque015"));
  ::salidas_cmd();
}
