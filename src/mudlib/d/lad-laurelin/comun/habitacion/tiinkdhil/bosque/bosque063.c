#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("este");
  SetPathToTrolls("nordeste");
  SetPathToGigants("oeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque064"));
  AddExit("oeste", TBOSQUE("bosque062"));
  AddExit("sur", TBOSQUE("bosque080"));
  AddExit("sudeste", TBOSQUE("camino06"));
  AddExit("suroeste", TBOSQUE("bosque079"));
  AddExit("norte", TBOSQUE("bosque047"));
  AddExit("nordeste", TBOSQUE("bosque048"));
  AddExit("noroeste", TBOSQUE("bosque046"));
  ::salidas_cmd();
}
