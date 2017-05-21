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
  AddExit("este", TBOSQUE("bosque011"));
  AddExit("sur", TBOSQUE("bosque026"));
  AddExit("sudeste", TBOSQUE("bosque027"));
  AddExit("norte", TBOSQUE("bosque005"));
  AddExit("nordeste", TBOSQUE("bosque006"));
  ::salidas_cmd();
}
