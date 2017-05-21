#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("nordeste");
  SetPathToTrolls("norte");
  SetPathToGigants("noroeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque118"));
  AddExit("oeste", TBOSQUE("bosque116"));
  AddExit("sur", TBOSQUE("bosque131"));
  AddExit("sudeste", TBOSQUE("bosque132"));
  AddExit("suroeste", TBOSQUE("bosque130"));
  AddExit("norte", TBOSQUE("bosque103"));
  AddExit("nordeste", TBOSQUE("bosque104"));
  AddExit("noroeste", TBOSQUE("bosque102"));
  ::salidas_cmd();
}
