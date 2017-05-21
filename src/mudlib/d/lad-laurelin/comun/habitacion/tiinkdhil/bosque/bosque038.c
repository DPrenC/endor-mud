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
  AddExit("este", TBOSQUE("bosque039"));
  AddExit("sur", TBOSQUE("bosque054"));
  AddExit("oeste", TBOSQUE("bosque037"));
  AddExit("norte", TBOSQUE("bosque022"));
  AddExit("sudeste", TBOSQUE("bosque055"));
  AddExit("suroeste", TBOSQUE("bosque053"));
  AddExit("nordeste", TBOSQUE("bosque023"));
  AddExit("noroeste", TBOSQUE("bosque021"));
  ::salidas_cmd();
}
