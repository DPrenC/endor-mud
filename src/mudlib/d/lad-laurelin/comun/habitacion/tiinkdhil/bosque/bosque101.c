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
  AddExit("este", TBOSQUE("bosque102"));
  AddExit("oeste", TBOSQUE("bosque100"));
  AddExit("sur", TBOSQUE("bosque115"));
  AddExit("sudeste", TBOSQUE("bosque116"));
  AddExit("suroeste", TBOSQUE("bosque114"));
  AddExit("norte", TBOSQUE("bosque092"));
  AddExit("nordeste", TBOSQUE("bosque093"));
  AddExit("noroeste", TBOSQUE("bosque091"));
  ::salidas_cmd();

}
