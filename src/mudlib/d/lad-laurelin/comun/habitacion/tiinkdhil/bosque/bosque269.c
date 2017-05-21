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
  AddExit("este", TBOSQUE("bosque270"));
  AddExit("oeste", TBOSQUE("bosque268"));
  AddExit("sur", TBOSQUE("bosque280"));
  AddExit("sudeste", TBOSQUE("bosque281"));
  AddExit("suroeste", TBOSQUE("bosque279"));
  AddExit("norte", TBOSQUE("bosque258"));
  AddExit("nordeste", TBOSQUE("bosque259"));
  AddExit("noroeste", TBOSQUE("bosque257"));
  ::salidas_cmd();
}
