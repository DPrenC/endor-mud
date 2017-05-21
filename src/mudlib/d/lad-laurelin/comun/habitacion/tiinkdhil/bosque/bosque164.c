#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("suroeste");
  SetPathToTrolls("suroeste");
  SetPathToGigants("sur");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque165"));
  AddExit("oeste", TBOSQUE("bosque163"));
  AddExit("sur", TBOSQUE("bosque169"));
  AddExit("sudeste", TBOSQUE("bosque170"));
  AddExit("suroeste", TBOSQUE("bosque168"));
  ::salidas_cmd();
}
