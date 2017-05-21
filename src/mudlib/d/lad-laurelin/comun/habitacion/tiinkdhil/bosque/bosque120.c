#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("nordeste");
  SetPathToTrolls("nordeste");
  SetPathToGigants("noroeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque121"));
  AddExit("oeste", TBOSQUE("bosque119"));
  AddExit("sur", TBOSQUE("bosque134"));
  AddExit("sudeste", TBOSQUE("bosque135"));
  AddExit("suroeste", TBOSQUE("bosque133"));
  AddExit("norte", TBOSQUE("bosque106"));
  AddExit("nordeste", TBOSQUE("bosque107"));
  AddExit("noroeste", TBOSQUE("bosque105"));
  ::salidas_cmd();
}
