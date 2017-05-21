#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("noroeste");
  SetPathToTrolls("nordeste");
  SetPathToGigants("noroeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("norte", TBOSQUE("bosque129"));
  AddExit("nordeste", TBOSQUE("bosque130"));
  AddExit("noroeste", TBOSQUE("bosque128"));
  ::salidas_cmd();
}

