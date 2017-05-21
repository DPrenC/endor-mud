#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("este");
  SetPathToTrolls("noroeste");
  SetPathToGigants("sur");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque043"));
  AddExit("sur", TBOSQUE("bosque058"));
  AddExit("norte", TBOSQUE("bosque026"));
  AddExit("sudeste", TBOSQUE("bosque059"));
  AddExit("nordeste", TBOSQUE("bosque027"));
  ::salidas_cmd();
}
