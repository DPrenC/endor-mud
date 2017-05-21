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
  AddExit("este", TBOSQUE("bosque063"));
  AddExit("oeste", TBOSQUE("bosque061"));
  AddExit("sur", TBOSQUE("bosque079"));
  AddExit("sudeste", TBOSQUE("bosque080"));
  AddExit("suroeste", TBOSQUE("bosque078"));
  AddExit("norte", TBOSQUE("bosque046"));
  AddExit("nordeste", TBOSQUE("bosque047"));
  AddExit("noroeste", TBOSQUE("bosque045"));
  ::salidas_cmd();
}
