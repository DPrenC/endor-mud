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
  AddExit("este", TBOSQUE("camino06"));
  AddExit("oeste", TBOSQUE("bosque079"));
  AddExit("sur", TBOSQUE("camino05"));
  AddExit("sudeste", TBOSQUE("bosque091"));
  AddExit("suroeste", TBOSQUE("camino04"));
  AddExit("norte", TBOSQUE("bosque063"));
  AddExit("nordeste", TBOSQUE("bosque064"));
  AddExit("noroeste", TBOSQUE("bosque062"));
  ::salidas_cmd();
}
