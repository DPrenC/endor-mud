#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("suroeste");
  SetPathToTrolls("nordeste");
  SetPathToGigants("noroeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque101"));
  AddExit("oeste", TBOSQUE("bosque099"));
  AddExit("sur", TBOSQUE("bosque114"));
  AddExit("sudeste", TBOSQUE("bosque115"));
  AddExit("suroeste", TBOSQUE("bosque113"));
  AddExit("norte", TBOSQUE("bosque091"));
  AddExit("nordeste", TBOSQUE("bosque092"));
  AddExit("noroeste", TBOSQUE("camino05"));
  ::salidas_cmd();
}
