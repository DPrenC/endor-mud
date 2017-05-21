#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("noroeste");
  SetPathToTrolls("noroeste");
  SetPathToGigants("noroeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("oeste", TBOSQUE("bosque237"));
  AddExit("sur", TBOSQUE("bosque249"));
  AddExit("suroeste", TBOSQUE("bosque248"));
  AddExit("norte", TBOSQUE("bosque227"));
  AddExit("noroeste", TBOSQUE("bosque226"));
  ::salidas_cmd();
}
