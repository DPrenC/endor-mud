#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("oeste");
  SetPathToTrolls("noroeste");
  SetPathToGigants("oeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("oeste", TBOSQUE("bosque173"));
  AddExit("norte", TBOSQUE("bosque169"));
  AddExit("nordeste", TBOSQUE("bosque170"));
  AddExit("noroeste", TBOSQUE("bosque168"));
  ::salidas_cmd();
}
