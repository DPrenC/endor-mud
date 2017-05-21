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
  AddExit("este", TBOSQUE("bosque147"));
  AddExit("oeste", TBOSQUE("bosque145"));
  AddExit("sur", TBOSQUE("bosque151"));
  AddExit("sudeste", TBOSQUE("bosque152"));
  AddExit("suroeste", TBOSQUE("bosque150"));
  AddExit("norte", TBOSQUE("bosque135"));
  AddExit("nordeste", TBOSQUE("bosque136"));
  AddExit("noroeste", TBOSQUE("bosque134"));
  ::salidas_cmd();
}
