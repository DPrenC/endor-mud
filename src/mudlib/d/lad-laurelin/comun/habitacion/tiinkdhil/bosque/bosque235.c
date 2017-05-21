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
  AddExit("este", TBOSQUE("bosque236"));
  AddExit("oeste", TBOSQUE("bosque234"));
  AddExit("sur", TBOSQUE("bosque246"));
  AddExit("sudeste", TBOSQUE("bosque247"));
  AddExit("suroeste", TBOSQUE("bosque245"));
  AddExit("norte", TBOSQUE("bosque224"));
  AddExit("nordeste", TBOSQUE("bosque225"));
  AddExit("noroeste", TBOSQUE("bosque223"));
  ::salidas_cmd();
}
