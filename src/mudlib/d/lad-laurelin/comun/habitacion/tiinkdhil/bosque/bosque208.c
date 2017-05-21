#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("oeste");
  SetPathToTrolls("noroeste");
  SetPathToGigants("noroeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("oeste", TBOSQUE("bosque207"));
  AddExit("sur", TBOSQUE("bosque216"));
  AddExit("suroeste", TBOSQUE("bosque215"));
  AddExit("norte", TBOSQUE("bosque200"));
  AddExit("noroeste", TBOSQUE("bosque199"));
  ::salidas_cmd();
}
