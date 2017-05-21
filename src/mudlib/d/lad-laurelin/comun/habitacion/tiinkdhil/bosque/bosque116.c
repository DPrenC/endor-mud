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
  AddExit("este", TBOSQUE("bosque117"));
  AddExit("oeste", TBOSQUE("bosque115"));
  AddExit("sur", TBOSQUE("bosque130"));
  AddExit("sudeste", TBOSQUE("bosque131"));
  AddExit("suroeste", TBOSQUE("bosque129"));
  AddExit("norte", TBOSQUE("bosque102"));
  AddExit("nordeste", TBOSQUE("bosque103"));
  AddExit("noroeste", TBOSQUE("bosque101"));
  ::salidas_cmd();
}
