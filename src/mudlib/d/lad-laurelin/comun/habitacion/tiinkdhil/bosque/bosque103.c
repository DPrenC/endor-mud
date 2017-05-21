#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("nordeste");
  SetPathToTrolls("nordeste");
  SetPathToGigants("noroeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque104"));
  AddExit("oeste", TBOSQUE("bosque102"));
  AddExit("sur", TBOSQUE("bosque117"));
  AddExit("sudeste", TBOSQUE("bosque118"));
  AddExit("suroeste", TBOSQUE("bosque116"));
  AddExit("norte", TBOSQUE("bosque094"));
  AddExit("nordeste", TBOSQUE("camino10"));
  AddExit("noroeste", TBOSQUE("bosque093"));
  ::salidas_cmd();

}
