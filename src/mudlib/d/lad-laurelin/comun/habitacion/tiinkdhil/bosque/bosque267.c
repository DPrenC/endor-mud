#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("noroeste");
  SetPathToTrolls("noroeste");
  SetPathToGigants("nordeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque268"));
  AddExit("oeste", TBOSQUE("bosque266"));
  AddExit("sur", TBOSQUE("bosque278"));
  AddExit("sudeste", TBOSQUE("bosque279"));
  AddExit("suroeste", TBOSQUE("bosque277"));
  AddExit("norte", TBOSQUE("bosque256"));
  AddExit("nordeste", TBOSQUE("bosque257"));
  AddExit("noroeste", TBOSQUE("bosque255"));
  ::salidas_cmd();
}
