#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("suroeste");
  SetPathToTrolls("noroeste");
  SetPathToGigants("sudeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque174"));
  AddExit("oeste", TBOSQUE("bosque172"));
  AddExit("sur", TBOSQUE("bosque177"));
  AddExit("sudeste", TBOSQUE("bosque178"));
  AddExit("suroeste", TBOSQUE("bosque176"));
  AddExit("norte", TBOSQUE("bosque168"));
  AddExit("nordeste", TBOSQUE("bosque169"));
  AddExit("noroeste", TBOSQUE("bosque167"));
  ::salidas_cmd();
}
