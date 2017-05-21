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
  AddExit("este", TBOSQUE("bosque141"));
  AddExit("oeste", TBOSQUE("bosque139"));
  AddExit("norte", TBOSQUE("bosque126"));
  AddExit("nordeste", TBOSQUE("bosque127"));
  AddExit("noroeste", TBOSQUE("bosque125"));
  ::salidas_cmd();
}
