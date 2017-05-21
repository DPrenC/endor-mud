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
  AddExit("este", TBOSQUE("bosque023"));
  AddExit("sur", TBOSQUE("bosque038"));
  AddExit("oeste", TBOSQUE("bosque021"));
  AddExit("sudeste", TBOSQUE("bosque039"));
  AddExit("suroeste", TBOSQUE("bosque037"));
  ::salidas_cmd();
}
