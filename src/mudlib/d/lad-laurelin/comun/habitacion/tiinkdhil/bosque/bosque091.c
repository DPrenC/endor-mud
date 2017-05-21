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
  AddExit("este", TBOSQUE("bosque092"));
  AddExit("oeste", TBOSQUE("camino05"));
  AddExit("sur", TBOSQUE("bosque100"));
  AddExit("sudeste", TBOSQUE("bosque101"));
  AddExit("suroeste", TBOSQUE("bosque099"));
  AddExit("norte", TBOSQUE("camino06"));
  AddExit("nordeste", TBOSQUE("camino07"));
  AddExit("noroeste", TBOSQUE("bosque080"));
  ::salidas_cmd();
}
