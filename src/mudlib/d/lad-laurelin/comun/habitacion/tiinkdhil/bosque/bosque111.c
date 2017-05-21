#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("suroeste");
  SetPathToTrolls("nordeste");
  SetPathToGigants("noroeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque112"));
  AddExit("oeste", TBOSQUE("camino02"));
  AddExit("sur", TBOSQUE("bosque125"));
  AddExit("sudeste", TBOSQUE("bosque126"));
  AddExit("suroeste", TBOSQUE("bosque124"));
  AddExit("norte", TBOSQUE("camino03"));
  AddExit("nordeste", TBOSQUE("bosque098"));
  AddExit("noroeste", TBOSQUE("bosque097"));
  ::salidas_cmd();
}
