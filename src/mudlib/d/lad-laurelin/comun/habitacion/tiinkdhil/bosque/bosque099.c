#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("suroeste");
  SetPathToTrolls("nordeste");
  SetPathToGigants("noroeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque100"));
  AddExit("oeste", TBOSQUE("bosque098"));
  AddExit("sur", TBOSQUE("bosque113"));
  AddExit("sudeste", TBOSQUE("bosque114"));
  AddExit("suroeste", TBOSQUE("bosque112"));
  AddExit("norte", TBOSQUE("camino05"));
  AddExit("nordeste", TBOSQUE("bosque091"));
  AddExit("noroeste", TBOSQUE("camino04"));
  ::salidas_cmd();
}
