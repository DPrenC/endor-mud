#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("noroeste");
  SetPathToTrolls("norodste");
  SetPathToGigants("nordeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque231"));
  AddExit("oeste", TBOSQUE("bosque229"));
  AddExit("sur", TBOSQUE("bosque241"));
  AddExit("sudeste", TBOSQUE("bosque242"));
  AddExit("suroeste", TBOSQUE("bosque240"));
  AddExit("norte", TBOSQUE("bosque219"));
  AddExit("nordeste", TBOSQUE("bosque220"));
  AddExit("noroeste", TBOSQUE("bosque218"));
  ::salidas_cmd();
}
