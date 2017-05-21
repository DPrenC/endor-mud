#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("oeste");
  SetPathToTrolls("nordeste");
  SetPathToGigants("noroeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque129"));
  AddExit("oeste", TBOSQUE("bosque127"));
  AddExit("sudeste", TBOSQUE("bosque142"));
  AddExit("suroeste", TBOSQUE("bosque141"));
  AddExit("norte", TBOSQUE("bosque114"));
  AddExit("nordeste", TBOSQUE("bosque115"));
  AddExit("noroeste", TBOSQUE("bosque113"));
  ::salidas_cmd();
}
