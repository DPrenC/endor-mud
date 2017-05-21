#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("oeste");
  SetPathToTrolls("noroeste");
  SetPathToGigants("nordeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque190"));
  AddExit("oeste", TBOSQUE("bosque188"));
  AddExit("sur", TBOSQUE("bosque195"));
  AddExit("sudeste", TBOSQUE("bosque196"));
  AddExit("suroeste", TBOSQUE("bosque194"));
  AddExit("norte", TBOSQUE("bosque180"));
  AddExit("nordeste", TBOSQUE("bosque181"));
  AddExit("noroeste", TBOSQUE("bosque179"));
  ::salidas_cmd();
}
