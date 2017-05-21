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
  AddExit("este", TBOSQUE("bosque113"));
  AddExit("oeste", TBOSQUE("bosque111"));
  AddExit("sur", TBOSQUE("bosque126"));
  AddExit("sudeste", TBOSQUE("bosque127"));
  AddExit("suroeste", TBOSQUE("bosque125"));
  AddExit("norte", TBOSQUE("bosque098"));
  AddExit("nordeste", TBOSQUE("bosque099"));
  AddExit("noroeste", TBOSQUE("camino03"));
  ::salidas_cmd();
}
