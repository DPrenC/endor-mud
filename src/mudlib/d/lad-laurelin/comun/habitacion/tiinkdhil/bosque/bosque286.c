#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("noroeste");
  SetPathToTrolls("noroeste");
  SetPathToGigants("norte");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque287"));
  AddExit("oeste", TBOSQUE("bosque285"));
  AddExit("norte", TBOSQUE("bosque280"));
  AddExit("nordeste", TBOSQUE("bosque281"));
  AddExit("noroeste", TBOSQUE("bosque279"));
  ::salidas_cmd();
}
