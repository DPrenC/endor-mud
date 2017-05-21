#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("nordeste");
  SetPathToTrolls("noroeste");
  SetPathToGigants("noroeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque119"));
  AddExit("oeste", TBOSQUE("bosque117"));
  AddExit("sur", TBOSQUE("bosque132"));
  AddExit("sudeste", TBOSQUE("bosque133"));
  AddExit("suroeste", TBOSQUE("bosque131"));
  AddExit("norte", TBOSQUE("bosque104"));
  AddExit("nordeste", TBOSQUE("bosque105"));
  AddExit("noroeste", TBOSQUE("bosque103"));
  ::salidas_cmd();
}
