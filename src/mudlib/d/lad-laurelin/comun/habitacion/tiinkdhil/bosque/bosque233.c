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
  AddExit("este", TBOSQUE("bosque234"));
  AddExit("oeste", TBOSQUE("bosque232"));
  AddExit("sur", TBOSQUE("bosque244"));
  AddExit("sudeste", TBOSQUE("bosque245"));
  AddExit("suroeste", TBOSQUE("bosque243"));
  AddExit("norte", TBOSQUE("bosque222"));
  AddExit("nordeste", TBOSQUE("bosque223"));
  AddExit("noroeste", TBOSQUE("bosque221"));
  ::salidas_cmd();
}
