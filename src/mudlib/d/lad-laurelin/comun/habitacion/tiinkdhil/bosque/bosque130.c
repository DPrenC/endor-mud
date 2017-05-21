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
  AddExit("este", TBOSQUE("bosque131"));
  AddExit("oeste", TBOSQUE("bosque129"));
  AddExit("suroeste", TBOSQUE("bosque142"));
  AddExit("norte", TBOSQUE("bosque116"));
  AddExit("nordeste", TBOSQUE("bosque117"));
  AddExit("noroeste", TBOSQUE("bosque115"));
  ::salidas_cmd();
}
