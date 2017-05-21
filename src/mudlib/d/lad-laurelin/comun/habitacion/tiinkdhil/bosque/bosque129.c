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
  AddExit("este", TBOSQUE("bosque130"));
  AddExit("oeste", TBOSQUE("bosque128"));
  AddExit("sur", TBOSQUE("bosque142"));
  AddExit("norte", TBOSQUE("bosque115"));
  AddExit("nordeste", TBOSQUE("bosque116"));
  AddExit("noroeste", TBOSQUE("bosque114"));
  ::salidas_cmd();
}
