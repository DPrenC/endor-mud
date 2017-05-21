#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("nordeste");
  SetPathToTrolls("norte");
  SetPathToGigants("norte");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque144"));
  AddExit("sudeste", TBOSQUE("bosque149"));
  AddExit("norte", TBOSQUE("bosque132"));
  AddExit("nordeste", TBOSQUE("bosque133"));
  ::salidas_cmd();
}
