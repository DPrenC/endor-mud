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
  AddExit("este", TBOSQUE("bosque128"));
  AddExit("oeste", TBOSQUE("bosque126"));
  AddExit("sur", TBOSQUE("bosque141"));
  AddExit("suroeste", TBOSQUE("bosque140"));
  AddExit("norte", TBOSQUE("bosque113"));
  AddExit("nordeste", TBOSQUE("bosque114"));
  AddExit("noroeste", TBOSQUE("bosque112"));
  ::salidas_cmd();
}
