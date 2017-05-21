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
  AddExit("este", TBOSQUE("bosque245"));
  AddExit("oeste", TBOSQUE("bosque243"));
  AddExit("sur", TBOSQUE("bosque255"));
  AddExit("sudeste", TBOSQUE("bosque256"));
  AddExit("suroeste", TBOSQUE("bosque254"));
  AddExit("norte", TBOSQUE("bosque233"));
  AddExit("nordeste", TBOSQUE("bosque234"));
  AddExit("noroeste", TBOSQUE("bosque232"));
  ::salidas_cmd();
}
