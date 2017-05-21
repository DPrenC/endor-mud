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
  AddExit("este", TBOSQUE("bosque048"));
  AddExit("oeste", TBOSQUE("bosque046"));
  AddExit("sur", TBOSQUE("bosque063"));
  AddExit("sudeste", TBOSQUE("bosque064"));
  AddExit("suroeste", TBOSQUE("bosque062"));
  AddExit("norte", TBOSQUE("bosque031"));
  AddExit("nordeste", TBOSQUE("bosque032"));
  AddExit("noroeste", TBOSQUE("bosque030"));
  ::salidas_cmd();
}
