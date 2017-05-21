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
  AddExit("este", TBOSQUE("bosque246"));
  AddExit("oeste", TBOSQUE("bosque244"));
  AddExit("sur", TBOSQUE("bosque256"));
  AddExit("sudeste", TBOSQUE("bosque257"));
  AddExit("suroeste", TBOSQUE("bosque255"));
  AddExit("norte", TBOSQUE("bosque234"));
  AddExit("nordeste", TBOSQUE("bosque235"));
  AddExit("noroeste", TBOSQUE("bosque233"));
  ::salidas_cmd();
}
