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
  AddExit("este", TBOSQUE("bosque267"));
  AddExit("oeste", TBOSQUE("bosque265"));
  AddExit("sur", TBOSQUE("bosque277"));
  AddExit("sudeste", TBOSQUE("bosque278"));
  AddExit("suroeste", TBOSQUE("bosque276"));
  AddExit("norte", TBOSQUE("bosque255"));
  AddExit("nordeste", TBOSQUE("bosque256"));
  AddExit("noroeste", TBOSQUE("bosque254"));
  ::salidas_cmd();
}
