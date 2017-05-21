#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("norte");
  SetPathToTrolls("noroeste");
  SetPathToGigants("nordeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque263"));
  AddExit("oeste", TBOSQUE("bosque261"));
  AddExit("sur", TBOSQUE("bosque273"));
  AddExit("sudeste", TBOSQUE("bosque274"));
  AddExit("suroeste", TBOSQUE("bosque272"));
  AddExit("norte", TBOSQUE("bosque251"));
  AddExit("nordeste", TBOSQUE("bosque252"));
  AddExit("noroeste", TBOSQUE("bosque250"));
  ::salidas_cmd();
}
