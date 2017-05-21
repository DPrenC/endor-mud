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
  AddExit("este", TBOSQUE("bosque136"));
  AddExit("oeste", TBOSQUE("bosque134"));
  AddExit("sur", TBOSQUE("bosque146"));
  AddExit("sudeste", TBOSQUE("bosque147"));
  AddExit("suroeste", TBOSQUE("bosque145"));
  AddExit("norte", TBOSQUE("bosque121"));
  AddExit("nordeste", TBOSQUE("bosque122"));
  AddExit("noroeste", TBOSQUE("bosque120"));
  ::salidas_cmd();
}
