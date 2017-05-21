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
  AddExit("este", TBOSQUE("bosque204"));
  AddExit("oeste", TBOSQUE("bosque202"));
  AddExit("sur", TBOSQUE("bosque211"));
  AddExit("sudeste", TBOSQUE("bosque212"));
  AddExit("suroeste", TBOSQUE("bosque210"));
  AddExit("norte", TBOSQUE("bosque195"));
  AddExit("nordeste", TBOSQUE("bosque196"));
  AddExit("noroeste", TBOSQUE("bosque194"));
  ::salidas_cmd();
}
