#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("noroeste");
  SetPathToTrolls("norte");
  SetPathToGigants("nordeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque253"));
  AddExit("oeste", TBOSQUE("bosque251"));
  AddExit("sur", TBOSQUE("bosque263"));
  AddExit("sudeste", TBOSQUE("bosque264"));
  AddExit("suroeste", TBOSQUE("bosque262"));
  AddExit("norte", TBOSQUE("bosque241"));
  AddExit("nordeste", TBOSQUE("bosque242"));
  AddExit("noroeste", TBOSQUE("bosque240"));
  ::salidas_cmd();
}
