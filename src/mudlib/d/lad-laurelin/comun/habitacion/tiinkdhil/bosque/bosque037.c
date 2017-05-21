#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("sudeste");
  SetPathToTrolls("noroeste");
  SetPathToGigants("suroeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque038"));
  AddExit("sur", TBOSQUE("bosque053"));
  AddExit("oeste", TBOSQUE("bosque036"));
  AddExit("norte", TBOSQUE("bosque021"));
  AddExit("sudeste", TBOSQUE("bosque054"));
  AddExit("suroeste", TBOSQUE("bosque052"));
  AddExit("nordeste", TBOSQUE("bosque022"));
  AddExit("noroeste", TBOSQUE("bosque020"));
  ::salidas_cmd();
}
