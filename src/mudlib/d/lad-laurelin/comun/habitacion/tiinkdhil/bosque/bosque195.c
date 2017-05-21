#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("suroeste");
  SetPathToTrolls("noroeste");
  SetPathToGigants("nordeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque196"));
  AddExit("oeste", TBOSQUE("bosque194"));
  AddExit("sur", TBOSQUE("bosque203"));
  AddExit("sudeste", TBOSQUE("bosque204"));
  AddExit("suroeste", TBOSQUE("bosque202"));
  AddExit("norte", TBOSQUE("bosque189"));
  AddExit("nordeste", TBOSQUE("bosque190"));
  AddExit("noroeste", TBOSQUE("bosque188"));
  ::salidas_cmd();
}
