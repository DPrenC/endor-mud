#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("norte");
  SetPathToTrolls("nordeste");
  SetPathToGigants("nordeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque252"));
  AddExit("oeste", TBOSQUE("bosque250"));
  AddExit("sur", TBOSQUE("bosque262"));
  AddExit("sudeste", TBOSQUE("bosque263"));
  AddExit("suroeste", TBOSQUE("bosque261"));
  AddExit("norte", TBOSQUE("bosque240"));
  AddExit("nordeste", TBOSQUE("bosque241"));
  AddExit("noroeste", TBOSQUE("bosque239"));
  ::salidas_cmd();
}
