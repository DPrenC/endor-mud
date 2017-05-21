#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("este");
  SetPathToTrolls("noroeste");
  SetPathToGigants("noroeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque083"));
  AddExit("oeste", TBOSQUE("bosque081"));
  AddExit("sur", TBOSQUE("camino11"));
  AddExit("sudeste", TBOSQUE("camino12"));
  AddExit("suroeste", TBOSQUE("camino10"));
  AddExit("norte", TBOSQUE("bosque069"));
  AddExit("nordeste", TBOSQUE("bosque070"));
  AddExit("noroeste", TBOSQUE("bosque068"));
  ::salidas_cmd();
}
