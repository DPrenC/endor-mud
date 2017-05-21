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
  AddExit("este", TBOSQUE("bosque135"));
  AddExit("oeste", TBOSQUE("bosque133"));
  AddExit("sur", TBOSQUE("bosque145"));
  AddExit("sudeste", TBOSQUE("bosque146"));
  AddExit("suroeste", TBOSQUE("bosque144"));
  AddExit("norte", TBOSQUE("bosque120"));
  AddExit("nordeste", TBOSQUE("bosque121"));
  AddExit("noroeste", TBOSQUE("bosque119"));
  ::salidas_cmd();
}
