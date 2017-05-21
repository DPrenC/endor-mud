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
  AddExit("este", TBOSQUE("bosque240"));
  AddExit("oeste", TBOSQUE("bosque148"));
  AddExit("sur", TBOSQUE("bosque250"));
  AddExit("sudeste", TBOSQUE("bosque251"));
  AddExit("suroeste", TBOSQUE("bosque153"));
  AddExit("norte", TBOSQUE("bosque228"));
  AddExit("nordeste", TBOSQUE("bosque229"));
  AddExit("noroeste", TBOSQUE("bosque137"));
  ::salidas_cmd();
}
