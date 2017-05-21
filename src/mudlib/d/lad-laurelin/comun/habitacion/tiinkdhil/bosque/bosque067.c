#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("este");
  SetPathToTrolls("norte");
  SetPathToGigants("oeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque068"));
  AddExit("oeste", TBOSQUE("bosque066"));
  AddExit("sur", TBOSQUE("camino09"));
  AddExit("sudeste", TBOSQUE("bosque081"));
  AddExit("suroeste", TBOSQUE("camino08"));
  AddExit("norte", TBOSQUE("bosque051"));
  AddExit("nordeste", TBOSQUE("bosque052"));
  AddExit("noroeste", TBOSQUE("bosque050"));
  ::salidas_cmd();
}
