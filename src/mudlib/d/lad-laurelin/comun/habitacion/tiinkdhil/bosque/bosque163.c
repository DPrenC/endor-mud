#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("suroeste");
  SetPathToTrolls("suroeste");
  SetPathToGigants("sur");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque164"));
  AddExit("sur", TBOSQUE("bosque168"));
  AddExit("sudeste", TBOSQUE("bosque169"));
  AddExit("suroeste", TBOSQUE("bosque167"));
  ::salidas_cmd();
}
