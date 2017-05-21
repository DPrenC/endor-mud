#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("sudeste");
  SetPathToTrolls("nordeste");
  SetPathToGigants("suroeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque034"));
  AddExit("sur", TBOSQUE("bosque049"));
  AddExit("oeste", TBOSQUE("bosque032"));
  AddExit("norte", TBOSQUE("bosque017"));
  AddExit("sudeste", TBOSQUE("bosque050"));
  AddExit("suroeste", TBOSQUE("bosque048"));
  AddExit("noroeste", TBOSQUE("bosque016"));
  AddExit("nordeste", TBOSQUE("bosque018"));
  ::salidas_cmd();
}
