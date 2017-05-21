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
  AddExit("este", TBOSQUE("bosque160"));
  AddExit("sudeste", TBOSQUE("bosque162"));
  AddExit("norte", TBOSQUE("bosque156"));
  AddExit("nordeste", TBOSQUE("bosque157"));
  AddExit("noroeste", TBOSQUE("bosque155"));
  ::salidas_cmd();
}
