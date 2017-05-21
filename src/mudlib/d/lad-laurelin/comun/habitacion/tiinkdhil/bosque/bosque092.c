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
  AddExit("este", TBOSQUE("bosque093"));
  AddExit("oeste", TBOSQUE("bosque091"));
  AddExit("sur", TBOSQUE("bosque101"));
  AddExit("sudeste", TBOSQUE("bosque102"));
  AddExit("suroeste", TBOSQUE("bosque100"));
  AddExit("norte", TBOSQUE("camino07"));
  AddExit("nordeste", TBOSQUE("camino08"));
  AddExit("noroeste", TBOSQUE("camino06"));
  ::salidas_cmd();
}
