#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("sudeste");
  SetPathToTrolls("este");
  SetPathToGigants("sur");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque027"));
  AddExit("sur", TBOSQUE("bosque042"));
  AddExit("norte", TBOSQUE("bosque010"));
  AddExit("sudeste", TBOSQUE("bosque043"));
  AddExit("nordeste", TBOSQUE("bosque011"));
  ::salidas_cmd();
}
