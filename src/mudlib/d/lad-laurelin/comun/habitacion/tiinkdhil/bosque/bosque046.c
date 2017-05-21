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
  AddExit("este", TBOSQUE("bosque047"));
  AddExit("oeste", TBOSQUE("bosque045"));
  AddExit("sur", TBOSQUE("bosque062"));
  AddExit("sudeste", TBOSQUE("bosque063"));
  AddExit("suroeste", TBOSQUE("bosque061"));
  AddExit("norte", TBOSQUE("bosque030"));
  AddExit("nordeste", TBOSQUE("bosque031"));
  AddExit("noroeste", TBOSQUE("bosque029"));
  ::salidas_cmd();
}
