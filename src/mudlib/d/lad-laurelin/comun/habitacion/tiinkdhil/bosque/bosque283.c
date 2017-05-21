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
  AddExit("este", TBOSQUE("bosque284"));
  AddExit("sudeste", TBOSQUE("bosque288"));
  AddExit("norte", TBOSQUE("bosque277"));
  AddExit("nordeste", TBOSQUE("bosque278"));
  AddExit("noroeste", TBOSQUE("bosque276"));
  ::salidas_cmd();
}
