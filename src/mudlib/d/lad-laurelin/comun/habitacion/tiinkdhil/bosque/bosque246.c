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
  AddExit("este", TBOSQUE("bosque247"));
  AddExit("oeste", TBOSQUE("bosque245"));
  AddExit("sur", TBOSQUE("bosque257"));
  AddExit("sudeste", TBOSQUE("bosque258"));
  AddExit("suroeste", TBOSQUE("bosque256"));
  AddExit("norte", TBOSQUE("bosque235"));
  AddExit("nordeste", TBOSQUE("bosque236"));
  AddExit("noroeste", TBOSQUE("bosque234"));
  ::salidas_cmd();
}
