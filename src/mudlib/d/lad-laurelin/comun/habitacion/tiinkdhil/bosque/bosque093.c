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
  AddExit("este", TBOSQUE("bosque094"));
  AddExit("oeste", TBOSQUE("bosque092"));
  AddExit("sur", TBOSQUE("bosque102"));
  AddExit("sudeste", TBOSQUE("bosque103"));
  AddExit("suroeste", TBOSQUE("bosque101"));
  AddExit("norte", TBOSQUE("camino08"));
  AddExit("nordeste", TBOSQUE("camino09"));
  AddExit("noroeste", TBOSQUE("camino07"));
  ::salidas_cmd();
}
