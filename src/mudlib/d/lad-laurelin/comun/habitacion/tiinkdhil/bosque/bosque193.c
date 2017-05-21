#include "path.h"
inherit TBOSQUE("aleat_bosque");
#define TOCITY "oeste"

create(){
  ::create();
  SetPathToCity("sur");
  SetPathToTrolls("noroeste");
  SetPathToGigants("nordeste");
  SetIntNoise("Aparte del frotar de hojas provocado por el viento no escuchas "
   	"nada.\n");
  AddExit("este", TBOSQUE("bosque194"));
  AddExit("sur", TBOSQUE("bosque201"));
  AddExit("sudeste", TBOSQUE("bosque202"));
  AddExit("norte", TBOSQUE("bosque187"));
  AddExit("nordeste", TBOSQUE("bosque188"));
  AddExit("noroeste", TBOSQUE("bosque186"));
  ::salidas_cmd();
}
