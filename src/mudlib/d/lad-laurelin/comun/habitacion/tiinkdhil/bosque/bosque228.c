#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("nordeste");
  SetPathToTrolls("noroeste");
  SetPathToGigants("nordeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque229"));
  AddExit("oeste", TBOSQUE("bosque137"));
  AddExit("sur", TBOSQUE("bosque239"));
  AddExit("sudeste", TBOSQUE("bosque240"));
  AddExit("suroeste", TBOSQUE("bosque148"));
  AddExit("norte", TBOSQUE("bosque217"));
  AddExit("nordeste", TBOSQUE("bosque218"));
  AddExit("noroeste", TBOSQUE("bosque123"));
  ::salidas_cmd();
}
