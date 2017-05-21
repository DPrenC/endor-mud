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
  AddExit("este", TBOSQUE("bosque133"));
  AddExit("oeste", TBOSQUE("bosque131"));
  AddExit("sur", TBOSQUE("bosque143"));
  AddExit("sudeste", TBOSQUE("bosque144"));
  AddExit("norte", TBOSQUE("bosque118"));
  AddExit("nordeste", TBOSQUE("bosque119"));
  AddExit("noroeste", TBOSQUE("bosque117"));
  ::salidas_cmd();
}
