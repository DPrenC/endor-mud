#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("nordeste");
  SetPathToTrolls("nordeste");
  SetPathToGigants("noroeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque152"));
  AddExit("oeste", TBOSQUE("bosque150"));
  AddExit("sur", TBOSQUE("bosque156"));
  AddExit("sudeste", TBOSQUE("bosque157"));
  AddExit("suroeste", TBOSQUE("bosque155"));
  AddExit("norte", TBOSQUE("bosque146"));
  AddExit("nordeste", TBOSQUE("bosque147"));
  AddExit("noroeste", TBOSQUE("bosque145"));
  ::salidas_cmd();
}
