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
  AddExit("este", TBOSQUE("bosque079"));
  AddExit("oeste", TBOSQUE("bosque077"));
  AddExit("sur", TBOSQUE("bosque090"));
  AddExit("sudeste", TBOSQUE("camino04"));
  AddExit("suroeste", TBOSQUE("bosque089"));
  AddExit("norte", TBOSQUE("bosque061"));
  AddExit("nordeste", TBOSQUE("bosque062"));
  AddExit("noroeste", TBOSQUE("bosque060"));
  ::salidas_cmd();
}
