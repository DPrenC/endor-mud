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
  AddExit("este", TBOSQUE("bosque127"));
  AddExit("oeste", TBOSQUE("bosque125"));
  AddExit("sur", TBOSQUE("bosque140"));
  AddExit("sudeste", TBOSQUE("bosque141"));
  AddExit("suroeste", TBOSQUE("bosque139"));
  AddExit("norte", TBOSQUE("bosque112"));
  AddExit("nordeste", TBOSQUE("bosque113"));
  AddExit("noroeste", TBOSQUE("bosque111"));
  ::salidas_cmd();
}
