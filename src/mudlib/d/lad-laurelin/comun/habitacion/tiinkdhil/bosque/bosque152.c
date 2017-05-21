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
  AddExit("este", TBOSQUE("bosque153"));
  AddExit("oeste", TBOSQUE("bosque151"));
  AddExit("sur", TBOSQUE("bosque157"));
  AddExit("sudeste", TBOSQUE("bosque158"));
  AddExit("suroeste", TBOSQUE("bosque156"));
  AddExit("norte", TBOSQUE("bosque147"));
  AddExit("nordeste", TBOSQUE("bosque148"));
  AddExit("noroeste", TBOSQUE("bosque146"));
  ::salidas_cmd();
}
