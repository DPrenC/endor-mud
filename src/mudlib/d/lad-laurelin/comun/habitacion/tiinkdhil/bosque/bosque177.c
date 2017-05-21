#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("suroeste");
  SetPathToTrolls("noroeste");
  SetPathToGigants("este");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque178"));
  AddExit("oeste", TBOSQUE("bosque176"));
  AddExit("sur", TBOSQUE("bosque186"));
  AddExit("sudeste", TBOSQUE("bosque187"));
  AddExit("suroeste", TBOSQUE("bosque185"));
  AddExit("norte", TBOSQUE("bosque173"));
  AddExit("noroeste", TBOSQUE("bosque172"));
  ::salidas_cmd();
}
