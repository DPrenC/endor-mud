#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("este");
  SetPathToTrolls("noroeste");
  SetPathToGigants("oeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque070"));
  AddExit("oeste", TBOSQUE("bosque068"));
  AddExit("sur", TBOSQUE("bosque082"));
  AddExit("sudeste", TBOSQUE("bosque083"));
  AddExit("suroeste", TBOSQUE("bosque081"));
  AddExit("norte", TBOSQUE("bosque053"));
  AddExit("nordeste", TBOSQUE("bosque054"));
  AddExit("noroeste", TBOSQUE("bosque052"));
  ::salidas_cmd();
}
