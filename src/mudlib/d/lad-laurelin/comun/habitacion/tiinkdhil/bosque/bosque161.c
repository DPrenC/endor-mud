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
  AddExit("este", TBOSQUE("bosque272"));
  AddExit("oeste", TBOSQUE("bosque160"));
  AddExit("suroeste", TBOSQUE("bosque162"));
  AddExit("norte", TBOSQUE("bosque158"));
  AddExit("nordeste", TBOSQUE("bosque261"));
  AddExit("noroeste", TBOSQUE("bosque157"));
  ::salidas_cmd();
}
