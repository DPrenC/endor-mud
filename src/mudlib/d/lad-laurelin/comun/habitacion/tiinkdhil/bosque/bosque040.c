#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("sudeste");
  SetPathToTrolls("norte");
  SetPathToGigants("suroeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque041"));
  AddExit("sur", TBOSQUE("bosque056"));
  AddExit("oeste", TBOSQUE("bosque039"));
  AddExit("norte", TBOSQUE("bosque024"));
  AddExit("sudeste", TBOSQUE("bosque057"));
  AddExit("suroeste", TBOSQUE("bosque055"));
  AddExit("nordeste", TBOSQUE("bosque025"));
  AddExit("noroeste", TBOSQUE("bosque023"));
  ::salidas_cmd();
}
