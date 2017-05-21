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
  AddExit("este", TBOSQUE("bosque080"));
  AddExit("oeste", TBOSQUE("bosque078"));
  AddExit("sur", TBOSQUE("camino04"));
  AddExit("sudeste", TBOSQUE("camino05"));
  AddExit("suroeste", TBOSQUE("bosque090"));
  AddExit("norte", TBOSQUE("bosque062"));
  AddExit("nordeste", TBOSQUE("bosque063"));
  AddExit("noroeste", TBOSQUE("bosque061"));
  ::salidas_cmd();
}
