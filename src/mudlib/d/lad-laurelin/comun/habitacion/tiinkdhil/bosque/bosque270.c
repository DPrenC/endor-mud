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
  AddExit("este", TBOSQUE("bosque271"));
  AddExit("oeste", TBOSQUE("bosque269"));
  AddExit("sur", TBOSQUE("bosque281"));
  AddExit("sudeste", TBOSQUE("bosque282"));
  AddExit("suroeste", TBOSQUE("bosque280"));
  AddExit("norte", TBOSQUE("bosque259"));
  AddExit("nordeste", TBOSQUE("bosque260"));
  AddExit("noroeste", TBOSQUE("bosque258"));
  ::salidas_cmd();
}
