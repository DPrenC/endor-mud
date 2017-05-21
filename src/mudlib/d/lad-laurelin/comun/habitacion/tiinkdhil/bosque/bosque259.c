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
  AddExit("este", TBOSQUE("bosque260"));
  AddExit("oeste", TBOSQUE("bosque258"));
  AddExit("sur", TBOSQUE("bosque270"));
  AddExit("sudeste", TBOSQUE("bosque271"));
  AddExit("suroeste", TBOSQUE("bosque269"));
  AddExit("norte", TBOSQUE("bosque248"));
  AddExit("nordeste", TBOSQUE("bosque249"));
  AddExit("noroeste", TBOSQUE("bosque247"));
  ::salidas_cmd();
}
