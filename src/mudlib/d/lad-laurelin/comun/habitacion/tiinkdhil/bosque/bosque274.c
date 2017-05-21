#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("noroeste");
  SetPathToTrolls("nordeste");
  SetPathToGigants("nordeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque275"));
  AddExit("oeste", TBOSQUE("bosque273"));
  AddExit("norte", TBOSQUE("bosque263"));
  AddExit("nordeste", TBOSQUE("bosque264"));
  AddExit("noroeste", TBOSQUE("bosque262"));
  ::salidas_cmd();
}
