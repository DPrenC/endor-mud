#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("norte");
  SetPathToTrolls("noroeste");
  SetPathToGigants("nordeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque230"));
  AddExit("oeste", TBOSQUE("bosque228"));
  AddExit("sur", TBOSQUE("bosque240"));
  AddExit("sudeste", TBOSQUE("bosque241"));
  AddExit("suroeste", TBOSQUE("bosque239"));
  AddExit("norte", TBOSQUE("bosque218"));
  AddExit("nordeste", TBOSQUE("bosque219"));
  AddExit("noroeste", TBOSQUE("bosque217"));
  ::salidas_cmd();
}
