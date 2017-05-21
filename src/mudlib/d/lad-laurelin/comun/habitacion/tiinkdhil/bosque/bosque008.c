#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("sur");
  SetPathToTrolls("sur");
  SetPathToGigants("sur");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque009"));
  AddExit("oeste", TBOSQUE("bosque007"));
  AddExit("sur", TBOSQUE("bosque013"));
  AddExit("suroeste", TBOSQUE("bosque012"));
  AddExit("norte", TBOSQUE("bosque004"));
  AddExit("noroeste", TBOSQUE("bosque003"));
  ::salidas_cmd();
}
