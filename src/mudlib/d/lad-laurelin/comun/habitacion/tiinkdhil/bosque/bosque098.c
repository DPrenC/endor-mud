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
  AddExit("este", TBOSQUE("bosque099"));
  AddExit("oeste", TBOSQUE("camino03"));
  AddExit("sur", TBOSQUE("bosque112"));
  AddExit("sudeste", TBOSQUE("bosque113"));
  AddExit("suroeste", TBOSQUE("bosque111"));
  AddExit("norte", TBOSQUE("camino04"));
  AddExit("nordeste", TBOSQUE("camino05"));
  AddExit("noroeste", TBOSQUE("bosque090"));
  ::salidas_cmd();
}
