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
  AddExit("este", TBOSQUE("bosque150"));
  AddExit("sur", TBOSQUE("bosque154"));
  AddExit("sudeste", TBOSQUE("bosque155"));
  AddExit("norte", TBOSQUE("bosque144"));
  AddExit("nordeste", TBOSQUE("bosque145"));
  AddExit("noroeste", TBOSQUE("bosque143"));
  ::salidas_cmd();
}
