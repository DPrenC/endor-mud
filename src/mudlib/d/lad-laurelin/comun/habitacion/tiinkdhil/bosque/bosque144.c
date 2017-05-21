#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("nordeste");
  SetPathToTrolls("noroeste");
  SetPathToGigants("noroeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque145"));
  AddExit("oeste", TBOSQUE("bosque143"));
  AddExit("sur", TBOSQUE("bosque149"));
  AddExit("sudeste", TBOSQUE("bosque150"));
  AddExit("norte", TBOSQUE("bosque133"));
  AddExit("nordeste", TBOSQUE("bosque134"));
  AddExit("noroeste", TBOSQUE("bosque132"));
  ::salidas_cmd();
}
