#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("noroeste");
  SetPathToTrolls("nordeste");
  SetPathToGigants("noroeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("oeste", TBOSQUE("bosque140"));
  AddExit("norte", TBOSQUE("bosque127"));
  AddExit("nordeste", TBOSQUE("bosque128"));
  AddExit("noroeste", TBOSQUE("bosque126"));
  ::salidas_cmd();
}
