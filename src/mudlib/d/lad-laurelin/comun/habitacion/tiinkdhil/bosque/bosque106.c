#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("nordeste");
  SetPathToTrolls("nordeste");
  SetPathToGigants("noroeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque107"));
  AddExit("oeste", TBOSQUE("bosque105"));
  AddExit("sur", TBOSQUE("bosque120"));
  AddExit("sudeste", TBOSQUE("bosque121"));
  AddExit("suroeste", TBOSQUE("bosque119"));
  AddExit("norte", TBOSQUE("camino12"));
  AddExit("nordeste", TBOSQUE("camino13"));
  AddExit("noroeste", TBOSQUE("camino11"));
  ::salidas_cmd();

}
