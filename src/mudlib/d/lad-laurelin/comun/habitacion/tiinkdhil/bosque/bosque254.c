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
  AddExit("este", TBOSQUE("bosque255"));
  AddExit("oeste", TBOSQUE("bosque253"));
  AddExit("sur", TBOSQUE("bosque265"));
  AddExit("sudeste", TBOSQUE("bosque266"));
  AddExit("suroeste", TBOSQUE("bosque264"));
  AddExit("norte", TBOSQUE("bosque243"));
  AddExit("nordeste", TBOSQUE("bosque244"));
  AddExit("noroeste", TBOSQUE("bosque242"));
  ::salidas_cmd();
}
