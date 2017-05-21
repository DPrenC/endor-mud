#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("este");
  SetPathToTrolls("noroeste");
  SetPathToGigants("este");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque218"));
  AddExit("oeste", TBOSQUE("bosque123"));
  AddExit("sur", TBOSQUE("bosque228"));
  AddExit("sudeste", TBOSQUE("bosque229"));
  AddExit("suroeste", TBOSQUE("bosque137"));
  AddExit("noroeste", TBOSQUE("bosque109"));
  ::salidas_cmd();
}
