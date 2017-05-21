#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("sur");
  SetPathToTrolls("noroeste");
  SetPathToGigants("noroeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("oeste", TBOSQUE("bosque085"));
  AddExit("sur", TBOSQUE("camino15"));
  AddExit("suroeste", TBOSQUE("camino14"));
  AddExit("norte", TBOSQUE("bosque073"));
  AddExit("nordeste", TBOSQUE("bosque184"));
  AddExit("noroeste", TBOSQUE("bosque072"));
  ::salidas_cmd();
}
