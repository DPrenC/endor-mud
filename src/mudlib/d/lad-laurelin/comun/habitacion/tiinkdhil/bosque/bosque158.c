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
  AddExit("este", TBOSQUE("bosque261"));
  AddExit("oeste", TBOSQUE("bosque157"));
  AddExit("sur", TBOSQUE("bosque161"));
  AddExit("sudeste", TBOSQUE("bosque272"));
  AddExit("suroeste", TBOSQUE("bosque160"));
  AddExit("norte", TBOSQUE("bosque153"));
  AddExit("nordeste", TBOSQUE("bosque250"));
  AddExit("noroeste", TBOSQUE("bosque152"));
  ::salidas_cmd();
}
