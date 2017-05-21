#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("nordeste");
  SetPathToTrolls("norte");
  SetPathToGigants("noroeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque132"));
  AddExit("oeste", TBOSQUE("bosque130"));
  AddExit("norte", TBOSQUE("bosque117"));
  AddExit("nordeste", TBOSQUE("bosque118"));
  AddExit("noroeste", TBOSQUE("bosque116"));
  ::salidas_cmd();
}
