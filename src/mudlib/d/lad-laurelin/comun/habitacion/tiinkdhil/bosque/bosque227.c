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
  AddExit("oeste", TBOSQUE("bosque226"));
  AddExit("sur", TBOSQUE("bosque238"));
  AddExit("suroeste", TBOSQUE("bosque237"));
  AddExit("norte", TBOSQUE("bosque216"));
  AddExit("noroeste", TBOSQUE("bosque215"));
  ::salidas_cmd();
}
