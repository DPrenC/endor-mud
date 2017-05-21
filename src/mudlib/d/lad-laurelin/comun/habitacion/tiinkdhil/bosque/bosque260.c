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
  AddExit("oeste", TBOSQUE("bosque259"));
  AddExit("sur", TBOSQUE("bosque271"));
  AddExit("suroeste", TBOSQUE("bosque270"));
  AddExit("norte", TBOSQUE("bosque249"));
  AddExit("noroeste", TBOSQUE("bosque248"));
  ::salidas_cmd();
}
