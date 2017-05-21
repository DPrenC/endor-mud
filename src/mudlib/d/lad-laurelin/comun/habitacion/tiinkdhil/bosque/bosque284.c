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
  AddExit("este", TBOSQUE("bosque285"));
  AddExit("oeste", TBOSQUE("bosque283"));
  AddExit("sur", TBOSQUE("bosque288"));
  AddExit("sudeste", TBOSQUE("bosque289"));
  AddExit("norte", TBOSQUE("bosque278"));
  AddExit("nordeste", TBOSQUE("bosque279"));
  AddExit("noroeste", TBOSQUE("bosque277"));
  ::salidas_cmd();
}
