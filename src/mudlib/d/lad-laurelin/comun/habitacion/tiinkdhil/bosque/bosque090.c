#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("este");
  SetPathToTrolls("nordeste");
  SetPathToGigants("noroeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("camino04"));
  AddExit("oeste", TBOSQUE("bosque089"));
  AddExit("sur", TBOSQUE("camino03"));
  AddExit("sudeste", TBOSQUE("bosque098"));
  AddExit("suroeste", TBOSQUE("bosque097"));
  AddExit("norte", TBOSQUE("bosque078"));
  AddExit("nordeste", TBOSQUE("bosque079"));
  AddExit("noroeste", TBOSQUE("bosque077"));
  ::salidas_cmd();
}
