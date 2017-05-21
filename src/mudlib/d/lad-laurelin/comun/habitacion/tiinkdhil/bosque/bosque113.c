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
  AddExit("este", TBOSQUE("bosque114"));
  AddExit("oeste", TBOSQUE("bosque112"));
  AddExit("sur", TBOSQUE("bosque127"));
  AddExit("sudeste", TBOSQUE("bosque128"));
  AddExit("suroeste", TBOSQUE("bosque126"));
  AddExit("norte", TBOSQUE("bosque099"));
  AddExit("nordeste", TBOSQUE("bosque100"));
  AddExit("noroeste", TBOSQUE("bosque098"));
  ::salidas_cmd();
}
