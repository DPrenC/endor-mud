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
  AddExit("este", TBOSQUE("bosque278"));
  AddExit("oeste", TBOSQUE("bosque276"));
  AddExit("sur", TBOSQUE("bosque283"));
  AddExit("sudeste", TBOSQUE("bosque284"));
  AddExit("norte", TBOSQUE("bosque266"));
  AddExit("nordeste", TBOSQUE("bosque267"));
  AddExit("noroeste", TBOSQUE("bosque265"));
  ::salidas_cmd();
}
