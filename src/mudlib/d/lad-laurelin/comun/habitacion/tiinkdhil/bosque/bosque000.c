#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("sudeste");
  SetPathToTrolls("sudeste");
  SetPathToGigants("sur");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque001"));
  AddExit("sur", TBOSQUE("bosque003"));
  AddExit("suroeste", TBOSQUE("bosque002"));
  AddExit("sudeste", TBOSQUE("bosque004"));
  ::salidas_cmd();
}
