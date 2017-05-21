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
  AddExit("este", TBOSQUE("bosque158"));
  AddExit("oeste", TBOSQUE("bosque156"));
  AddExit("sur", TBOSQUE("bosque160"));
  AddExit("sudeste", TBOSQUE("bosque161"));
  AddExit("suroeste", TBOSQUE("bosque159"));
  AddExit("norte", TBOSQUE("bosque152"));
  AddExit("nordeste", TBOSQUE("bosque153"));
  AddExit("noroeste", TBOSQUE("bosque151"));
  ::salidas_cmd();
}
