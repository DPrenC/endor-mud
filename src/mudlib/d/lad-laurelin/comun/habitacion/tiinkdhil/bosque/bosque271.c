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
  AddExit("oeste", TBOSQUE("bosque270"));
  AddExit("sur", TBOSQUE("bosque282"));
  AddExit("suroeste", TBOSQUE("bosque281"));
  AddExit("norte", TBOSQUE("bosque260"));
  AddExit("noroeste", TBOSQUE("bosque259"));
  ::salidas_cmd();
}
