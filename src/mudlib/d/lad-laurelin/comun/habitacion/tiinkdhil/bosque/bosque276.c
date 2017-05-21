#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("noroeste");
  SetPathToTrolls("noroeste");
  SetPathToGigants("nordeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque277"));
  AddExit("oeste", TBOSQUE("bosque275"));
  AddExit("sudeste", TBOSQUE("bosque283"));
  AddExit("norte", TBOSQUE("bosque265"));
  AddExit("nordeste", TBOSQUE("bosque266"));
  AddExit("noroeste", TBOSQUE("bosque264"));
  ::salidas_cmd();
}
