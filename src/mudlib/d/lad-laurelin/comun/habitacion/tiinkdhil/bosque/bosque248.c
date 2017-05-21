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
  AddExit("este", TBOSQUE("bosque249"));
  AddExit("oeste", TBOSQUE("bosque247"));
  AddExit("sur", TBOSQUE("bosque259"));
  AddExit("sudeste", TBOSQUE("bosque260"));
  AddExit("suroeste", TBOSQUE("bosque258"));
  AddExit("norte", TBOSQUE("bosque237"));
  AddExit("nordeste", TBOSQUE("bosque238"));
  AddExit("noroeste", TBOSQUE("bosque236"));
  ::salidas_cmd();
}
