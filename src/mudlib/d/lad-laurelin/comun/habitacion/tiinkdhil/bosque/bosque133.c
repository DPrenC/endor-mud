#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("nordeste");
  SetPathToTrolls("noroeste");
  SetPathToGigants("noroeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque134"));
  AddExit("oeste", TBOSQUE("bosque132"));
  AddExit("sur", TBOSQUE("bosque144"));
  AddExit("sudeste", TBOSQUE("bosque145"));
  AddExit("suroeste", TBOSQUE("bosque143"));
  AddExit("norte", TBOSQUE("bosque119"));
  AddExit("nordeste", TBOSQUE("bosque120"));
  AddExit("noroeste", TBOSQUE("bosque118"));
  ::salidas_cmd();
}
