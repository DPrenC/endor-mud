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
  AddExit("este", TBOSQUE("bosque115"));
  AddExit("oeste", TBOSQUE("bosque113"));
  AddExit("sur", TBOSQUE("bosque128"));
  AddExit("sudeste", TBOSQUE("bosque129"));
  AddExit("suroeste", TBOSQUE("bosque127"));
  AddExit("norte", TBOSQUE("bosque100"));
  AddExit("nordeste", TBOSQUE("bosque101"));
  AddExit("noroeste", TBOSQUE("bosque099"));
  ::salidas_cmd();
}
