#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("sur");
  SetPathToTrolls("nordeste");
  SetPathToGigants("noroeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque097"));
  AddExit("oeste", TBOSQUE("bosque095"));
  AddExit("sur", TBOSQUE("bosque110"));
  AddExit("sudeste", TBOSQUE("camino02"));
  AddExit("norte", TBOSQUE("bosque088"));
  AddExit("nordeste", TBOSQUE("bosque089"));
  AddExit("noroeste", TBOSQUE("bosque087"));
  ::salidas_cmd();
}
