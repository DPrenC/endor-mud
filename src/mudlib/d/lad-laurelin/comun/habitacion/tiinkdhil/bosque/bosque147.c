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
  AddExit("este", TBOSQUE("bosque148"));
  AddExit("oeste", TBOSQUE("bosque146"));
  AddExit("sur", TBOSQUE("bosque152"));
  AddExit("sudeste", TBOSQUE("bosque153"));
  AddExit("suroeste", TBOSQUE("bosque151"));
  AddExit("norte", TBOSQUE("bosque136"));
  AddExit("nordeste", TBOSQUE("bosque137"));
  AddExit("noroeste", TBOSQUE("bosque135"));
  ::salidas_cmd();
}
