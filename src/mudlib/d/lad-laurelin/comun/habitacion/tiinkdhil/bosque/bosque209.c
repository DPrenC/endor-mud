#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("norte");
  SetPathToTrolls("norte");
  SetPathToGigants("nordeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque210"));
  AddExit("sur", TBOSQUE("bosque220"));
  AddExit("sudeste", TBOSQUE("bosque221"));
  AddExit("suroeste", TBOSQUE("bosque219"));
  AddExit("norte", TBOSQUE("bosque201"));
  AddExit("nordeste", TBOSQUE("bosque202"));
  ::salidas_cmd();
}
