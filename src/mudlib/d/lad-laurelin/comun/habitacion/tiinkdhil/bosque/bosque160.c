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
  AddExit("este", TBOSQUE("bosque161"));
  AddExit("oeste", TBOSQUE("bosque159"));
  AddExit("sur", TBOSQUE("bosque162"));
  AddExit("norte", TBOSQUE("bosque157"));
  AddExit("nordeste", TBOSQUE("bosque158"));
  AddExit("noroeste", TBOSQUE("bosque156"));
  ::salidas_cmd();
}
