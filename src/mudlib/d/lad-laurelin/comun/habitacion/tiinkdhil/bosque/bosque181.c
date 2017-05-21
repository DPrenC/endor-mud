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
  AddExit("este", TBOSQUE("bosque182"));
  AddExit("oeste", TBOSQUE("bosque180"));
  AddExit("sur", TBOSQUE("bosque190"));
  AddExit("sudeste", TBOSQUE("bosque191"));
  AddExit("suroeste", TBOSQUE("bosque189"));
  ::salidas_cmd();
}
