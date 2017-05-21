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
  AddExit("este", TBOSQUE("bosque062"));
  AddExit("oeste", TBOSQUE("bosque060"));
  AddExit("sur", TBOSQUE("bosque078"));
  AddExit("sudeste", TBOSQUE("bosque079"));
  AddExit("suroeste", TBOSQUE("bosque077"));
  AddExit("norte", TBOSQUE("bosque045"));
  AddExit("nordeste", TBOSQUE("bosque046"));
  AddExit("noroeste", TBOSQUE("bosque044"));
  ::salidas_cmd();
}
