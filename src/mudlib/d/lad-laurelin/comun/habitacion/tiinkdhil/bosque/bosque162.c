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
  AddExit("norte", TBOSQUE("bosque160"));
  AddExit("nordeste", TBOSQUE("bosque161"));
  AddExit("noroeste", TBOSQUE("bosque159"));
  ::salidas_cmd();
}
