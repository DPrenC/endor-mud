#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("noroeste");
  SetPathToTrolls("noroeste");
  SetPathToGigants("norte");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque281"));
  AddExit("oeste", TBOSQUE("bosque279"));
  AddExit("sur", TBOSQUE("bosque286"));
  AddExit("sudeste", TBOSQUE("bosque287"));
  AddExit("suroeste", TBOSQUE("bosque285"));
  AddExit("norte", TBOSQUE("bosque269"));
  AddExit("nordeste", TBOSQUE("bosque270"));
  AddExit("noroeste", TBOSQUE("bosque268"));
  ::salidas_cmd();
}
