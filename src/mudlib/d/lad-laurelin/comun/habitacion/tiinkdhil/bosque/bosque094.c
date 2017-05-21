#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("este");
  SetPathToTrolls("norte");
  SetPathToGigants("noroeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("camino10"));
  AddExit("oeste", TBOSQUE("bosque093"));
  AddExit("sur", TBOSQUE("bosque103"));
  AddExit("sudeste", TBOSQUE("bosque104"));
  AddExit("suroeste", TBOSQUE("bosque102"));
  AddExit("norte", TBOSQUE("camino09"));
  AddExit("nordeste", TBOSQUE("bosque081"));
  AddExit("noroeste", TBOSQUE("camino08"));
  ::salidas_cmd();
}
