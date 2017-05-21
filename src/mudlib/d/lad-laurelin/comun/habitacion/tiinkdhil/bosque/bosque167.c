#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("sur");
  SetPathToTrolls("oeste");
  SetPathToGigants("sudeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque168"));
  AddExit("oeste", TBOSQUE("bosque166"));
  AddExit("sur", TBOSQUE("bosque172"));
  AddExit("sudeste", TBOSQUE("bosque173"));
  AddExit("suroeste", TBOSQUE("bosque171"));
  AddExit("nordeste", TBOSQUE("bosque163"));
  ::salidas_cmd();
}
