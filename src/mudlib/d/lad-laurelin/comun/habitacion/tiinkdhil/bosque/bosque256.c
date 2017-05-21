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
  AddExit("este", TBOSQUE("bosque257"));
  AddExit("oeste", TBOSQUE("bosque255"));
  AddExit("sur", TBOSQUE("bosque267"));
  AddExit("sudeste", TBOSQUE("bosque268"));
  AddExit("suroeste", TBOSQUE("bosque266"));
  AddExit("norte", TBOSQUE("bosque245"));
  AddExit("nordeste", TBOSQUE("bosque246"));
  AddExit("noroeste", TBOSQUE("bosque244"));
  ::salidas_cmd();
}
