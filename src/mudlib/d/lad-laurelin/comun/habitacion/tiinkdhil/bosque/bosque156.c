#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("nordeste");
  SetPathToTrolls("nordeste");
  SetPathToGigants("noroeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque157"));
  AddExit("oeste", TBOSQUE("bosque155"));
  AddExit("sur", TBOSQUE("bosque159"));
  AddExit("sudeste", TBOSQUE("bosque160"));
  AddExit("norte", TBOSQUE("bosque151"));
  AddExit("nordeste", TBOSQUE("bosque152"));
  AddExit("noroeste", TBOSQUE("bosque150"));
  ::salidas_cmd();
}
