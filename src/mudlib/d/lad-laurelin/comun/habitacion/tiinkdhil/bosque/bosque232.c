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
  AddExit("este", TBOSQUE("bosque233"));
  AddExit("oeste", TBOSQUE("bosque231"));
  AddExit("sur", TBOSQUE("bosque243"));
  AddExit("sudeste", TBOSQUE("bosque244"));
  AddExit("suroeste", TBOSQUE("bosque242"));
  AddExit("norte", TBOSQUE("bosque221"));
  AddExit("nordeste", TBOSQUE("bosque222"));
  AddExit("noroeste", TBOSQUE("bosque220"));
  ::salidas_cmd();
}
