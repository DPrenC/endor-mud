#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("suroeste");
  SetPathToTrolls("oeste");
  SetPathToGigants("este");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque183"));
  AddExit("oeste", TBOSQUE("bosque181"));
  AddExit("sur", TBOSQUE("bosque191"));
  AddExit("sudeste", TBOSQUE("bosque192"));
  AddExit("suroeste", TBOSQUE("bosque190"));
  ::salidas_cmd();
}
