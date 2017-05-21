#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("sudeste");
  SetPathToTrolls("oeste");
  SetPathToGigants("sudeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque167"));
  AddExit("oeste", TBOSQUE("bosque025"));
  AddExit("sur", TBOSQUE("bosque171"));
  AddExit("sudeste", TBOSQUE("bosque172"));
  AddExit("suroeste", TBOSQUE("bosque041"));
  ::salidas_cmd();
}
