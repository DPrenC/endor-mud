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
  AddExit("este", TBOSQUE("bosque120"));
  AddExit("oeste", TBOSQUE("bosque118"));
  AddExit("sur", TBOSQUE("bosque133"));
  AddExit("sudeste", TBOSQUE("bosque134"));
  AddExit("suroeste", TBOSQUE("bosque132"));
  AddExit("norte", TBOSQUE("bosque105"));
  AddExit("nordeste", TBOSQUE("bosque106"));
  AddExit("noroeste", TBOSQUE("bosque104"));
  ::salidas_cmd();
}
