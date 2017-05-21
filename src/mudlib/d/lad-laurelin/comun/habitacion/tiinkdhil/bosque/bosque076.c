#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("este");
  SetPathToTrolls("nordeste");
  SetPathToGigants("noroeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque077"));
  AddExit("oeste", TBOSQUE("bosque075"));
  AddExit("sur", TBOSQUE("bosque088"));
  AddExit("sudeste", TBOSQUE("bosque089"));
  AddExit("suroeste", TBOSQUE("bosque087"));
  AddExit("norte", TBOSQUE("bosque059"));
  AddExit("nordeste", TBOSQUE("bosque060"));
  AddExit("noroeste", TBOSQUE("bosque058"));
  ::salidas_cmd();
}
