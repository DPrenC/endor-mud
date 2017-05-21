#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("nordeste");
  SetPathToTrolls("noroeste");
  SetPathToGigants("noroeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque106"));
  AddExit("oeste", TBOSQUE("bosque104"));
  AddExit("sur", TBOSQUE("bosque119"));
  AddExit("sudeste", TBOSQUE("bosque120"));
  AddExit("suroeste", TBOSQUE("bosque118"));
  AddExit("norte", TBOSQUE("camino11"));
  AddExit("nordeste", TBOSQUE("camino12"));
  AddExit("noroeste", TBOSQUE("camino10"));
  ::salidas_cmd();

}
