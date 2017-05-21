#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("este");
  SetPathToTrolls("nordeste");
  SetPathToGigants("suroeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque050"));
  AddExit("oeste", TBOSQUE("bosque048"));
  AddExit("sur", TBOSQUE("bosque065"));
  AddExit("sudeste", TBOSQUE("bosque066"));
  AddExit("suroeste", TBOSQUE("bosque064"));
  AddExit("norte", TBOSQUE("bosque033"));
  AddExit("nordeste", TBOSQUE("bosque034"));
  AddExit("noroeste", TBOSQUE("bosque032"));
  ::salidas_cmd();
}
