#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("este");
  SetPathToTrolls("nordeste");
  SetPathToGigants("noroeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque078"));
  AddExit("oeste", TBOSQUE("bosque076"));
  AddExit("sur", TBOSQUE("bosque089"));
  AddExit("sudeste", TBOSQUE("bosque090"));
  AddExit("suroeste", TBOSQUE("bosque088"));
  AddExit("norte", TBOSQUE("bosque060"));
  AddExit("nordeste", TBOSQUE("bosque061"));
  AddExit("noroeste", TBOSQUE("bosque059"));
  ::salidas_cmd();
}
