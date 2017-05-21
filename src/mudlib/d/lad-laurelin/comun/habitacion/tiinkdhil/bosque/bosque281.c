#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("noroeste");
  SetPathToTrolls("noroeste");
  SetPathToGigants("noroeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque282"));
  AddExit("oeste", TBOSQUE("bosque280"));
  AddExit("sur", TBOSQUE("bosque287"));
  AddExit("suroeste", TBOSQUE("bosque286"));
  AddExit("norte", TBOSQUE("bosque270"));
  AddExit("nordeste", TBOSQUE("bosque271"));
  AddExit("noroeste", TBOSQUE("bosque269"));
  ::salidas_cmd();
}
