#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("noroeste");
  SetPathToTrolls("noroeste");
  SetPathToGigants("nordeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque256"));
  AddExit("oeste", TBOSQUE("bosque254"));
  AddExit("sur", TBOSQUE("bosque266"));
  AddExit("sudeste", TBOSQUE("bosque267"));
  AddExit("suroeste", TBOSQUE("bosque265"));
  AddExit("norte", TBOSQUE("bosque244"));
  AddExit("nordeste", TBOSQUE("bosque245"));
  AddExit("noroeste", TBOSQUE("bosque243"));
  ::salidas_cmd();
}
