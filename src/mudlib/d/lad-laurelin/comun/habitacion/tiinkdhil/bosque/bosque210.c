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
  AddExit("este", TBOSQUE("bosque211"));
  AddExit("oeste", TBOSQUE("bosque209"));
  AddExit("sur", TBOSQUE("bosque221"));
  AddExit("sudeste", TBOSQUE("bosque222"));
  AddExit("suroeste", TBOSQUE("bosque220"));
  AddExit("norte", TBOSQUE("bosque202"));
  AddExit("nordeste", TBOSQUE("bosque203"));
  AddExit("noroeste", TBOSQUE("bosque201"));
  ::salidas_cmd();
}
