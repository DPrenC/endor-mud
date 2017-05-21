#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("noroeste");
  SetPathToTrolls("noroeste");
  SetPathToGigants("nordeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque235"));
  AddExit("oeste", TBOSQUE("bosque233"));
  AddExit("sur", TBOSQUE("bosque245"));
  AddExit("sudeste", TBOSQUE("bosque246"));
  AddExit("suroeste", TBOSQUE("bosque244"));
  AddExit("norte", TBOSQUE("bosque223"));
  AddExit("nordeste", TBOSQUE("bosque224"));
  AddExit("noroeste", TBOSQUE("bosque222"));
  ::salidas_cmd();
}
