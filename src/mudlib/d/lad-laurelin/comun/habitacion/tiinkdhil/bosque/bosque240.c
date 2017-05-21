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
  AddExit("este", TBOSQUE("bosque241"));
  AddExit("oeste", TBOSQUE("bosque239"));
  AddExit("sur", TBOSQUE("bosque251"));
  AddExit("sudeste", TBOSQUE("bosque252"));
  AddExit("suroeste", TBOSQUE("bosque250"));
  AddExit("norte", TBOSQUE("bosque229"));
  AddExit("nordeste", TBOSQUE("bosque230"));
  AddExit("noroeste", TBOSQUE("bosque228"));
  ::salidas_cmd();
}
