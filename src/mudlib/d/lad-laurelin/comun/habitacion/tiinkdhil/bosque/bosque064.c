#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("este");
  SetPathToTrolls("nordeste");
  SetPathToGigants("oeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque065"));
  AddExit("oeste", TBOSQUE("bosque063"));
  AddExit("sur", TBOSQUE("camino06"));
  AddExit("sudeste", TBOSQUE("camino07"));
  AddExit("suroeste", TBOSQUE("bosque080"));
  AddExit("norte", TBOSQUE("bosque048"));
  AddExit("nordeste", TBOSQUE("bosque049"));
  AddExit("noroeste", TBOSQUE("bosque047"));
  ::salidas_cmd();
}
