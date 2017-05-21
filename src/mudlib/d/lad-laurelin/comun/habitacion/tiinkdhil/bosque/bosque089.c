#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("este");
  SetPathToTrolls("nordeste");
  SetPathToGigants("noroeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque090"));
  AddExit("oeste", TBOSQUE("bosque088"));
  AddExit("sur", TBOSQUE("bosque097"));
  AddExit("sudeste", TBOSQUE("camino03"));
  AddExit("suroeste", TBOSQUE("bosque096"));
  AddExit("norte", TBOSQUE("bosque077"));
  AddExit("nordeste", TBOSQUE("bosque078"));
  AddExit("noroeste", TBOSQUE("bosque076"));
  ::salidas_cmd();
}
