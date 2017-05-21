#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("noroeste");
  SetPathToTrolls("noroeste");
  SetPathToGigants("nordeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("oeste", TBOSQUE("bosque248"));
  AddExit("sur", TBOSQUE("bosque260"));
  AddExit("suroeste", TBOSQUE("bosque259"));
  AddExit("norte", TBOSQUE("bosque238"));
  AddExit("noroeste", TBOSQUE("bosque237"));
  ::salidas_cmd();
}
