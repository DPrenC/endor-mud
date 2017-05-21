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
  AddExit("este", TBOSQUE("bosque105"));
  AddExit("oeste", TBOSQUE("bosque103"));
  AddExit("sur", TBOSQUE("bosque118"));
  AddExit("sudeste", TBOSQUE("bosque119"));
  AddExit("suroeste", TBOSQUE("bosque117"));
  AddExit("norte", TBOSQUE("camino10"));
  AddExit("nordeste", TBOSQUE("camino11"));
  AddExit("noroeste", TBOSQUE("bosque094"));
  ::salidas_cmd();

}
