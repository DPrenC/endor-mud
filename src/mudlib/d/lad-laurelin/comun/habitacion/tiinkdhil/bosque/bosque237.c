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
  AddExit("este", TBOSQUE("bosque238"));
  AddExit("oeste", TBOSQUE("bosque236"));
  AddExit("sur", TBOSQUE("bosque248"));
  AddExit("sudeste", TBOSQUE("bosque249"));
  AddExit("suroeste", TBOSQUE("bosque247"));
  AddExit("norte", TBOSQUE("bosque226"));
  AddExit("nordeste", TBOSQUE("bosque227"));
  AddExit("noroeste", TBOSQUE("bosque225"));
  ::salidas_cmd();
}
