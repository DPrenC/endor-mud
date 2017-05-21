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
  AddExit("este", TBOSQUE("bosque262"));
  AddExit("oeste", TBOSQUE("bosque158"));
  AddExit("sur", TBOSQUE("bosque272"));
  AddExit("sudeste", TBOSQUE("bosque273"));
  AddExit("suroeste", TBOSQUE("bosque161"));
  AddExit("norte", TBOSQUE("bosque250"));
  AddExit("nordeste", TBOSQUE("bosque251"));
  AddExit("noroeste", TBOSQUE("bosque153"));
  ::salidas_cmd();
}
