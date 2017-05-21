#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("nordeste");
  SetPathToTrolls("norte");
  SetPathToGigants("noroeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque239"));
  AddExit("oeste", TBOSQUE("bosque147"));
  AddExit("sur", TBOSQUE("bosque153"));
  AddExit("sudeste", TBOSQUE("bosque250"));
  AddExit("suroeste", TBOSQUE("bosque152"));
  AddExit("norte", TBOSQUE("bosque137"));
  AddExit("nordeste", TBOSQUE("bosque228"));
  AddExit("noroeste", TBOSQUE("bosque136"));
  ::salidas_cmd();
}
