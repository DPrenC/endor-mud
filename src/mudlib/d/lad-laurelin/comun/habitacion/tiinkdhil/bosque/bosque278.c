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
  AddExit("este", TBOSQUE("bosque279"));
  AddExit("oeste", TBOSQUE("bosque277"));
  AddExit("sur", TBOSQUE("bosque284"));
  AddExit("sudeste", TBOSQUE("bosque285"));
  AddExit("suroeste", TBOSQUE("bosque283"));
  AddExit("norte", TBOSQUE("bosque267"));
  AddExit("nordeste", TBOSQUE("bosque268"));
  AddExit("noroeste", TBOSQUE("bosque266"));
  ::salidas_cmd();
}
