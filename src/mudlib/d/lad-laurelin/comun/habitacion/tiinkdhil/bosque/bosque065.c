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
  AddExit("este", TBOSQUE("bosque066"));
  AddExit("oeste", TBOSQUE("bosque064"));
  AddExit("sur", TBOSQUE("camino07"));
  AddExit("sudeste", TBOSQUE("camino08"));
  AddExit("suroeste", TBOSQUE("camino06"));
  AddExit("norte", TBOSQUE("bosque049"));
  AddExit("nordeste", TBOSQUE("bosque050"));
  AddExit("noroeste", TBOSQUE("bosque048"));
  ::salidas_cmd();
}
