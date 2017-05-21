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
  AddExit("este", TBOSQUE("bosque269"));
  AddExit("oeste", TBOSQUE("bosque267"));
  AddExit("sur", TBOSQUE("bosque279"));
  AddExit("sudeste", TBOSQUE("bosque280"));
  AddExit("suroeste", TBOSQUE("bosque278"));
  AddExit("norte", TBOSQUE("bosque257"));
  AddExit("nordeste", TBOSQUE("bosque258"));
  AddExit("noroeste", TBOSQUE("bosque256"));
  ::salidas_cmd();
}
