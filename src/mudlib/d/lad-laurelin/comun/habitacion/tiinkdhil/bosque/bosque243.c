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
  AddExit("este", TBOSQUE("bosque244"));
  AddExit("oeste", TBOSQUE("bosque242"));
  AddExit("sur", TBOSQUE("bosque254"));
  AddExit("sudeste", TBOSQUE("bosque255"));
  AddExit("suroeste", TBOSQUE("bosque253"));
  AddExit("norte", TBOSQUE("bosque232"));
  AddExit("nordeste", TBOSQUE("bosque233"));
  AddExit("noroeste", TBOSQUE("bosque231"));
  ::salidas_cmd();
}
