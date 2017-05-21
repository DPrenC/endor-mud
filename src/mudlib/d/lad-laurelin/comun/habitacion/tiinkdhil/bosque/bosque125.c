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
  AddExit("este", TBOSQUE("bosque126"));
  AddExit("oeste", TBOSQUE("bosque124"));
  AddExit("sur", TBOSQUE("bosque139"));
  AddExit("sudeste", TBOSQUE("bosque140"));
  AddExit("suroeste", TBOSQUE("bosque138"));
  AddExit("norte", TBOSQUE("bosque111"));
  AddExit("nordeste", TBOSQUE("bosque112"));
  AddExit("noroeste", TBOSQUE("camino02"));
  ::salidas_cmd();
}
