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
  AddExit("este", TBOSQUE("bosque061"));
  AddExit("oeste", TBOSQUE("bosque059"));
  AddExit("sur", TBOSQUE("bosque077"));
  AddExit("sudeste", TBOSQUE("bosque078"));
  AddExit("suroeste", TBOSQUE("bosque076"));
  AddExit("norte", TBOSQUE("bosque044"));
  AddExit("nordeste", TBOSQUE("bosque045"));
  AddExit("noroeste", TBOSQUE("bosque043"));
  ::salidas_cmd();
}
