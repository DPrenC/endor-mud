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
  AddExit("este", TBOSQUE("bosque280"));
  AddExit("oeste", TBOSQUE("bosque278"));
  AddExit("sur", TBOSQUE("bosque285"));
  AddExit("sudeste", TBOSQUE("bosque286"));
  AddExit("suroeste", TBOSQUE("bosque284"));
  AddExit("norte", TBOSQUE("bosque268"));
  AddExit("nordeste", TBOSQUE("bosque269"));
  AddExit("noroeste", TBOSQUE("bosque267"));
  ::salidas_cmd();
}
