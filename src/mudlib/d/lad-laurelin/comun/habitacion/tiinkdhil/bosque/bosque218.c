#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("norte");
  SetPathToTrolls("oeste");
  SetPathToGigants("este");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque219"));
  AddExit("oeste", TBOSQUE("bosque217"));
  AddExit("sur", TBOSQUE("bosque229"));
  AddExit("sudeste", TBOSQUE("bosque230"));
  AddExit("suroeste", TBOSQUE("bosque228"));
  AddExit("norte", TCSUELO("salida4"));
  ::salidas_cmd();
}
