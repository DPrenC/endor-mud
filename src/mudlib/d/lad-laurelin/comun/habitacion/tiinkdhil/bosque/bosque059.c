#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("este");
  SetPathToTrolls("nordeste");
  SetPathToGigants("oeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque060"));
  AddExit("oeste", TBOSQUE("bosque058"));
  AddExit("sur", TBOSQUE("bosque076"));
  AddExit("sudeste", TBOSQUE("bosque077"));
  AddExit("suroeste", TBOSQUE("bosque075"));
  AddExit("norte", TBOSQUE("bosque043"));
  AddExit("nordeste", TBOSQUE("bosque044"));
  AddExit("noroeste", TBOSQUE("bosque042"));
  ::salidas_cmd();
}
