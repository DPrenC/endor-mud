#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("sudeste");
  SetPathToTrolls("noroeste");
  SetPathToGigants("sudeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque172"));
  AddExit("oeste", TBOSQUE("bosque041"));
  AddExit("sur", TBOSQUE("bosque175"));
  AddExit("sudeste", TBOSQUE("bosque176"));
  AddExit("suroeste", TBOSQUE("bosque057"));
  AddExit("norte", TBOSQUE("bosque166"));
  AddExit("nordeste", TBOSQUE("bosque167"));
  AddExit("noroeste", TBOSQUE("bosque025"));
  ::salidas_cmd();
}
