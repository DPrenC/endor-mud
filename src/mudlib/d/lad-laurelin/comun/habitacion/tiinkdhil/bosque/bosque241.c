#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("noroeste");
  SetPathToTrolls("nordeste");
  SetPathToGigants("nordeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque242"));
  AddExit("oeste", TBOSQUE("bosque240"));
  AddExit("sur", TBOSQUE("bosque252"));
  AddExit("sudeste", TBOSQUE("bosque253"));
  AddExit("suroeste", TBOSQUE("bosque251"));
  AddExit("norte", TBOSQUE("bosque230"));
  AddExit("nordeste", TBOSQUE("bosque231"));
  AddExit("noroeste", TBOSQUE("bosque229"));
  ::salidas_cmd();
}
