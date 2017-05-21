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
  AddExit("este", TBOSQUE("bosque116"));
  AddExit("oeste", TBOSQUE("bosque114"));
  AddExit("sur", TBOSQUE("bosque129"));
  AddExit("sudeste", TBOSQUE("bosque130"));
  AddExit("suroeste", TBOSQUE("bosque128"));
  AddExit("norte", TBOSQUE("bosque101"));
  AddExit("nordeste", TBOSQUE("bosque102"));
  AddExit("noroeste", TBOSQUE("bosque100"));
  ::salidas_cmd();
}
