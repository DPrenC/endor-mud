#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("noroeste");
  SetPathToTrolls("noroeste");
  SetPathToGigants("nordeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque286"));
  AddExit("oeste", TBOSQUE("bosque284"));
  AddExit("sur", TBOSQUE("bosque289"));
  AddExit("suroeste", TBOSQUE("bosque288"));
  AddExit("norte", TBOSQUE("bosque279"));
  AddExit("nordeste", TBOSQUE("bosque280"));
  AddExit("noroeste", TBOSQUE("bosque278"));
  ::salidas_cmd();
}
