#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("nordeste");
  SetPathToTrolls("noroeste");
  SetPathToGigants("nordeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque273"));
  AddExit("oeste", TBOSQUE("bosque161"));
  AddExit("norte", TBOSQUE("bosque261"));
  AddExit("nordeste", TBOSQUE("bosque262"));
  AddExit("noroeste", TBOSQUE("bosque158"));
  ::salidas_cmd();
}
