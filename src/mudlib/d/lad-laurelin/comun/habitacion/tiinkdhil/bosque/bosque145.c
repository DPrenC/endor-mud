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
  AddExit("este", TBOSQUE("bosque146"));
  AddExit("oeste", TBOSQUE("bosque144"));
  AddExit("sur", TBOSQUE("bosque150"));
  AddExit("sudeste", TBOSQUE("bosque151"));
  AddExit("suroeste", TBOSQUE("bosque149"));
  AddExit("norte", TBOSQUE("bosque134"));
  AddExit("nordeste", TBOSQUE("bosque135"));
  AddExit("noroeste", TBOSQUE("bosque133"));
  ::salidas_cmd();
}
