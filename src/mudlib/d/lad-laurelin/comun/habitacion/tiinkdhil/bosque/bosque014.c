#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("sudeste");
  SetPathToTrolls("este");
  SetPathToGigants("suroeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque015"));
  AddExit("sur", TBOSQUE("bosque030"));
  AddExit("oeste", TBOSQUE("bosque013"));
  AddExit("sudeste", TBOSQUE("bosque031"));
  AddExit("suroeste", TBOSQUE("bosque029"));
  ::salidas_cmd();
}
