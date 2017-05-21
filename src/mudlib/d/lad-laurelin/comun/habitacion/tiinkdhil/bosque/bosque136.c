#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("nordeste");
  SetPathToTrolls("norte");
  SetPathToGigants("noroeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque137"));
  AddExit("oeste", TBOSQUE("bosque135"));
  AddExit("sur", TBOSQUE("bosque147"));
  AddExit("sudeste", TBOSQUE("bosque148"));
  AddExit("suroeste", TBOSQUE("bosque146"));
  AddExit("norte", TBOSQUE("bosque122"));
  AddExit("nordeste", TBOSQUE("bosque123"));
  AddExit("noroeste", TBOSQUE("bosque121"));
  ::salidas_cmd();
}
