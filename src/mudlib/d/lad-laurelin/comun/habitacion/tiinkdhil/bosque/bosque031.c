#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("sudeste");
  SetPathToTrolls("este");
  SetPathToGigants("suroeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque032"));
  AddExit("sur", TBOSQUE("bosque047"));
  AddExit("oeste", TBOSQUE("bosque030"));
  AddExit("norte", TBOSQUE("bosque015"));
  AddExit("sudeste", TBOSQUE("bosque048"));
  AddExit("suroeste", TBOSQUE("bosque046"));
  AddExit("noroeste", TBOSQUE("bosque014"));
  AddExit("nordeste", TBOSQUE("bosque016"));
  ::salidas_cmd();
}
