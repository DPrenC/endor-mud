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
  AddExit("este", TBOSQUE("bosque089"));
  AddExit("oeste", TBOSQUE("bosque087"));
  AddExit("sur", TBOSQUE("bosque096"));
  AddExit("sudeste", TBOSQUE("bosque097"));
  AddExit("suroeste", TBOSQUE("bosque095"));
  AddExit("norte", TBOSQUE("bosque076"));
  AddExit("nordeste", TBOSQUE("bosque077"));
  AddExit("noroeste", TBOSQUE("bosque075"));
  ::salidas_cmd();
}
