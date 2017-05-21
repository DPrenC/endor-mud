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
  AddExit("este", TBOSQUE("bosque250"));
  AddExit("oeste", TBOSQUE("bosque152"));
  AddExit("sur", TBOSQUE("bosque158"));
  AddExit("sudeste", TBOSQUE("bosque261"));
  AddExit("suroeste", TBOSQUE("bosque157"));
  AddExit("norte", TBOSQUE("bosque148"));
  AddExit("nordeste", TBOSQUE("bosque239"));
  AddExit("noroeste", TBOSQUE("bosque147"));
  ::salidas_cmd();
}
