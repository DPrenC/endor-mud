#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("noroeste");
  SetPathToTrolls("noroeste");
  SetPathToGigants("noroeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque216"));
  AddExit("oeste", TBOSQUE("bosque214"));
  AddExit("sur", TBOSQUE("bosque226"));
  AddExit("sudeste", TBOSQUE("bosque227"));
  AddExit("suroeste", TBOSQUE("bosque225"));
  AddExit("norte", TBOSQUE("bosque207"));
  AddExit("nordeste", TBOSQUE("bosque208"));
  AddExit("noroeste", TBOSQUE("bosque206"));
  ::salidas_cmd();
}
